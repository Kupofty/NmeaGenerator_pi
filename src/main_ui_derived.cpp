#include "utils.h"
#include <cmath>
#include <ctime>
#include <wx/hyperlink.h>
#include <wx/clipbrd.h>

#include "main_ui_derived.h"
#include "globals.h"
#include "nmeagenerator_plugin.h"



////////////////////////////
/// Class Initialization ///
////////////////////////////
DialogMainGui::DialogMainGui(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : MyDialog( parent )
{
  //Hide/show checkbox autoChecksum
  addAutoChecksum = m_checkBox_autoChecksum->GetValue();
  m_staticText_checksum->Show(addAutoChecksum);
  m_staticText_isChecksumCorrect->Show(!addAutoChecksum);

  //List for search box
  sbSizerListSentenceBuilder = {
      {sbSizer_RMC->GetStaticBox()->GetLabel(), sbSizer_RMC},
      {sbSizer_GGA->GetStaticBox()->GetLabel(), sbSizer_GGA},
      {sbSizer_GLL->GetStaticBox()->GetLabel(), sbSizer_GLL},
      {sbSizer_HDT->GetStaticBox()->GetLabel(), sbSizer_HDT},
      {sbSizer_HDM->GetStaticBox()->GetLabel(), sbSizer_HDM},
      {sbSizer_HDG->GetStaticBox()->GetLabel(), sbSizer_HDG},
      {sbSizer_MTW->GetStaticBox()->GetLabel(), sbSizer_MTW},
      {sbSizer_TLL->GetStaticBox()->GetLabel(), sbSizer_TLL},
      {sbSizer_ROT->GetStaticBox()->GetLabel(), sbSizer_ROT},
      {sbSizer_RSA->GetStaticBox()->GetLabel(), sbSizer_RSA},
      {sbSizer_DPT->GetStaticBox()->GetLabel(), sbSizer_DPT},
      {sbSizer_DBx->GetStaticBox()->GetLabel(), sbSizer_DBx},
      {sbSizer_THS->GetStaticBox()->GetLabel(), sbSizer_THS},
      {sbSizer_WPL->GetStaticBox()->GetLabel(), sbSizer_WPL},
      {sbSizer_VTG->GetStaticBox()->GetLabel(), sbSizer_VTG},
      {sbSizer_GSV->GetStaticBox()->GetLabel(), sbSizer_GSV},
      {sbSizer_XDR->GetStaticBox()->GetLabel(), sbSizer_XDR},
      {sbSizer_OSD->GetStaticBox()->GetLabel(), sbSizer_OSD},
      {sbSizer_MWV->GetStaticBox()->GetLabel(), sbSizer_MWV},
      {sbSizer_MWD->GetStaticBox()->GetLabel(), sbSizer_MWD},
      {sbSizer_VDR->GetStaticBox()->GetLabel(), sbSizer_VDR},
      {sbSizer_VHW->GetStaticBox()->GetLabel(), sbSizer_VHW},
      {sbSizer_VWR->GetStaticBox()->GetLabel(), sbSizer_VWR},
      {sbSizer_ZDA->GetStaticBox()->GetLabel(), sbSizer_ZDA},
      {sbSizer_VDM->GetStaticBox()->GetLabel(), sbSizer_VDM}
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
    if(!g_sendDataAfterWindowClose)
      stopTimers();

    plugin->OnGuiClosed();

  }
}

void DialogMainGui::sendNmeaToOCPN(wxString sentence)
{
  //Securities
  if (sentence.IsEmpty())
    return;
  if (!sentence.StartsWith("$") && !sentence.StartsWith("!"))
    return;

  if (plugin){
    plugin->sendNmeaSentence(sentence);
  }
}

void DialogMainGui::copyToClipboard(wxString text)
{
  if (!wxTheClipboard->Open())
    return;

  wxTheClipboard->SetData(new wxTextDataObject(text));
  wxTheClipboard->Close();
}

void DialogMainGui::stopTimers()
{
  m_timer_autoSendNmea.Stop();
  m_checkBox_automaticSend->SetValue(false);

  m_timer_autoSendBuilder.Stop();
  m_checkBox_automaticSendBuilder->SetValue(false);

  m_timer_autoSendSim.Stop();

  m_toggleBtn_startStopSim->SetValue(false);
  m_toggleBtn_startStopSim->SetLabel(_("START"));
}





////////////////////
/// Manual Input ///
////////////////////
void DialogMainGui::sendManualInput()
{
  wxString sentenceStr = m_textCtrl_sentenceInput->GetValue();

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
  wxString input = m_textCtrl_sentenceInput->GetValue().Trim().Trim(false);

  // AIS : no auto checksum
  if(input.StartsWith("!"))
  {
    m_checkBox_autoChecksum->SetValue(false);
    m_checkBox_autoChecksum->Enable(false);
    m_staticText_checksum->Hide();
    m_staticText_isChecksumCorrect->SetLabel("");
    addAutoChecksum = false;
    return;
  }

  // NMEA : autochecksumm mode allowed
  else if(input.StartsWith("$"))
  {
    addAutoChecksum = m_checkBox_autoChecksum->GetValue();
    m_staticText_checksum->Show(addAutoChecksum);
    m_checkBox_autoChecksum->Enable(true);
  }

  // Wrong prefix
  else
  {
    m_checkBox_autoChecksum->Enable(false);
    m_staticText_checksum->Hide();
    m_staticText_isChecksumCorrect->SetLabel("");
    return;
  }

  // Remove '$'
  wxString payload = input.Mid(1);

  // Locate '*'
  int asteriskPos = payload.Find('*');

  // Extract payload for computation
  wxString payloadForChecksum = (asteriskPos != wxNOT_FOUND) ? payload.Left(asteriskPos) : payload;

  // Compute checksum
  unsigned char checksum = utils::calculateChecksum(payloadForChecksum);
  wxString checksumStr = utils::checksumToString(checksum);

  m_staticText_checksum->SetLabel(checksumStr);

  // Manual checksum validation
  if(asteriskPos != wxNOT_FOUND && payload.Length() == static_cast<size_t>(asteriskPos + 3))
  {
    wxString userChecksum = "*" + payload.Mid(asteriskPos + 1, 2);

    if(userChecksum.CmpNoCase(checksumStr) == 0)
      m_staticText_isChecksumCorrect->SetLabel(_("Correct checksum"));
    else
      m_staticText_isChecksumCorrect->SetLabel(_("Incorrect checksum"));
  }
  else
  {
    m_staticText_isChecksumCorrect->SetLabel(_("No checksum detected"));
  }

}

void DialogMainGui::OnAutoChecksumChecked(wxCommandEvent& event)
{
  addAutoChecksum = m_checkBox_autoChecksum->GetValue();
  m_staticText_checksum->Show(addAutoChecksum);
  m_staticText_isChecksumCorrect->Show(!addAutoChecksum);
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

void DialogMainGui::OnButtonClick_copyManualSentence(wxCommandEvent& event)
{
  wxString text = m_textCtrl_sentenceInput->GetValue();
  copyToClipboard(text);
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
      _("NMEA Format Help"),
      wxDefaultPosition,
      wxSize(450, 220),
      wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER
      );

  wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

  wxStaticText* info = new wxStaticText(
      dlg,
      wxID_ANY,
      _("Refer to NMEA documentation for detailed information \n on sentence structure, fields, and units:")
      );

  sizer->AddStretchSpacer(1);
  sizer->Add(info, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 10);

  wxHyperlinkCtrl* link1 = new wxHyperlinkCtrl(
      dlg,
      wxID_ANY,
      _("OpenCPN NMEA Communication"),
      "https://opencpn.org/wiki/dokuwiki/doku.php?id=opencpn:manual_basic:nmea0183"
      );

  wxHyperlinkCtrl* link2 = new wxHyperlinkCtrl(
      dlg,
      wxID_ANY,
      _("NMEA Revealed"),
      "https://gpsd.gitlab.io/gpsd/NMEA.html"
      );

  wxHyperlinkCtrl* link3 = new wxHyperlinkCtrl(
      dlg,
      wxID_ANY,
      _("AIVDM/AIVDO protocol decoding"),
      "https://gpsd.gitlab.io/gpsd/AIVDM.html"
      );

  sizer->Add(link1, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 8);
  sizer->Add(link2, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 8);
  sizer->Add(link3, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 8);

  sizer->AddStretchSpacer(1);

  dlg->SetSizer(sizer);
  dlg->Layout();
  dlg->Centre();

  dlg->ShowModal();
  dlg->Destroy();
}

//Autosend checkboxes
void DialogMainGui::OnToggleButton_CheckAllBuilders(wxCommandEvent& event)
{
  bool checked = m_toggleBtn_checkAllBuilder->GetValue();

  updateAutoSendBuildersCheckboxes(checked);

  if (checked)
    m_toggleBtn_checkAllBuilder->SetLabel(_("Uncheck All"));
  else
    m_toggleBtn_checkAllBuilder->SetLabel(_("Check All"));
}

void DialogMainGui::updateAutoSendBuildersCheckboxes(bool check)
{
  m_checkBox_autoSendGLL->SetValue(check);
  m_checkBox_autoSendRMC->SetValue(check);
  m_checkBox_autoSendGGA->SetValue(check);
  m_checkBox_autoSendHDT->SetValue(check);
  m_checkBox_autoSendHDM->SetValue(check);
  m_checkBox_autoSendHDG->SetValue(check);
  m_checkBox_autoSendMTW->SetValue(check);
  m_checkBox_autoSendTLL->SetValue(check);
  m_checkBox_autoSendROT->SetValue(check);
  m_checkBox_autoSendRSA->SetValue(check);
  m_checkBox_autoSendDPT->SetValue(check);
  m_checkBox_autoSendDBx->SetValue(check);
  m_checkBox_autoSendTHS->SetValue(check);
  m_checkBox_autoSendWPL->SetValue(check);
  m_checkBox_autoSendVTG->SetValue(check);
  m_checkBox_autoSendGSV->SetValue(check);
  m_checkBox_autoSendXDR->SetValue(check);
  m_checkBox_autoSendOSD->SetValue(check);
  m_checkBox_autoSendMWV->SetValue(check);
  m_checkBox_autoSendMWD->SetValue(check);
  m_checkBox_autoSendVDR->SetValue(check);
  m_checkBox_autoSendVHW->SetValue(check);
  m_checkBox_autoSendVWR->SetValue(check);
  m_checkBox_autoSendZDA->SetValue(check);
  m_checkBox_autoSendVDM->SetValue(check);
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
    sendNmeaToOCPN(createFromGuiGLL());

  if(m_checkBox_autoSendRMC->GetValue())
    sendNmeaToOCPN(createFromGuiRMC());

  if(m_checkBox_autoSendGGA->GetValue())
    sendNmeaToOCPN(createFromGuiGGA());

  if(m_checkBox_autoSendHDT->GetValue())
    sendNmeaToOCPN(createFromGuiHDT());

  if(m_checkBox_autoSendHDM->GetValue())
    sendNmeaToOCPN(createFromGuiHDM());

  if(m_checkBox_autoSendHDG->GetValue())
    sendNmeaToOCPN(createFromGuiHDG());

  if(m_checkBox_autoSendMTW->GetValue())
    sendNmeaToOCPN(createFromGuiMTW());

  if(m_checkBox_autoSendTLL->GetValue())
    sendNmeaToOCPN(createFromGuiTLL());

  if(m_checkBox_autoSendROT->GetValue())
    sendNmeaToOCPN(createFromGuiROT());

  if(m_checkBox_autoSendRSA->GetValue())
    sendNmeaToOCPN(createFromGuiRSA());

  if(m_checkBox_autoSendDPT->GetValue())
    sendNmeaToOCPN(createFromGuiDPT());

  if(m_checkBox_autoSendDBx->GetValue())
    sendNmeaToOCPN(createFromGuiDBx());

  if(m_checkBox_autoSendTHS->GetValue())
    sendNmeaToOCPN(createFromGuiTHS());

  if(m_checkBox_autoSendWPL->GetValue())
    sendNmeaToOCPN(createFromGuiWPL());

  if(m_checkBox_autoSendVTG->GetValue())
    sendNmeaToOCPN(createFromGuiVTG());

  if(m_checkBox_autoSendGSV->GetValue())
    sendNmeaToOCPN(createFromGuiGSV());

  if(m_checkBox_autoSendXDR->GetValue())
    sendNmeaToOCPN(createFromGuiXDR());

  if(m_checkBox_autoSendOSD->GetValue())
    sendNmeaToOCPN(createFromGuiOSD());

  if(m_checkBox_autoSendMWV->GetValue())
    sendNmeaToOCPN(createFromGuiMWV());

  if(m_checkBox_autoSendMWD->GetValue())
    sendNmeaToOCPN(createFromGuiMWD());

  if(m_checkBox_autoSendVDR->GetValue())
    sendNmeaToOCPN(createFromGuiVDR());

  if(m_checkBox_autoSendVHW->GetValue())
    sendNmeaToOCPN(createFromGuiVHW());

  if(m_checkBox_autoSendVWR->GetValue())
    sendNmeaToOCPN(createFromGuiVWR());

  if(m_checkBox_autoSendZDA->GetValue())
    sendNmeaToOCPN(createFromGuiZDA());

  if(m_checkBox_autoSendVDM->GetValue())
    sendNmeaToOCPN(createFromGuiVDM());
}


//Update UI callbacks
void DialogMainGui::OnChoice_UpdateXDR(wxCommandEvent& event)
{
  int xdrChoice = m_choice_nameXDR->GetSelection();

  if(xdrChoice == 0) //Barometer
  {
    m_staticText_typeXDR->SetLabel("P");
    m_staticText_unitXDR->SetLabel("B");

    m_spinCtrlDouble_measureXDR->SetRange(0.85, 1.10);
    m_spinCtrlDouble_measureXDR->SetIncrement(0.01);
    m_spinCtrlDouble_measureXDR->SetValue(1.0);
    m_spinCtrlDouble_measureXDR->SetDigits(2);
  }
  else if(xdrChoice == 1) //TempAir
  {
    m_staticText_typeXDR->SetLabel("C");
    m_staticText_unitXDR->SetLabel("C");

    m_spinCtrlDouble_measureXDR->SetRange(-100,100);
    m_spinCtrlDouble_measureXDR->SetIncrement(5);
    m_spinCtrlDouble_measureXDR->SetValue(20);
    m_spinCtrlDouble_measureXDR->SetDigits(1);
  }
  else if(xdrChoice == 2) //TempWater
  {
    m_staticText_typeXDR->SetLabel("C");
    m_staticText_unitXDR->SetLabel("C");

    m_spinCtrlDouble_measureXDR->SetRange(0,100);
    m_spinCtrlDouble_measureXDR->SetIncrement(5);
    m_spinCtrlDouble_measureXDR->SetValue(10);
    m_spinCtrlDouble_measureXDR->SetDigits(1);
  }
  else if(xdrChoice == 3) //PITCH
  {
    m_staticText_typeXDR->SetLabel("A");
    m_staticText_unitXDR->SetLabel("D");

    m_spinCtrlDouble_measureXDR->SetRange(-180,180);
    m_spinCtrlDouble_measureXDR->SetIncrement(5);
    m_spinCtrlDouble_measureXDR->SetValue(0);
    m_spinCtrlDouble_measureXDR->SetDigits(1);
  }
  else if(xdrChoice == 4) //ROLL
  {
    m_staticText_typeXDR->SetLabel("A");
    m_staticText_unitXDR->SetLabel("D");

    m_spinCtrlDouble_measureXDR->SetRange(-180,180);
    m_spinCtrlDouble_measureXDR->SetIncrement(5);
    m_spinCtrlDouble_measureXDR->SetValue(0);
    m_spinCtrlDouble_measureXDR->SetDigits(1);
  }
}

void DialogMainGui::OnChoice_aisClassVDM(wxCommandEvent& event)
{
  int classChoice = m_choice_classVDM->GetSelection();
  int isClassA = (classChoice == 0);

  //Only enable following if ais is class A
  m_spinCtrl_statusVDM->Enable(isClassA);
  m_spinCtrl_rotVDM->Enable(isClassA);
  m_spinCtrl_maneuverVDM->Enable(isClassA);
}


//Send logic
void DialogMainGui::sendAndMaybeCopy(const wxString& msg)
{
  if(msg.IsEmpty())
    return;

  sendNmeaToOCPN(msg);

  //Copy to clipboard if setting is activated
  if(g_copyNmeaToClipboard)
    copyToClipboard(msg);
}


//Send buttons callbacks
void DialogMainGui::OnButtonClick_SendGLL(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiGLL());
}
void DialogMainGui::OnButtonClick_SendRMC(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiRMC());
}
void DialogMainGui::OnButtonClick_SendGGA(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiGGA());
}
void DialogMainGui::OnButtonClick_SendHDT(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiHDT());
}
void DialogMainGui::OnButtonClick_SendHDM(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiHDM());
}
void DialogMainGui::OnButtonClick_SendHDG(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiHDG());
}
void DialogMainGui::OnButtonClick_SendMTW(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiMTW());
}
void DialogMainGui::OnButtonClick_SendTLL(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiTLL());
}
void DialogMainGui::OnButtonClick_SendROT(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiROT());
}
void DialogMainGui::OnButtonClick_SendRSA(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiRSA());
}
void DialogMainGui::OnButtonClick_SendDPT(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiDPT());
}
void DialogMainGui::OnButtonClick_SendDBx(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiDBx());
}
void DialogMainGui::OnButtonClick_SendTHS(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiTHS());
}
void DialogMainGui::OnButtonClick_SendWPL(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiWPL());
}
void DialogMainGui::OnButtonClick_SendVTG(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiVTG());
}
void DialogMainGui::OnButtonClick_SendGSV(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiGSV());
}
void DialogMainGui::OnButtonClick_SendXDR(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiXDR());
}
void DialogMainGui::OnButtonClick_SendOSD(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiOSD());
}
void DialogMainGui::OnButtonClick_SendMWV(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiMWV());
}
void DialogMainGui::OnButtonClick_SendMWD(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiMWD());
}
void DialogMainGui::OnButtonClick_SendVDM(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiVDM());
}
void DialogMainGui::OnButtonClick_SendVDR(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiVDR());
}
void DialogMainGui::OnButtonClick_SendVHW(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiVHW());
}
void DialogMainGui::OnButtonClick_SendVWR(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiVWR());
}
void DialogMainGui::OnButtonClick_SendZDA(wxCommandEvent& event)
{
  sendAndMaybeCopy(createFromGuiZDA());
}


