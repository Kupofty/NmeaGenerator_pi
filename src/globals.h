#ifndef GLOBALS_H
#define GLOBALS_H

// wxWidgets Precompiled Headers
#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
#include "wx/wx.h"
#endif

// Globally accessible variables used by the plugin, dialogs etc.
extern wxBitmap g_pluginBitmap;
extern bool g_someBooleanValue;
extern int g_someIntegerValue;
extern wxString g_someStringValue;

#endif //GLOBALS_H
