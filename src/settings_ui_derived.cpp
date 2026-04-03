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
  // Save the original settings in case user changes values, hits apply, but then cancels...
  originalNotebookPage = g_notebookPage;

  //Update UI
  m_choice_notebookPage->SetSelection(g_notebookPage);

  Layout();
  Fit();
}



//////////////
/// Others ///
//////////////
void DialogSettings::updateSettings()
{
  g_notebookPage = m_choice_notebookPage->GetSelection();
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

void DialogSettings::OnCancel(wxCommandEvent& event)
{
  // Restore the original settings
  g_notebookPage = originalNotebookPage;
  EndModal(wxID_CANCEL);
}