//Copy buttons callbacks
void DialogMainGui::OnButtonClick_CopyGLL(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiGLL());
}
void DialogMainGui::OnButtonClick_CopyRMC(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiRMC());
}
void DialogMainGui::OnButtonClick_CopyGGA(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiGGA());
}
void DialogMainGui::OnButtonClick_CopyHDT(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiHDT());
}
void DialogMainGui::OnButtonClick_CopyHDM(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiHDM());
}
void DialogMainGui::OnButtonClick_CopyHDG(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiHDG());
}
void DialogMainGui::OnButtonClick_CopyMTW(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiMTW());
}
void DialogMainGui::OnButtonClick_CopyTLL(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiTLL());
}
void DialogMainGui::OnButtonClick_CopyROT(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiROT());
}
void DialogMainGui::OnButtonClick_CopyRSA(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiRSA());
}
void DialogMainGui::OnButtonClick_CopyDPT(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiDPT());
}
void DialogMainGui::OnButtonClick_CopyDBx(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiDBx());
}
void DialogMainGui::OnButtonClick_CopyTHS(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiTHS());
}
void DialogMainGui::OnButtonClick_CopyWPL(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiWPL());
}
void DialogMainGui::OnButtonClick_CopyVTG(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiVTG());
}
void DialogMainGui::OnButtonClick_CopyGSV(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiGSV());
}
void DialogMainGui::OnButtonClick_CopyXDR(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiXDR());
}
void DialogMainGui::OnButtonClick_CopyOSD(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiOSD());
}
void DialogMainGui::OnButtonClick_CopyMWV(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiMWV());
}
void DialogMainGui::OnButtonClick_CopyMWD(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiMWD());
}
void DialogMainGui::OnButtonClick_CopyVDM(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiVDM());
}
void DialogMainGui::OnButtonClick_CopyVDR(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiVDR());
}
void DialogMainGui::OnButtonClick_CopyVHW(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiVHW());
}
void DialogMainGui::OnButtonClick_CopyVWR(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiVWR());
}
void DialogMainGui::OnButtonClick_CopyZDA(wxCommandEvent& event)
{
  copyToClipboard(createFromGuiZDA());
}


