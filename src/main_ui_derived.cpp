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

  //Open first tab by default (can be different due to settings loaded)
  m_notebook->SetSelection(0);

  //List for search box
  sbSizerListSentenceBuilder = {
      {sbSizer_RMC->GetStaticBox()->GetLabel(), sbSizer_RMC},
      {sbSizer_GGA->GetStaticBox()->GetLabel(), sbSizer_GGA},
      {sbSizer_GLL->GetStaticBox()->GetLabel(), sbSizer_GLL},
      {sbSizer_HDT->GetStaticBox()->GetLabel(), sbSizer_HDT},
      {sbSizer_HDM->GetStaticBox()->GetLabel(), sbSizer_HDM},
      {sbSizer_MTW->GetStaticBox()->GetLabel(), sbSizer_MTW},
      {sbSizer_TLL->GetStaticBox()->GetLabel(), sbSizer_TLL},
      {sbSizer_ROT->GetStaticBox()->GetLabel(), sbSizer_ROT},
      {sbSizer_RSA->GetStaticBox()->GetLabel(), sbSizer_RSA}
  };

  //Timers list
  m_timers = {
      { &m_timer_autoSendNmea,    m_checkBox_automaticSend },
      { &m_timer_autoSendBuilder, m_checkBox_automaticSendBuilder }
  };
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
  for (auto& t : m_timers)
  {
    if (t.timer)
      t.timer->Stop();

    if (t.checkbox)
      t.checkbox->SetValue(false);
  }
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

//Search specific sentences
void DialogMainGui::OnText_SearchSentenceBuilder(wxCommandEvent& event)
{
  wxString filter = m_searchCtrl_sentencesBuilder->GetValue().Upper();
  bool showAll = filter.IsEmpty();

  for (auto& item : sbSizerListSentenceBuilder)
  {
    bool show = showAll ||
                item.name.Upper().StartsWith(filter);

    item.sizer->ShowItems(show);
  }

  bSizer_NmeaList->Layout();
  m_scrolledWindow_sentenceBuilder->FitInside();
}


//Help button
void DialogMainGui::OnButtonClick_OpenSentenceBuilderHelp(wxCommandEvent& event)
{
  wxDialog* dlg = new wxDialog(
      this,
      wxID_ANY,
      "NMEA Format Help (Units & Field Structure)",
      wxDefaultPosition,
      wxSize(400, 300),
      wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER
      );

  wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

  wxTextCtrl* text = new wxTextCtrl(
      dlg,
      wxID_ANY,
      "This help explains the expected NMEA units and formats required in this tool:\n\n"
      "UTC Time: hhmmss\n"
      "Latitude: ddmm.mmmm\n"
      "Longitude: dddmm.mmmm\n"
      "SOG: knots\n"
      "COG: degrees\n"
      "Date: ddmmyy\n"
      "Mag Var: degrees\n"
      "Heading: degrees\n"
      "ROT: degrees per minute",
      wxDefaultPosition,
      wxDefaultSize,
      wxTE_MULTILINE | wxTE_READONLY | wxTE_RICH2
      );

  sizer->Add(text, 1, wxEXPAND | wxALL, 10);

  dlg->SetSizer(sizer);
  dlg->Layout();
  dlg->Centre();

  dlg->ShowModal();
  dlg->Destroy();
}


//Autosend checkboxes
void DialogMainGui::OnButtonClick_CheckAllBuilder(wxCommandEvent& event)
{
  updateAutoSendBuildersCheckboxes(true);
}

void DialogMainGui::OnButtonClick_UncheckAllBuilder(wxCommandEvent& event)
{
  updateAutoSendBuildersCheckboxes(false);
}

