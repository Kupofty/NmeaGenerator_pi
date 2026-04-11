#ifndef GLOBALS_H
#define GLOBALS_H

// wxWidgets Precompiled Headers
#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
#include "wx/wx.h"
#endif

// Globally accessible variables used by the plugin, dialogs etc.
extern wxBitmap g_pluginBitmap;

extern int g_defaultNotebookPage;

extern bool g_restoreLastTab;
extern int g_lastOpenTab;

extern bool g_restoreWindowSize;
extern int g_windowWidth;
extern int g_windowHeight;

extern bool g_restoreWindowPos;
extern int g_windowPosX;
extern int g_windowPosY;

#endif //GLOBALS_H
