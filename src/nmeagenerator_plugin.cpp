//////////////////////////////////////
/// Project:  OpenCPN              ///
/// Plugin:   NmeaGenerator        ///
/// Author:   Kupofty              ///
//////////////////////////////////////


///////////////////////
/// Include Headers ///
///////////////////////
#include "nmeagenerator_plugin.h"
#include "globals.h"
#include "settings_ui_derived.h"



///////////////////////
/// Class Factories ///
///////////////////////
extern "C" DECL_EXP opencpn_plugin* create_pi(void *ppimgr) {
  return new NmeaGeneratorPlugin(ppimgr);
}

extern "C" DECL_EXP void destroy_pi(opencpn_plugin* p) {
  delete p;
}



////////////////////////////
/// Class Initialization ///
////////////////////////////
NmeaGeneratorPlugin::NmeaGeneratorPlugin(void* ppimgr) : opencpn_plugin_120(ppimgr), wxEvtHandler()
{
  //Logo for plugin catalog (SVG only)
  wxString pluginFolder = GetPluginDataDir(PKG_NAME) + wxFileName::GetPathSeparator() + "data" + wxFileName::GetPathSeparator();
  g_pluginBitmap = GetBitmapFromSVGFile(pluginFolder + "icon_nmea_catalog.svg", 32, 32);

  // A flag used to indicate the toggled/untoggled state of the toolbar button
  isToolbarActive = false;
}

NmeaGeneratorPlugin::~NmeaGeneratorPlugin()
{
}

int NmeaGeneratorPlugin::Init()
{
  parentWindow = GetOCPNCanvasWindow();
  configSettings = GetOCPNConfigObject();

  LoadSettings();

  // Add the toolbar button (SVG only)
  wxString pluginFolder = GetPluginDataDir(PKG_NAME) + wxFileName::GetPathSeparator() + "data" + wxFileName::GetPathSeparator();
  wxString normalIcon   = pluginFolder + "icon_nmea_toolbar_default.svg";
  wxString rolloverIcon = pluginFolder + "icon_nmea_toolbar_toggled.svg"; //BUG : rollover state not working in OpenCPN
  wxString toggledIcon  = pluginFolder + "icon_nmea_toolbar_toggled.svg";
  toolbarId = InsertPlugInToolSVG("NmeaGenerator", normalIcon, rolloverIcon, toggledIcon, wxITEM_CHECK, "NmeaGenerator", "NmeaGenerator Plugin Toolbar", NULL, -1, 0, this);

  //Init main GUI to NULL
  myGUI = NULL;

  // Notify OpenCPN what callbacks the plugin registers to receive
  return (INSTALLS_TOOLBAR_TOOL //Add toolbar icon
          | WANTS_PREFERENCES); //Add "Preferences" button in plugin catalogue
}

bool NmeaGeneratorPlugin::DeInit()
{
  if (NULL != myGUI)
  {
    myGUI->Close();
    delete myGUI;
    myGUI = NULL;

    isToolbarActive = false;
    SetToolbarItemState(toolbarId, isToolbarActive);
  }

  return true;
}


////////////////////////////////////////
/// OCPN Required Plugin Information ///
////////////////////////////////////////
int NmeaGeneratorPlugin::GetAPIVersionMajor()
{
  return atoi(API_VERSION);
}

int NmeaGeneratorPlugin::GetAPIVersionMinor()
{
  std::string v(API_VERSION);
  size_t dotpos = v.find('.');
  return atoi(v.substr(dotpos + 1).c_str());
}

int NmeaGeneratorPlugin::GetPlugInVersionMajor()
{
  return PLUGIN_VERSION_MAJOR;
}

int NmeaGeneratorPlugin::GetPlugInVersionMinor()
{
  return PLUGIN_VERSION_MINOR;
}

int NmeaGeneratorPlugin::GetPlugInVersionPatch()
{
  return PLUGIN_VERSION_PATCH;
}

wxString NmeaGeneratorPlugin::GetCommonName()
{
  return PLUGIN_API_NAME;
}

wxString NmeaGeneratorPlugin::GetShortDescription()
{
  return PKG_SUMMARY;
}

wxString NmeaGeneratorPlugin::GetLongDescription()
{
  return PKG_DESCRIPTION;
}

wxBitmap* NmeaGeneratorPlugin::GetPlugInBitmap()
{
  return &g_pluginBitmap;
}

int NmeaGeneratorPlugin::GetToolbarToolCount() {
  return 1;
}



////////////////
/// Settings ///
////////////////
void NmeaGeneratorPlugin::LoadSettings()
{
  if (configSettings)
  {
    configSettings->SetPath("/PlugIns/NmeaGeneratorPlugin");
    configSettings->Read("NotebookPage", &g_notebookPage, 0);
  }
}

void NmeaGeneratorPlugin::SaveSettings()
{
  if (configSettings)
  {
    configSettings->SetPath("/PlugIns/NmeaGeneratorPlugin");
    configSettings->Write("NotebookPage", g_notebookPage);
  }
}



/////////////////////////////////
/// OCPN Interactions Methods ///
/////////////////////////////////
void NmeaGeneratorPlugin::ShowPreferencesDialog(wxWindow* parent)
{
  auto dialogSettings = std::make_unique<DialogSettings>(parent, wxID_ANY, _("NmeaGenerator Preferences"));
  if (wxID_OK == dialogSettings->ShowModal())
    SaveSettings();
}

void NmeaGeneratorPlugin::OnToolbarToolCallback(int id)
{
  if (id != toolbarId)
  {
    return;
  }

  //Create GUI first time
  if(myGUI == NULL)
  {
    myGUI = new DialogMainGui(parentWindow);
    myGUI->plugin = this;

    //Apply settings to UI
    myGUI->m_notebook->SetSelection(g_notebookPage);
  }

  //Toggle UI & toolbar icon state
  isToolbarActive = !isToolbarActive;
  SetToolbarItemState(id, isToolbarActive);
  if (isToolbarActive)
  {
    myGUI->Show();
    myGUI->Raise();
    myGUI->SetFocus();
  }
  else
  {
    myGUI->Hide();
    myGUI->stopTimers();
  }

  //Refresh screen
  RequestRefresh(parentWindow);
}



////////////////////
/// wxGUI Events ///
////////////////////
void NmeaGeneratorPlugin::OnGuiClosed()
{
  isToolbarActive = false;
  SetToolbarItemState(toolbarId, false);
  myGUI->Hide();

  //Refresh screen
  RequestRefresh(parentWindow);
}

void NmeaGeneratorPlugin::sendNmeaSentence(wxString sentence)
{
  PushNMEABuffer(sentence); //using old API
}
