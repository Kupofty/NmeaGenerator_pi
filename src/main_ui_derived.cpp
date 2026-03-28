#include "main_ui_derived.h"
#include "nmeagenerator_plugin.h"

DialogMainGui::DialogMainGui(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : MyDialog( parent )
{

}

DialogMainGui::~DialogMainGui()
{

}

void DialogMainGui::OnClose(wxCloseEvent& event)
{
  if (plugin)
    plugin->OnGuiClosed();
}
