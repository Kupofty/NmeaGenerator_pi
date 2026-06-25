//////////////////////////////////////
/// Project:  OpenCPN              ///
/// Plugin:   NmeaGenerator        ///
/// Author:   Kupofty              ///
//////////////////////////////////////


///////////////////////
/// Include Headers ///
///////////////////////
#include "nmeagenerator_plugin.h"
#include "settings/global_settings.h"
#include "settings/settings_ui_derived.h"



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
  //Load translations
  AddLocaleCatalog("opencpn-nmeagenerator_pi");

  //Init GUI
  parentWindow = GetOCPNCanvasWindow();
  configSettings = GetOCPNConfigObject();
  myGUI = NULL;

  //Settings
  LoadSettings();

  //Add the toolbar button (SVG only)
  wxString pluginFolder = GetPluginDataDir(PKG_NAME) + wxFileName::GetPathSeparator() + "data" + wxFileName::GetPathSeparator();
  wxString normalIcon   = pluginFolder + "icon_nmea_toolbar_default.svg";
  wxString rolloverIcon = pluginFolder + "icon_nmea_toolbar_toggled.svg"; //BUG : rollover state not working in OpenCPN
  wxString toggledIcon  = pluginFolder + "icon_nmea_toolbar_toggled.svg";
  toolbarId = InsertPlugInToolSVG("NmeaGenerator", normalIcon, rolloverIcon, toggledIcon, wxITEM_CHECK, "NmeaGenerator", "NmeaGenerator Plugin Toolbar", NULL, -1, 0, this);

  //Right-click menu entry
  wxMenu simPositionMenu;
  positionMenuID = AddCanvasContextMenuItem(new wxMenuItem(&simPositionMenu, -1, _("NmeaGenerator...")), this);
  SetCanvasContextMenuItemViz(positionMenuID, false);

  //Inform OpenCPN about the plugin capabilities and requested callbacks
  return  ( INSTALLS_TOOLBAR_TOOL  //Add toolbar icon
          | WANTS_PREFERENCES      //Add "Preferences" button in plugin catalogue
          | WANTS_CURSOR_LATLON);  //Enable SetCursorLatLon()
}

bool NmeaGeneratorPlugin::DeInit()
{
  SaveSettings();

  if (myGUI != NULL)
  {
    myGUI->stopTimers();
    myGUI->Close();
    delete myGUI;
    myGUI = NULL;

    isToolbarActive = false;
    SetToolbarItemState(toolbarId, false);
    SetCanvasContextMenuItemViz(positionMenuID, false);
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

    configSettings->Read("NotebookPage", &g_defaultNotebookPage, 0);
    configSettings->Read("RestoreLastTab", &g_restoreLastTab, 1);
    configSettings->Read("LastOpenTab", &g_lastOpenTab, 0);

    configSettings->Read("RestoreWindowSize", &g_restoreWindowSize, 1);
    configSettings->Read("WindowWidth", &g_windowWidth, 650);
    configSettings->Read("WindowHeight", &g_windowHeight, 400);

    configSettings->Read("RestoreWindowPos", &g_restoreWindowPos, 1);
    configSettings->Read("WindowPosX", &g_windowPosX, 0);
    configSettings->Read("WindowPosY", &g_windowPosY, 0);

    configSettings->Read("SendDataAfterWindowClose", &g_sendDataAfterWindowClose, 0);

    configSettings->Read("aisMMSI", &g_aisMMSI, 227000000);
  }
}

void NmeaGeneratorPlugin::SaveSettings()
{
  //Update settings variables
  if (myGUI != NULL)
  {
    g_lastOpenTab = myGUI->m_notebook->GetSelection();

    wxSize size = myGUI->GetSize();
    g_windowWidth = size.GetWidth();
    g_windowHeight = size.GetHeight();

    wxPoint pos = myGUI->GetPosition();
    g_windowPosX = pos.x;
    g_windowPosY = pos.y;
  }

  if (configSettings)
  {
    configSettings->SetPath("/PlugIns/NmeaGeneratorPlugin");

    configSettings->Write("NotebookPage", g_defaultNotebookPage);
    configSettings->Write("RestoreLastTab", g_restoreLastTab);
    configSettings->Write("LastOpenTab", g_lastOpenTab);


    configSettings->Write("RestoreWindowSize", g_restoreWindowSize);
    configSettings->Write("WindowWidth", g_windowWidth);
    configSettings->Write("WindowHeight", g_windowHeight);

    configSettings->Write("RestoreWindowPos", g_restoreWindowPos);
    configSettings->Write("WindowPosX", g_windowPosX);
    configSettings->Write("WindowPosY", g_windowPosY);

    configSettings->Write("SendDataAfterWindowClose", g_sendDataAfterWindowClose);

    configSettings->Write("aisMMSI", g_aisMMSI);

  }
}



/////////////////////////////
/// OCPN Automatic Update ///
/////////////////////////////
void NmeaGeneratorPlugin::SetCursorLatLon(double lat, double lon)
{
  m_cursor_lat = lat;
  m_cursor_lon = lon;
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
    return;

  //Create GUI first time
  if(myGUI == NULL)
  {
    myGUI = new DialogMainGui(parentWindow);
    myGUI->plugin = this;

    //Apply settings to UI
    if(g_restoreLastTab)
      myGUI->m_notebook->SetSelection(g_lastOpenTab);
    else
      myGUI->m_notebook->SetSelection(g_defaultNotebookPage);

    if(g_restoreWindowSize)
      myGUI->SetSize(g_windowWidth, g_windowHeight);
    if(g_restoreWindowPos)
      myGUI->Move(wxPoint(g_windowPosX, g_windowPosY));
  }

  //Toggle UI & toolbar icon state
  isToolbarActive = !isToolbarActive;
  SetToolbarItemState(id, isToolbarActive);
  if (isToolbarActive)
  {
    myGUI->Show();
    myGUI->Raise();
    myGUI->SetFocus();
    SetCanvasContextMenuItemViz(positionMenuID, true);
  }
  else
  {
    myGUI->Hide();

    if(!g_sendDataAfterWindowClose)
    {
      SetCanvasContextMenuItemViz(positionMenuID, false);
      myGUI->stopTimers();
    }
  }

  //Refresh screen
  RequestRefresh(parentWindow);
}

void NmeaGeneratorPlugin::OnContextMenuItemCallback(int id)
{
  if (myGUI == NULL)
    return;

  if(id == positionMenuID)
  {
    DialogMenuEntry dlg(GetOCPNCanvasWindow());

    if(dlg.ShowModal() == wxID_OK)
    {
      switch(dlg.m_updateVesselPositionChoice)
      {
        case 1:
          myGUI->updateSimStartPosition(VesselType::OwnShip, m_cursor_lat, m_cursor_lon);
          break;

        case 2:
          myGUI->updateSimStartPosition(VesselType::AisTarget, m_cursor_lat, m_cursor_lon);
          break;
      }
    }
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

  if(!g_sendDataAfterWindowClose)
    SetCanvasContextMenuItemViz(positionMenuID, false);

  //Refresh screen
  RequestRefresh(parentWindow);
}

void NmeaGeneratorPlugin::sendNmeaSentence(wxString sentence)
{
  PushNMEABuffer(sentence); //using old API
}
