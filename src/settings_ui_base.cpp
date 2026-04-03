///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "settings_ui_base.h"

///////////////////////////////////////////////////////////////////////////

DialogSettingsBase::DialogSettingsBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* sizerDialog;
	sizerDialog = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* sizerSettings;
	sizerSettings = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3 = new wxStaticText( this, wxID_ANY, _("Always open GUI on tab:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer4->Add( m_staticText3, 0, wxALIGN_CENTER|wxALL, 5 );

	wxString m_choice_notebookPageChoices[] = { _("Manual input"), _("Sentence builder"), _("Simulation") };
	int m_choice_notebookPageNChoices = sizeof( m_choice_notebookPageChoices ) / sizeof( wxString );
	m_choice_notebookPage = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_notebookPageNChoices, m_choice_notebookPageChoices, 0 );
	m_choice_notebookPage->SetSelection( 0 );
	bSizer4->Add( m_choice_notebookPage, 0, wxALIGN_CENTER|wxALL, 5 );


	sizerSettings->Add( bSizer4, 1, wxEXPAND, 5 );


	sizerDialog->Add( sizerSettings, 1, wxEXPAND, 5 );

	wxBoxSizer* sizerButtons;
	sizerButtons = new wxBoxSizer( wxHORIZONTAL );


	sizerButtons->Add( 0, 0, 1, wxEXPAND, 5 );

	buttonOK = new wxButton( this, wxID_ANY, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonOK, 0, wxALL, 5 );

	buttonApply = new wxButton( this, wxID_ANY, _("Apply"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonApply, 0, wxALL, 5 );

	buttonCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonCancel, 0, wxALL, 5 );


	sizerDialog->Add( sizerButtons, 0, wxEXPAND, 5 );


	this->SetSizer( sizerDialog );
	this->Layout();
	sizerDialog->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( DialogSettingsBase::OnInit ) );
	buttonOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettingsBase::OnOK ), NULL, this );
	buttonApply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettingsBase::OnApply ), NULL, this );
	buttonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettingsBase::OnCancel ), NULL, this );
}

DialogSettingsBase::~DialogSettingsBase()
{
}
