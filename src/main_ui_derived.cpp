#include "main_ui_derived.h"
#include "nmeagenerator_plugin.h"


////////////////////////////
/// Class Initialization ///
////////////////////////////
DialogMainGui::DialogMainGui(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : MyDialog( parent )
{
  //Add input
  AddNewManualLine();
}

DialogMainGui::~DialogMainGui()
{
  stopAutomaticSendTimers();
}



///////////////////////
/// Window wxEvents ///
///////////////////////
void DialogMainGui::OnClose(wxCloseEvent& event)
{
  if (plugin)
  {
    stopAutomaticSendTimers();
    plugin->OnGuiClosed();
  }
}



/////////////////////////
/// General functions ///
/////////////////////////
void DialogMainGui::sendNmea(wxString sentenceStr)
{
  //Securities
  if (sentenceStr.IsEmpty())
    return;
  if (!sentenceStr.StartsWith("$"))
    return;

  //Use nmeagenerator_plugin parent to send NMEA sentence
  if (plugin){
    plugin->sendNmeaSentence(sentenceStr);
  }
}

void DialogMainGui::stopAutomaticSendTimers()
{
  m_timer_autoSendNmea.Stop();
  m_checkBox_automaticSendManual->SetValue(false);
}



/////////////////////////////
/// Manual NMEA Sentences ///
/////////////////////////////
void DialogMainGui::AddNewManualLine()
{
  auto rowSizer = new wxBoxSizer(wxHORIZONTAL);

  // Checkbox
  auto cb = new wxCheckBox(this, wxID_ANY, "");
  cb->SetValue(true);
  rowSizer->Add(cb, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

  // "$"
  auto dollar = new wxStaticText(this, wxID_ANY, "$");
  rowSizer->Add(dollar, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

  // TextCtrl
  auto txt = new wxTextCtrl(this, wxID_ANY);
  rowSizer->Add(txt, 1, wxALL | wxEXPAND, 5);

  // Checksum label
  auto checksum = new wxStaticText(this, wxID_ANY, "*00");
  rowSizer->Add(checksum, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

  // Send button
  auto sendBtn = new wxButton(this, wxID_ANY, "Send", wxDefaultPosition, wxSize(50, -1));
  rowSizer->Add(sendBtn, 0, wxALL, 5);

  // Delete button
  auto delBtn = new wxButton(this, wxID_ANY, "X", wxDefaultPosition, wxSize(25, -1));
  rowSizer->Add(delBtn, 0, wxALL, 5);

  // Add to main container
  bSizer_inputList ->Add(rowSizer, 0, wxEXPAND);
  Layout();

  // Store in list
  ManualLine line{cb, txt, checksum, sendBtn, delBtn, rowSizer};
  m_lines.push_back(line);

  // Checksum update
  txt->Bind(wxEVT_TEXT, [checksum](wxCommandEvent& e)
            {
              wxString payload = e.GetString();

              std::string s = payload.ToStdString();
              unsigned char cs = 0;

              for (char c : s)
                cs ^= static_cast<unsigned char>(c);

              checksum->SetLabel(wxString::Format("*%02X", cs));
            });

  // Send logic
  sendBtn->Bind(wxEVT_BUTTON, [this, txt, checksum](wxCommandEvent&)
                {
                  wxString payload = txt->GetValue();
                  wxString sentence = "$" + payload + checksum->GetLabel();
                  sendNmea(sentence);
                });

  // Delete logic
  delBtn->Bind(wxEVT_BUTTON, [this, rowSizer](wxCommandEvent&)
               {
                 for (auto it = m_lines.begin(); it != m_lines.end(); ++it)
                 {
                   if (it->rowSizer == rowSizer)
                   {
                     bSizer_inputList ->Detach(rowSizer);
                     rowSizer->Clear(true); // destroy children
                     delete rowSizer;

                     m_lines.erase(it);
                     Layout();
                     break;
                   }
                 }

                 //Always show 1 input line
                 if (m_lines.empty())
                   AddNewManualLine();
               });
}

void DialogMainGui::OnTimer_AutoSendNmea(wxTimerEvent& event)
{
  for (auto& line : m_lines)
  {
    //Check if line is activated
    if (!line.checkBox->GetValue())
      continue;

    //Get payload
    wxString payload = line.textCtrl->GetValue();
    if (payload.IsEmpty())
      continue;

    //Add $ and checksum
    wxString sentence = "$" + payload + line.checksumLabel->GetLabel();

    //Send
    sendNmea(sentence);
  }
}

void DialogMainGui::OnCheckBox_AutomaticSendManual(wxCommandEvent& event)
{
  //Start/stop the timer
  if (m_checkBox_automaticSendManual->GetValue())
  {
    double hz = m_spinCtrlDouble_manualTimerFreq->GetValue();
    int intervalMs = static_cast<int>(1000.0 / hz);
    m_timer_autoSendNmea.Start(intervalMs);
  }
  else
  {
    m_timer_autoSendNmea.Stop();
  }
}

void DialogMainGui::OnSpinCtrlDouble_UpdateManualTimerFreq(wxSpinDoubleEvent& event)
{
  //Update timer period
  if (!m_checkBox_automaticSendManual->GetValue())
    return;
  double hz = m_spinCtrlDouble_manualTimerFreq->GetValue();

  int intervalMs = static_cast<int>(1000.0 / hz);
  m_timer_autoSendNmea.Start(intervalMs);
}

void DialogMainGui::OnButtonClick_AddNewInput(wxCommandEvent& event)
{
  AddNewManualLine();
}

void DialogMainGui::OnButtonClick_DeleteAllManualInputs(wxCommandEvent& event)
{
  //Warning msg box
  int res = wxMessageBox("Delete all inputs?", "Confirm",
                         wxYES_NO | wxICON_WARNING);
  if (res != wxYES)
    return;

  // Remove all rows from sizer and destroy them
  for (auto& line : m_lines)
  {
    if (line.rowSizer)
    {
      bSizer_inputList->Detach(line.rowSizer);
      line.rowSizer->Clear(true); // destroy all child controls
      delete line.rowSizer;
    }
  }

  // Clear container
  m_lines.clear();

  // Always keep one input
  AddNewManualLine();

  // Refresh layout
  Layout();
}
