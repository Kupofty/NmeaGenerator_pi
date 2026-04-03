///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "main_ui_base.h"

///////////////////////////////////////////////////////////////////////////

MyDialog::MyDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	m_timer_autoSendNmea.SetOwner( this, m_timer_autoSendNmea.GetId() );
	m_timer_autoSendBuilder.SetOwner( this, m_timer_autoSendBuilder.GetId() );
	wxBoxSizer* bSizer_main;
	bSizer_main = new wxBoxSizer( wxVERTICAL );

	m_notebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel_manual = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3 = new wxStaticText( m_panel_manual, wxID_ANY, _("NMEA sentence:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer4->Add( m_staticText3, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_sentenceInput = new wxTextCtrl( m_panel_manual, wxID_ANY, _("$"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl_sentenceInput->SetMinSize( wxSize( 200,-1 ) );

	bSizer4->Add( m_textCtrl_sentenceInput, 1, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );

	m_staticText_checksum = new wxStaticText( m_panel_manual, wxID_ANY, _("*00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_checksum->Wrap( -1 );
	bSizer4->Add( m_staticText_checksum, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer3->Add( bSizer4, 1, wxEXPAND, 5 );

	m_checkBox_autoChecksum = new wxCheckBox( m_panel_manual, wxID_ANY, _("Automatic checksum calculation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_autoChecksum->SetValue(true);
	bSizer3->Add( m_checkBox_autoChecksum, 1, wxALIGN_CENTER|wxALL, 5 );

	m_staticline1 = new wxStaticLine( m_panel_manual, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer3->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxHORIZONTAL );


	bSizer51->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_sendSentence = new wxButton( m_panel_manual, wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer51->Add( m_button_sendSentence, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_button_clearInput = new wxButton( m_panel_manual, wxID_ANY, _("Clear"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer51->Add( m_button_clearInput, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer51->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer3->Add( bSizer51, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );


	bSizer7->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox_automaticSend = new wxCheckBox( m_panel_manual, wxID_ANY, _("Automatic send at"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_checkBox_automaticSend, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_automaticSendFreq = new wxSpinCtrlDouble( m_panel_manual, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0.1, 10, 1.000000, 0.25 );
	m_spinCtrlDouble_automaticSendFreq->SetDigits( 1 );
	bSizer7->Add( m_spinCtrlDouble_automaticSendFreq, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText4 = new wxStaticText( m_panel_manual, wxID_ANY, _("Hz"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer7->Add( m_staticText4, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer7->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer3->Add( bSizer7, 1, wxEXPAND, 5 );


	m_panel_manual->SetSizer( bSizer3 );
	m_panel_manual->Layout();
	bSizer3->Fit( m_panel_manual );
	m_notebook->AddPage( m_panel_manual, _("Manual Input"), false );
	m_panel2 = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	m_scrolledWindow_sentenceBuilder = new wxScrolledWindow( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow_sentenceBuilder->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer_GLL;
	fgSizer_GLL = new wxFlexGridSizer( 2, 11, 0, 0 );
	fgSizer_GLL->SetFlexibleDirection( wxBOTH );
	fgSizer_GLL->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	fgSizer_GLL->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText19 = new wxStaticText( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	fgSizer_GLL->Add( m_staticText19, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_GLL->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText9 = new wxStaticText( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("Latitude\n(ddmm.mm)"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText9->Wrap( -1 );
	m_staticText9->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	fgSizer_GLL->Add( m_staticText9, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_GLL->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText11 = new wxStaticText( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("Longitude\n(dddmm.mm)"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText11->Wrap( -1 );
	fgSizer_GLL->Add( m_staticText11, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_GLL->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText14 = new wxStaticText( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("UTC time\n(hhmmss:ss)"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText14->Wrap( -1 );
	fgSizer_GLL->Add( m_staticText14, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText15 = new wxStaticText( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("Status"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	fgSizer_GLL->Add( m_staticText15, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText18 = new wxStaticText( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("Mode"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	fgSizer_GLL->Add( m_staticText18, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_GLL->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox_autoSendGLL = new wxCheckBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_autoSendGLL->SetValue(true);
	fgSizer_GLL->Add( m_checkBox_autoSendGLL, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_idGLL = new wxTextCtrl( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("GP"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_idGLL->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_idGLL->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_idGLL->SetMaxLength( 2 );
	#endif
	fgSizer_GLL->Add( m_textCtrl_idGLL, 0, wxALL, 5 );

	m_staticText5 = new wxStaticText( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("GLL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	fgSizer_GLL->Add( m_staticText5, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_latitudeGLL = new wxTextCtrl( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("0000.0000000"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_latitudeGLL->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_latitudeGLL->SetMaxLength( 12 );
	}
	#else
	m_textCtrl_latitudeGLL->SetMaxLength( 12 );
	#endif
	fgSizer_GLL->Add( m_textCtrl_latitudeGLL, 0, wxALL, 5 );

	wxString m_choice_latDirGLLChoices[] = { _("N"), _("S") };
	int m_choice_latDirGLLNChoices = sizeof( m_choice_latDirGLLChoices ) / sizeof( wxString );
	m_choice_latDirGLL = new wxChoice( m_scrolledWindow_sentenceBuilder, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_latDirGLLNChoices, m_choice_latDirGLLChoices, 0 );
	m_choice_latDirGLL->SetSelection( 0 );
	fgSizer_GLL->Add( m_choice_latDirGLL, 0, wxALL, 5 );

	m_textCtrl_longitudeGLL = new wxTextCtrl( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("00000.0000000"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_longitudeGLL->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_longitudeGLL->SetMaxLength( 13 );
	}
	#else
	m_textCtrl_longitudeGLL->SetMaxLength( 13 );
	#endif
	fgSizer_GLL->Add( m_textCtrl_longitudeGLL, 0, wxALL, 5 );

	wxString m_choice_lonDirGLLChoices[] = { _("E"), _("W") };
	int m_choice_lonDirGLLNChoices = sizeof( m_choice_lonDirGLLChoices ) / sizeof( wxString );
	m_choice_lonDirGLL = new wxChoice( m_scrolledWindow_sentenceBuilder, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_lonDirGLLNChoices, m_choice_lonDirGLLChoices, 0 );
	m_choice_lonDirGLL->SetSelection( 0 );
	fgSizer_GLL->Add( m_choice_lonDirGLL, 0, wxALL, 5 );

	m_textCtrl_timeGLL = new wxTextCtrl( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("000000:00"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_timeGLL->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_timeGLL->SetMaxLength( 9 );
	}
	#else
	m_textCtrl_timeGLL->SetMaxLength( 9 );
	#endif
	fgSizer_GLL->Add( m_textCtrl_timeGLL, 0, wxALL, 5 );

	wxString m_choice_statusGLLChoices[] = { _("A"), _("V") };
	int m_choice_statusGLLNChoices = sizeof( m_choice_statusGLLChoices ) / sizeof( wxString );
	m_choice_statusGLL = new wxChoice( m_scrolledWindow_sentenceBuilder, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), m_choice_statusGLLNChoices, m_choice_statusGLLChoices, 0 );
	m_choice_statusGLL->SetSelection( 0 );
	fgSizer_GLL->Add( m_choice_statusGLL, 0, wxALL, 5 );

	wxString m_choice_modeGLLChoices[] = { _("A"), _("D"), _("E"), _("M"), _("S"), _("N") };
	int m_choice_modeGLLNChoices = sizeof( m_choice_modeGLLChoices ) / sizeof( wxString );
	m_choice_modeGLL = new wxChoice( m_scrolledWindow_sentenceBuilder, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_modeGLLNChoices, m_choice_modeGLLChoices, 0 );
	m_choice_modeGLL->SetSelection( 4 );
	fgSizer_GLL->Add( m_choice_modeGLL, 0, wxALL, 5 );

	m_button_sendGLL = new wxButton( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendGLL->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	fgSizer_GLL->Add( m_button_sendGLL, 0, wxALL, 5 );


	bSizer11->Add( fgSizer_GLL, 1, wxEXPAND, 5 );


	m_scrolledWindow_sentenceBuilder->SetSizer( bSizer11 );
	m_scrolledWindow_sentenceBuilder->Layout();
	bSizer11->Fit( m_scrolledWindow_sentenceBuilder );
	bSizer9->Add( m_scrolledWindow_sentenceBuilder, 1, wxEXPAND | wxALL, 5 );

	m_staticline3 = new wxStaticLine( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer9->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );


	bSizer12->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_checkAllBuilder = new wxButton( m_panel2, wxID_ANY, _("Check all"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_button_checkAllBuilder, 0, wxALL, 5 );

	m_button_uncheckAllBuilder = new wxButton( m_panel2, wxID_ANY, _("Uncheck all"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_button_uncheckAllBuilder, 0, wxALL, 5 );


	bSizer12->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticline4 = new wxStaticLine( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL|wxLI_VERTICAL );
	bSizer12->Add( m_staticline4, 0, wxEXPAND | wxALL, 5 );


	bSizer12->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox_automaticSendBuilder = new wxCheckBox( m_panel2, wxID_ANY, _("Automatic send at"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_checkBox_automaticSendBuilder, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_autoSendFreqBuilder = new wxSpinCtrlDouble( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0.1, 10, 1, 0.25 );
	m_spinCtrlDouble_autoSendFreqBuilder->SetDigits( 1 );
	bSizer12->Add( m_spinCtrlDouble_autoSendFreqBuilder, 0, wxALL, 5 );

	m_staticText20 = new wxStaticText( m_panel2, wxID_ANY, _("Hz"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer12->Add( m_staticText20, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer12->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer9->Add( bSizer12, 0, wxEXPAND, 5 );


	m_panel2->SetSizer( bSizer9 );
	m_panel2->Layout();
	bSizer9->Fit( m_panel2 );
	m_notebook->AddPage( m_panel2, _("Sentence Builder"), true );
	m_panel3 = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );


	bSizer8->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText41 = new wxStaticText( m_panel3, wxID_ANY, _("Coming soon..."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	bSizer8->Add( m_staticText41, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer8->Add( 0, 0, 1, wxEXPAND, 5 );


	m_panel3->SetSizer( bSizer8 );
	m_panel3->Layout();
	bSizer8->Fit( m_panel3 );
	m_notebook->AddPage( m_panel3, _("Simulation"), false );

	bSizer_main->Add( m_notebook, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer_main );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyDialog::OnClose ) );
	this->Connect( m_timer_autoSendNmea.GetId(), wxEVT_TIMER, wxTimerEventHandler( MyDialog::OnTimer_autoSendNmea ) );
	this->Connect( m_timer_autoSendBuilder.GetId(), wxEVT_TIMER, wxTimerEventHandler( MyDialog::OnTimer_autoSendBuilder ) );
	m_textCtrl_sentenceInput->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyDialog::OnInputTextChanged ), NULL, this );
	m_checkBox_autoChecksum->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyDialog::OnAutoChecksumChecked ), NULL, this );
	m_button_sendSentence->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_manualSend ), NULL, this );
	m_button_clearInput->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnClearInput ), NULL, this );
	m_checkBox_automaticSend->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyDialog::OnCheckBox_AutomaticSend ), NULL, this );
	m_spinCtrlDouble_automaticSendFreq->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( MyDialog::OnSpinCtrlDouble_AutomaticSendFreq ), NULL, this );
	m_button_sendGLL->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendGLL ), NULL, this );
	m_button_checkAllBuilder->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_CheckAllBuilder ), NULL, this );
	m_button_uncheckAllBuilder->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_UncheckAllBuilder ), NULL, this );
	m_checkBox_automaticSendBuilder->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyDialog::OnCheckBox_AutomaticSendBuilder ), NULL, this );
	m_spinCtrlDouble_autoSendFreqBuilder->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( MyDialog::OnSpinCtrlDouble_AutomaticSendFreqBuilder ), NULL, this );
}

MyDialog::~MyDialog()
{
}
