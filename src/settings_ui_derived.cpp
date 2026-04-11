#include "settings_ui_derived.h"


////////////////////////////
/// Class Initialization ///
////////////////////////////
DialogSettings::DialogSettings(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : DialogSettingsBase(parent, id, title, pos, size, style)
{
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