void DialogMainGui::updateAutoSendBuildersCheckboxes(bool check)
{
  m_checkBox_autoSendGLL->SetValue(check);
  m_checkBox_autoSendRMC->SetValue(check);
  m_checkBox_autoSendGGA->SetValue(check);
  m_checkBox_autoSendHDT->SetValue(check);
  m_checkBox_autoSendHDM->SetValue(check);
  m_checkBox_autoSendMTW->SetValue(check);
  m_checkBox_autoSendTLL->SetValue(check);
  m_checkBox_autoSendROT->SetValue(check);
  m_checkBox_autoSendRSA->SetValue(check);
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
  //Only send sentence if auto-checkbox is checked
  if(m_checkBox_autoSendGLL->GetValue())
    sendGLL();
  if(m_checkBox_autoSendRMC->GetValue())
    sendRMC();
  if(m_checkBox_autoSendGGA->GetValue())
    sendGGA();
  if(m_checkBox_autoSendHDT->GetValue())
    sendHDT();
  if(m_checkBox_autoSendHDM->GetValue())
    sendHDM();
  if(m_checkBox_autoSendMTW->GetValue())
    sendMTW();
  if(m_checkBox_autoSendTLL->GetValue())
    sendTLL();
  if(m_checkBox_autoSendROT->GetValue())
    sendROT();
  if(m_checkBox_autoSendRSA->GetValue())
    sendRSA();
}


//Send buttons
void DialogMainGui::OnButtonClick_SendGLL(wxCommandEvent& event)
{
  sendGLL();
}

void DialogMainGui::OnButtonClick_SendRMC(wxCommandEvent& event)
{
  sendRMC();
}

void DialogMainGui::OnButtonClick_SendGGA(wxCommandEvent& event)
{
  sendGGA();
}

void DialogMainGui::OnButtonClick_SendHDT(wxCommandEvent& event)
{
  sendHDT();
}

void DialogMainGui::OnButtonClick_SendHDM(wxCommandEvent& event)
{
  sendHDM();
}

void DialogMainGui::OnButtonClick_SendMTW(wxCommandEvent& event)
{
  sendMTW();
}

void DialogMainGui::OnButtonClick_SendTLL(wxCommandEvent& event)
{
  sendTLL();
}

void DialogMainGui::OnButtonClick_SendROT(wxCommandEvent& event)
{
  sendROT();
}