//Create nmea from SentenceBuilder tab
wxString DialogMainGui::createFromGuiGLL()
{
  wxString talker = m_textCtrl_talkerGLL->GetValue();
  wxString lat    = m_textCtrl_latitudeGLL->GetValue();
  wxString latDir = m_choice_latDirGLL->GetStringSelection();
  wxString lon    = m_textCtrl_longitudeGLL->GetValue();
  wxString lonDir = m_choice_lonDirGLL->GetStringSelection();
  wxString time   = m_textCtrl_timeGLL->GetValue();
  wxString status = m_choice_statusGLL->GetStringSelection();
  wxString mode   = m_choice_modeGLL->GetStringSelection();

  wxString gll = nmea::createGLL(talker, lat, latDir, lon, lonDir, time, status, mode);
  return gll;
}

wxString DialogMainGui::createFromGuiRMC()
{
  wxString talker    = m_textCtrl_talkerRMC->GetValue();
  wxString time      = m_textCtrl_timeRMC->GetValue();
  wxString status    = m_choice_statusRMC->GetStringSelection();
  wxString lat       = m_textCtrl_latitudeRMC->GetValue();
  wxString latDir    = m_choice_latDirRMC->GetStringSelection();
  wxString lon       = m_textCtrl_longitudeRMC->GetValue();
  wxString lonDir    = m_choice_lonDirRMC->GetStringSelection();
  wxString sog       = wxString::Format("%.1f", m_spinCtrlDouble_sogRMC->GetValue());
  wxString cog       = wxString::Format("%.1f", m_spinCtrlDouble_cogRMC->GetValue());
  wxString date      = m_textCtrl_dateRMC->GetValue();
  wxString magVar    = wxString::Format("%.1f",  m_spinCtrlDouble_magRMC->GetValue());
  wxString magVarDir = m_choice_magDirRMC->GetStringSelection();

  wxString rmc  = nmea::createRMC(talker, time, status, lat, latDir, lon, lonDir, sog, cog, date, magVar, magVarDir);
  return rmc;
}

