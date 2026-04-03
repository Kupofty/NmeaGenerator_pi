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

	m_staticText13 = new wxStaticText( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	fgSizer_RMC->Add( m_staticText13, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_RMC->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText141 = new wxStaticText( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("UTC time\n(hhmmss:ss)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText141->Wrap( -1 );
	fgSizer_RMC->Add( m_staticText141, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText151 = new wxStaticText( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("Status"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText151->Wrap( -1 );
	fgSizer_RMC->Add( m_staticText151, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText16 = new wxStaticText( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("Latitude"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	fgSizer_RMC->Add( m_staticText16, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_RMC->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText181 = new wxStaticText( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("Longitude\n(dddmm.mm)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText181->Wrap( -1 );
	fgSizer_RMC->Add( m_staticText181, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_RMC->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText201 = new wxStaticText( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("SOG\n(knots)"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText201->Wrap( -1 );
	fgSizer_RMC->Add( m_staticText201, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText26 = new wxStaticText( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("COG\n(degrees)"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText26->Wrap( -1 );
	fgSizer_RMC->Add( m_staticText26, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText27 = new wxStaticText( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("Date\n(ddmmyy)"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText27->Wrap( -1 );
	fgSizer_RMC->Add( m_staticText27, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText28 = new wxStaticText( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("Mag var.\n(degrees)"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText28->Wrap( -1 );
	fgSizer_RMC->Add( m_staticText28, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_RMC->Add( 0, 0, 1, wxEXPAND, 5 );

	m_textCtrl_idRMC = new wxTextCtrl( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("GP"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_idRMC->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_idRMC->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_idRMC->SetMaxLength( 2 );
	#endif
	fgSizer_RMC->Add( m_textCtrl_idRMC, 0, wxALL, 5 );

	m_staticText22 = new wxStaticText( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("RMC"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	fgSizer_RMC->Add( m_staticText22, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_timeRMC = new wxTextCtrl( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("000000:00"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
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

	m_spinCtrlDouble_sogRMC = new wxSpinCtrlDouble( sbSizer_RMC->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 999.9, 0, 1 );
	m_spinCtrlDouble_sogRMC->SetDigits( 1 );
	fgSizer_RMC->Add( m_spinCtrlDouble_sogRMC, 0, wxALL, 5 );

	m_spinCtrlDouble_cogRMC = new wxSpinCtrlDouble( sbSizer_RMC->GetStaticBox(), wxID_ANY, wxT("0.0"), wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 360, 0, 1 );
	m_spinCtrlDouble_cogRMC->SetDigits( 1 );
	fgSizer_RMC->Add( m_spinCtrlDouble_cogRMC, 0, wxALL, 5 );

	m_textCtrl_dateRMC = new wxTextCtrl( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("010180"), wxDefaultPosition, wxSize( 55,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_dateRMC->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_dateRMC->SetMaxLength( 6 );
	}
	#else
	m_textCtrl_dateRMC->SetMaxLength( 6 );
	#endif
	fgSizer_RMC->Add( m_textCtrl_dateRMC, 0, wxALL, 5 );

	m_spinCtrlDouble_magRMC = new wxSpinCtrlDouble( sbSizer_RMC->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 180, 0.000000, 1 );
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

	m_staticText29 = new wxStaticText( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	fgSizer_GGA->Add( m_staticText29, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_GGA->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText30 = new wxStaticText( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("UTC time\n(hhmmss:ss)"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
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

	m_staticText33 = new wxStaticText( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("GPS\nquality"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText33->Wrap( -1 );
	fgSizer_GGA->Add( m_staticText33, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText34 = new wxStaticText( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("Satellites\nin view"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText34->Wrap( -1 );
	fgSizer_GGA->Add( m_staticText34, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText35 = new wxStaticText( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("HDOP"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35->Wrap( -1 );
	fgSizer_GGA->Add( m_staticText35, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText36 = new wxStaticText( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("Altitude"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText36->Wrap( -1 );
	fgSizer_GGA->Add( m_staticText36, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_GGA->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText37 = new wxStaticText( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("Geoid\nseparation"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText37->Wrap( -1 );
	fgSizer_GGA->Add( m_staticText37, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_GGA->Add( 0, 0, 1, wxEXPAND, 5 );

	m_textCtrl_idGGA = new wxTextCtrl( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("GP"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_idGGA->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_idGGA->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_idGGA->SetMaxLength( 2 );
	#endif
	fgSizer_GGA->Add( m_textCtrl_idGGA, 0, wxALL, 5 );

	m_staticText40 = new wxStaticText( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("GGA"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText40->Wrap( -1 );
	fgSizer_GGA->Add( m_staticText40, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_timeGGA = new wxTextCtrl( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("000000:00"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
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

	m_spinCtrl_gpsQualityGGA = new wxSpinCtrl( sbSizer_GGA->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 6, 1 );
	fgSizer_GGA->Add( m_spinCtrl_gpsQualityGGA, 0, wxALL, 5 );

	m_spinCtrl_satellitesGGA = new wxSpinCtrl( sbSizer_GGA->GetStaticBox(), wxID_ANY, wxT("12"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 99, 12 );
	fgSizer_GGA->Add( m_spinCtrl_satellitesGGA, 0, wxALL, 5 );

	m_spinCtrlDouble_hdopGGA = new wxSpinCtrlDouble( sbSizer_GGA->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 100, 0, 1 );
	m_spinCtrlDouble_hdopGGA->SetDigits( 1 );
	fgSizer_GGA->Add( m_spinCtrlDouble_hdopGGA, 0, wxALL, 5 );

	m_spinCtrlDouble_altitude_GGA = new wxSpinCtrlDouble( sbSizer_GGA->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 100, 0, 1 );
	m_spinCtrlDouble_altitude_GGA->SetDigits( 1 );
	fgSizer_GGA->Add( m_spinCtrlDouble_altitude_GGA, 0, wxALL, 5 );

	m_staticText411 = new wxStaticText( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("M"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText411->Wrap( -1 );
	fgSizer_GGA->Add( m_staticText411, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_geoidSeparationGGA = new wxSpinCtrlDouble( sbSizer_GGA->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 100, 0, 1 );
	m_spinCtrlDouble_geoidSeparationGGA->SetDigits( 1 );
	fgSizer_GGA->Add( m_spinCtrlDouble_geoidSeparationGGA, 0, wxALL, 5 );

	m_staticText42 = new wxStaticText( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("M,,"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText42->Wrap( -1 );
	fgSizer_GGA->Add( m_staticText42, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_GGA->Add( fgSizer_GGA, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_GGA, 0, wxEXPAND, 5 );

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

	m_staticText19 = new wxStaticText( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	fgSizer_GLL->Add( m_staticText19, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_GLL->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText9 = new wxStaticText( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("Latitude\n(ddmm.mm)"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText9->Wrap( -1 );
	m_staticText9->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	fgSizer_GLL->Add( m_staticText9, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_GLL->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText11 = new wxStaticText( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("Longitude\n(dddmm.mm)"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText11->Wrap( -1 );
	fgSizer_GLL->Add( m_staticText11, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_GLL->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText14 = new wxStaticText( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("UTC time\n(hhmmss:ss)"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText14->Wrap( -1 );
	fgSizer_GLL->Add( m_staticText14, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText15 = new wxStaticText( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("Status"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	fgSizer_GLL->Add( m_staticText15, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText18 = new wxStaticText( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("Mode"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	fgSizer_GLL->Add( m_staticText18, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_idGLL = new wxTextCtrl( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("GP"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_idGLL->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_idGLL->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_idGLL->SetMaxLength( 2 );
	#endif
	fgSizer_GLL->Add( m_textCtrl_idGLL, 0, wxALL, 5 );

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
	m_choice_lonDirGLL->SetSelection( 0 );
	fgSizer_GLL->Add( m_choice_lonDirGLL, 0, wxALL, 5 );

	m_textCtrl_timeGLL = new wxTextCtrl( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("000000:00"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
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


	m_scrolledWindow_sentenceBuilder->SetSizer( bSizer_NmeaList );
	m_scrolledWindow_sentenceBuilder->Layout();
	bSizer_NmeaList->Fit( m_scrolledWindow_sentenceBuilder );
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

	m_searchCtrl_sentencesBuilder = new wxSearchCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifndef __WXMAC__
	m_searchCtrl_sentencesBuilder->ShowSearchButton( true );
	#endif
	m_searchCtrl_sentencesBuilder->ShowCancelButton( true );
	bSizer12->Add( m_searchCtrl_sentencesBuilder, 0, wxALL, 5 );


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
	m_button_sendRMC->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendRMC ), NULL, this );
	m_button_sendGGA->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendGGA ), NULL, this );
	m_button_sendGLL->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendGLL ), NULL, this );
	m_button_checkAllBuilder->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_CheckAllBuilder ), NULL, this );
	m_button_uncheckAllBuilder->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_UncheckAllBuilder ), NULL, this );
	m_searchCtrl_sentencesBuilder->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyDialog::OnText_SearchSentenceBuilder ), NULL, this );
	m_checkBox_automaticSendBuilder->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyDialog::OnCheckBox_AutomaticSendBuilder ), NULL, this );
	m_spinCtrlDouble_autoSendFreqBuilder->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( MyDialog::OnSpinCtrlDouble_AutomaticSendFreqBuilder ), NULL, this );
}

MyDialog::~MyDialog()
{
}
