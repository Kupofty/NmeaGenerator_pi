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


	bSizer3->Add( 0, 0, 1, wxEXPAND, 5 );

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


	bSizer3->Add( bSizer4, 0, wxEXPAND, 5 );

	m_checkBox_autoChecksum = new wxCheckBox( m_panel_manual, wxID_ANY, _("Automatic checksum calculation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_autoChecksum->SetValue(true);
	bSizer3->Add( m_checkBox_autoChecksum, 1, wxALIGN_CENTER|wxALL, 5 );


	bSizer3->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticline1 = new wxStaticLine( m_panel_manual, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer3->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );


	bSizer3->Add( 0, 0, 1, wxEXPAND, 5 );

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

	m_spinCtrlDouble_automaticSendFreq = new wxSpinCtrlDouble( m_panel_manual, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0.1, 10, 1, 0.25 );
	m_spinCtrlDouble_automaticSendFreq->SetDigits( 1 );
	bSizer7->Add( m_spinCtrlDouble_automaticSendFreq, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText4 = new wxStaticText( m_panel_manual, wxID_ANY, _("Hz"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer7->Add( m_staticText4, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer7->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer3->Add( bSizer7, 1, wxEXPAND, 5 );


	bSizer3->Add( 0, 0, 1, wxEXPAND, 5 );


	m_panel_manual->SetSizer( bSizer3 );
	m_panel_manual->Layout();
	bSizer3->Fit( m_panel_manual );
	m_notebook->AddPage( m_panel_manual, _("Manual Input"), false );
	m_panel2 = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	m_scrolledWindow_sentenceBuilder = new wxScrolledWindow( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow_sentenceBuilder->SetScrollRate( 5, 5 );
	bSizer_NmeaList = new wxBoxSizer( wxVERTICAL );

	sbSizer_RMC = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("RMC") ), wxHORIZONTAL );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );


	bSizer14->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_sendRMC = new wxButton( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendRMC->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer14->Add( m_button_sendRMC, 0, wxALL, 5 );

	m_checkBox_autoSendRMC = new wxCheckBox( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_autoSendRMC->SetValue(true);
	bSizer14->Add( m_checkBox_autoSendRMC, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer14->Add( 0, 0, 1, wxEXPAND, 5 );


	sbSizer_RMC->Add( bSizer14, 0, wxEXPAND, 5 );

	m_staticline6 = new wxStaticLine( sbSizer_RMC->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL|wxLI_VERTICAL );
	sbSizer_RMC->Add( m_staticline6, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer_RMC;
	fgSizer_RMC = new wxFlexGridSizer( 2, 13, 0, 0 );
	fgSizer_RMC->SetFlexibleDirection( wxBOTH );
	fgSizer_RMC->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText13 = new wxStaticText( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	fgSizer_RMC->Add( m_staticText13, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_RMC->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText141 = new wxStaticText( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("UTC time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText141->Wrap( -1 );
	fgSizer_RMC->Add( m_staticText141, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText151 = new wxStaticText( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("Status"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText151->Wrap( -1 );
	fgSizer_RMC->Add( m_staticText151, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText16 = new wxStaticText( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("Latitude"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	fgSizer_RMC->Add( m_staticText16, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_RMC->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText181 = new wxStaticText( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("Longitude"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText181->Wrap( -1 );
	fgSizer_RMC->Add( m_staticText181, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_RMC->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText201 = new wxStaticText( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("SOG"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText201->Wrap( -1 );
	fgSizer_RMC->Add( m_staticText201, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText26 = new wxStaticText( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("COG"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText26->Wrap( -1 );
	fgSizer_RMC->Add( m_staticText26, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText27 = new wxStaticText( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("Date"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText27->Wrap( -1 );
	fgSizer_RMC->Add( m_staticText27, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText28 = new wxStaticText( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("Mag var."), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText28->Wrap( -1 );
	fgSizer_RMC->Add( m_staticText28, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_RMC->Add( 0, 0, 1, wxEXPAND, 5 );

	m_textCtrl_talkerRMC = new wxTextCtrl( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("GP"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerRMC->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerRMC->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerRMC->SetMaxLength( 2 );
	#endif
	fgSizer_RMC->Add( m_textCtrl_talkerRMC, 0, wxALL, 5 );

	m_staticText22 = new wxStaticText( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("RMC"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	fgSizer_RMC->Add( m_staticText22, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_timeRMC = new wxTextCtrl( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("120000"), wxDefaultPosition, wxSize( 55,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_timeRMC->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_timeRMC->SetMaxLength( 9 );
	}
	#else
	m_textCtrl_timeRMC->SetMaxLength( 9 );
	#endif
	fgSizer_RMC->Add( m_textCtrl_timeRMC, 0, wxALL, 5 );

	wxString m_choice_statusRMCChoices[] = { _("A"), _("V") };
	int m_choice_statusRMCNChoices = sizeof( m_choice_statusRMCChoices ) / sizeof( wxString );
	m_choice_statusRMC = new wxChoice( sbSizer_RMC->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_statusRMCNChoices, m_choice_statusRMCChoices, 0 );
	m_choice_statusRMC->SetSelection( 0 );
	fgSizer_RMC->Add( m_choice_statusRMC, 0, wxALL, 5 );

	m_textCtrl_latitudeRMC = new wxTextCtrl( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("0000.0000000"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_latitudeRMC->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_latitudeRMC->SetMaxLength( 12 );
	}
	#else
	m_textCtrl_latitudeRMC->SetMaxLength( 12 );
	#endif
	fgSizer_RMC->Add( m_textCtrl_latitudeRMC, 0, wxALL, 5 );

	wxString m_choice_latDirRMCChoices[] = { _("N"), _("S") };
	int m_choice_latDirRMCNChoices = sizeof( m_choice_latDirRMCChoices ) / sizeof( wxString );
	m_choice_latDirRMC = new wxChoice( sbSizer_RMC->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_latDirRMCNChoices, m_choice_latDirRMCChoices, 0 );
	m_choice_latDirRMC->SetSelection( 0 );
	fgSizer_RMC->Add( m_choice_latDirRMC, 0, wxALL, 5 );

	m_textCtrl_longitudeRMC = new wxTextCtrl( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("00000.0000000"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_longitudeRMC->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_longitudeRMC->SetMaxLength( 13 );
	}
	#else
	m_textCtrl_longitudeRMC->SetMaxLength( 13 );
	#endif
	fgSizer_RMC->Add( m_textCtrl_longitudeRMC, 0, wxALL, 5 );

	wxString m_choice_lonDirRMCChoices[] = { _("E"), _("W") };
	int m_choice_lonDirRMCNChoices = sizeof( m_choice_lonDirRMCChoices ) / sizeof( wxString );
	m_choice_lonDirRMC = new wxChoice( sbSizer_RMC->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_lonDirRMCNChoices, m_choice_lonDirRMCChoices, 0 );
	m_choice_lonDirRMC->SetSelection( 0 );
	fgSizer_RMC->Add( m_choice_lonDirRMC, 0, wxALL, 5 );

	m_spinCtrlDouble_sogRMC = new wxSpinCtrlDouble( sbSizer_RMC->GetStaticBox(), wxID_ANY, wxT("6"), wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 999.9, 1.000000, 1 );
	m_spinCtrlDouble_sogRMC->SetDigits( 1 );
	fgSizer_RMC->Add( m_spinCtrlDouble_sogRMC, 0, wxALL, 5 );

	m_spinCtrlDouble_cogRMC = new wxSpinCtrlDouble( sbSizer_RMC->GetStaticBox(), wxID_ANY, wxT("60"), wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 360, 45.000000, 45 );
	m_spinCtrlDouble_cogRMC->SetDigits( 1 );
	fgSizer_RMC->Add( m_spinCtrlDouble_cogRMC, 0, wxALL, 5 );

	m_textCtrl_dateRMC = new wxTextCtrl( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("010126"), wxDefaultPosition, wxSize( 55,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_dateRMC->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_dateRMC->SetMaxLength( 6 );
	}
	#else
	m_textCtrl_dateRMC->SetMaxLength( 6 );
	#endif
	fgSizer_RMC->Add( m_textCtrl_dateRMC, 0, wxALL, 5 );

	m_spinCtrlDouble_magRMC = new wxSpinCtrlDouble( sbSizer_RMC->GetStaticBox(), wxID_ANY, wxT("3"), wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 180, 3.000000, 1 );
	m_spinCtrlDouble_magRMC->SetDigits( 1 );
	fgSizer_RMC->Add( m_spinCtrlDouble_magRMC, 0, wxALL, 5 );

	wxString m_choice_magDirRMCChoices[] = { _("E"), _("W") };
	int m_choice_magDirRMCNChoices = sizeof( m_choice_magDirRMCChoices ) / sizeof( wxString );
	m_choice_magDirRMC = new wxChoice( sbSizer_RMC->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_magDirRMCNChoices, m_choice_magDirRMCChoices, 0 );
	m_choice_magDirRMC->SetSelection( 0 );
	fgSizer_RMC->Add( m_choice_magDirRMC, 0, wxALL, 5 );


	sbSizer_RMC->Add( fgSizer_RMC, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_RMC, 0, wxEXPAND, 5 );

	sbSizer_GGA = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("GGA") ), wxHORIZONTAL );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );


	bSizer15->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_sendGGA = new wxButton( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendGGA->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer15->Add( m_button_sendGGA, 0, wxALL, 5 );

	m_checkBox_autoSendGGA = new wxCheckBox( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_autoSendGGA->SetValue(true);
	bSizer15->Add( m_checkBox_autoSendGGA, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer15->Add( 0, 0, 1, wxEXPAND, 5 );


	sbSizer_GGA->Add( bSizer15, 0, wxEXPAND, 5 );

	m_staticline8 = new wxStaticLine( sbSizer_GGA->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	sbSizer_GGA->Add( m_staticline8, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer_GGA;
	fgSizer_GGA = new wxFlexGridSizer( 0, 14, 0, 0 );
	fgSizer_GGA->SetFlexibleDirection( wxBOTH );
	fgSizer_GGA->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText29 = new wxStaticText( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	fgSizer_GGA->Add( m_staticText29, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_GGA->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText30 = new wxStaticText( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("UTC time"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText30->Wrap( -1 );
	fgSizer_GGA->Add( m_staticText30, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText31 = new wxStaticText( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("Latitude"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText31->Wrap( -1 );
	fgSizer_GGA->Add( m_staticText31, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_GGA->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText32 = new wxStaticText( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("Longitude"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText32->Wrap( -1 );
	fgSizer_GGA->Add( m_staticText32, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_GGA->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText33 = new wxStaticText( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("GPS fix"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText33->Wrap( -1 );
	fgSizer_GGA->Add( m_staticText33, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText34 = new wxStaticText( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("Satellites"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText34->Wrap( -1 );
	fgSizer_GGA->Add( m_staticText34, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText35 = new wxStaticText( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("HDOP"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35->Wrap( -1 );
	fgSizer_GGA->Add( m_staticText35, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText36 = new wxStaticText( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("Altitude"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText36->Wrap( -1 );
	fgSizer_GGA->Add( m_staticText36, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_GGA->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText37 = new wxStaticText( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("Geoid separation"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText37->Wrap( -1 );
	fgSizer_GGA->Add( m_staticText37, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_GGA->Add( 0, 0, 1, wxEXPAND, 5 );

	m_textCtrl_talkerGGA = new wxTextCtrl( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("GP"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerGGA->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerGGA->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerGGA->SetMaxLength( 2 );
	#endif
	fgSizer_GGA->Add( m_textCtrl_talkerGGA, 0, wxALL, 5 );

	m_staticText40 = new wxStaticText( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("GGA"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText40->Wrap( -1 );
	fgSizer_GGA->Add( m_staticText40, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_timeGGA = new wxTextCtrl( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("120000"), wxDefaultPosition, wxSize( 55,-1 ), 0 );
	fgSizer_GGA->Add( m_textCtrl_timeGGA, 0, wxALL, 5 );

	m_textCtrl_latitudeGGA = new wxTextCtrl( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("0000.0000000"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	fgSizer_GGA->Add( m_textCtrl_latitudeGGA, 0, wxALL, 5 );

	wxString m_choice_latDirGGAChoices[] = { _("N"), _("S") };
	int m_choice_latDirGGANChoices = sizeof( m_choice_latDirGGAChoices ) / sizeof( wxString );
	m_choice_latDirGGA = new wxChoice( sbSizer_GGA->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_latDirGGANChoices, m_choice_latDirGGAChoices, 0 );
	m_choice_latDirGGA->SetSelection( 0 );
	fgSizer_GGA->Add( m_choice_latDirGGA, 0, wxALL, 5 );

	m_textCtrl_longitudeGGA = new wxTextCtrl( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("00000.0000000"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	fgSizer_GGA->Add( m_textCtrl_longitudeGGA, 0, wxALL, 5 );

	wxString m_choice_lonDirGGAChoices[] = { _("E"), _("W") };
	int m_choice_lonDirGGANChoices = sizeof( m_choice_lonDirGGAChoices ) / sizeof( wxString );
	m_choice_lonDirGGA = new wxChoice( sbSizer_GGA->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_lonDirGGANChoices, m_choice_lonDirGGAChoices, 0 );
	m_choice_lonDirGGA->SetSelection( 0 );
	fgSizer_GGA->Add( m_choice_lonDirGGA, 0, wxALL, 5 );

	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );

	m_spinCtrl_gpsQualityGGA = new wxSpinCtrl( sbSizer_GGA->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 6, 1 );
	bSizer19->Add( m_spinCtrl_gpsQualityGGA, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_GGA->Add( bSizer19, 1, wxEXPAND, 5 );

	m_spinCtrl_satellitesGGA = new wxSpinCtrl( sbSizer_GGA->GetStaticBox(), wxID_ANY, wxT("12"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 99, 11 );
	fgSizer_GGA->Add( m_spinCtrl_satellitesGGA, 0, wxALL, 5 );

	m_spinCtrlDouble_hdopGGA = new wxSpinCtrlDouble( sbSizer_GGA->GetStaticBox(), wxID_ANY, wxT("0.5"), wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 100, 0.500000, 0.5 );
	m_spinCtrlDouble_hdopGGA->SetDigits( 1 );
	fgSizer_GGA->Add( m_spinCtrlDouble_hdopGGA, 0, wxALL, 5 );

	m_spinCtrlDouble_altitude_GGA = new wxSpinCtrlDouble( sbSizer_GGA->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 100, 10.000000, 1 );
	m_spinCtrlDouble_altitude_GGA->SetDigits( 1 );
	fgSizer_GGA->Add( m_spinCtrlDouble_altitude_GGA, 0, wxALL, 5 );

	m_staticText411 = new wxStaticText( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("M"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText411->Wrap( -1 );
	fgSizer_GGA->Add( m_staticText411, 0, wxALIGN_CENTER|wxALL, 5 );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );

	m_spinCtrlDouble_geoidSeparationGGA = new wxSpinCtrlDouble( sbSizer_GGA->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 100, 0, 1 );
	m_spinCtrlDouble_geoidSeparationGGA->SetDigits( 1 );
	bSizer18->Add( m_spinCtrlDouble_geoidSeparationGGA, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_GGA->Add( bSizer18, 1, wxEXPAND, 5 );

	m_staticText42 = new wxStaticText( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("M"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText42->Wrap( -1 );
	fgSizer_GGA->Add( m_staticText42, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_GGA->Add( fgSizer_GGA, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_GGA, 0, wxEXPAND, 5 );

	sbSizer_TLL = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("TLL") ), wxHORIZONTAL );

	wxBoxSizer* bSizer171111;
	bSizer171111 = new wxBoxSizer( wxVERTICAL );

	m_button_sendTLL = new wxButton( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendTLL->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer171111->Add( m_button_sendTLL, 0, wxALL, 5 );

	m_checkBox_autoSendTLL = new wxCheckBox( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_autoSendTLL->SetValue(true);
	bSizer171111->Add( m_checkBox_autoSendTLL, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_TLL->Add( bSizer171111, 0, wxEXPAND, 5 );

	m_staticline61111 = new wxStaticLine( sbSizer_TLL->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	sbSizer_TLL->Add( m_staticline61111, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer4111;
	fgSizer4111 = new wxFlexGridSizer( 2, 11, 0, 0 );
	fgSizer4111->SetFlexibleDirection( wxBOTH );
	fgSizer4111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText351111 = new wxStaticText( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText351111->Wrap( -1 );
	fgSizer4111->Add( m_staticText351111, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer4111->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText361111 = new wxStaticText( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText361111->Wrap( -1 );
	fgSizer4111->Add( m_staticText361111, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText63 = new wxStaticText( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("Latitude"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText63->Wrap( -1 );
	fgSizer4111->Add( m_staticText63, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer4111->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText64 = new wxStaticText( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("Longitude"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText64->Wrap( -1 );
	fgSizer4111->Add( m_staticText64, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer4111->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText65 = new wxStaticText( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText65->Wrap( -1 );
	fgSizer4111->Add( m_staticText65, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText66 = new wxStaticText( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("UTC Time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText66->Wrap( -1 );
	fgSizer4111->Add( m_staticText66, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText67 = new wxStaticText( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("Status"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText67->Wrap( -1 );
	fgSizer4111->Add( m_staticText67, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer4111->Add( 0, 0, 1, wxEXPAND, 5 );

	m_textCtrl_talkerTLL = new wxTextCtrl( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("GP"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer4111->Add( m_textCtrl_talkerTLL, 0, wxALL, 5 );

	m_staticText371111 = new wxStaticText( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("TLL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText371111->Wrap( -1 );
	fgSizer4111->Add( m_staticText371111, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrl_idTLL = new wxSpinCtrl( sbSizer_TLL->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer4111->Add( m_spinCtrl_idTLL, 0, wxALL, 5 );

	m_textCtrl_latitudeTLL = new wxTextCtrl( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("0000.0000000"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	fgSizer4111->Add( m_textCtrl_latitudeTLL, 0, wxALL, 5 );

	wxString m_choice_latDirTLLChoices[] = { _("N"), _("S") };
	int m_choice_latDirTLLNChoices = sizeof( m_choice_latDirTLLChoices ) / sizeof( wxString );
	m_choice_latDirTLL = new wxChoice( sbSizer_TLL->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_latDirTLLNChoices, m_choice_latDirTLLChoices, 0 );
	m_choice_latDirTLL->SetSelection( 0 );
	fgSizer4111->Add( m_choice_latDirTLL, 0, wxALL, 5 );

	m_textCtrl_longitudeTLL = new wxTextCtrl( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("00000.0000000"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	fgSizer4111->Add( m_textCtrl_longitudeTLL, 0, wxALL, 5 );

	wxString m_choice_lonDirTLLChoices[] = { _("E"), _("W") };
	int m_choice_lonDirTLLNChoices = sizeof( m_choice_lonDirTLLChoices ) / sizeof( wxString );
	m_choice_lonDirTLL = new wxChoice( sbSizer_TLL->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_lonDirTLLNChoices, m_choice_lonDirTLLChoices, 0 );
	m_choice_lonDirTLL->SetSelection( 0 );
	fgSizer4111->Add( m_choice_lonDirTLL, 0, wxALL, 5 );

	m_textCtrl_nameTLL = new wxTextCtrl( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("DUMMY"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4111->Add( m_textCtrl_nameTLL, 0, wxALL, 5 );

	m_textCtrl_timeTLL = new wxTextCtrl( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("120000"), wxDefaultPosition, wxSize( 55,-1 ), 0 );
	fgSizer4111->Add( m_textCtrl_timeTLL, 0, wxALL, 5 );

	wxString m_choice_statusTLLChoices[] = { _("T"), _("Q"), _("L") };
	int m_choice_statusTLLNChoices = sizeof( m_choice_statusTLLChoices ) / sizeof( wxString );
	m_choice_statusTLL = new wxChoice( sbSizer_TLL->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_statusTLLNChoices, m_choice_statusTLLChoices, 0 );
	m_choice_statusTLL->SetSelection( 0 );
	fgSizer4111->Add( m_choice_statusTLL, 0, wxALL, 5 );

	m_staticText68 = new wxStaticText( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("R"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText68->Wrap( -1 );
	fgSizer4111->Add( m_staticText68, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_TLL->Add( fgSizer4111, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_TLL, 0, wxEXPAND, 5 );

	sbSizer_GLL = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("GLL") ), wxHORIZONTAL );

	wxBoxSizer* bSizer121;
	bSizer121 = new wxBoxSizer( wxVERTICAL );


	bSizer121->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_sendGLL = new wxButton( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendGLL->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer121->Add( m_button_sendGLL, 0, wxALL, 5 );

	m_checkBox_autoSendGLL = new wxCheckBox( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_autoSendGLL->SetValue(true);
	bSizer121->Add( m_checkBox_autoSendGLL, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer121->Add( 0, 0, 1, wxEXPAND, 5 );


	sbSizer_GLL->Add( bSizer121, 0, wxEXPAND, 5 );

	m_staticline5 = new wxStaticLine( sbSizer_GLL->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL|wxLI_VERTICAL );
	sbSizer_GLL->Add( m_staticline5, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer_GLL;
	fgSizer_GLL = new wxFlexGridSizer( 2, 9, 0, 0 );
	fgSizer_GLL->SetFlexibleDirection( wxBOTH );
	fgSizer_GLL->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText19 = new wxStaticText( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	fgSizer_GLL->Add( m_staticText19, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_GLL->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText9 = new wxStaticText( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("Latitude"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText9->Wrap( -1 );
	m_staticText9->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	fgSizer_GLL->Add( m_staticText9, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_GLL->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText11 = new wxStaticText( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("Longitude"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText11->Wrap( -1 );
	fgSizer_GLL->Add( m_staticText11, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_GLL->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText14 = new wxStaticText( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("UTC time"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText14->Wrap( -1 );
	fgSizer_GLL->Add( m_staticText14, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText15 = new wxStaticText( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("Status"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	fgSizer_GLL->Add( m_staticText15, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText18 = new wxStaticText( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("Mode"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	fgSizer_GLL->Add( m_staticText18, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_talkerGLL = new wxTextCtrl( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("GP"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerGLL->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerGLL->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerGLL->SetMaxLength( 2 );
	#endif
	fgSizer_GLL->Add( m_textCtrl_talkerGLL, 0, wxALL, 5 );

	m_staticText5 = new wxStaticText( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("GLL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	fgSizer_GLL->Add( m_staticText5, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_latitudeGLL = new wxTextCtrl( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("0000.0000000"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
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
	m_choice_latDirGLL = new wxChoice( sbSizer_GLL->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_latDirGLLNChoices, m_choice_latDirGLLChoices, 0 );
	m_choice_latDirGLL->SetSelection( 0 );
	fgSizer_GLL->Add( m_choice_latDirGLL, 0, wxALL, 5 );

	m_textCtrl_longitudeGLL = new wxTextCtrl( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("00000.0000000"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
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
	m_choice_lonDirGLL = new wxChoice( sbSizer_GLL->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_lonDirGLLNChoices, m_choice_lonDirGLLChoices, 0 );
	m_choice_lonDirGLL->SetSelection( 1 );
	fgSizer_GLL->Add( m_choice_lonDirGLL, 0, wxALL, 5 );

	m_textCtrl_timeGLL = new wxTextCtrl( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("120000"), wxDefaultPosition, wxSize( 55,-1 ), 0 );
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
	m_choice_statusGLL = new wxChoice( sbSizer_GLL->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), m_choice_statusGLLNChoices, m_choice_statusGLLChoices, 0 );
	m_choice_statusGLL->SetSelection( 0 );
	fgSizer_GLL->Add( m_choice_statusGLL, 0, wxALL, 5 );

	wxString m_choice_modeGLLChoices[] = { _("A"), _("D"), _("E"), _("M"), _("S"), _("N") };
	int m_choice_modeGLLNChoices = sizeof( m_choice_modeGLLChoices ) / sizeof( wxString );
	m_choice_modeGLL = new wxChoice( sbSizer_GLL->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_modeGLLNChoices, m_choice_modeGLLChoices, 0 );
	m_choice_modeGLL->SetSelection( 4 );
	fgSizer_GLL->Add( m_choice_modeGLL, 0, wxALL, 5 );


	sbSizer_GLL->Add( fgSizer_GLL, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_GLL, 0, wxEXPAND, 5 );

	sbSizer_HDT = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("HDT") ), wxHORIZONTAL );

	wxBoxSizer* bSizer171;
	bSizer171 = new wxBoxSizer( wxVERTICAL );

	m_button_sendHDT = new wxButton( sbSizer_HDT->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendHDT->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer171->Add( m_button_sendHDT, 0, wxALL, 5 );

	m_checkBox_autoSendHDT = new wxCheckBox( sbSizer_HDT->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_autoSendHDT->SetValue(true);
	bSizer171->Add( m_checkBox_autoSendHDT, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_HDT->Add( bSizer171, 0, wxEXPAND, 5 );

	m_staticline61 = new wxStaticLine( sbSizer_HDT->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	sbSizer_HDT->Add( m_staticline61, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText351 = new wxStaticText( sbSizer_HDT->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText351->Wrap( -1 );
	fgSizer4->Add( m_staticText351, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer4->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText361 = new wxStaticText( sbSizer_HDT->GetStaticBox(), wxID_ANY, _("Heading"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText361->Wrap( -1 );
	fgSizer4->Add( m_staticText361, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer4->Add( 0, 0, 1, wxEXPAND, 5 );

	m_textCtrl_talkerHDT = new wxTextCtrl( sbSizer_HDT->GetStaticBox(), wxID_ANY, _("GP"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer4->Add( m_textCtrl_talkerHDT, 0, wxALL, 5 );

	m_staticText371 = new wxStaticText( sbSizer_HDT->GetStaticBox(), wxID_ANY, _("HDT"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText371->Wrap( -1 );
	fgSizer4->Add( m_staticText371, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_headingHDT = new wxSpinCtrlDouble( sbSizer_HDT->GetStaticBox(), wxID_ANY, wxT("135"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 360, 135.000000, 45 );
	m_spinCtrlDouble_headingHDT->SetDigits( 1 );
	fgSizer4->Add( m_spinCtrlDouble_headingHDT, 0, wxALL, 5 );

	m_staticText38 = new wxStaticText( sbSizer_HDT->GetStaticBox(), wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText38->Wrap( -1 );
	fgSizer4->Add( m_staticText38, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_HDT->Add( fgSizer4, 1, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_HDT, 0, wxEXPAND, 5 );

	sbSizer_HDM = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("HDM") ), wxHORIZONTAL );

	wxBoxSizer* bSizer1711;
	bSizer1711 = new wxBoxSizer( wxVERTICAL );

	m_button_sendHDM = new wxButton( sbSizer_HDM->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendHDM->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer1711->Add( m_button_sendHDM, 0, wxALL, 5 );

	m_checkBox_autoSendHDM = new wxCheckBox( sbSizer_HDM->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_autoSendHDM->SetValue(true);
	bSizer1711->Add( m_checkBox_autoSendHDM, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_HDM->Add( bSizer1711, 0, wxEXPAND, 5 );

	m_staticline611 = new wxStaticLine( sbSizer_HDM->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	sbSizer_HDM->Add( m_staticline611, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer41;
	fgSizer41 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer41->SetFlexibleDirection( wxBOTH );
	fgSizer41->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText3511 = new wxStaticText( sbSizer_HDM->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3511->Wrap( -1 );
	fgSizer41->Add( m_staticText3511, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer41->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText3611 = new wxStaticText( sbSizer_HDM->GetStaticBox(), wxID_ANY, _("Heading"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3611->Wrap( -1 );
	fgSizer41->Add( m_staticText3611, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer41->Add( 0, 0, 1, wxEXPAND, 5 );

	m_textCtrl_talkerHDM = new wxTextCtrl( sbSizer_HDM->GetStaticBox(), wxID_ANY, _("GP"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer41->Add( m_textCtrl_talkerHDM, 0, wxALL, 5 );

	m_staticText3711 = new wxStaticText( sbSizer_HDM->GetStaticBox(), wxID_ANY, _("HDM"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3711->Wrap( -1 );
	fgSizer41->Add( m_staticText3711, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_headingHDM = new wxSpinCtrlDouble( sbSizer_HDM->GetStaticBox(), wxID_ANY, wxT("180"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 360, 180.000000, 45 );
	m_spinCtrlDouble_headingHDM->SetDigits( 1 );
	fgSizer41->Add( m_spinCtrlDouble_headingHDM, 0, wxALL, 5 );

	m_staticText381 = new wxStaticText( sbSizer_HDM->GetStaticBox(), wxID_ANY, _("M"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText381->Wrap( -1 );
	fgSizer41->Add( m_staticText381, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_HDM->Add( fgSizer41, 1, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_HDM, 0, wxEXPAND, 5 );

	sbSizer_HDG = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("HDG") ), wxHORIZONTAL );

	wxBoxSizer* bSizer17112;
	bSizer17112 = new wxBoxSizer( wxVERTICAL );

	m_button_sendHDG = new wxButton( sbSizer_HDG->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendHDG->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer17112->Add( m_button_sendHDG, 0, wxALL, 5 );

	m_checkBox_autoSendHDG = new wxCheckBox( sbSizer_HDG->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_autoSendHDG->SetValue(true);
	bSizer17112->Add( m_checkBox_autoSendHDG, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_HDG->Add( bSizer17112, 0, wxEXPAND, 5 );

	m_staticline6112 = new wxStaticLine( sbSizer_HDG->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	sbSizer_HDG->Add( m_staticline6112, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer412;
	fgSizer412 = new wxFlexGridSizer( 2, 7, 0, 0 );
	fgSizer412->SetFlexibleDirection( wxBOTH );
	fgSizer412->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText35112 = new wxStaticText( sbSizer_HDG->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35112->Wrap( -1 );
	fgSizer412->Add( m_staticText35112, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer412->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText36112 = new wxStaticText( sbSizer_HDG->GetStaticBox(), wxID_ANY, _("Heading"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText36112->Wrap( -1 );
	fgSizer412->Add( m_staticText36112, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText96 = new wxStaticText( sbSizer_HDG->GetStaticBox(), wxID_ANY, _("Deviation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText96->Wrap( -1 );
	fgSizer412->Add( m_staticText96, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer412->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText97 = new wxStaticText( sbSizer_HDG->GetStaticBox(), wxID_ANY, _("Variation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText97->Wrap( -1 );
	fgSizer412->Add( m_staticText97, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer412->Add( 0, 0, 1, wxEXPAND, 5 );

	m_textCtrl_talkerHDG = new wxTextCtrl( sbSizer_HDG->GetStaticBox(), wxID_ANY, _("GP"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer412->Add( m_textCtrl_talkerHDG, 0, wxALL, 5 );

	m_staticText37112 = new wxStaticText( sbSizer_HDG->GetStaticBox(), wxID_ANY, _("HDG"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText37112->Wrap( -1 );
	fgSizer412->Add( m_staticText37112, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_headingHDG = new wxSpinCtrlDouble( sbSizer_HDG->GetStaticBox(), wxID_ANY, wxT("180"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 360, 180.000000, 45 );
	m_spinCtrlDouble_headingHDG->SetDigits( 1 );
	fgSizer412->Add( m_spinCtrlDouble_headingHDG, 0, wxALL, 5 );

	m_spinCtrlDouble_deviationHDG = new wxSpinCtrlDouble( sbSizer_HDG->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 180, 0, 1 );
	m_spinCtrlDouble_deviationHDG->SetDigits( 1 );
	fgSizer412->Add( m_spinCtrlDouble_deviationHDG, 0, wxALL, 5 );

	wxString m_choice_deviationDirHDGChoices[] = { _("E"), _("W") };
	int m_choice_deviationDirHDGNChoices = sizeof( m_choice_deviationDirHDGChoices ) / sizeof( wxString );
	m_choice_deviationDirHDG = new wxChoice( sbSizer_HDG->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_deviationDirHDGNChoices, m_choice_deviationDirHDGChoices, 0 );
	m_choice_deviationDirHDG->SetSelection( 0 );
	fgSizer412->Add( m_choice_deviationDirHDG, 0, wxALL, 5 );

	m_spinCtrlDouble_variationHDG = new wxSpinCtrlDouble( sbSizer_HDG->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 180, 0, 1 );
	m_spinCtrlDouble_variationHDG->SetDigits( 1 );
	fgSizer412->Add( m_spinCtrlDouble_variationHDG, 0, wxALL, 5 );

	wxString m_choice_variationDirHDGChoices[] = { _("E"), _("W") };
	int m_choice_variationDirHDGNChoices = sizeof( m_choice_variationDirHDGChoices ) / sizeof( wxString );
	m_choice_variationDirHDG = new wxChoice( sbSizer_HDG->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_variationDirHDGNChoices, m_choice_variationDirHDGChoices, 0 );
	m_choice_variationDirHDG->SetSelection( 1 );
	fgSizer412->Add( m_choice_variationDirHDG, 0, wxALL, 5 );


	sbSizer_HDG->Add( fgSizer412, 1, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_HDG, 1, wxEXPAND, 5 );

	sbSizer_MTW = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("MTW") ), wxHORIZONTAL );

	wxBoxSizer* bSizer17111;
	bSizer17111 = new wxBoxSizer( wxVERTICAL );

	m_button_sendMTW = new wxButton( sbSizer_MTW->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendMTW->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer17111->Add( m_button_sendMTW, 0, wxALL, 5 );

	m_checkBox_autoSendMTW = new wxCheckBox( sbSizer_MTW->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_autoSendMTW->SetValue(true);
	bSizer17111->Add( m_checkBox_autoSendMTW, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_MTW->Add( bSizer17111, 0, wxEXPAND, 5 );

	m_staticline6111 = new wxStaticLine( sbSizer_MTW->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	sbSizer_MTW->Add( m_staticline6111, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer411;
	fgSizer411 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer411->SetFlexibleDirection( wxBOTH );
	fgSizer411->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText35111 = new wxStaticText( sbSizer_MTW->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35111->Wrap( -1 );
	fgSizer411->Add( m_staticText35111, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer411->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText36111 = new wxStaticText( sbSizer_MTW->GetStaticBox(), wxID_ANY, _("Temperature"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText36111->Wrap( -1 );
	fgSizer411->Add( m_staticText36111, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer411->Add( 0, 0, 1, wxEXPAND, 5 );

	m_textCtrl_talkerMTW = new wxTextCtrl( sbSizer_MTW->GetStaticBox(), wxID_ANY, _("IN"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer411->Add( m_textCtrl_talkerMTW, 0, wxALL, 5 );

	m_staticText37111 = new wxStaticText( sbSizer_MTW->GetStaticBox(), wxID_ANY, _("MTW"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText37111->Wrap( -1 );
	fgSizer411->Add( m_staticText37111, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_tempMTW = new wxSpinCtrlDouble( sbSizer_MTW->GetStaticBox(), wxID_ANY, wxT("10"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -10, 100, 10.000000, 5 );
	m_spinCtrlDouble_tempMTW->SetDigits( 1 );
	fgSizer411->Add( m_spinCtrlDouble_tempMTW, 0, wxALL, 5 );

	m_staticText3811 = new wxStaticText( sbSizer_MTW->GetStaticBox(), wxID_ANY, _("C"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3811->Wrap( -1 );
	fgSizer411->Add( m_staticText3811, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_MTW->Add( fgSizer411, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_MTW, 0, wxEXPAND, 5 );

	sbSizer_ROT = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("ROT") ), wxHORIZONTAL );

	wxBoxSizer* bSizer171112;
	bSizer171112 = new wxBoxSizer( wxVERTICAL );

	m_button_sendROT = new wxButton( sbSizer_ROT->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendROT->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer171112->Add( m_button_sendROT, 0, wxALL, 5 );

	m_checkBox_autoSendROT = new wxCheckBox( sbSizer_ROT->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_autoSendROT->SetValue(true);
	bSizer171112->Add( m_checkBox_autoSendROT, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_ROT->Add( bSizer171112, 0, wxEXPAND, 5 );

	m_staticline61112 = new wxStaticLine( sbSizer_ROT->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	sbSizer_ROT->Add( m_staticline61112, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer4112;
	fgSizer4112 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer4112->SetFlexibleDirection( wxBOTH );
	fgSizer4112->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText351112 = new wxStaticText( sbSizer_ROT->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText351112->Wrap( -1 );
	fgSizer4112->Add( m_staticText351112, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer4112->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText361112 = new wxStaticText( sbSizer_ROT->GetStaticBox(), wxID_ANY, _("Rate of turn"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText361112->Wrap( -1 );
	fgSizer4112->Add( m_staticText361112, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText77 = new wxStaticText( sbSizer_ROT->GetStaticBox(), wxID_ANY, _("Status"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText77->Wrap( -1 );
	fgSizer4112->Add( m_staticText77, 0, wxALL, 5 );

	m_textCtrl_talkerROT = new wxTextCtrl( sbSizer_ROT->GetStaticBox(), wxID_ANY, _("HE"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer4112->Add( m_textCtrl_talkerROT, 0, wxALL, 5 );

	m_staticText371112 = new wxStaticText( sbSizer_ROT->GetStaticBox(), wxID_ANY, _("ROT"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText371112->Wrap( -1 );
	fgSizer4112->Add( m_staticText371112, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_rateROT = new wxSpinCtrlDouble( sbSizer_ROT->GetStaticBox(), wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -360, 360, 5, 5 );
	m_spinCtrlDouble_rateROT->SetDigits( 1 );
	fgSizer4112->Add( m_spinCtrlDouble_rateROT, 0, wxALL, 5 );

	wxString m_choice_statusROTChoices[] = { _("A"), _("V") };
	int m_choice_statusROTNChoices = sizeof( m_choice_statusROTChoices ) / sizeof( wxString );
	m_choice_statusROT = new wxChoice( sbSizer_ROT->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_statusROTNChoices, m_choice_statusROTChoices, 0 );
	m_choice_statusROT->SetSelection( 0 );
	fgSizer4112->Add( m_choice_statusROT, 0, wxALL, 5 );


	sbSizer_ROT->Add( fgSizer4112, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_ROT, 0, wxEXPAND, 5 );

	sbSizer_RSA = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("RSA") ), wxHORIZONTAL );

	wxBoxSizer* bSizer1711121;
	bSizer1711121 = new wxBoxSizer( wxVERTICAL );

	m_button_sendRSA = new wxButton( sbSizer_RSA->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendRSA->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer1711121->Add( m_button_sendRSA, 0, wxALL, 5 );

	m_checkBox_autoSendRSA = new wxCheckBox( sbSizer_RSA->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_autoSendRSA->SetValue(true);
	bSizer1711121->Add( m_checkBox_autoSendRSA, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_RSA->Add( bSizer1711121, 0, wxEXPAND, 5 );

	m_staticline611121 = new wxStaticLine( sbSizer_RSA->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	sbSizer_RSA->Add( m_staticline611121, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer41121;
	fgSizer41121 = new wxFlexGridSizer( 2, 6, 0, 0 );
	fgSizer41121->SetFlexibleDirection( wxBOTH );
	fgSizer41121->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText3511121 = new wxStaticText( sbSizer_RSA->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3511121->Wrap( -1 );
	fgSizer41121->Add( m_staticText3511121, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer41121->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText3611121 = new wxStaticText( sbSizer_RSA->GetStaticBox(), wxID_ANY, _("Starboard"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3611121->Wrap( -1 );
	fgSizer41121->Add( m_staticText3611121, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText771 = new wxStaticText( sbSizer_RSA->GetStaticBox(), wxID_ANY, _("Status"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText771->Wrap( -1 );
	fgSizer41121->Add( m_staticText771, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText86 = new wxStaticText( sbSizer_RSA->GetStaticBox(), wxID_ANY, _("Port"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText86->Wrap( -1 );
	fgSizer41121->Add( m_staticText86, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText87 = new wxStaticText( sbSizer_RSA->GetStaticBox(), wxID_ANY, _("Status"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText87->Wrap( -1 );
	fgSizer41121->Add( m_staticText87, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_talkerRSA = new wxTextCtrl( sbSizer_RSA->GetStaticBox(), wxID_ANY, _("GP"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer41121->Add( m_textCtrl_talkerRSA, 0, wxALL, 5 );

	m_staticText3711121 = new wxStaticText( sbSizer_RSA->GetStaticBox(), wxID_ANY, _("RSA"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3711121->Wrap( -1 );
	fgSizer41121->Add( m_staticText3711121, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_starboardRSA = new wxSpinCtrlDouble( sbSizer_RSA->GetStaticBox(), wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -360, 360, 5, 15 );
	m_spinCtrlDouble_starboardRSA->SetDigits( 1 );
	fgSizer41121->Add( m_spinCtrlDouble_starboardRSA, 0, wxALL, 5 );

	wxString m_choice_starboardStatusRSAChoices[] = { _("A"), _("V") };
	int m_choice_starboardStatusRSANChoices = sizeof( m_choice_starboardStatusRSAChoices ) / sizeof( wxString );
	m_choice_starboardStatusRSA = new wxChoice( sbSizer_RSA->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_starboardStatusRSANChoices, m_choice_starboardStatusRSAChoices, 0 );
	m_choice_starboardStatusRSA->SetSelection( 0 );
	fgSizer41121->Add( m_choice_starboardStatusRSA, 0, wxALL, 5 );

	m_spinCtrlDouble_portRSA = new wxSpinCtrlDouble( sbSizer_RSA->GetStaticBox(), wxID_ANY, wxT("10"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -360, 360, 10, 15 );
	m_spinCtrlDouble_portRSA->SetDigits( 1 );
	fgSizer41121->Add( m_spinCtrlDouble_portRSA, 0, wxALL, 5 );

	wxString m_choice_statusPortRSAChoices[] = { _("A"), _("V") };
	int m_choice_statusPortRSANChoices = sizeof( m_choice_statusPortRSAChoices ) / sizeof( wxString );
	m_choice_statusPortRSA = new wxChoice( sbSizer_RSA->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_statusPortRSANChoices, m_choice_statusPortRSAChoices, 0 );
	m_choice_statusPortRSA->SetSelection( 0 );
	fgSizer41121->Add( m_choice_statusPortRSA, 0, wxALL, 5 );


	sbSizer_RSA->Add( fgSizer41121, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_RSA, 0, wxEXPAND, 5 );

	sbSizer_DPT = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("DPT") ), wxHORIZONTAL );

	wxBoxSizer* bSizer171113;
	bSizer171113 = new wxBoxSizer( wxVERTICAL );

	m_button_sendDPT = new wxButton( sbSizer_DPT->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendDPT->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer171113->Add( m_button_sendDPT, 0, wxALL, 5 );

	m_checkBox_autoSendDPT = new wxCheckBox( sbSizer_DPT->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_autoSendDPT->SetValue(true);
	bSizer171113->Add( m_checkBox_autoSendDPT, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_DPT->Add( bSizer171113, 0, wxEXPAND, 5 );

	m_staticline61113 = new wxStaticLine( sbSizer_DPT->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	sbSizer_DPT->Add( m_staticline61113, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer4113;
	fgSizer4113 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer4113->SetFlexibleDirection( wxBOTH );
	fgSizer4113->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText351113 = new wxStaticText( sbSizer_DPT->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText351113->Wrap( -1 );
	fgSizer4113->Add( m_staticText351113, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer4113->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText361113 = new wxStaticText( sbSizer_DPT->GetStaticBox(), wxID_ANY, _("Depth"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText361113->Wrap( -1 );
	fgSizer4113->Add( m_staticText361113, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText106 = new wxStaticText( sbSizer_DPT->GetStaticBox(), wxID_ANY, _("Offset"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText106->Wrap( -1 );
	fgSizer4113->Add( m_staticText106, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_talkerDPT = new wxTextCtrl( sbSizer_DPT->GetStaticBox(), wxID_ANY, _("IN"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer4113->Add( m_textCtrl_talkerDPT, 0, wxALL, 5 );

	m_staticText371113 = new wxStaticText( sbSizer_DPT->GetStaticBox(), wxID_ANY, _("DPT"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText371113->Wrap( -1 );
	fgSizer4113->Add( m_staticText371113, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_depthDPT = new wxSpinCtrlDouble( sbSizer_DPT->GetStaticBox(), wxID_ANY, wxT("10"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 2000, 80.000000, 5 );
	m_spinCtrlDouble_depthDPT->SetDigits( 1 );
	fgSizer4113->Add( m_spinCtrlDouble_depthDPT, 0, wxALL, 5 );

	m_spinCtrlDouble_offsetDPT = new wxSpinCtrlDouble( sbSizer_DPT->GetStaticBox(), wxID_ANY, wxT("2"), wxDefaultPosition, wxSize( -1,-1 ), wxSP_ARROW_KEYS, -100, 100, 2, 1 );
	m_spinCtrlDouble_offsetDPT->SetDigits( 1 );
	fgSizer4113->Add( m_spinCtrlDouble_offsetDPT, 0, wxALL, 5 );


	sbSizer_DPT->Add( fgSizer4113, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_DPT, 1, wxEXPAND, 5 );

	sbSizer_DBx = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("DBT/S/K") ), wxHORIZONTAL );

	wxBoxSizer* bSizer1711131;
	bSizer1711131 = new wxBoxSizer( wxVERTICAL );

	m_button_sendDBx = new wxButton( sbSizer_DBx->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendDBx->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer1711131->Add( m_button_sendDBx, 0, wxALL, 5 );

	m_checkBox_autoSendDBx = new wxCheckBox( sbSizer_DBx->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_autoSendDBx->SetValue(true);
	bSizer1711131->Add( m_checkBox_autoSendDBx, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_DBx->Add( bSizer1711131, 0, wxEXPAND, 5 );

	m_staticline611131 = new wxStaticLine( sbSizer_DBx->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	sbSizer_DBx->Add( m_staticline611131, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer41131;
	fgSizer41131 = new wxFlexGridSizer( 2, 8, 0, 0 );
	fgSizer41131->SetFlexibleDirection( wxBOTH );
	fgSizer41131->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText3511131 = new wxStaticText( sbSizer_DBx->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3511131->Wrap( -1 );
	fgSizer41131->Add( m_staticText3511131, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer41131->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText3611131 = new wxStaticText( sbSizer_DBx->GetStaticBox(), wxID_ANY, _("Depth"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3611131->Wrap( -1 );
	fgSizer41131->Add( m_staticText3611131, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer41131->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText1061 = new wxStaticText( sbSizer_DBx->GetStaticBox(), wxID_ANY, _("Depth"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1061->Wrap( -1 );
	fgSizer41131->Add( m_staticText1061, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer41131->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText115 = new wxStaticText( sbSizer_DBx->GetStaticBox(), wxID_ANY, _("Depth"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText115->Wrap( -1 );
	fgSizer41131->Add( m_staticText115, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer41131->Add( 0, 0, 1, wxEXPAND, 5 );

	m_textCtrl_talkerDBx = new wxTextCtrl( sbSizer_DBx->GetStaticBox(), wxID_ANY, _("IN"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer41131->Add( m_textCtrl_talkerDBx, 0, wxALL, 5 );

	wxString m_choice_sentenceDBxChoices[] = { _("DBT"), _("DBS"), _("DBK") };
	int m_choice_sentenceDBxNChoices = sizeof( m_choice_sentenceDBxChoices ) / sizeof( wxString );
	m_choice_sentenceDBx = new wxChoice( sbSizer_DBx->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_sentenceDBxNChoices, m_choice_sentenceDBxChoices, 0 );
	m_choice_sentenceDBx->SetSelection( 0 );
	fgSizer41131->Add( m_choice_sentenceDBx, 0, wxALL, 5 );

	m_spinCtrlDouble_depthFeetDBx = new wxSpinCtrlDouble( sbSizer_DBx->GetStaticBox(), wxID_ANY, wxT("32.8"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 2000, 32.8, 10 );
	m_spinCtrlDouble_depthFeetDBx->SetDigits( 1 );
	fgSizer41131->Add( m_spinCtrlDouble_depthFeetDBx, 0, wxALL, 5 );

	m_staticText116 = new wxStaticText( sbSizer_DBx->GetStaticBox(), wxID_ANY, _("f"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText116->Wrap( -1 );
	fgSizer41131->Add( m_staticText116, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_depthMeterDBx = new wxSpinCtrlDouble( sbSizer_DBx->GetStaticBox(), wxID_ANY, wxT("10"), wxDefaultPosition, wxSize( -1,-1 ), wxSP_ARROW_KEYS, 0, 2000, 10, 10 );
	m_spinCtrlDouble_depthMeterDBx->SetDigits( 1 );
	fgSizer41131->Add( m_spinCtrlDouble_depthMeterDBx, 0, wxALL, 5 );

	m_staticText117 = new wxStaticText( sbSizer_DBx->GetStaticBox(), wxID_ANY, _("M"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText117->Wrap( -1 );
	fgSizer41131->Add( m_staticText117, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_depthFathomDBx = new wxSpinCtrlDouble( sbSizer_DBx->GetStaticBox(), wxID_ANY, wxT("5.5"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 2000, 5.5, 10 );
	m_spinCtrlDouble_depthFathomDBx->SetDigits( 1 );
	fgSizer41131->Add( m_spinCtrlDouble_depthFathomDBx, 0, wxALL, 5 );

	m_staticText118 = new wxStaticText( sbSizer_DBx->GetStaticBox(), wxID_ANY, _("F"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText118->Wrap( -1 );
	fgSizer41131->Add( m_staticText118, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_DBx->Add( fgSizer41131, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_DBx, 1, wxEXPAND, 5 );


	m_scrolledWindow_sentenceBuilder->SetSizer( bSizer_NmeaList );
	m_scrolledWindow_sentenceBuilder->Layout();
	bSizer_NmeaList->Fit( m_scrolledWindow_sentenceBuilder );
	bSizer9->Add( m_scrolledWindow_sentenceBuilder, 1, wxEXPAND | wxALL, 5 );

	m_staticline3 = new wxStaticLine( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer9->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );


	bSizer12->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );

	m_button_checkAllBuilder = new wxButton( m_panel2, wxID_ANY, _("Check all"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_button_checkAllBuilder, 0, wxALL, 5 );

	m_button_uncheckAllBuilder = new wxButton( m_panel2, wxID_ANY, _("Uncheck all"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_button_uncheckAllBuilder, 0, wxALL, 5 );


	bSizer12->Add( bSizer16, 1, wxEXPAND, 5 );


	bSizer12->Add( 0, 0, 1, wxEXPAND, 5 );

	m_searchCtrl_sentencesBuilder = new wxSearchCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifndef __WXMAC__
	m_searchCtrl_sentencesBuilder->ShowSearchButton( true );
	#endif
	m_searchCtrl_sentencesBuilder->ShowCancelButton( true );
	bSizer12->Add( m_searchCtrl_sentencesBuilder, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer12->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );

	m_checkBox_automaticSendBuilder = new wxCheckBox( m_panel2, wxID_ANY, _("Automatic send at"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_checkBox_automaticSendBuilder, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_autoSendFreqBuilder = new wxSpinCtrlDouble( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0.1, 10, 1, 0.25 );
	m_spinCtrlDouble_autoSendFreqBuilder->SetDigits( 1 );
	bSizer17->Add( m_spinCtrlDouble_autoSendFreqBuilder, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText20 = new wxStaticText( m_panel2, wxID_ANY, _("Hz"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer17->Add( m_staticText20, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer12->Add( bSizer17, 1, wxEXPAND, 5 );


	bSizer12->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_sentenceBuilderHelp = new wxButton( m_panel2, wxID_ANY, _("Help"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_button_sentenceBuilderHelp, 0, wxALIGN_CENTER|wxALL, 5 );


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
	m_button_sendRMC->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendRMC ), NULL, this );
	m_button_sendGGA->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendGGA ), NULL, this );
	m_button_sendTLL->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendTLL ), NULL, this );
	m_button_sendGLL->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendGLL ), NULL, this );
	m_button_sendHDT->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendHDT ), NULL, this );
	m_button_sendHDM->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendHDM ), NULL, this );
	m_button_sendHDG->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendHDG ), NULL, this );
	m_button_sendMTW->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendMTW ), NULL, this );
	m_button_sendROT->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendROT ), NULL, this );
	m_button_sendRSA->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendRSA ), NULL, this );
	m_button_sendDPT->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendDPT ), NULL, this );
	m_button_sendDBx->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendDBx ), NULL, this );
	m_button_checkAllBuilder->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_CheckAllBuilder ), NULL, this );
	m_button_uncheckAllBuilder->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_UncheckAllBuilder ), NULL, this );
	m_searchCtrl_sentencesBuilder->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyDialog::OnText_SearchSentenceBuilder ), NULL, this );
	m_checkBox_automaticSendBuilder->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyDialog::OnCheckBox_AutomaticSendBuilder ), NULL, this );
	m_spinCtrlDouble_autoSendFreqBuilder->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( MyDialog::OnSpinCtrlDouble_AutomaticSendFreqBuilder ), NULL, this );
	m_button_sentenceBuilderHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_OpenSentenceBuilderHelp ), NULL, this );
}

MyDialog::~MyDialog()
{
}