void DialogMainGui::OnButtonClick_SendRSA(wxCommandEvent& event)
{
  sendRSA();
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

void DialogMainGui::sendRMC()
{
  wxString payload;
  payload = m_textCtrl_idRMC->GetValue();
  payload += "RMC,";
  payload += m_textCtrl_timeRMC->GetValue() + ",";
  payload += m_choice_statusRMC->GetStringSelection() + ",";
  payload += m_textCtrl_latitudeRMC->GetValue() + ",";
  payload += m_choice_latDirRMC->GetStringSelection() + ",";
  payload += m_textCtrl_longitudeRMC->GetValue() + ",";
  payload += m_choice_lonDirRMC->GetStringSelection() + ",";
  payload += wxString::Format("%.1f", m_spinCtrlDouble_sogRMC->GetValue()) + ",";
  payload += wxString::Format("%.1f", m_spinCtrlDouble_cogRMC->GetValue()) + ",";
  payload += m_textCtrl_dateRMC->GetValue() + ",";
  payload += wxString::Format("%.1f", m_spinCtrlDouble_magRMC->GetValue()) + ",";
  payload += m_choice_magDirRMC->GetStringSelection();


  wxString checksum = utils::calculateChecksumString(payload);

  wxString sentence = "$" + payload + checksum;

  sendNmeaToOCPN(sentence);
}

void DialogMainGui::sendGGA()
{
  wxString payload;
  payload = m_textCtrl_idGGA->GetValue();
  payload += "GGA,";
  payload += m_textCtrl_timeGGA->GetValue() + ",";
  payload += m_textCtrl_latitudeGGA->GetValue() + ",";
  payload += m_choice_latDirGGA->GetStringSelection() + ",";
  payload += m_textCtrl_longitudeGGA->GetValue() + ",";
  payload += m_choice_lonDirGGA->GetStringSelection() + ",";
  payload += wxString::Format("%d", m_spinCtrl_gpsQualityGGA->GetValue()) + ",";
  payload += wxString::Format("%d", m_spinCtrl_satellitesGGA->GetValue()) + ",";
  payload += wxString::Format("%.1f", m_spinCtrlDouble_hdopGGA->GetValue()) + ",";
  payload += wxString::Format("%.1f", m_spinCtrlDouble_altitude_GGA->GetValue()) + ",M,";
  payload += wxString::Format("%.1f", m_spinCtrlDouble_geoidSeparationGGA->GetValue()) + ",M,,";

  wxString checksum = utils::calculateChecksumString(payload);

  wxString sentence = "$" + payload + checksum;

  sendNmeaToOCPN(sentence);
}

void DialogMainGui::sendHDT()
{
  wxString payload;
  payload = m_textCtrl_idHDT->GetValue();
  payload += "HDT,";
  payload += wxString::Format("%.1f", m_spinCtrlDouble_headingHDT->GetValue()) + ",T";

  wxString checksum = utils::calculateChecksumString(payload);

  wxString sentence = "$" + payload + checksum;

  sendNmeaToOCPN(sentence);
}

void DialogMainGui::sendHDM()
{
  wxString payload;
  payload = m_textCtrl_idHDM->GetValue();
  payload += "HDM,";
  payload += wxString::Format("%.1f", m_spinCtrlDouble_headingHDM->GetValue()) + ",M";

  wxString checksum = utils::calculateChecksumString(payload);

  wxString sentence = "$" + payload + checksum;

  sendNmeaToOCPN(sentence);
}

void DialogMainGui::sendMTW()
{
  wxString payload;
  payload = m_textCtrl_idMTW->GetValue();
  payload += "MTW,";
  payload += wxString::Format("%.1f", m_spinCtrlDouble_tempMTW->GetValue()) + ",C";

  wxString checksum = utils::calculateChecksumString(payload);

  wxString sentence = "$" + payload + checksum;

  sendNmeaToOCPN(sentence);
}

void DialogMainGui::sendTLL()
{
  wxString payload;
  payload = m_textCtrl_idTLL->GetValue();
  payload += "TLL,";
  payload += wxString::Format("%.1f", m_spinCtrlDouble_numberTLL->GetValue()) + ",";
  payload += m_textCtrl_latitudeTLL->GetValue() + ",";
  payload += m_choice_latDirTLL->GetStringSelection() + ",";
  payload += m_textCtrl_longitudeTLL->GetValue() + ",";
  payload += m_choice_lonDirTLL->GetStringSelection() + ",";
  payload += m_textCtrl_nameTLL->GetValue() + ",";
  payload += m_textCtrl_timeTLL->GetValue() + ",";
  payload += m_choice_statusTLL->GetStringSelection() + ",R";

  wxString checksum = utils::calculateChecksumString(payload);

  wxString sentence = "$" + payload + checksum;

  sendNmeaToOCPN(sentence);
}

void DialogMainGui::sendROT()
{
  wxString payload;
  payload = m_textCtrl_idROT->GetValue();
  payload += "ROT,";
  payload += wxString::Format("%.1f", m_spinCtrlDouble_rateROT->GetValue()) + ",";
  payload += m_choice_statusROT->GetStringSelection();

  wxString checksum = utils::calculateChecksumString(payload);

  wxString sentence = "$" + payload + checksum;

  sendNmeaToOCPN(sentence);
}

void DialogMainGui::sendRSA()
{
  wxString payload;
  payload = m_textCtrl_idRSA->GetValue();
  payload += "RSA,";
  payload += wxString::Format("%.1f", m_spinCtrlDouble_starboardRSA->GetValue()) + ",";
  payload += m_choice_starboardStatusRSA->GetStringSelection();
  payload += wxString::Format("%.1f", m_spinCtrlDouble_portRSA->GetValue()) + ",";
  payload += m_choice_statusPortRSA->GetStringSelection();

  wxString checksum = utils::calculateChecksumString(payload);

  wxString sentence = "$" + payload + checksum;

  sendNmeaToOCPN(sentence);
}
