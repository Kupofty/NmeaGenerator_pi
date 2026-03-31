#include "main_ui_derived.h"
#include "nmeagenerator_plugin.h"


////////////////////////////
/// Class Initialization ///
////////////////////////////
DialogMainGui::DialogMainGui(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : MyDialog( parent )
{
  addAutoChecksum = m_checkBox_autoChecksum->GetValue();
  m_staticText_checksum->Show(addAutoChecksum);
}

DialogMainGui::~DialogMainGui()
{
  stopTimer();
}




//////////////
/// Others ///
//////////////
void DialogMainGui::sendNmea()
{
  wxString sentenceStr = m_textCtrl_sentenceInput->GetValue();

  //Securities
  if (sentenceStr.IsEmpty())
    return;
  if (!sentenceStr.StartsWith("$"))
    return;

  // Add checksum to string
  if(addAutoChecksum)
  {
    wxString checksumStr = m_staticText_checksum->GetLabel();
    sentenceStr += checksumStr;
  }

  if (plugin){
    plugin->sendNmeaSentence(sentenceStr);
  }
}

void DialogMainGui::stopTimer()
{
  m_timer_autoSendNmea.Stop();
  m_checkBox_automaticSend->SetValue(false);
}



//////////////////////////////
/// wxGUI Events - Actions ///
//////////////////////////////
void DialogMainGui::OnClose(wxCloseEvent& event)
{
  if (plugin)
  {
    stopTimer();
    plugin->OnGuiClosed();
  }
}

void DialogMainGui::OnButtonClick_manualSend(wxCommandEvent& event)
{
  sendNmea();
}

void DialogMainGui::OnTimer_autoSendNmea(wxTimerEvent& event)
{
  sendNmea();
}

void DialogMainGui::OnClearInput(wxCommandEvent& event)
{
  m_textCtrl_sentenceInput->Clear();
}



/////////////////////////////
/// wxGUI Events - Update ///
/////////////////////////////
void DialogMainGui::OnInputTextChanged(wxCommandEvent& event)
{
  wxString input = m_textCtrl_sentenceInput->GetValue();

  if (!input.StartsWith("$"))
  {
    m_staticText_checksum->SetLabel("*00");
    return;
  }

  //Remove $ to calculate checksum
  wxString payload = input.Mid(1);

  //Calculate checksum
  unsigned char checksum = 0;
  for (size_t i = 0; i < payload.length(); ++i)
  {
    checksum ^= static_cast<unsigned char>(payload[i]);
  }

  //Update checksum text
  wxString checksumStr;
  checksumStr.Printf("*%02X", checksum);
  m_staticText_checksum->SetLabel(checksumStr);
}

void DialogMainGui::OnAutoChecksumChecked(wxCommandEvent& event)
{
  addAutoChecksum = m_checkBox_autoChecksum->GetValue();
  m_staticText_checksum->Show(addAutoChecksum);
}

void DialogMainGui::OnCheckBox_AutomaticSend(wxCommandEvent& event)
{
  //Start/stop the timer
  if (m_checkBox_automaticSend->GetValue())
  {
    double hz = m_spinCtrlDouble_automaticSendFreq->GetValue();
    int intervalMs = static_cast<int>(1000.0 / hz);
    m_timer_autoSendNmea.Start(intervalMs);
  }
  else
  {
    m_timer_autoSendNmea.Stop();
  }
}

void DialogMainGui::OnSpinCtrlDouble_AutomaticSendFreq(wxSpinDoubleEvent& event)
{
  //Update timer period
  if (!m_checkBox_automaticSend->GetValue())
    return;
  double hz = m_spinCtrlDouble_automaticSendFreq->GetValue();

  int intervalMs = static_cast<int>(1000.0 / hz);
  m_timer_autoSendNmea.Start(intervalMs);
}
