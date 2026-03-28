#include "settings_ui_derived.h"

// Constructor and destructor implementation
DialogSettings::DialogSettings(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : DialogSettingsBase(parent, id, title, pos, size, style)
{
}

DialogSettings::~DialogSettings()
{
}

void DialogSettings::OnInit(wxInitDialogEvent& event)
{
  // Save the original settings in case user changes values, hits apply, but then cancels...
  originalBooleanValue = g_someBooleanValue;
  originalIntegerValue = g_someIntegerValue;
  originalStringValue = g_someStringValue;

  checkBoxBoolean->SetValue(g_someBooleanValue);
  sliderInteger->SetValue(g_someIntegerValue);
  textString->SetValue(g_someStringValue);

  Layout();
  Fit();
}

void DialogSettings::OnOK(wxCommandEvent& event)
{
  g_someBooleanValue = checkBoxBoolean->IsChecked();
  g_someIntegerValue = sliderInteger->GetValue();
  g_someStringValue = textString->GetValue();
  EndModal(wxID_OK);
}

void DialogSettings::OnCancel(wxCommandEvent& event)
{
  // Restore the original settings
  g_someBooleanValue = originalBooleanValue;
  g_someIntegerValue = originalIntegerValue;
  g_someStringValue = originalStringValue;
  EndModal(wxID_CANCEL);
}

void DialogSettings::OnApply(wxCommandEvent& event)
{
  g_someBooleanValue = checkBoxBoolean->IsChecked();
  g_someIntegerValue = sliderInteger->GetValue();
  g_someStringValue = textString->GetValue();
}
