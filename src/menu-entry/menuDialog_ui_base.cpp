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


	sbSizer1->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_updateOwnShipPosition = new wxButton( sbSizer1->GetStaticBox(), wxID_ANY, _("Own ship"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( m_button_updateOwnShipPosition, 1, wxALIGN_CENTER|wxALL, 5 );


	sbSizer1->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_updateAisTargetPosition = new wxButton( sbSizer1->GetStaticBox(), wxID_ANY, _("AIS target"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( m_button_updateAisTargetPosition, 1, wxALIGN_CENTER|wxALL, 5 );


	sbSizer1->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer1->Add( sbSizer1, 1, wxALL|wxEXPAND, 5 );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("AIS targets - Add new...") ), wxHORIZONTAL );


	sbSizer3->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_addClassA = new wxButton( sbSizer3->GetStaticBox(), wxID_ANY, _("ClassA"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer3->Add( m_button_addClassA, 0, wxALL, 5 );


	sbSizer3->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_addClassB = new wxButton( sbSizer3->GetStaticBox(), wxID_ANY, _("ClassB"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer3->Add( m_button_addClassB, 0, wxALL, 5 );


	sbSizer3->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_addARPA = new wxButton( sbSizer3->GetStaticBox(), wxID_ANY, _("ARPA"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer3->Add( m_button_addARPA, 0, wxALL, 5 );


	sbSizer3->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer1->Add( sbSizer3, 1, wxALL|wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("AIS targets - Delete...") ), wxHORIZONTAL );


	sbSizer4->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_removeLastAisTarget = new wxButton( sbSizer4->GetStaticBox(), wxID_ANY, _("Last"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( m_button_removeLastAisTarget, 1, wxALL, 5 );


	sbSizer4->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_deleteAllAisTargets = new wxButton( sbSizer4->GetStaticBox(), wxID_ANY, _("All"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( m_button_deleteAllAisTargets, 1, wxALL, 5 );


	sbSizer4->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer1->Add( sbSizer4, 1, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button_updateOwnShipPosition->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogMenuEntryBase::OnButtonClick_UpdateOwnShipPosition ), NULL, this );
	m_button_updateAisTargetPosition->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogMenuEntryBase::OnButtonClick_UpdateAisTargetPosition ), NULL, this );
	m_button_addClassA->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogMenuEntryBase::OnButtonClick_AddClassA ), NULL, this );
	m_button_addClassB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogMenuEntryBase::OnButtonClick_AddClassB ), NULL, this );
	m_button_addARPA->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogMenuEntryBase::OnButtonClick_AddARPA ), NULL, this );
	m_button_removeLastAisTarget->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogMenuEntryBase::OnButtonClick_RemoveLastAisTargets ), NULL, this );
	m_button_deleteAllAisTargets->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogMenuEntryBase::OnButtonClick_ClearAisTargets ), NULL, this );
}

DialogMenuEntryBase::~DialogMenuEntryBase()
{
}
