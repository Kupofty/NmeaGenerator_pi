#include "menuDialog_ui_derived.h"

DialogMenuEntry::DialogMenuEntry(wxWindow* parent): DialogMenuEntryBase(parent)
{

}

void DialogMenuEntry::OnButtonClick_UpdateOwnShipPosition( wxCommandEvent& event )
{
  m_updateVesselPositionChoice = 1;
  EndModal(wxID_OK);
}

void DialogMenuEntry::OnButtonClick_UpdateAisTargetPosition( wxCommandEvent& event )
{
  m_updateVesselPositionChoice = 2;
  EndModal(wxID_OK);
}