wxString DialogMainGui::createFromGuiGGA()
{
  wxString talker   = m_textCtrl_talkerGGA->GetValue();
  wxString time     = m_textCtrl_timeGGA->GetValue();
  wxString lat      = m_textCtrl_latitudeGGA->GetValue();
  wxString latDir   = m_choice_latDirGGA->GetStringSelection();
  wxString lon      = m_textCtrl_longitudeGGA->GetValue();
  wxString lonDir   = m_choice_lonDirGGA->GetStringSelection();
  wxString gpsFix   = wxString::Format("%d", m_spinCtrl_gpsQualityGGA->GetValue());
  wxString sats     = wxString::Format("%d", m_spinCtrl_satellitesGGA->GetValue());
  wxString hdop     = wxString::Format("%.1f", m_spinCtrlDouble_hdopGGA->GetValue());
  wxString altitude = wxString::Format("%.1f", m_spinCtrlDouble_altitudeGGA->GetValue());
  wxString geoid    = wxString::Format("%.1f", m_spinCtrlDouble_geoidSeparationGGA->GetValue());

  wxString gga  = nmea::createGGA(talker, time, lat, latDir, lon, lonDir, gpsFix, sats, hdop, altitude, geoid);
  return gga;
}

wxString DialogMainGui::createFromGuiHDT()
{
  wxString talker  = m_textCtrl_talkerHDT->GetValue();
  wxString heading = wxString::Format("%.1f", m_spinCtrlDouble_headingHDT->GetValue());

  wxString hdt  = nmea::createHDT(talker, heading);
  return hdt;
}

wxString DialogMainGui::createFromGuiHDM()
{
  wxString talker  = m_textCtrl_talkerHDM->GetValue();
  wxString heading = wxString::Format("%.1f", m_spinCtrlDouble_headingHDM->GetValue());

  wxString hdm  = nmea::createHDM(talker, heading);
  return hdm;
}

wxString DialogMainGui::createFromGuiHDG()
{
  wxString talker       = m_textCtrl_talkerHDG->GetValue();
  wxString heading      = wxString::Format("%.1f", m_spinCtrlDouble_headingHDG->GetValue());
  wxString deviation    = wxString::Format("%.1f", m_spinCtrlDouble_deviationHDG->GetValue());
  wxString deviationDir = m_choice_deviationDirHDG->GetStringSelection();
  wxString variation    = wxString::Format("%.1f", m_spinCtrlDouble_variationHDG->GetValue());
  wxString variationDir = m_choice_variationDirHDG->GetStringSelection();

  wxString hdg  = nmea::createHDG(talker, heading, deviation, deviationDir, variation, variationDir);
  return hdg;
}

wxString DialogMainGui::createFromGuiMTW()
{
  wxString talker = m_textCtrl_talkerMTW->GetValue();
  wxString temp   = wxString::Format("%.1f", m_spinCtrlDouble_tempMTW->GetValue());

  wxString mtw  = nmea::createMTW(talker, temp);
  return mtw;
}

