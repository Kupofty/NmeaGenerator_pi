#include "main_ui_derived.h"
#include "nmeagenerator_plugin.h"


////////////////////////////
/// Class Initialization ///
////////////////////////////
DialogMainGui::DialogMainGui(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : MyDialog( parent )
{

}

DialogMainGui::~DialogMainGui()
{

}



////////////////////
/// wxGUI Events ///
////////////////////
void DialogMainGui::OnClose(wxCloseEvent& event)
{
  if (plugin)
    plugin->OnGuiClosed();
}

void DialogMainGui::OnSendSentence(wxCommandEvent& event)
{
  wxString sentence = m_textCtrl_sentenceInput->GetValue();
  if (sentence.IsEmpty())
    return;

  if (plugin)
    plugin->sendNmeaSentence(sentence);
}

void DialogMainGui::OnClearInput(wxCommandEvent& event)
{
  m_textCtrl_sentenceInput->Clear();
}
