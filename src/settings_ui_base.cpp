///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6-dirty)
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

	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel_display = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* sizerSettings;
	sizerSettings = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer_lastTab;
	bSizer_lastTab = new wxBoxSizer( wxHORIZONTAL );


	bSizer_lastTab->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText3 = new wxStaticText( m_panel_display, wxID_ANY, _("Default tab:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer_lastTab->Add( m_staticText3, 0, wxALIGN_CENTER|wxALL, 5 );

	wxString m_choice_notebookPageChoices[] = { _("Manual input"), _("Sentence builder"), _("Simulation") };
	int m_choice_notebookPageNChoices = sizeof( m_choice_notebookPageChoices ) / sizeof( wxString );
	m_choice_notebookPage = new wxChoice( m_panel_display, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_notebookPageNChoices, m_choice_notebookPageChoices, 0 );
	m_choice_notebookPage->SetSelection( 0 );
	bSizer_lastTab->Add( m_choice_notebookPage, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer_lastTab->Add( 0, 0, 1, wxEXPAND, 5 );


	sizerSettings->Add( bSizer_lastTab, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );


	bSizer7->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox_restoreLastTab = new wxCheckBox( m_panel_display, wxID_ANY, _("Restore last tab"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_restoreLastTab->SetValue(true);
	bSizer7->Add( m_checkBox_restoreLastTab, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer7->Add( 0, 0, 1, wxEXPAND, 5 );


	sizerSettings->Add( bSizer7, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );


	bSizer8->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox_restoreWindowPos = new wxCheckBox( m_panel_display, wxID_ANY, _("Restore last window position"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_restoreWindowPos->SetValue(true);
	bSizer8->Add( m_checkBox_restoreWindowPos, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer8->Add( 0, 0, 1, wxEXPAND, 5 );


	sizerSettings->Add( bSizer8, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );


	bSizer9->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox_restoreWindowSize = new wxCheckBox( m_panel_display, wxID_ANY, _("Restore last window size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_restoreWindowSize->SetValue(true);
	bSizer9->Add( m_checkBox_restoreWindowSize, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer9->Add( 0, 0, 1, wxEXPAND, 5 );


	sizerSettings->Add( bSizer9, 1, wxEXPAND, 5 );


	m_panel_display->SetSizer( sizerSettings );
	m_panel_display->Layout();
	sizerSettings->Fit( m_panel_display );
	m_notebook1->AddPage( m_panel_display, _("Display"), true );
	m_panel_options = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );


	bSizer12->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer( wxHORIZONTAL );


	bSizer91->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox_keepSendingData = new wxCheckBox( m_panel_options, wxID_ANY, _("Keep transmitting data\nwhen window is closed"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer91->Add( m_checkBox_keepSendingData, 0, wxALL, 5 );


	bSizer91->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer12->Add( bSizer91, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );


	bSizer10->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox_copyNmeaToClipboard = new wxCheckBox( m_panel_options, wxID_ANY, _("Copy NMEA sentence to \nclipboard on manual send"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_checkBox_copyNmeaToClipboard, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer10->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer12->Add( bSizer10, 1, wxEXPAND, 5 );


	bSizer12->Add( 0, 0, 1, wxEXPAND, 5 );


	m_panel_options->SetSizer( bSizer12 );
	m_panel_options->Layout();
	bSizer12->Fit( m_panel_options );
	m_notebook1->AddPage( m_panel_options, _("Options"), false );

	sizerDialog->Add( m_notebook1, 1, wxEXPAND, 5 );

	wxBoxSizer* sizerButtons;
	sizerButtons = new wxBoxSizer( wxHORIZONTAL );


	sizerButtons->Add( 0, 0, 1, wxEXPAND, 5 );

	buttonOK = new wxButton( this, wxID_ANY, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonOK, 0, wxALL, 5 );

	buttonApply = new wxButton( this, wxID_ANY, _("Apply"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerButtons->Add( buttonApply, 0, wxALL, 5 );


	sizerButtons->Add( 0, 0, 1, wxEXPAND, 5 );


	sizerDialog->Add( sizerButtons, 0, wxEXPAND, 5 );


	this->SetSizer( sizerDialog );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( DialogSettingsBase::OnInit ) );
	buttonOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettingsBase::OnOK ), NULL, this );
	buttonApply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettingsBase::OnApply ), NULL, this );
}

DialogSettingsBase::~DialogSettingsBase()
{
}