wxString DialogMainGui::createFromGuiTLL()
{
  wxString talker   = m_textCtrl_talkerTLL->GetValue();
  wxString targetID = wxString::Format("%d", m_spinCtrl_idTLL->GetValue());
  wxString lat      = m_textCtrl_latitudeTLL->GetValue();
  wxString latDir   = m_choice_latDirTLL->GetStringSelection();
  wxString lon      = m_textCtrl_longitudeTLL->GetValue();
  wxString lonDir   = m_choice_lonDirTLL->GetStringSelection();
  wxString name     = m_textCtrl_nameTLL->GetValue();
  wxString time     = m_textCtrl_timeTLL->GetValue();
  wxString status   = m_choice_statusTLL->GetStringSelection();
  wxString ref      = "R";

  wxString tll  = nmea::createTLL(talker, targetID, lat, latDir, lon, lonDir, name, time, status, ref);
  return tll;
}

wxString DialogMainGui::createFromGuiROT()
{
  wxString talker = m_textCtrl_talkerROT->GetValue();
  wxString rate   = wxString::Format("%.1f", m_spinCtrlDouble_rateROT->GetValue());
  wxString status = m_choice_statusROT->GetStringSelection();

  wxString rot  = nmea::createROT(talker, rate, status);
  return rot;
}

wxString DialogMainGui::createFromGuiRSA()
{
  wxString talker     = m_textCtrl_talkerRSA->GetValue();
  wxString stbdAngle  = wxString::Format("%.1f", m_spinCtrlDouble_starboardRSA->GetValue());
  wxString stbdStatus = m_choice_starboardStatusRSA->GetStringSelection();
  wxString portAngle  = wxString::Format("%.1f", m_spinCtrlDouble_portRSA->GetValue());
  wxString portStatus = m_choice_statusPortRSA->GetStringSelection();

  wxString rsa  = nmea::createRSA(talker, stbdAngle, stbdStatus, portAngle, portStatus);
  return rsa;
}

wxString DialogMainGui::createFromGuiDPT()
{
  wxString talker = m_textCtrl_talkerDPT->GetValue();
  wxString depth  = wxString::Format("%.1f", m_spinCtrlDouble_depthDPT->GetValue());
  wxString offset = wxString::Format("%.1f", m_spinCtrlDouble_offsetDPT->GetValue());

  wxString dpt  = nmea::createDPT(talker, depth, offset);
  return dpt;
}

wxString DialogMainGui::createFromGuiDBx()
{
  wxString talker      = m_textCtrl_talkerDBx->GetValue();
  wxString type        = m_choice_sentenceDBx->GetStringSelection(); //can be DBT, DBS, DBK
  wxString depthFeet   = wxString::Format("%.1f", m_spinCtrlDouble_depthFeetDBx->GetValue());
  wxString depthMeter  = wxString::Format("%.1f", m_spinCtrlDouble_depthMeterDBx->GetValue());
  wxString depthFathom = wxString::Format("%.1f", m_spinCtrlDouble_depthFathomDBx->GetValue());

  wxString dbx  = nmea::createDBx(talker, type, depthFeet, depthMeter, depthFathom);
  return dbx;
}

wxString DialogMainGui::createFromGuiTHS()
{
  wxString talker  = m_textCtrl_talkerTHS->GetValue();
  wxString heading = wxString::Format("%.1f", m_spinCtrlDouble_headingTHS->GetValue());
  wxString mode    = m_choice_modeTHS->GetStringSelection();

  wxString ths  = nmea::createTHS(talker, heading, mode);
  return ths;
}

wxString DialogMainGui::createFromGuiWPL()
{
  wxString talker = m_textCtrl_talkerWPL->GetValue();
  wxString lat    = m_textCtrl_latitudeWPL->GetValue();
  wxString latDir = m_choice_latDirWPL->GetStringSelection();
  wxString lon    = m_textCtrl_longitudeWPL->GetValue();
  wxString lonDir = m_choice_lonDirWPL->GetStringSelection();
  wxString wpName = m_textCtrl_nameWPL->GetValue();

  wxString wpl  = nmea::createWPL(talker, lat, latDir, lon, lonDir, wpName);
  return wpl;
}

wxString DialogMainGui::createFromGuiVTG()
{
  wxString talker  = m_textCtrl_talkerVTG->GetValue();
  wxString cogTrue = wxString::Format("%.1f", m_spinCtrlDouble_cogTrueVTG->GetValue());
  wxString cogMag  = wxString::Format("%.1f", m_spinCtrlDouble_cogMagVTG->GetValue());
  wxString sogKnot = wxString::Format("%.1f", m_spinCtrlDouble_sogKnotVTG->GetValue());
  wxString sogKph  = wxString::Format("%.1f", m_spinCtrlDouble_sogKphVTG->GetValue());
  wxString mode    = m_choice_modeVTG->GetStringSelection();

  wxString vtg  = nmea::createVTG(talker, cogTrue, cogMag, sogKnot, sogKph, mode);
  return vtg;
}

wxString DialogMainGui::createFromGuiGSV()
{
  wxString talker          = m_textCtrl_talkerGSV->GetValue();
  wxString totalSentences  = wxString::Format("%d", m_spinCtrl_totalSentencesGSV->GetValue());
  wxString sentenceNumber  = wxString::Format("%d", m_spinCtrl_sentenceIdGSV->GetValue());
  wxString totalSatellites = wxString::Format("%d", m_spinCtrl_satellitesGSV->GetValue());
  wxString PRN             = wxString::Format("%d", m_spinCtrl_prnGSV->GetValue());
  wxString elevation       = wxString::Format("%d", m_spinCtrl_elevationGSV->GetValue());
  wxString azimuth         = wxString::Format("%d", m_spinCtrl_azimuthGSV->GetValue());
  wxString SNR             = wxString::Format("%d", m_spinCtrl_snrGSV->GetValue());

  wxString gsv  = nmea::createGSV(talker, totalSentences, sentenceNumber, totalSatellites, PRN, elevation, azimuth, SNR);
  return gsv;
}

wxString DialogMainGui::createFromGuiXDR()
{
  wxString talker      = m_textCtrl_talkerXDR->GetValue();
  wxString type        = m_staticText_typeXDR->GetLabel();
  wxString measurement = wxString::Format("%.2f", m_spinCtrlDouble_measureXDR->GetValue());
  wxString unit        = m_staticText_unitXDR->GetLabel();
  wxString name;

  int xdrChoice = m_choice_nameXDR->GetSelection();
  switch (xdrChoice)
  {
    case 0:
      name = "Baro";
      break;

    case 1:
      name = "Air";
      break;

    case 2:
      name = "Water";
      break;

    case 3:
      name = "Pitch";
      break;

    case 4:
      name = "Roll";
      break;
  }

  wxString xdr  = nmea::createXDR(talker, type, measurement, unit, name);
  return xdr;
}

