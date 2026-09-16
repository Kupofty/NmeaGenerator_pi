#include "menuDialog_ui_derived.h"

DialogMenuEntry::DialogMenuEntry(wxWindow* parent): DialogMenuEntryBase(parent)
{

}


//Update position
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


//Add AIS targets
void DialogMenuEntry::OnButtonClick_AddClassA(wxCommandEvent& event)
{
  m_action = DialogAction::AddClassA;
  EndModal(wxID_OK);
}

void DialogMenuEntry::OnButtonClick_AddClassB(wxCommandEvent& event)
{
  m_action = DialogAction::AddClassB;
  EndModal(wxID_OK);
}

void DialogMenuEntry::OnButtonClick_AddARPA(wxCommandEvent& event)
{
  m_action = DialogAction::AddARPA;
  EndModal(wxID_OK);
}



//Remove AIS targets
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