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

	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
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


	bSizer12->Add( 0, 0, 1, wxEXPAND, 5 );


	m_panel_options->SetSizer( bSizer12 );
	m_panel_options->Layout();
	bSizer12->Fit( m_panel_options );
	m_notebook1->AddPage( m_panel_options, _("Options"), false );
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
	m_notebook1->AddPage( m_panel_display, _("Display"), false );
	m_panel_simulation = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer122;
	bSizer122 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer_simPos;
	bSizer_simPos = new wxBoxSizer( wxHORIZONTAL );

	m_staticText31 = new wxStaticText( m_panel_simulation, wxID_ANY, _("Position:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer_simPos->Add( m_staticText31, 0, wxALIGN_CENTER|wxALL, 5 );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );


	bSizer16->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox_simGLL = new wxCheckBox( m_panel_simulation, wxID_ANY, _("GLL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_simGLL->SetValue(true);
	bSizer16->Add( m_checkBox_simGLL, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer16->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox_simGGA = new wxCheckBox( m_panel_simulation, wxID_ANY, _("GGA"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_checkBox_simGGA, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer16->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox_simRMC = new wxCheckBox( m_panel_simulation, wxID_ANY, _("RMC"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_checkBox_simRMC, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer16->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer_simPos->Add( bSizer16, 1, wxEXPAND, 5 );


	bSizer122->Add( bSizer_simPos, 1, wxEXPAND, 5 );

	m_staticline1 = new wxStaticLine( m_panel_simulation, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer122->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer_simHead;
	bSizer_simHead = new wxBoxSizer( wxHORIZONTAL );

	m_staticText4 = new wxStaticText( m_panel_simulation, wxID_ANY, _("Heading:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer_simHead->Add( m_staticText4, 0, wxALIGN_CENTER|wxALL, 5 );

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );


	bSizer17->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox_simHDT = new wxCheckBox( m_panel_simulation, wxID_ANY, _("HDT"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_simHDT->SetValue(true);
	bSizer17->Add( m_checkBox_simHDT, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer17->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox_simHDM = new wxCheckBox( m_panel_simulation, wxID_ANY, _("HDM"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_checkBox_simHDM, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer17->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox_simHDG = new wxCheckBox( m_panel_simulation, wxID_ANY, _("HDG"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_checkBox_simHDG, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer17->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox_simTHS = new wxCheckBox( m_panel_simulation, wxID_ANY, _("THS"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_checkBox_simTHS, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer17->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer_simHead->Add( bSizer17, 1, wxEXPAND, 5 );


	bSizer122->Add( bSizer_simHead, 1, wxEXPAND, 5 );

	m_staticline2 = new wxStaticLine( m_panel_simulation, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer122->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer_simOthers;
	bSizer_simOthers = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5 = new wxStaticText( m_panel_simulation, wxID_ANY, _("Others:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer_simOthers->Add( m_staticText5, 0, wxALIGN_CENTER|wxALL, 5 );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );


	bSizer18->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox_simRSA = new wxCheckBox( m_panel_simulation, wxID_ANY, _("RSA"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_simRSA->SetValue(true);
	bSizer18->Add( m_checkBox_simRSA, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer18->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox_simROT = new wxCheckBox( m_panel_simulation, wxID_ANY, _("ROT"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_checkBox_simROT, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer18->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox_simVTG = new wxCheckBox( m_panel_simulation, wxID_ANY, _("VTG"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_checkBox_simVTG, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer18->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox_simZDA = new wxCheckBox( m_panel_simulation, wxID_ANY, _("ZDA"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_checkBox_simZDA, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer18->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer_simOthers->Add( bSizer18, 1, wxEXPAND, 5 );


	bSizer122->Add( bSizer_simOthers, 1, wxEXPAND, 5 );


	m_panel_simulation->SetSizer( bSizer122 );
	m_panel_simulation->Layout();
	bSizer122->Fit( m_panel_simulation );
	m_notebook1->AddPage( m_panel_simulation, _("Simulation"), true );
	m_panel_ais = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );


	bSizer11->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer121;
	bSizer121 = new wxBoxSizer( wxHORIZONTAL );


	bSizer121->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText2 = new wxStaticText( m_panel_ais, wxID_ANY, _("MMSI:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer121->Add( m_staticText2, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrl_mmsi = new wxSpinCtrl( m_panel_ais, wxID_ANY, wxT("227000000"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 999999999, 227000000 );
	bSizer121->Add( m_spinCtrl_mmsi, 0, wxALL, 5 );


	bSizer121->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer11->Add( bSizer121, 0, wxEXPAND, 5 );


	bSizer11->Add( 0, 0, 1, wxEXPAND, 5 );


	m_panel_ais->SetSizer( bSizer11 );
	m_panel_ais->Layout();
	bSizer11->Fit( m_panel_ais );
	m_notebook1->AddPage( m_panel_ais, _("AIS"), false );

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