wxString DialogMainGui::createFromGuiOSD()
{
  wxString talker     = m_textCtrl_talkerOSD->GetValue();
  wxString heading    = wxString::Format("%.1f", m_spinCtrlDouble_headingOSD->GetValue());
  wxString status     = m_choice_statusOSD->GetStringSelection();
  wxString course     = wxString::Format("%.1f", m_spinCtrlDouble_courseOSD->GetValue());
  wxString courseRef  = m_choice_courseRefOSD->GetStringSelection();
  wxString speed      = wxString::Format("%.1f", m_spinCtrlDouble_speedOSD->GetValue());
  wxString speedRef   = m_choice_speedRefOSD->GetStringSelection();
  wxString driftAngle = wxString::Format("%.1f", m_spinCtrlDouble_driftAngleOSD->GetValue());
  wxString driftSpeed = wxString::Format("%.1f", m_spinCtrlDouble_driftSpeedOSD->GetValue());
  wxString speedUnit  = m_choice_speedUnitOSD->GetStringSelection();

  wxString osd  = nmea::createOSD(talker, heading, status, course, courseRef, speed, speedRef, driftAngle, driftSpeed, speedUnit);
  return osd;
}

wxString DialogMainGui::createFromGuiMWV()
{
  wxString talker = m_textCtrl_talkerMWV->GetValue();
  wxString angle  = wxString::Format("%.1f", m_spinCtrlDouble_angleMWV->GetValue());
  wxString ref    = m_choice_refMWV->GetStringSelection();
  wxString speed  = wxString::Format("%.1f", m_spinCtrlDouble_speedMWV->GetValue());
  wxString unit   = m_choice_unitMWV->GetStringSelection();
  wxString status = m_choice_statusMWV->GetStringSelection();

  wxString mwv  = nmea::createMWV(talker, angle, ref, speed, unit, status);
  return mwv;
}

wxString DialogMainGui::createFromGuiMWD()
{
  wxString talker = m_textCtrl_talkerMWD->GetValue();
  wxString dir1   = wxString::Format("%.1f", m_spinCtrlDouble_windDirection1MWD->GetValue());
  wxString dir2   = wxString::Format("%.1f", m_spinCtrlDouble_windDirection2MWD->GetValue());
  wxString speed1 = wxString::Format("%.1f", m_spinCtrlDouble_speed1MWD->GetValue());
  wxString speed2 = wxString::Format("%.1f", m_spinCtrlDouble_speed2MWD->GetValue());

  wxString mwd  = nmea::createMWD(talker, dir1, dir2, speed1, speed2);
  return mwd;
}

wxString DialogMainGui::createFromGuiVDM()
{
  wxString talker = m_textCtrl_talkerVDM->GetValue();
  wxString id = m_choice_idVDM->GetStringSelection();

  int mmsi = g_aisMMSI;
  int mmsiSelection = m_comboBox_mmsiVDM->GetSelection();
  if (mmsiSelection != wxNOT_FOUND)
  {
    switch (mmsiSelection)
    {
      case 0: mmsi = g_aisMMSI; break; //Custom
      case 1: mmsi = 227000000; break; //French ship
      case 2: mmsi = 970000000; break; //SART
      case 3: mmsi = 972000000; break; //MOB
      case 4: mmsi = 974000000; break; //EPIRB
      case 5: mmsi = 111227000; break; //SAR aircraft
      default: break;
    }
  }
  else
  {
    // User typed value
    wxString text = m_comboBox_mmsiVDM->GetValue();

    // Validate: only digits
    if (!text.IsEmpty() && text.IsNumber())
    {
      long value;
      text.ToLong(&value);
      mmsi = static_cast<int>(value);
    }
  }

  int status       = m_spinCtrl_statusVDM->GetValue();     //class A only
  int rot          = m_spinCtrl_rotVDM->GetValue();        //class A only
  double speed     = m_spinCtrlDouble_sogVDM->GetValue();
  double lat       = m_spinCtrlDouble_latVDM->GetValue();
  double lon       = m_spinCtrlDouble_lonVDM->GetValue();
  double cog       = m_spinCtrlDouble_cogVDM->GetValue();
  double heading   = m_spinCtrlDouble_headingVDM->GetValue();
  int maneuver     = m_spinCtrl_maneuverVDM->GetValue();   //class A only
  wxString channel = m_choice_channelVDM->GetStringSelection();

  wxString vdm;
  int classType = m_choice_classVDM->GetSelection();

  //Class A
  if(classType == 0)
    vdm  = ais::encodeType1_2_3(talker, id, mmsi, status, rot, speed, lat, lon, cog, heading, maneuver, channel);
  //Class B
  else if(classType == 1)
    vdm  = ais::encodeType18(talker, id, mmsi, speed, lat, lon, cog, heading, channel);

  return vdm;
}

wxString DialogMainGui::createFromGuiVDR()
{
  wxString talker       = m_textCtrl_talkerVDR->GetValue();
  wxString dirTrue      = wxString::Format("%.1f", m_spinCtrlDouble_directionTrueVDR->GetValue());
  wxString dirMag       = wxString::Format("%.1f", m_spinCtrlDouble_directionMagVDR->GetValue());
  wxString currentSpeed = wxString::Format("%.1f", m_spinCtrlDouble_currentSpeedVDR->GetValue());

  wxString vdr  = nmea::createVDR(talker, dirTrue, dirMag, currentSpeed);
  return vdr;
}

wxString DialogMainGui::createFromGuiVHW()
{
  wxString talker      = m_textCtrl_talkerVHW->GetValue();
  wxString headingTrue = wxString::Format("%.1f", m_spinCtrlDouble_headingTrueVHW->GetValue());
  wxString headingMag  = wxString::Format("%.1f", m_spinCtrlDouble_headingMagVHW->GetValue());
  wxString stwKnot     = wxString::Format("%.1f", m_spinCtrlDouble_stwKnotVHW->GetValue());
  wxString stwKph      = wxString::Format("%.1f", m_spinCtrlDouble_stwKphVHW->GetValue());

  wxString vhw  = nmea::createVHW(talker, headingTrue, headingMag, stwKnot, stwKph);
  return vhw;
}

