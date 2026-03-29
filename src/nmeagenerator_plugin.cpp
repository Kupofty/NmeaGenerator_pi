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
  wxString pluginFolder = GetPluginDataDir(PKG_NAME) + wxFileName::GetPathSeparator() + "data" + wxFileName::GetPathSeparator();

  //Logo for plugin catalog (SVG only)
  g_pluginBitmap = GetBitmapFromSVGFile(pluginFolder + "icon_nmea_catalog.svg", 32, 32);

  // Get a pointer to the opencpn display canvas, to use as a parent for the POI Manager dialog
  m_parent_window = GetOCPNCanvasWindow();

  //Main GUI
  myGUI = new DialogMainGui(m_parent_window);
  myGUI->plugin = this;
}

NmeaGeneratorPlugin::~NmeaGeneratorPlugin()
{
}

int NmeaGeneratorPlugin::Init()
{
  LoadSettings();

  wxString pluginFolder = GetPluginDataDir(PKG_NAME) + wxFileName::GetPathSeparator() + "data" + wxFileName::GetPathSeparator();

  // Logo for toolbar (SVG only)
  wxString normalIcon   = pluginFolder + "icon_nmea_toolbar_default.svg";
  wxString rolloverIcon = pluginFolder + "icon_nmea_toolbar_toggled.svg"; //BUG : rollover state not working in OpenCPN
  wxString toggledIcon  = pluginFolder + "icon_nmea_toolbar_toggled.svg";

  // Add the toolbar button
  toolbarId = InsertPlugInToolSVG("NmeaGenerator", normalIcon, rolloverIcon, toggledIcon, wxITEM_CHECK, "NmeaGenerator", "NmeaGenerator Plugin Toolbar", NULL, -1, 0, this);

  // A flag used to indicate the toggled/untoggled state of the toolbar button
  isToolbarActive = false;

  // Notify OpenCPN what callbacks the plugin registers to receive
  return (INSTALLS_TOOLBAR_TOOL);
}

bool NmeaGeneratorPlugin::DeInit()
{
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
  if (id == toolbarId)
  {
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
    }
  }
}


////////////////
/// Settings ///
////////////////
void NmeaGeneratorPlugin::LoadSettings()
{
  wxFileConfig* configSettings = GetOCPNConfigObject();
  if (configSettings)
  {
    configSettings->SetPath("/PlugIns/NmeaGeneratorPlugin");
    configSettings->Read("A_Boolean_Value", &g_someBooleanValue, false);
    configSettings->Read("An_Integer_Value", &g_someIntegerValue, 0);
    configSettings->Read("A_String_Value", &g_someStringValue, wxEmptyString);
  }
}

void NmeaGeneratorPlugin::SaveSettings()
{
  wxFileConfig* configSettings = GetOCPNConfigObject();
  if (configSettings)
  {
    configSettings->SetPath("/PlugIns/NmeaGeneratorPlugin");
    configSettings->Write("A_Boolean_Value", g_someBooleanValue);
    configSettings->Write("An_Integer_Value", g_someIntegerValue);
    configSettings->Write("A_String_Value", g_someStringValue);
  }
}



////////////////////
/// wxGUI Events ///
////////////////////
void NmeaGeneratorPlugin::OnGuiClosed()
{
  isToolbarActive = false;
  SetToolbarItemState(toolbarId, false);
  myGUI->Hide();
}

void NmeaGeneratorPlugin::sendNmeaSentence(wxString sentence)
{
  PushNMEABuffer(sentence); //using old API
}
