#include "global_settings.h"


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

//AIS
int g_aisMMSI = 227000000;

//Simulation outputs
bool g_simOutputGLL = 1;
bool g_simOutputGGA = 0;
bool g_simOutputRMC = 0;

bool g_simOutputHDT = 1;
bool g_simOutputHDM = 0;
bool g_simOutputHDG = 0;
bool g_simOutputTHS = 0;

bool g_simOutputRSA = 1;
bool g_simOutputROT = 0;
bool g_simOutputVTG = 0;
bool g_simOutputZDA = 0;

//Manual input list
std::vector<ManualInput> g_manualInputList;