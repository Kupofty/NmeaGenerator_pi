#include "menuDialog_ui_derived.h"

DialogMenuEntry::DialogMenuEntry(wxWindow* parent): DialogMenuEntryBase(parent)
{

}

void DialogMenuEntry::OnButtonClick_UpdateOwnShipPosition( wxCommandEvent& event )
{
  m_action = DialogAction::UpdateOwnShip;
  EndModal(wxID_OK);
}

void DialogMenuEntry::OnButtonClick_UpdateAisTargetPosition( wxCommandEvent& event )
{
  m_action = DialogAction::UpdateAisTarget;
  EndModal(wxID_OK);
}

void DialogMenuEntry::OnButtonClick_AddAisTarget(wxCommandEvent&)
{
  m_action = DialogAction::AddAisTarget;
  EndModal(wxID_OK);
}

void DialogMenuEntry::OnButtonClick_RemoveLastAisTargets( wxCommandEvent& event )
{
  m_action = DialogAction::RemoveLastAisTarget;
  EndModal(wxID_OK);
}

void DialogMenuEntry::OnButtonClick_ClearAisTargets(wxCommandEvent&)
{
  m_action = DialogAction::ClearAisTargets;
  EndModal(wxID_OK);
}