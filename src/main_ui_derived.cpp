#include "main_ui_derived.h"
#include "nmeagenerator_plugin.h"
#include "utils.h"

////////////////////////////
/// Class Initialization ///
////////////////////////////
DialogMainGui::DialogMainGui(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : MyDialog( parent )
{
  //Hide/show checkbox autoChecksum
  addAutoChecksum = m_checkBox_autoChecksum->GetValue();
  m_staticText_checksum->Show(addAutoChecksum);

  //Open first tab by default
  m_notebook->SetSelection(0);
}

DialogMainGui::~DialogMainGui()
{
  stopTimers();
}




//////////////
/// Others ///
//////////////
void DialogMainGui::OnClose(wxCloseEvent& event)
{
  if (plugin)
  {
    stopTimers();
    plugin->OnGuiClosed();
  }
}

void DialogMainGui::sendNmeaToOCPN(wxString sentence)
{
  //Securities
  if (sentence.IsEmpty())
    return;
  if (!sentence.StartsWith("$"))
    return;

  if (plugin){
    plugin->sendNmeaSentence(sentence);
  }
}

void DialogMainGui::stopTimers()
{
  m_timer_autoSendNmea.Stop();
  m_checkBox_automaticSend->SetValue(false);

  m_timer_autoSendBuilder.Stop();
  m_checkBox_automaticSendBuilder->SetValue(false);
}



////////////////////
/// Manual Input ///
////////////////////
void DialogMainGui::sendManualInput()
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

  //Send
  sendNmeaToOCPN(sentenceStr);
}

void DialogMainGui::OnButtonClick_manualSend(wxCommandEvent& event)
{
  sendManualInput();
}

void DialogMainGui::OnTimer_autoSendNmea(wxTimerEvent& event)
{
  sendManualInput();
}

void DialogMainGui::OnClearInput(wxCommandEvent& event)
{
  m_textCtrl_sentenceInput->Clear();
}

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
  unsigned char checksum = utils::calculateChecksum(payload);
  wxString checksumStr = utils::checksumToString(checksum);

  //Update checksum text
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



////////////////////////
/// Sentence Builder ///
////////////////////////
void DialogMainGui::OnButtonClick_CheckAllBuilder(wxCommandEvent& event)
{
  m_checkBox_autoSendGLL->SetValue(true);
}

void DialogMainGui::OnButtonClick_UncheckAllBuilder(wxCommandEvent& event)
{
  m_checkBox_autoSendGLL->SetValue(false);
}

//Auto-send timer
void DialogMainGui::OnCheckBox_AutomaticSendBuilder(wxCommandEvent& event)
{
  if (m_checkBox_automaticSendBuilder->GetValue())
  {
    double hz = m_spinCtrlDouble_autoSendFreqBuilder->GetValue();
    int intervalMs = static_cast<int>(1000.0 / hz);
    m_timer_autoSendBuilder.Start(intervalMs);
  }
  else
  {
    m_timer_autoSendBuilder.Stop();
  }
}

void DialogMainGui::OnSpinCtrlDouble_AutomaticSendFreqBuilder(wxSpinDoubleEvent& event)
{
  if (!m_checkBox_automaticSendBuilder->GetValue())
    return;
  double hz = m_spinCtrlDouble_autoSendFreqBuilder->GetValue();

  int intervalMs = static_cast<int>(1000.0 / hz);
  m_timer_autoSendBuilder.Start(intervalMs);
}

void DialogMainGui::OnTimer_autoSendBuilder(wxTimerEvent& event)
{
  if(m_checkBox_autoSendGLL->GetValue())
    sendGLL();
}

//Send buttons
void DialogMainGui::OnButtonClick_SendGLL(wxCommandEvent& event)
{
  sendGLL();
}

//NMEA sentences construction
void DialogMainGui::sendGLL()
{
  wxString payload;
  payload = m_textCtrl_idGLL->GetValue();
  payload += "GLL,";
  payload += m_textCtrl_latitudeGLL->GetValue() +",";
  payload += m_choice_latDirGLL->GetStringSelection() + ",";
  payload += m_textCtrl_longitudeGLL->GetValue() + ",";
  payload += m_choice_lonDirGLL->GetStringSelection() + ",";
  payload += m_textCtrl_timeGLL->GetValue() + ",";
  payload += m_choice_statusGLL->GetStringSelection() + ",";
  payload += m_choice_modeGLL->GetStringSelection();

  wxString checksum = utils::calculateChecksumString(payload);

  wxString sentence = "$" + payload + checksum;

  sendNmeaToOCPN(sentence);
}
