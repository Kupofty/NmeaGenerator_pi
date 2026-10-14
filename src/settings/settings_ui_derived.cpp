#include "settings_ui_derived.h"


////////////////////////////
/// Class Initialization ///
////////////////////////////
DialogSettings::DialogSettings(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : DialogSettingsBase(parent, id, title, pos, size, style)
{
  m_notebook1->SetSelection(0);
}

DialogSettings::~DialogSettings()
{
}

void DialogSettings::OnInit(wxInitDialogEvent& event)
{
  //Update UI
  m_choice_notebookPage->SetSelection(g_defaultNotebookPage);
  m_checkBox_restoreLastTab->SetValue(g_restoreLastTab);
  m_checkBox_restoreWindowPos->SetValue(g_restoreWindowPos);
  m_checkBox_restoreWindowSize->SetValue(g_restoreWindowSize);
  m_checkBox_keepSendingData->SetValue(g_sendDataAfterWindowClose);
  m_spinCtrl_mmsi->SetValue(g_aisMMSI);

  m_checkBox_simGLL->SetValue(g_simOutputGLL);
  m_checkBox_simGGA->SetValue(g_simOutputGGA);
  m_checkBox_simRMC->SetValue(g_simOutputRMC);
  m_checkBox_simHDT->SetValue(g_simOutputHDT);
  m_checkBox_simHDM->SetValue(g_simOutputHDM);
  m_checkBox_simHDG->SetValue(g_simOutputHDG);
  m_checkBox_simTHS->SetValue(g_simOutputTHS);
  m_checkBox_simRSA->SetValue(g_simOutputRSA);
  m_checkBox_simROT->SetValue(g_simOutputROT);
  m_checkBox_simVTG->SetValue(g_simOutputVTG);
  m_checkBox_simZDA->SetValue(g_simOutputZDA);

  Layout();
  Fit();
}



//////////////
/// Others ///
//////////////
void DialogSettings::updateSettings()
{
  g_defaultNotebookPage = m_choice_notebookPage->GetSelection();
  g_restoreLastTab = m_checkBox_restoreLastTab->IsChecked();
  g_restoreWindowPos = m_checkBox_restoreWindowPos->IsChecked();
  g_restoreWindowSize = m_checkBox_restoreWindowSize->IsChecked();
  g_sendDataAfterWindowClose = m_checkBox_keepSendingData->IsChecked();
  g_aisMMSI = m_spinCtrl_mmsi->GetValue();

  g_simOutputGLL = m_checkBox_simGLL->IsChecked();
  g_simOutputGGA = m_checkBox_simGGA->IsChecked();
  g_simOutputRMC = m_checkBox_simRMC->IsChecked();
  g_simOutputHDT = m_checkBox_simHDT->IsChecked();
  g_simOutputHDM = m_checkBox_simHDM->IsChecked();
  g_simOutputHDG = m_checkBox_simHDG->IsChecked();
  g_simOutputTHS = m_checkBox_simTHS->IsChecked();
  g_simOutputRSA = m_checkBox_simRSA->IsChecked();
  g_simOutputROT = m_checkBox_simROT->IsChecked();
  g_simOutputVTG = m_checkBox_simVTG->IsChecked();
  g_simOutputZDA = m_checkBox_simZDA->IsChecked();

  // Warn if no position output is selected
  if (!g_simOutputRMC && !g_simOutputGGA && !g_simOutputGLL)
  {
    wxString message = _("No position output is selected.") + "\n" +
                       _("Enable at least one: RMC, GGA, or GLL.");

    wxMessageBox(
        message,
        _("Position Output Warning"),
        wxOK | wxICON_WARNING, this);

    g_simOutputGLL = 1;
    m_checkBox_simGLL->SetValue(1);

  }
}



////////////////////
/// wxGUI Events ///
////////////////////
void DialogSettings::OnOK(wxCommandEvent& event)
{
  updateSettings();
  EndModal(wxID_OK);
}

void DialogSettings::OnApply(wxCommandEvent& event)
{
  updateSettings();
}
