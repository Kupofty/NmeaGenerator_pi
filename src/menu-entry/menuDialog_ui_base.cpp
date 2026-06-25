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

	m_button_updateOwnShipPosition = new wxButton( this, wxID_ANY, _("Own ship"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_button_updateOwnShipPosition, 1, wxALIGN_CENTER|wxALL, 5 );

	m_button_updateAisTargetPosition = new wxButton( this, wxID_ANY, _("AIS target"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_button_updateAisTargetPosition, 1, wxALIGN_CENTER|wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button_updateOwnShipPosition->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogMenuEntryBase::OnButtonClick_UpdateOwnShipPosition ), NULL, this );
	m_button_updateAisTargetPosition->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogMenuEntryBase::OnButtonClick_UpdateAisTargetPosition ), NULL, this );
}

DialogMenuEntryBase::~DialogMenuEntryBase()
{
}
