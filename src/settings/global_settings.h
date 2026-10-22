#ifndef GLOBAL_SETTINGS_H
#define GLOBAL_SETTINGS_H

// wxWidgets Precompiled Headers
#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
#include "wx/wx.h"
#endif

#include <vector>


/////////////////////////////////////////////////////////////////////
/// Globally accessible variables used by the plugin, dialogs etc ///
/////////////////////////////////////////////////////////////////////

extern int g_defaultNotebookPage;

extern bool g_restoreLastTab;
extern int g_lastOpenTab;

extern bool g_restoreWindowSize;
extern int g_windowWidth;
extern int g_windowHeight;

extern bool g_restoreWindowPos;
extern int g_windowPosX;
extern int g_windowPosY;

extern bool g_sendDataAfterWindowClose;

extern int g_aisMMSI;

extern bool g_simOutputGLL;
extern bool g_simOutputGGA;
extern bool g_simOutputRMC;

extern bool g_simOutputHDT;
extern bool g_simOutputHDM;
extern bool g_simOutputHDG;
extern bool g_simOutputTHS;

extern bool g_simOutputRSA;
extern bool g_simOutputROT;
extern bool g_simOutputVTG;
extern bool g_simOutputZDA;


//Manual input list (saved sentences of the manual input tab)
struct ManualInput
{
  wxString sentence;
  bool autoChecksum = false;
  bool autoSend = false;
};

extern std::vector<ManualInput> g_manualInputList;

#endif //GLOBAL_SETTINGS_H