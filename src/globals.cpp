#include "globals.h"

// Globally accessible variables used by the plugin, dialogs etc.

// Plugin icon
wxBitmap g_pluginBitmap;

//Notebook page to open by default
int g_defaultNotebookPage = 0;
bool g_restoreLastTab = 1;
int g_lastOpenTab = 0;

//Windows size & pos
bool g_restoreWindowSize = 1;
bool g_restoreWindowPos = 1;

int g_windowWidth = 0;
int g_windowHeight = 0;
int g_windowPosX = 0;
int g_windowPosY = 0;

