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

//Keep streaming data when window is closed
bool g_sendDataAfterWindowClose = 0;

//Copy NMEA sentence to clipboard when clicking "Send"
bool g_copyNmeaToClipboard = 0;
