///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "menuDialog_ui_base.h"

///////////////////////////////////////////////////////////////////////////

DialogMenuEntryBase::DialogMenuEntryBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Update position") ), wxHORIZONTAL );

	m_button_updateOwnShipPosition = new wxButton( sbSizer1->GetStaticBox(), wxID_ANY, _("Own ship"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( m_button_updateOwnShipPosition, 1, wxALIGN_CENTER|wxALL, 5 );

	m_button_updateAisTargetPosition = new wxButton( sbSizer1->GetStaticBox(), wxID_ANY, _("AIS target"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( m_button_updateAisTargetPosition, 1, wxALIGN_CENTER|wxALL, 5 );


	bSizer1->Add( sbSizer1, 1, wxALL|wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("AIS targets") ), wxVERTICAL );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	m_button_addAisTarget = new wxButton( sbSizer2->GetStaticBox(), wxID_ANY, _("Add new"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button_addAisTarget, 1, wxALL, 5 );


	sbSizer2->Add( bSizer4, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	m_button_removeLastAisTarget = new wxButton( sbSizer2->GetStaticBox(), wxID_ANY, _("Remove last"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button_removeLastAisTarget, 1, wxALL, 5 );

	m_button_deleteAllAisTargets = new wxButton( sbSizer2->GetStaticBox(), wxID_ANY, _("Delete all"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button_deleteAllAisTargets, 1, wxALL, 5 );


	sbSizer2->Add( bSizer3, 1, wxEXPAND, 5 );


	bSizer1->Add( sbSizer2, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button_updateOwnShipPosition->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogMenuEntryBase::OnButtonClick_UpdateOwnShipPosition ), NULL, this );
	m_button_updateAisTargetPosition->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogMenuEntryBase::OnButtonClick_UpdateAisTargetPosition ), NULL, this );
	m_button_addAisTarget->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogMenuEntryBase::OnButtonClick_AddAisTarget ), NULL, this );
	m_button_removeLastAisTarget->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogMenuEntryBase::OnButtonClick_RemoveLastAisTargets ), NULL, this );
	m_button_deleteAllAisTargets->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogMenuEntryBase::OnButtonClick_ClearAisTargets ), NULL, this );
}

DialogMenuEntryBase::~DialogMenuEntryBase()
{
}