wxString DialogMainGui::createFromGuiVWR()
{
  wxString talker    = m_textCtrl_talkerVWR->GetValue();
  wxString angle     = wxString::Format("%.1f", m_spinCtrlDouble_angleVWR->GetValue());
  wxString direction = m_choice_dirVWR->GetStringSelection();
  wxString speedKnot = wxString::Format("%.1f", m_spinCtrlDouble_speedKnotVWR->GetValue());
  wxString speedMps  = wxString::Format("%.1f", m_spinCtrlDouble_speedMpsVWR->GetValue());
  wxString speedKph  = wxString::Format("%.1f", m_spinCtrlDouble_speedKphVWR->GetValue());

  wxString vwr  = nmea::createVWR(talker, angle, direction, speedKnot, speedMps, speedKph);
  return vwr;
}

wxString DialogMainGui::createFromGuiZDA()
{
  wxString talker       = m_textCtrl_talkerZDA->GetValue();
  wxString time         = m_textCtrl_timeZDA->GetValue();
  wxString day          = wxString::Format("%d", m_spinCtrl_dayZDA->GetValue());
  wxString month        = wxString::Format("%d", m_spinCtrl_monthZDA->GetValue());
  wxString year         = wxString::Format("%d", m_spinCtrl_yearZDA->GetValue());
  wxString hourOffset   = wxString::Format("%d", m_spinCtrl_hourOffsetZDA->GetValue());
  wxString minuteOffset = wxString::Format("%d", m_spinCtrl_minuteOffsetZDA->GetValue());

  wxString zda  = nmea::createZDA(talker, time, day, month, year, hourOffset, minuteOffset);
  return zda;
}




//////////////////
/// Simulation ///
//////////////////

//Update controlled vessel type
SimVessel* DialogMainGui::getControlledVessel()
{
  if (controlledVessel == VesselType::OwnShip)
    return &shipSimu;
  else
    return &aisSimu;
}

void DialogMainGui::OnChoice_controlledVesselSimChanged(wxCommandEvent& event)
{
  //Get selection from GUI
  int sel = m_choice_controlledVessel->GetSelection();
  if (sel == 0)
    controlledVessel = VesselType::OwnShip;
  else
    controlledVessel = VesselType::AisTarget;

  //Update UI to match the controlled vessel current status
  SimVessel* vessel = getControlledVessel();

  wxScrollEvent updateGUI;
  m_slider_throttleSim->SetValue(vessel->throttle);
  OnScroll_UpdateThrottleSim(updateGUI);

  m_slider_rudderSim->SetValue(vessel->rudderAngle);
  OnScroll_UpdateRudderAngleSim(updateGUI);

  m_staticText_headingSim->SetLabel(wxString::Format("%.0f", vessel->heading));
  m_staticText_cogSim->SetLabel(wxString::Format("%.0f", vessel->cog ));

  DegMin dm = utils::toDegMin(vessel->lat, vessel->lon);
  m_staticText_latDegSim->SetLabel(wxString::Format("%d", dm.latDeg));
  m_staticText_latMinSim->SetLabel(wxString::Format("%.4f", dm.latMin));
  m_staticText_lonDegSim->SetLabel(wxString::Format("%d", dm.lonDeg));
  m_staticText_lonMinSim->SetLabel(wxString::Format("%.4f", dm.lonMin));
}

//Update ship position to cursor position
void DialogMainGui::updateSimStartPosition(double lat, double lon)
{
  SimVessel* vessel = getControlledVessel();
  vessel->lat = lat;
  vessel->lon = lon;

  // Extract degrees & minutes
  DegMin dm = utils::toDegMin(vessel->lat, vessel->lon);

  // Update UI
  m_spinCtrl_latDegSim->SetValue(dm.latDeg);
  m_spinCtrlDouble_latMinutesSim->SetValue(dm.latMin);
  m_spinCtrl_lonDegSim->SetValue(dm.lonDeg);
  m_spinCtrlDouble_lonMinutesSim->SetValue(dm.lonMin);

  m_choice_latDirSim->SetStringSelection(lat < 0 ? "S" : "N");
  m_choice_lonDirSim->SetStringSelection(lon < 0 ? "W" : "E");
}

void DialogMainGui::OnTimer_autoSendSim(wxTimerEvent& event)
{
  // ---- Time ----
  double dt = m_timer_autoSendSim.GetInterval() / 1000.0;
  std::time_t now = std::time(nullptr);
  std::tm utc = *std::gmtime(&now);

  wxString timeStr = wxString::Format("%02d%02d%02d", utc.tm_hour, utc.tm_min, utc.tm_sec);
  wxString dateStr = wxString::Format("%02d%02d%02d", utc.tm_mday, utc.tm_mon + 1, utc.tm_year % 100);


  // ---- Output mode ----
  int outputMode = m_choice_nmeaOutputSim->GetSelection();
  bool sendOwnShip = (outputMode == 1) || (controlledVessel == VesselType::OwnShip);
  bool sendAisTarget = (outputMode == 1) || (controlledVessel == VesselType::AisTarget);


  // ---- Update & send OwnShip NMEA ----
  if (sendOwnShip)
  {
    GeoPos pos = utils::updatePosition(
        shipSimu.lat, shipSimu.lon,
        shipSimu.speed, shipSimu.heading,
        m_timer_autoSendSim.GetInterval()
        );

    shipSimu.lat = pos.lat;
    shipSimu.lon = pos.lon;

    shipSimu.heading = fmod( shipSimu.heading + (shipSimu.rudderAngle * shipSimu.directionSign) * dt, 360.0 );

    if (shipSimu.heading < 0)
      shipSimu.heading += 360.0;

    wxString latDir = utils::getLatDir(shipSimu.lat);
    wxString lonDir = utils::getLonDir(shipSimu.lon);
    wxString latStr = utils::toNMEA_lat(fabs(shipSimu.lat));
    wxString lonStr = utils::toNMEA_lon(fabs(shipSimu.lon));

    double cog = shipSimu.heading;
    if (shipSimu.directionSign < 0)
      cog = fmod(shipSimu.heading + 180.0, 360.0);

    wxString speedStr = wxString::Format("%.1f", fabs(shipSimu.speed));
    wxString headingStr = wxString::Format("%.1f", shipSimu.heading);
    wxString cogStr = wxString::Format("%.1f", cog);
    wxString rudderStr = wxString::Format("%.1f", shipSimu.rudderAngle);

    sendNmeaToOCPN(nmea::createRMC("GP", timeStr, "A", latStr, latDir, lonStr, lonDir, speedStr, cogStr, dateStr, "0", "E"));
    sendNmeaToOCPN(nmea::createHDT("II", headingStr));
    sendNmeaToOCPN(nmea::createRSA("II", rudderStr, "A", "0", "V"));
  }


  // ---- Update & send AIS target NMEA ----
  if (sendAisTarget)
  {
    GeoPos pos = utils::updatePosition(
        aisSimu.lat, aisSimu.lon,
        aisSimu.speed, aisSimu.heading,
        m_timer_autoSendSim.GetInterval()
        );

    aisSimu.lat = pos.lat;
    aisSimu.lon = pos.lon;

    aisSimu.heading = fmod( aisSimu.heading + (aisSimu.rudderAngle * aisSimu.directionSign) * dt, 360.0 );

    if (aisSimu.heading < 0)
      aisSimu.heading += 360.0;

    wxString latDir = utils::getLatDir(aisSimu.lat);
    wxString lonDir = utils::getLonDir(aisSimu.lon);
    wxString latStr = utils::toNMEA_lat(fabs(aisSimu.lat));
    wxString lonStr = utils::toNMEA_lon(fabs(aisSimu.lon));

    wxString aisNmea;
    int aisType = m_choice_aisType->GetSelection();
    switch(aisType)
    {
      //TLL : ARPA
      case 0:
        aisNmea = nmea::createTLL("II", "99", latStr, latDir, lonStr, lonDir, "DUMMY", timeStr, "T", "R");
        break;

      //VDM : Class A (type 1)
      case 1:
        aisNmea = ais::encodeType1_2_3("AI", "VDM", g_aisMMSI, 0, aisSimu.rudderAngle, fabs(aisSimu.speed), aisSimu.lat, aisSimu.lon, aisSimu.cog, aisSimu.heading, 0, "A");
        break;

      //VDM : Class B (type 18)
      case 2:
        aisNmea = ais::encodeType18("AI", "VDM", g_aisMMSI, fabs(aisSimu.speed), aisSimu.lat, aisSimu.lon, aisSimu.cog, aisSimu.heading, "A");
        break;
    }

    sendNmeaToOCPN(aisNmea);
  }


  // ---- Update UI for controlled vessel ----
  SimVessel* vessel = getControlledVessel();

  vessel->cog = vessel->heading;
  if (vessel->directionSign < 0)
    vessel->cog  = fmod(vessel->heading + 180.0, 360.0);
  m_staticText_headingSim->SetLabel(wxString::Format("%.0f", vessel->heading));
  m_staticText_cogSim->SetLabel(wxString::Format("%.0f", vessel->cog ));

  DegMin dm = utils::toDegMin(vessel->lat, vessel->lon);
  m_staticText_latDegSim->SetLabel(wxString::Format("%d", dm.latDeg));
  m_staticText_latMinSim->SetLabel(wxString::Format("%.4f", dm.latMin));
  m_staticText_lonDegSim->SetLabel(wxString::Format("%d", dm.lonDeg));
  m_staticText_lonMinSim->SetLabel(wxString::Format("%.4f", dm.lonMin));
}

// Start/stop timer
void DialogMainGui::OnToggleButton_StartStopSim(wxCommandEvent& event)
{
  bool isPressed = event.IsChecked();

  if (isPressed)
  {
    int timeInterval = m_spinCtrlDouble_simFreqTimer->GetValue() * 1000; //milliseconds
    m_timer_autoSendSim.Start(timeInterval);
    m_toggleBtn_startStopSim->SetLabel(_("STOP"));
  }
  else
  {
    m_timer_autoSendSim.Stop();
    m_toggleBtn_startStopSim->SetLabel(_("START"));
  }
}

void DialogMainGui::OnSpinCtrlDouble_UpdateFreqTimerSim(wxSpinDoubleEvent& event)
{
  if(m_toggleBtn_startStopSim->GetValue()) //if timer is running
  {
    int timeInterval = m_spinCtrlDouble_simFreqTimer->GetValue() * 1000; //milliseconds
    m_timer_autoSendSim.Start(timeInterval);
  }
}

//Update values from GUI
void DialogMainGui::OnButtonClick_UpdateSimPos(wxCommandEvent& event)
{
  int latDeg = m_spinCtrl_latDegSim->GetValue();
  double latMinutes = m_spinCtrlDouble_latMinutesSim->GetValue();
  wxString latDirStr = m_choice_latDirSim->GetStringSelection();

  int lonDeg = m_spinCtrl_lonDegSim->GetValue();
  double lonMinutes = m_spinCtrlDouble_lonMinutesSim->GetValue();
  wxString lonDirStr = m_choice_lonDirSim->GetStringSelection();

  // Build NMEA format
  double latNmea = latDeg * 100.0 + latMinutes;   // DDMM.MMM
  double lonNmea = lonDeg * 100.0 + lonMinutes;   // DDDMM.MMM

  // Convert to decimal degrees
  double lat = utils::NMEA_to_decimal(latNmea);
  double lon = utils::NMEA_to_decimal(lonNmea);

  // Apply direction
  if(latDirStr == "S")
    lat = -lat;

  if(lonDirStr == "W")
    lon = -lon;

  SimVessel* vessel = getControlledVessel();
  vessel->lat = lat;
  vessel->lon = lon;
}

void DialogMainGui::OnScroll_UpdateThrottleSim(wxScrollEvent& event)
{
  double throttle = m_slider_throttleSim->GetValue();

  SimVessel* vessel = getControlledVessel();
  vessel->throttle = throttle;
  vessel->speed = throttle;
  vessel->directionSign = (throttle >= 0) ? 1 : -1; //heading is decremented when boat is going reverse

  wxString throttleStr = wxString::Format("%.0f", vessel->speed);
  m_staticText_throttleSim->SetLabel(throttleStr);
  wxString speedStr = wxString::Format("%.0f", fabs(vessel->speed));
  m_staticText_speedSim->SetLabel(speedStr);
}

void DialogMainGui::OnScroll_UpdateRudderAngleSim(wxScrollEvent& event)
{
  SimVessel* vessel = getControlledVessel();
  vessel->rudderAngle = m_slider_rudderSim->GetValue();

  wxString rudderStr = wxString::Format("%.0f", vessel->rudderAngle);
  m_staticText_rudderAngleSim->SetLabel(rudderStr);
}

void DialogMainGui::OnButtonClick_ResetRudder(wxCommandEvent& event)
{
  SimVessel* vessel = getControlledVessel();
  vessel->rudderAngle = 0;

  m_slider_rudderSim->SetValue(0);
  m_staticText_rudderAngleSim->SetLabel("0");
}

void DialogMainGui::OnButtonClick_ResetThrottle(wxCommandEvent& event)
{
  SimVessel* vessel = getControlledVessel();
  vessel->throttle = 0;
  vessel->speed = 0;

  m_slider_throttleSim->SetValue(0);
  m_staticText_throttleSim->SetLabel("0");
  m_staticText_speedSim->SetLabel("0");
}
