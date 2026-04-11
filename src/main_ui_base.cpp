///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6-dirty)
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
	m_timer_autoSendSim.SetOwner( this, m_timer_autoSendSim.GetId() );
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

	m_spinCtrlDouble_automaticSendFreq = new wxSpinCtrlDouble( m_panel_manual, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxSP_ARROW_KEYS, 0.1, 10, 1, 0.2 );
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
	m_panel_list = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	m_scrolledWindow_sentenceBuilder = new wxScrolledWindow( m_panel_list, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow_sentenceBuilder->SetScrollRate( 5, 5 );
	bSizer_NmeaList = new wxBoxSizer( wxVERTICAL );

	sbSizer_DBx = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("DBT/S/K") ), wxHORIZONTAL );

	wxBoxSizer* bSizer1711131;
	bSizer1711131 = new wxBoxSizer( wxVERTICAL );

	m_button_sendDBx = new wxButton( sbSizer_DBx->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendDBx->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer1711131->Add( m_button_sendDBx, 0, wxALL, 5 );

	m_checkBox_autoSendDBx = new wxCheckBox( sbSizer_DBx->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
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

	m_textCtrl_talkerDBx = new wxTextCtrl( sbSizer_DBx->GetStaticBox(), wxID_ANY, _("SD"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerDBx->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerDBx->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerDBx->SetMaxLength( 2 );
	#endif
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


	bSizer_NmeaList->Add( sbSizer_DBx, 0, wxEXPAND, 5 );

	sbSizer_DPT = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("DPT") ), wxHORIZONTAL );

	wxBoxSizer* bSizer171113;
	bSizer171113 = new wxBoxSizer( wxVERTICAL );

	m_button_sendDPT = new wxButton( sbSizer_DPT->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendDPT->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer171113->Add( m_button_sendDPT, 0, wxALL, 5 );

	m_checkBox_autoSendDPT = new wxCheckBox( sbSizer_DPT->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
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

	m_textCtrl_talkerDPT = new wxTextCtrl( sbSizer_DPT->GetStaticBox(), wxID_ANY, _("SD"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerDPT->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerDPT->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerDPT->SetMaxLength( 2 );
	#endif
	fgSizer4113->Add( m_textCtrl_talkerDPT, 0, wxALL, 5 );

	m_staticText371113 = new wxStaticText( sbSizer_DPT->GetStaticBox(), wxID_ANY, _("DPT"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText371113->Wrap( -1 );
	fgSizer4113->Add( m_staticText371113, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_depthDPT = new wxSpinCtrlDouble( sbSizer_DPT->GetStaticBox(), wxID_ANY, wxT("10"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 2000, 5.000000, 5 );
	m_spinCtrlDouble_depthDPT->SetDigits( 1 );
	fgSizer4113->Add( m_spinCtrlDouble_depthDPT, 0, wxALL, 5 );

	m_spinCtrlDouble_offsetDPT = new wxSpinCtrlDouble( sbSizer_DPT->GetStaticBox(), wxID_ANY, wxT("2"), wxDefaultPosition, wxSize( -1,-1 ), wxSP_ARROW_KEYS, -100, 100, 2, 1 );
	m_spinCtrlDouble_offsetDPT->SetDigits( 1 );
	fgSizer4113->Add( m_spinCtrlDouble_offsetDPT, 0, wxALL, 5 );


	sbSizer_DPT->Add( fgSizer4113, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_DPT, 0, wxEXPAND, 5 );

	sbSizer_GGA = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("GGA") ), wxHORIZONTAL );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );


	bSizer15->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_sendGGA = new wxButton( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendGGA->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer15->Add( m_button_sendGGA, 0, wxALL, 5 );

	m_checkBox_autoSendGGA = new wxCheckBox( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
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

	m_textCtrl_talkerGGA = new wxTextCtrl( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("GP"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
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

	m_textCtrl_timeGGA = new wxTextCtrl( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("120000"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
	fgSizer_GGA->Add( m_textCtrl_timeGGA, 0, wxALL, 5 );

	m_textCtrl_latitudeGGA = new wxTextCtrl( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("0000.0000000"), wxDefaultPosition, wxSize( 95,-1 ), 0 );
	fgSizer_GGA->Add( m_textCtrl_latitudeGGA, 0, wxALL, 5 );

	wxString m_choice_latDirGGAChoices[] = { _("N"), _("S") };
	int m_choice_latDirGGANChoices = sizeof( m_choice_latDirGGAChoices ) / sizeof( wxString );
	m_choice_latDirGGA = new wxChoice( sbSizer_GGA->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_latDirGGANChoices, m_choice_latDirGGAChoices, 0 );
	m_choice_latDirGGA->SetSelection( 0 );
	fgSizer_GGA->Add( m_choice_latDirGGA, 0, wxALL, 5 );

	m_textCtrl_longitudeGGA = new wxTextCtrl( sbSizer_GGA->GetStaticBox(), wxID_ANY, _("00000.0000000"), wxDefaultPosition, wxSize( 95,-1 ), 0 );
	fgSizer_GGA->Add( m_textCtrl_longitudeGGA, 0, wxALL, 5 );

	wxString m_choice_lonDirGGAChoices[] = { _("E"), _("W") };
	int m_choice_lonDirGGANChoices = sizeof( m_choice_lonDirGGAChoices ) / sizeof( wxString );
	m_choice_lonDirGGA = new wxChoice( sbSizer_GGA->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_lonDirGGANChoices, m_choice_lonDirGGAChoices, 0 );
	m_choice_lonDirGGA->SetSelection( 0 );
	fgSizer_GGA->Add( m_choice_lonDirGGA, 0, wxALL, 5 );

	m_spinCtrl_gpsQualityGGA = new wxSpinCtrl( sbSizer_GGA->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 6, 1 );
	fgSizer_GGA->Add( m_spinCtrl_gpsQualityGGA, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrl_satellitesGGA = new wxSpinCtrl( sbSizer_GGA->GetStaticBox(), wxID_ANY, wxT("12"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 99, 11 );
	fgSizer_GGA->Add( m_spinCtrl_satellitesGGA, 0, wxALL, 5 );

	m_spinCtrlDouble_hdopGGA = new wxSpinCtrlDouble( sbSizer_GGA->GetStaticBox(), wxID_ANY, wxT("1"), wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 100, 1.000000, 0.5 );
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

	sbSizer_GLL = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("GLL") ), wxHORIZONTAL );

	wxBoxSizer* bSizer121;
	bSizer121 = new wxBoxSizer( wxVERTICAL );


	bSizer121->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_sendGLL = new wxButton( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendGLL->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer121->Add( m_button_sendGLL, 0, wxALL, 5 );

	m_checkBox_autoSendGLL = new wxCheckBox( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
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

	m_textCtrl_talkerGLL = new wxTextCtrl( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("GP"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
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

	m_textCtrl_latitudeGLL = new wxTextCtrl( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("0000.0000000"), wxDefaultPosition, wxSize( 95,-1 ), 0 );
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

	m_textCtrl_longitudeGLL = new wxTextCtrl( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("00000.0000000"), wxDefaultPosition, wxSize( 95,-1 ), 0 );
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

	m_textCtrl_timeGLL = new wxTextCtrl( sbSizer_GLL->GetStaticBox(), wxID_ANY, _("120000"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
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

	sbSizer_GSV = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("GSV") ), wxHORIZONTAL );

	wxBoxSizer* bSizer1213;
	bSizer1213 = new wxBoxSizer( wxVERTICAL );


	bSizer1213->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_sendGSV = new wxButton( sbSizer_GSV->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendGSV->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer1213->Add( m_button_sendGSV, 0, wxALL, 5 );

	m_checkBox_autoSendGSV = new wxCheckBox( sbSizer_GSV->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1213->Add( m_checkBox_autoSendGSV, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer1213->Add( 0, 0, 1, wxEXPAND, 5 );


	sbSizer_GSV->Add( bSizer1213, 0, wxEXPAND, 5 );

	m_staticline53 = new wxStaticLine( sbSizer_GSV->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL|wxLI_VERTICAL );
	sbSizer_GSV->Add( m_staticline53, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer_GSV;
	fgSizer_GSV = new wxFlexGridSizer( 2, 9, 0, 0 );
	fgSizer_GSV->SetFlexibleDirection( wxBOTH );
	fgSizer_GSV->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText193 = new wxStaticText( sbSizer_GSV->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText193->Wrap( -1 );
	fgSizer_GSV->Add( m_staticText193, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_GSV->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText910 = new wxStaticText( sbSizer_GSV->GetStaticBox(), wxID_ANY, _("Total sentences"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText910->Wrap( -1 );
	m_staticText910->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	fgSizer_GSV->Add( m_staticText910, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText138 = new wxStaticText( sbSizer_GSV->GetStaticBox(), wxID_ANY, _("Sentence ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText138->Wrap( -1 );
	fgSizer_GSV->Add( m_staticText138, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText113 = new wxStaticText( sbSizer_GSV->GetStaticBox(), wxID_ANY, _("Satellites in view"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText113->Wrap( -1 );
	fgSizer_GSV->Add( m_staticText113, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText1391 = new wxStaticText( sbSizer_GSV->GetStaticBox(), wxID_ANY, _("PRN"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1391->Wrap( -1 );
	fgSizer_GSV->Add( m_staticText1391, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText137 = new wxStaticText( sbSizer_GSV->GetStaticBox(), wxID_ANY, _("Elevation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText137->Wrap( -1 );
	fgSizer_GSV->Add( m_staticText137, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText144 = new wxStaticText( sbSizer_GSV->GetStaticBox(), wxID_ANY, _("Azimuth"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText144->Wrap( -1 );
	fgSizer_GSV->Add( m_staticText144, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText152 = new wxStaticText( sbSizer_GSV->GetStaticBox(), wxID_ANY, _("SNR"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText152->Wrap( -1 );
	fgSizer_GSV->Add( m_staticText152, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_talkerGSV = new wxTextCtrl( sbSizer_GSV->GetStaticBox(), wxID_ANY, _("GP"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerGSV->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerGSV->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerGSV->SetMaxLength( 2 );
	#endif
	fgSizer_GSV->Add( m_textCtrl_talkerGSV, 0, wxALL, 5 );

	m_staticText53 = new wxStaticText( sbSizer_GSV->GetStaticBox(), wxID_ANY, _("GSV"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText53->Wrap( -1 );
	fgSizer_GSV->Add( m_staticText53, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrl_totalSentencesGSV = new wxSpinCtrl( sbSizer_GSV->GetStaticBox(), wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 1, 1 );
	fgSizer_GSV->Add( m_spinCtrl_totalSentencesGSV, 0, wxALL, 5 );

	m_spinCtrl_sentenceIdGSV = new wxSpinCtrl( sbSizer_GSV->GetStaticBox(), wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 1, 0 );
	fgSizer_GSV->Add( m_spinCtrl_sentenceIdGSV, 0, wxALL, 5 );

	m_spinCtrl_satellitesGSV = new wxSpinCtrl( sbSizer_GSV->GetStaticBox(), wxID_ANY, wxT("12"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 99, 12 );
	fgSizer_GSV->Add( m_spinCtrl_satellitesGSV, 0, wxALL, 5 );

	m_spinCtrl_prnGSV = new wxSpinCtrl( sbSizer_GSV->GetStaticBox(), wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 1 );
	fgSizer_GSV->Add( m_spinCtrl_prnGSV, 0, wxALL, 5 );

	m_spinCtrlDouble_elevationGSV = new wxSpinCtrlDouble( sbSizer_GSV->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -90, 90, 0, 10 );
	m_spinCtrlDouble_elevationGSV->SetDigits( 1 );
	fgSizer_GSV->Add( m_spinCtrlDouble_elevationGSV, 0, wxALL, 5 );

	m_spinCtrlDouble_azimuthGSV = new wxSpinCtrlDouble( sbSizer_GSV->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 360, 0, 45 );
	m_spinCtrlDouble_azimuthGSV->SetDigits( 1 );
	fgSizer_GSV->Add( m_spinCtrlDouble_azimuthGSV, 0, wxALL, 5 );

	m_spinCtrlDouble_snrGSV = new wxSpinCtrlDouble( sbSizer_GSV->GetStaticBox(), wxID_ANY, wxT("70"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 99, 70, 5 );
	m_spinCtrlDouble_snrGSV->SetDigits( 1 );
	fgSizer_GSV->Add( m_spinCtrlDouble_snrGSV, 0, wxALL, 5 );


	sbSizer_GSV->Add( fgSizer_GSV, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_GSV, 0, wxEXPAND, 5 );

	sbSizer_HDG = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("HDG") ), wxHORIZONTAL );

	wxBoxSizer* bSizer17112;
	bSizer17112 = new wxBoxSizer( wxVERTICAL );

	m_button_sendHDG = new wxButton( sbSizer_HDG->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendHDG->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer17112->Add( m_button_sendHDG, 0, wxALL, 5 );

	m_checkBox_autoSendHDG = new wxCheckBox( sbSizer_HDG->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
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

	m_textCtrl_talkerHDG = new wxTextCtrl( sbSizer_HDG->GetStaticBox(), wxID_ANY, _("HC"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerHDG->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerHDG->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerHDG->SetMaxLength( 2 );
	#endif
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
	m_choice_variationDirHDG->SetSelection( 0 );
	fgSizer412->Add( m_choice_variationDirHDG, 0, wxALL, 5 );


	sbSizer_HDG->Add( fgSizer412, 1, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_HDG, 0, wxEXPAND, 5 );

	sbSizer_HDM = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("HDM") ), wxHORIZONTAL );

	wxBoxSizer* bSizer1711;
	bSizer1711 = new wxBoxSizer( wxVERTICAL );

	m_button_sendHDM = new wxButton( sbSizer_HDM->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendHDM->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer1711->Add( m_button_sendHDM, 0, wxALL, 5 );

	m_checkBox_autoSendHDM = new wxCheckBox( sbSizer_HDM->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
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

	m_textCtrl_talkerHDM = new wxTextCtrl( sbSizer_HDM->GetStaticBox(), wxID_ANY, _("HC"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerHDM->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerHDM->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerHDM->SetMaxLength( 2 );
	#endif
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

	sbSizer_HDT = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("HDT") ), wxHORIZONTAL );

	wxBoxSizer* bSizer171;
	bSizer171 = new wxBoxSizer( wxVERTICAL );

	m_button_sendHDT = new wxButton( sbSizer_HDT->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendHDT->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer171->Add( m_button_sendHDT, 0, wxALL, 5 );

	m_checkBox_autoSendHDT = new wxCheckBox( sbSizer_HDT->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
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

	m_textCtrl_talkerHDT = new wxTextCtrl( sbSizer_HDT->GetStaticBox(), wxID_ANY, _("HC"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerHDT->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerHDT->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerHDT->SetMaxLength( 2 );
	#endif
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

	sbSizer_MTW = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("MTW") ), wxHORIZONTAL );

	wxBoxSizer* bSizer17111;
	bSizer17111 = new wxBoxSizer( wxVERTICAL );

	m_button_sendMTW = new wxButton( sbSizer_MTW->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendMTW->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer17111->Add( m_button_sendMTW, 0, wxALL, 5 );

	m_checkBox_autoSendMTW = new wxCheckBox( sbSizer_MTW->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
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

	m_textCtrl_talkerMTW = new wxTextCtrl( sbSizer_MTW->GetStaticBox(), wxID_ANY, _("WI"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerMTW->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerMTW->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerMTW->SetMaxLength( 2 );
	#endif
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

	sbSizer_MWD = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("MWD") ), wxHORIZONTAL );

	wxBoxSizer* bSizer171112111;
	bSizer171112111 = new wxBoxSizer( wxVERTICAL );

	m_button_sendMWD = new wxButton( sbSizer_MWD->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendMWD->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer171112111->Add( m_button_sendMWD, 0, wxALL, 5 );

	m_checkBox_autoSendMWD = new wxCheckBox( sbSizer_MWD->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer171112111->Add( m_checkBox_autoSendMWD, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_MWD->Add( bSizer171112111, 0, wxEXPAND, 5 );

	m_staticline61112111 = new wxStaticLine( sbSizer_MWD->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	sbSizer_MWD->Add( m_staticline61112111, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer4112111;
	fgSizer4112111 = new wxFlexGridSizer( 2, 10, 0, 0 );
	fgSizer4112111->SetFlexibleDirection( wxBOTH );
	fgSizer4112111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText351112111 = new wxStaticText( sbSizer_MWD->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText351112111->Wrap( -1 );
	fgSizer4112111->Add( m_staticText351112111, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer4112111->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText361112111 = new wxStaticText( sbSizer_MWD->GetStaticBox(), wxID_ANY, _("Direction"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText361112111->Wrap( -1 );
	fgSizer4112111->Add( m_staticText361112111, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer4112111->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText77111 = new wxStaticText( sbSizer_MWD->GetStaticBox(), wxID_ANY, _("Direction"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText77111->Wrap( -1 );
	fgSizer4112111->Add( m_staticText77111, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer4112111->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText8721 = new wxStaticText( sbSizer_MWD->GetStaticBox(), wxID_ANY, _("Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8721->Wrap( -1 );
	fgSizer4112111->Add( m_staticText8721, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer4112111->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText166 = new wxStaticText( sbSizer_MWD->GetStaticBox(), wxID_ANY, _("Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText166->Wrap( -1 );
	fgSizer4112111->Add( m_staticText166, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer4112111->Add( 0, 0, 1, wxEXPAND, 5 );

	m_textCtrl_talkerMWD = new wxTextCtrl( sbSizer_MWD->GetStaticBox(), wxID_ANY, _("WI"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerMWD->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerMWD->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerMWD->SetMaxLength( 2 );
	#endif
	fgSizer4112111->Add( m_textCtrl_talkerMWD, 0, wxALL, 5 );

	m_staticText371112111 = new wxStaticText( sbSizer_MWD->GetStaticBox(), wxID_ANY, _("MWD"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText371112111->Wrap( -1 );
	fgSizer4112111->Add( m_staticText371112111, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_windDirection1MWD = new wxSpinCtrlDouble( sbSizer_MWD->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 360, 0, 15 );
	m_spinCtrlDouble_windDirection1MWD->SetDigits( 1 );
	fgSizer4112111->Add( m_spinCtrlDouble_windDirection1MWD, 0, wxALL, 5 );

	m_staticText1671 = new wxStaticText( sbSizer_MWD->GetStaticBox(), wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1671->Wrap( -1 );
	fgSizer4112111->Add( m_staticText1671, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_windDirection2MWD = new wxSpinCtrlDouble( sbSizer_MWD->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 360, 0, 15 );
	m_spinCtrlDouble_windDirection2MWD->SetDigits( 1 );
	fgSizer4112111->Add( m_spinCtrlDouble_windDirection2MWD, 0, wxALL, 5 );

	m_staticText1681 = new wxStaticText( sbSizer_MWD->GetStaticBox(), wxID_ANY, _("M"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1681->Wrap( -1 );
	fgSizer4112111->Add( m_staticText1681, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_speed1MWD = new wxSpinCtrlDouble( sbSizer_MWD->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0, 5 );
	m_spinCtrlDouble_speed1MWD->SetDigits( 0 );
	fgSizer4112111->Add( m_spinCtrlDouble_speed1MWD, 0, wxALL, 5 );

	m_staticText1691 = new wxStaticText( sbSizer_MWD->GetStaticBox(), wxID_ANY, _("N"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1691->Wrap( -1 );
	fgSizer4112111->Add( m_staticText1691, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_speed2MWD = new wxSpinCtrlDouble( sbSizer_MWD->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0, 5 );
	m_spinCtrlDouble_speed2MWD->SetDigits( 0 );
	fgSizer4112111->Add( m_spinCtrlDouble_speed2MWD, 0, wxALL, 5 );

	m_staticText1701 = new wxStaticText( sbSizer_MWD->GetStaticBox(), wxID_ANY, _("M"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1701->Wrap( -1 );
	fgSizer4112111->Add( m_staticText1701, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_MWD->Add( fgSizer4112111, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_MWD, 0, wxEXPAND, 5 );

	sbSizer_MWV = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("MWV") ), wxHORIZONTAL );

	wxBoxSizer* bSizer17111211;
	bSizer17111211 = new wxBoxSizer( wxVERTICAL );

	m_button_sendMWV = new wxButton( sbSizer_MWV->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendMWV->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer17111211->Add( m_button_sendMWV, 0, wxALL, 5 );

	m_checkBox_autoSendMWV = new wxCheckBox( sbSizer_MWV->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17111211->Add( m_checkBox_autoSendMWV, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_MWV->Add( bSizer17111211, 0, wxEXPAND, 5 );

	m_staticline6111211 = new wxStaticLine( sbSizer_MWV->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	sbSizer_MWV->Add( m_staticline6111211, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer411211;
	fgSizer411211 = new wxFlexGridSizer( 2, 7, 0, 0 );
	fgSizer411211->SetFlexibleDirection( wxBOTH );
	fgSizer411211->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText35111211 = new wxStaticText( sbSizer_MWV->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35111211->Wrap( -1 );
	fgSizer411211->Add( m_staticText35111211, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer411211->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText36111211 = new wxStaticText( sbSizer_MWV->GetStaticBox(), wxID_ANY, _("Angle"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText36111211->Wrap( -1 );
	fgSizer411211->Add( m_staticText36111211, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer411211->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText7711 = new wxStaticText( sbSizer_MWV->GetStaticBox(), wxID_ANY, _("Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7711->Wrap( -1 );
	fgSizer411211->Add( m_staticText7711, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer411211->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText872 = new wxStaticText( sbSizer_MWV->GetStaticBox(), wxID_ANY, _("Status"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText872->Wrap( -1 );
	fgSizer411211->Add( m_staticText872, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_talkerMWV = new wxTextCtrl( sbSizer_MWV->GetStaticBox(), wxID_ANY, _("WI"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerMWV->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerMWV->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerMWV->SetMaxLength( 2 );
	#endif
	fgSizer411211->Add( m_textCtrl_talkerMWV, 0, wxALL, 5 );

	m_staticText37111211 = new wxStaticText( sbSizer_MWV->GetStaticBox(), wxID_ANY, _("MWV"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText37111211->Wrap( -1 );
	fgSizer411211->Add( m_staticText37111211, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_angleMWV = new wxSpinCtrlDouble( sbSizer_MWV->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 360, 0, 15 );
	m_spinCtrlDouble_angleMWV->SetDigits( 1 );
	fgSizer411211->Add( m_spinCtrlDouble_angleMWV, 0, wxALL, 5 );

	wxString m_choice_refMWVChoices[] = { _("R"), _("T") };
	int m_choice_refMWVNChoices = sizeof( m_choice_refMWVChoices ) / sizeof( wxString );
	m_choice_refMWV = new wxChoice( sbSizer_MWV->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_refMWVNChoices, m_choice_refMWVChoices, 0 );
	m_choice_refMWV->SetSelection( 0 );
	fgSizer411211->Add( m_choice_refMWV, 0, wxALL, 5 );

	m_spinCtrlDouble_speedMWV = new wxSpinCtrlDouble( sbSizer_MWV->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0, 5 );
	m_spinCtrlDouble_speedMWV->SetDigits( 1 );
	fgSizer411211->Add( m_spinCtrlDouble_speedMWV, 0, wxALL, 5 );

	wxString m_choice_unitMWVChoices[] = { _("N"), _("K"), _("M") };
	int m_choice_unitMWVNChoices = sizeof( m_choice_unitMWVChoices ) / sizeof( wxString );
	m_choice_unitMWV = new wxChoice( sbSizer_MWV->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_unitMWVNChoices, m_choice_unitMWVChoices, 0 );
	m_choice_unitMWV->SetSelection( 0 );
	fgSizer411211->Add( m_choice_unitMWV, 0, wxALL, 5 );

	wxString m_choice_statusMWVChoices[] = { _("A"), _("V") };
	int m_choice_statusMWVNChoices = sizeof( m_choice_statusMWVChoices ) / sizeof( wxString );
	m_choice_statusMWV = new wxChoice( sbSizer_MWV->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_statusMWVNChoices, m_choice_statusMWVChoices, 0 );
	m_choice_statusMWV->SetSelection( 0 );
	fgSizer411211->Add( m_choice_statusMWV, 0, wxALL, 5 );


	sbSizer_MWV->Add( fgSizer411211, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_MWV, 0, wxEXPAND, 5 );

	sbSizer_OSD = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("OSD") ), wxHORIZONTAL );

	wxBoxSizer* bSizer17111311;
	bSizer17111311 = new wxBoxSizer( wxVERTICAL );

	m_button_sendOSD = new wxButton( sbSizer_OSD->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendOSD->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer17111311->Add( m_button_sendOSD, 0, wxALL, 5 );

	m_checkBox_autoSendOSD = new wxCheckBox( sbSizer_OSD->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17111311->Add( m_checkBox_autoSendOSD, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_OSD->Add( bSizer17111311, 0, wxEXPAND, 5 );

	m_staticline6111311 = new wxStaticLine( sbSizer_OSD->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	sbSizer_OSD->Add( m_staticline6111311, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer411311;
	fgSizer411311 = new wxFlexGridSizer( 2, 11, 0, 0 );
	fgSizer411311->SetFlexibleDirection( wxBOTH );
	fgSizer411311->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText35111311 = new wxStaticText( sbSizer_OSD->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35111311->Wrap( -1 );
	fgSizer411311->Add( m_staticText35111311, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer411311->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText36111311 = new wxStaticText( sbSizer_OSD->GetStaticBox(), wxID_ANY, _("Heading"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText36111311->Wrap( -1 );
	fgSizer411311->Add( m_staticText36111311, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText167 = new wxStaticText( sbSizer_OSD->GetStaticBox(), wxID_ANY, _("Status"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText167->Wrap( -1 );
	fgSizer411311->Add( m_staticText167, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText10611 = new wxStaticText( sbSizer_OSD->GetStaticBox(), wxID_ANY, _("Course"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10611->Wrap( -1 );
	fgSizer411311->Add( m_staticText10611, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText168 = new wxStaticText( sbSizer_OSD->GetStaticBox(), wxID_ANY, _("Reference"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText168->Wrap( -1 );
	fgSizer411311->Add( m_staticText168, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText1151 = new wxStaticText( sbSizer_OSD->GetStaticBox(), wxID_ANY, _("Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1151->Wrap( -1 );
	fgSizer411311->Add( m_staticText1151, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText169 = new wxStaticText( sbSizer_OSD->GetStaticBox(), wxID_ANY, _("Reference"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText169->Wrap( -1 );
	fgSizer411311->Add( m_staticText169, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText170 = new wxStaticText( sbSizer_OSD->GetStaticBox(), wxID_ANY, _("Drift angle"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText170->Wrap( -1 );
	fgSizer411311->Add( m_staticText170, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText171 = new wxStaticText( sbSizer_OSD->GetStaticBox(), wxID_ANY, _("Drift speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText171->Wrap( -1 );
	fgSizer411311->Add( m_staticText171, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText174 = new wxStaticText( sbSizer_OSD->GetStaticBox(), wxID_ANY, _("Speed unit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText174->Wrap( -1 );
	fgSizer411311->Add( m_staticText174, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_talkerOSD = new wxTextCtrl( sbSizer_OSD->GetStaticBox(), wxID_ANY, _("RA"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerOSD->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerOSD->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerOSD->SetMaxLength( 2 );
	#endif
	fgSizer411311->Add( m_textCtrl_talkerOSD, 0, wxALL, 5 );

	m_staticText172 = new wxStaticText( sbSizer_OSD->GetStaticBox(), wxID_ANY, _("OSD"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText172->Wrap( -1 );
	fgSizer411311->Add( m_staticText172, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_headingOSD = new wxSpinCtrlDouble( sbSizer_OSD->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 360, 0, 45 );
	m_spinCtrlDouble_headingOSD->SetDigits( 1 );
	fgSizer411311->Add( m_spinCtrlDouble_headingOSD, 0, wxALL, 5 );

	wxString m_choice_statusOSDChoices[] = { _("A"), _("V") };
	int m_choice_statusOSDNChoices = sizeof( m_choice_statusOSDChoices ) / sizeof( wxString );
	m_choice_statusOSD = new wxChoice( sbSizer_OSD->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_statusOSDNChoices, m_choice_statusOSDChoices, 0 );
	m_choice_statusOSD->SetSelection( 0 );
	fgSizer411311->Add( m_choice_statusOSD, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_courseOSD = new wxSpinCtrlDouble( sbSizer_OSD->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( -1,-1 ), wxSP_ARROW_KEYS, 0, 360, 0, 45 );
	m_spinCtrlDouble_courseOSD->SetDigits( 1 );
	fgSizer411311->Add( m_spinCtrlDouble_courseOSD, 0, wxALL, 5 );

	wxString m_choice_courseRefOSDChoices[] = { _("B"), _("M"), _("W"), _("R"), _("P") };
	int m_choice_courseRefOSDNChoices = sizeof( m_choice_courseRefOSDChoices ) / sizeof( wxString );
	m_choice_courseRefOSD = new wxChoice( sbSizer_OSD->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_courseRefOSDNChoices, m_choice_courseRefOSDChoices, 0 );
	m_choice_courseRefOSD->SetSelection( 1 );
	fgSizer411311->Add( m_choice_courseRefOSD, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_speedOSD = new wxSpinCtrlDouble( sbSizer_OSD->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0, 5 );
	m_spinCtrlDouble_speedOSD->SetDigits( 1 );
	fgSizer411311->Add( m_spinCtrlDouble_speedOSD, 0, wxALL, 5 );

	wxString m_choice_speedRefOSDChoices[] = { _("B"), _("M"), _("W"), _("R"), _("P") };
	int m_choice_speedRefOSDNChoices = sizeof( m_choice_speedRefOSDChoices ) / sizeof( wxString );
	m_choice_speedRefOSD = new wxChoice( sbSizer_OSD->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_speedRefOSDNChoices, m_choice_speedRefOSDChoices, 0 );
	m_choice_speedRefOSD->SetSelection( 1 );
	fgSizer411311->Add( m_choice_speedRefOSD, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_driftAngleOSD = new wxSpinCtrlDouble( sbSizer_OSD->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 360, 0, 45 );
	m_spinCtrlDouble_driftAngleOSD->SetDigits( 1 );
	fgSizer411311->Add( m_spinCtrlDouble_driftAngleOSD, 0, wxALL, 5 );

	m_spinCtrlDouble_driftSpeedOSD = new wxSpinCtrlDouble( sbSizer_OSD->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0, 5 );
	m_spinCtrlDouble_driftSpeedOSD->SetDigits( 1 );
	fgSizer411311->Add( m_spinCtrlDouble_driftSpeedOSD, 0, wxALL, 5 );

	wxString m_choice_speedUnitOSDChoices[] = { _("N"), _("K") };
	int m_choice_speedUnitOSDNChoices = sizeof( m_choice_speedUnitOSDChoices ) / sizeof( wxString );
	m_choice_speedUnitOSD = new wxChoice( sbSizer_OSD->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_speedUnitOSDNChoices, m_choice_speedUnitOSDChoices, 0 );
	m_choice_speedUnitOSD->SetSelection( 0 );
	fgSizer411311->Add( m_choice_speedUnitOSD, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_OSD->Add( fgSizer411311, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_OSD, 0, wxEXPAND, 5 );

	sbSizer_RMC = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("RMC") ), wxHORIZONTAL );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );


	bSizer14->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_sendRMC = new wxButton( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendRMC->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer14->Add( m_button_sendRMC, 0, wxALL, 5 );

	m_checkBox_autoSendRMC = new wxCheckBox( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
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

	m_textCtrl_talkerRMC = new wxTextCtrl( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("GP"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
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

	m_textCtrl_timeRMC = new wxTextCtrl( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("120000"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
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

	m_textCtrl_latitudeRMC = new wxTextCtrl( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("0000.0000000"), wxDefaultPosition, wxSize( 95,-1 ), 0 );
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

	m_textCtrl_longitudeRMC = new wxTextCtrl( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("00000.0000000"), wxDefaultPosition, wxSize( 95,-1 ), 0 );
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

	m_spinCtrlDouble_cogRMC = new wxSpinCtrlDouble( sbSizer_RMC->GetStaticBox(), wxID_ANY, wxT("60"), wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 360, 0.000000, 45 );
	m_spinCtrlDouble_cogRMC->SetDigits( 1 );
	fgSizer_RMC->Add( m_spinCtrlDouble_cogRMC, 0, wxALL, 5 );

	m_textCtrl_dateRMC = new wxTextCtrl( sbSizer_RMC->GetStaticBox(), wxID_ANY, _("010126"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
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

	sbSizer_ROT = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("ROT") ), wxHORIZONTAL );

	wxBoxSizer* bSizer171112;
	bSizer171112 = new wxBoxSizer( wxVERTICAL );

	m_button_sendROT = new wxButton( sbSizer_ROT->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendROT->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer171112->Add( m_button_sendROT, 0, wxALL, 5 );

	m_checkBox_autoSendROT = new wxCheckBox( sbSizer_ROT->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
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

	m_textCtrl_talkerROT = new wxTextCtrl( sbSizer_ROT->GetStaticBox(), wxID_ANY, _("HE"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerROT->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerROT->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerROT->SetMaxLength( 2 );
	#endif
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

	m_textCtrl_talkerRSA = new wxTextCtrl( sbSizer_RSA->GetStaticBox(), wxID_ANY, _("II"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerRSA->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerRSA->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerRSA->SetMaxLength( 2 );
	#endif
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

	sbSizer_TLL = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("TLL") ), wxHORIZONTAL );

	wxBoxSizer* bSizer171111;
	bSizer171111 = new wxBoxSizer( wxVERTICAL );

	m_button_sendTLL = new wxButton( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendTLL->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer171111->Add( m_button_sendTLL, 0, wxALL, 5 );

	m_checkBox_autoSendTLL = new wxCheckBox( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
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

	m_textCtrl_talkerTLL = new wxTextCtrl( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("IN"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerTLL->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerTLL->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerTLL->SetMaxLength( 2 );
	#endif
	fgSizer4111->Add( m_textCtrl_talkerTLL, 0, wxALL, 5 );

	m_staticText371111 = new wxStaticText( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("TLL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText371111->Wrap( -1 );
	fgSizer4111->Add( m_staticText371111, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrl_idTLL = new wxSpinCtrl( sbSizer_TLL->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer4111->Add( m_spinCtrl_idTLL, 0, wxALL, 5 );

	m_textCtrl_latitudeTLL = new wxTextCtrl( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("0000.0000000"), wxDefaultPosition, wxSize( 95,-1 ), 0 );
	fgSizer4111->Add( m_textCtrl_latitudeTLL, 0, wxALL, 5 );

	wxString m_choice_latDirTLLChoices[] = { _("N"), _("S") };
	int m_choice_latDirTLLNChoices = sizeof( m_choice_latDirTLLChoices ) / sizeof( wxString );
	m_choice_latDirTLL = new wxChoice( sbSizer_TLL->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_latDirTLLNChoices, m_choice_latDirTLLChoices, 0 );
	m_choice_latDirTLL->SetSelection( 0 );
	fgSizer4111->Add( m_choice_latDirTLL, 0, wxALL, 5 );

	m_textCtrl_longitudeTLL = new wxTextCtrl( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("00000.0000000"), wxDefaultPosition, wxSize( 95,-1 ), 0 );
	fgSizer4111->Add( m_textCtrl_longitudeTLL, 0, wxALL, 5 );

	wxString m_choice_lonDirTLLChoices[] = { _("E"), _("W") };
	int m_choice_lonDirTLLNChoices = sizeof( m_choice_lonDirTLLChoices ) / sizeof( wxString );
	m_choice_lonDirTLL = new wxChoice( sbSizer_TLL->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_lonDirTLLNChoices, m_choice_lonDirTLLChoices, 0 );
	m_choice_lonDirTLL->SetSelection( 0 );
	fgSizer4111->Add( m_choice_lonDirTLL, 0, wxALL, 5 );

	m_textCtrl_nameTLL = new wxTextCtrl( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("DUMMY"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4111->Add( m_textCtrl_nameTLL, 0, wxALL, 5 );

	m_textCtrl_timeTLL = new wxTextCtrl( sbSizer_TLL->GetStaticBox(), wxID_ANY, _("120000"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
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

	sbSizer_THS = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("THS") ), wxHORIZONTAL );

	wxBoxSizer* bSizer1711122;
	bSizer1711122 = new wxBoxSizer( wxVERTICAL );

	m_button_sendTHS = new wxButton( sbSizer_THS->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendTHS->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer1711122->Add( m_button_sendTHS, 0, wxALL, 5 );

	m_checkBox_autoSendTHS = new wxCheckBox( sbSizer_THS->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1711122->Add( m_checkBox_autoSendTHS, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_THS->Add( bSizer1711122, 0, wxEXPAND, 5 );

	m_staticline611122 = new wxStaticLine( sbSizer_THS->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	sbSizer_THS->Add( m_staticline611122, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer41122;
	fgSizer41122 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer41122->SetFlexibleDirection( wxBOTH );
	fgSizer41122->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText3511122 = new wxStaticText( sbSizer_THS->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3511122->Wrap( -1 );
	fgSizer41122->Add( m_staticText3511122, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer41122->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText3611122 = new wxStaticText( sbSizer_THS->GetStaticBox(), wxID_ANY, _("Heading"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3611122->Wrap( -1 );
	fgSizer41122->Add( m_staticText3611122, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText772 = new wxStaticText( sbSizer_THS->GetStaticBox(), wxID_ANY, _("Mode"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText772->Wrap( -1 );
	fgSizer41122->Add( m_staticText772, 0, wxALL, 5 );

	m_textCtrl_talkerTHS = new wxTextCtrl( sbSizer_THS->GetStaticBox(), wxID_ANY, _("HE"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerTHS->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerTHS->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerTHS->SetMaxLength( 2 );
	#endif
	fgSizer41122->Add( m_textCtrl_talkerTHS, 0, wxALL, 5 );

	m_staticText3711122 = new wxStaticText( sbSizer_THS->GetStaticBox(), wxID_ANY, _("THS"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3711122->Wrap( -1 );
	fgSizer41122->Add( m_staticText3711122, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_headingTHS = new wxSpinCtrlDouble( sbSizer_THS->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 360, 0, 15 );
	m_spinCtrlDouble_headingTHS->SetDigits( 1 );
	fgSizer41122->Add( m_spinCtrlDouble_headingTHS, 0, wxALL, 5 );

	wxString m_choice_modeTHSChoices[] = { _("A"), _("V") };
	int m_choice_modeTHSNChoices = sizeof( m_choice_modeTHSChoices ) / sizeof( wxString );
	m_choice_modeTHS = new wxChoice( sbSizer_THS->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_modeTHSNChoices, m_choice_modeTHSChoices, 0 );
	m_choice_modeTHS->SetSelection( 0 );
	fgSizer41122->Add( m_choice_modeTHS, 0, wxALL, 5 );


	sbSizer_THS->Add( fgSizer41122, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_THS, 0, wxEXPAND, 5 );

	sbSizer_VDR = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("VDR") ), wxHORIZONTAL );

	wxBoxSizer* bSizer17111312;
	bSizer17111312 = new wxBoxSizer( wxVERTICAL );

	m_button_sendVDR = new wxButton( sbSizer_VDR->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendVDR->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer17111312->Add( m_button_sendVDR, 0, wxALL, 5 );

	m_checkBox_autoSendVDR = new wxCheckBox( sbSizer_VDR->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17111312->Add( m_checkBox_autoSendVDR, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_VDR->Add( bSizer17111312, 0, wxEXPAND, 5 );

	m_staticline6111312 = new wxStaticLine( sbSizer_VDR->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	sbSizer_VDR->Add( m_staticline6111312, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer411312;
	fgSizer411312 = new wxFlexGridSizer( 2, 8, 0, 0 );
	fgSizer411312->SetFlexibleDirection( wxBOTH );
	fgSizer411312->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText35111312 = new wxStaticText( sbSizer_VDR->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35111312->Wrap( -1 );
	fgSizer411312->Add( m_staticText35111312, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer411312->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText36111312 = new wxStaticText( sbSizer_VDR->GetStaticBox(), wxID_ANY, _("Direction"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText36111312->Wrap( -1 );
	fgSizer411312->Add( m_staticText36111312, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer411312->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText10612 = new wxStaticText( sbSizer_VDR->GetStaticBox(), wxID_ANY, _("Direction"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10612->Wrap( -1 );
	fgSizer411312->Add( m_staticText10612, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer411312->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText1152 = new wxStaticText( sbSizer_VDR->GetStaticBox(), wxID_ANY, _("Current speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1152->Wrap( -1 );
	fgSizer411312->Add( m_staticText1152, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer411312->Add( 0, 0, 1, wxEXPAND, 5 );

	m_textCtrl_talkerVDR = new wxTextCtrl( sbSizer_VDR->GetStaticBox(), wxID_ANY, _("II"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerVDR->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerVDR->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerVDR->SetMaxLength( 2 );
	#endif
	fgSizer411312->Add( m_textCtrl_talkerVDR, 0, wxALL, 5 );

	m_staticText185 = new wxStaticText( sbSizer_VDR->GetStaticBox(), wxID_ANY, _("VDR"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText185->Wrap( -1 );
	fgSizer411312->Add( m_staticText185, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_directionTrueVDR = new wxSpinCtrlDouble( sbSizer_VDR->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 360, 0, 45 );
	m_spinCtrlDouble_directionTrueVDR->SetDigits( 1 );
	fgSizer411312->Add( m_spinCtrlDouble_directionTrueVDR, 0, wxALL, 5 );

	m_staticText1161 = new wxStaticText( sbSizer_VDR->GetStaticBox(), wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1161->Wrap( -1 );
	fgSizer411312->Add( m_staticText1161, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_directionMagVDR = new wxSpinCtrlDouble( sbSizer_VDR->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( -1,-1 ), wxSP_ARROW_KEYS, 0, 360, 0, 45 );
	m_spinCtrlDouble_directionMagVDR->SetDigits( 1 );
	fgSizer411312->Add( m_spinCtrlDouble_directionMagVDR, 0, wxALL, 5 );

	m_staticText1171 = new wxStaticText( sbSizer_VDR->GetStaticBox(), wxID_ANY, _("M"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1171->Wrap( -1 );
	fgSizer411312->Add( m_staticText1171, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_currentSpeedVDR = new wxSpinCtrlDouble( sbSizer_VDR->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0, 5 );
	m_spinCtrlDouble_currentSpeedVDR->SetDigits( 1 );
	fgSizer411312->Add( m_spinCtrlDouble_currentSpeedVDR, 0, wxALL, 5 );

	m_staticText1181 = new wxStaticText( sbSizer_VDR->GetStaticBox(), wxID_ANY, _("N"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1181->Wrap( -1 );
	fgSizer411312->Add( m_staticText1181, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_VDR->Add( fgSizer411312, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_VDR, 0, wxEXPAND, 5 );

	sbSizer_VHW = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("VHW") ), wxHORIZONTAL );

	wxBoxSizer* bSizer171113121;
	bSizer171113121 = new wxBoxSizer( wxVERTICAL );

	m_button_sendVHW = new wxButton( sbSizer_VHW->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendVHW->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer171113121->Add( m_button_sendVHW, 0, wxALL, 5 );

	m_checkBox_autoSendVHW = new wxCheckBox( sbSizer_VHW->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer171113121->Add( m_checkBox_autoSendVHW, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_VHW->Add( bSizer171113121, 0, wxEXPAND, 5 );

	m_staticline61113121 = new wxStaticLine( sbSizer_VHW->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	sbSizer_VHW->Add( m_staticline61113121, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer4113121;
	fgSizer4113121 = new wxFlexGridSizer( 2, 10, 0, 0 );
	fgSizer4113121->SetFlexibleDirection( wxBOTH );
	fgSizer4113121->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText351113121 = new wxStaticText( sbSizer_VHW->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText351113121->Wrap( -1 );
	fgSizer4113121->Add( m_staticText351113121, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer4113121->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText361113121 = new wxStaticText( sbSizer_VHW->GetStaticBox(), wxID_ANY, _("Heading"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText361113121->Wrap( -1 );
	fgSizer4113121->Add( m_staticText361113121, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer4113121->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText106121 = new wxStaticText( sbSizer_VHW->GetStaticBox(), wxID_ANY, _("Heading"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText106121->Wrap( -1 );
	fgSizer4113121->Add( m_staticText106121, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer4113121->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText11521 = new wxStaticText( sbSizer_VHW->GetStaticBox(), wxID_ANY, _("STW"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11521->Wrap( -1 );
	fgSizer4113121->Add( m_staticText11521, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer4113121->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText202 = new wxStaticText( sbSizer_VHW->GetStaticBox(), wxID_ANY, _("STW"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText202->Wrap( -1 );
	fgSizer4113121->Add( m_staticText202, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer4113121->Add( 0, 0, 1, wxEXPAND, 5 );

	m_textCtrl_talkerVHW = new wxTextCtrl( sbSizer_VHW->GetStaticBox(), wxID_ANY, _("VW"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerVHW->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerVHW->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerVHW->SetMaxLength( 2 );
	#endif
	fgSizer4113121->Add( m_textCtrl_talkerVHW, 0, wxALL, 5 );

	m_staticText1851 = new wxStaticText( sbSizer_VHW->GetStaticBox(), wxID_ANY, _("VHW"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1851->Wrap( -1 );
	fgSizer4113121->Add( m_staticText1851, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_headingTrueVHW = new wxSpinCtrlDouble( sbSizer_VHW->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 360, 0, 45 );
	m_spinCtrlDouble_headingTrueVHW->SetDigits( 1 );
	fgSizer4113121->Add( m_spinCtrlDouble_headingTrueVHW, 0, wxALL, 5 );

	m_staticText11611 = new wxStaticText( sbSizer_VHW->GetStaticBox(), wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11611->Wrap( -1 );
	fgSizer4113121->Add( m_staticText11611, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_headingMagVHW = new wxSpinCtrlDouble( sbSizer_VHW->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( -1,-1 ), wxSP_ARROW_KEYS, 0, 360, 0, 45 );
	m_spinCtrlDouble_headingMagVHW->SetDigits( 1 );
	fgSizer4113121->Add( m_spinCtrlDouble_headingMagVHW, 0, wxALL, 5 );

	m_staticText11711 = new wxStaticText( sbSizer_VHW->GetStaticBox(), wxID_ANY, _("M"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11711->Wrap( -1 );
	fgSizer4113121->Add( m_staticText11711, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_stwKnotVHW = new wxSpinCtrlDouble( sbSizer_VHW->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0, 5 );
	m_spinCtrlDouble_stwKnotVHW->SetDigits( 1 );
	fgSizer4113121->Add( m_spinCtrlDouble_stwKnotVHW, 0, wxALL, 5 );

	m_staticText11811 = new wxStaticText( sbSizer_VHW->GetStaticBox(), wxID_ANY, _("N"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11811->Wrap( -1 );
	fgSizer4113121->Add( m_staticText11811, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_stwKphVHW = new wxSpinCtrlDouble( sbSizer_VHW->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0, 5 );
	m_spinCtrlDouble_stwKphVHW->SetDigits( 1 );
	fgSizer4113121->Add( m_spinCtrlDouble_stwKphVHW, 0, wxALL, 5 );

	m_staticText203 = new wxStaticText( sbSizer_VHW->GetStaticBox(), wxID_ANY, _("K"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText203->Wrap( -1 );
	fgSizer4113121->Add( m_staticText203, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_VHW->Add( fgSizer4113121, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_VHW, 0, wxEXPAND, 5 );

	sbSizer_VTG = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("VTG") ), wxHORIZONTAL );

	wxBoxSizer* bSizer1212;
	bSizer1212 = new wxBoxSizer( wxVERTICAL );


	bSizer1212->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_sendVTG = new wxButton( sbSizer_VTG->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendVTG->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer1212->Add( m_button_sendVTG, 0, wxALL, 5 );

	m_checkBox_autoSendVTG = new wxCheckBox( sbSizer_VTG->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1212->Add( m_checkBox_autoSendVTG, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer1212->Add( 0, 0, 1, wxEXPAND, 5 );


	sbSizer_VTG->Add( bSizer1212, 0, wxEXPAND, 5 );

	m_staticline52 = new wxStaticLine( sbSizer_VTG->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL|wxLI_VERTICAL );
	sbSizer_VTG->Add( m_staticline52, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer_VTG;
	fgSizer_VTG = new wxFlexGridSizer( 2, 11, 0, 0 );
	fgSizer_VTG->SetFlexibleDirection( wxBOTH );
	fgSizer_VTG->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText192 = new wxStaticText( sbSizer_VTG->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText192->Wrap( -1 );
	fgSizer_VTG->Add( m_staticText192, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_VTG->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText94 = new wxStaticText( sbSizer_VTG->GetStaticBox(), wxID_ANY, _("COG"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText94->Wrap( -1 );
	m_staticText94->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	fgSizer_VTG->Add( m_staticText94, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_VTG->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText148 = new wxStaticText( sbSizer_VTG->GetStaticBox(), wxID_ANY, _("COG"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText148->Wrap( -1 );
	fgSizer_VTG->Add( m_staticText148, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_VTG->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText112 = new wxStaticText( sbSizer_VTG->GetStaticBox(), wxID_ANY, _("SOG"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText112->Wrap( -1 );
	fgSizer_VTG->Add( m_staticText112, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_VTG->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText143 = new wxStaticText( sbSizer_VTG->GetStaticBox(), wxID_ANY, _("SOG"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText143->Wrap( -1 );
	fgSizer_VTG->Add( m_staticText143, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_VTG->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText182 = new wxStaticText( sbSizer_VTG->GetStaticBox(), wxID_ANY, _("Mode"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText182->Wrap( -1 );
	fgSizer_VTG->Add( m_staticText182, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_talkerVTG = new wxTextCtrl( sbSizer_VTG->GetStaticBox(), wxID_ANY, _("GP"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerVTG->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerVTG->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerVTG->SetMaxLength( 2 );
	#endif
	fgSizer_VTG->Add( m_textCtrl_talkerVTG, 0, wxALL, 5 );

	m_staticText52 = new wxStaticText( sbSizer_VTG->GetStaticBox(), wxID_ANY, _("VTG"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText52->Wrap( -1 );
	fgSizer_VTG->Add( m_staticText52, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_cogTrueVTG = new wxSpinCtrlDouble( sbSizer_VTG->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 360, 0, 15 );
	m_spinCtrlDouble_cogTrueVTG->SetDigits( 0 );
	fgSizer_VTG->Add( m_spinCtrlDouble_cogTrueVTG, 0, wxALL, 5 );

	m_staticText139 = new wxStaticText( sbSizer_VTG->GetStaticBox(), wxID_ANY, _("T"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText139->Wrap( -1 );
	fgSizer_VTG->Add( m_staticText139, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_cogMagVTG = new wxSpinCtrlDouble( sbSizer_VTG->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 360, 0, 15 );
	m_spinCtrlDouble_cogMagVTG->SetDigits( 0 );
	fgSizer_VTG->Add( m_spinCtrlDouble_cogMagVTG, 0, wxALL, 5 );

	m_staticText147 = new wxStaticText( sbSizer_VTG->GetStaticBox(), wxID_ANY, _("M"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText147->Wrap( -1 );
	fgSizer_VTG->Add( m_staticText147, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_sogKnotVTG = new wxSpinCtrlDouble( sbSizer_VTG->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0, 5 );
	m_spinCtrlDouble_sogKnotVTG->SetDigits( 0 );
	fgSizer_VTG->Add( m_spinCtrlDouble_sogKnotVTG, 0, wxALL, 5 );

	m_staticText149 = new wxStaticText( sbSizer_VTG->GetStaticBox(), wxID_ANY, _("N"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText149->Wrap( -1 );
	fgSizer_VTG->Add( m_staticText149, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_sogKphVTG = new wxSpinCtrlDouble( sbSizer_VTG->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 200, 0, 5 );
	m_spinCtrlDouble_sogKphVTG->SetDigits( 0 );
	fgSizer_VTG->Add( m_spinCtrlDouble_sogKphVTG, 0, wxALL, 5 );

	m_staticText150 = new wxStaticText( sbSizer_VTG->GetStaticBox(), wxID_ANY, _("K"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText150->Wrap( -1 );
	fgSizer_VTG->Add( m_staticText150, 0, wxALIGN_CENTER|wxALL, 5 );

	wxString m_choice_modeVTGChoices[] = { _("A"), _("V") };
	int m_choice_modeVTGNChoices = sizeof( m_choice_modeVTGChoices ) / sizeof( wxString );
	m_choice_modeVTG = new wxChoice( sbSizer_VTG->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), m_choice_modeVTGNChoices, m_choice_modeVTGChoices, 0 );
	m_choice_modeVTG->SetSelection( 0 );
	fgSizer_VTG->Add( m_choice_modeVTG, 0, wxALL, 5 );


	sbSizer_VTG->Add( fgSizer_VTG, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_VTG, 0, wxEXPAND, 5 );

	sbSizer_VWR = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("VWR") ), wxHORIZONTAL );

	wxBoxSizer* bSizer1711131211;
	bSizer1711131211 = new wxBoxSizer( wxVERTICAL );

	m_button_sendVWR = new wxButton( sbSizer_VWR->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendVWR->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer1711131211->Add( m_button_sendVWR, 0, wxALL, 5 );

	m_checkBox_autoSendVWR = new wxCheckBox( sbSizer_VWR->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1711131211->Add( m_checkBox_autoSendVWR, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_VWR->Add( bSizer1711131211, 0, wxEXPAND, 5 );

	m_staticline611131211 = new wxStaticLine( sbSizer_VWR->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	sbSizer_VWR->Add( m_staticline611131211, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer41131211;
	fgSizer41131211 = new wxFlexGridSizer( 2, 10, 0, 0 );
	fgSizer41131211->SetFlexibleDirection( wxBOTH );
	fgSizer41131211->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText3511131211 = new wxStaticText( sbSizer_VWR->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3511131211->Wrap( -1 );
	fgSizer41131211->Add( m_staticText3511131211, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer41131211->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText3611131211 = new wxStaticText( sbSizer_VWR->GetStaticBox(), wxID_ANY, _("Angle"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3611131211->Wrap( -1 );
	fgSizer41131211->Add( m_staticText3611131211, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer41131211->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText1061211 = new wxStaticText( sbSizer_VWR->GetStaticBox(), wxID_ANY, _("Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1061211->Wrap( -1 );
	fgSizer41131211->Add( m_staticText1061211, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer41131211->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText115211 = new wxStaticText( sbSizer_VWR->GetStaticBox(), wxID_ANY, _("Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText115211->Wrap( -1 );
	fgSizer41131211->Add( m_staticText115211, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer41131211->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText2021 = new wxStaticText( sbSizer_VWR->GetStaticBox(), wxID_ANY, _("Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2021->Wrap( -1 );
	fgSizer41131211->Add( m_staticText2021, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer41131211->Add( 0, 0, 1, wxEXPAND, 5 );

	m_textCtrl_talkerVWR = new wxTextCtrl( sbSizer_VWR->GetStaticBox(), wxID_ANY, _("II"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerVWR->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerVWR->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerVWR->SetMaxLength( 2 );
	#endif
	fgSizer41131211->Add( m_textCtrl_talkerVWR, 0, wxALL, 5 );

	m_staticText18511 = new wxStaticText( sbSizer_VWR->GetStaticBox(), wxID_ANY, _("VWR"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18511->Wrap( -1 );
	fgSizer41131211->Add( m_staticText18511, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_angleVWR = new wxSpinCtrlDouble( sbSizer_VWR->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 180, 0, 15 );
	m_spinCtrlDouble_angleVWR->SetDigits( 1 );
	fgSizer41131211->Add( m_spinCtrlDouble_angleVWR, 0, wxALL, 5 );

	wxString m_choice_dirVWRChoices[] = { _("L"), _("R") };
	int m_choice_dirVWRNChoices = sizeof( m_choice_dirVWRChoices ) / sizeof( wxString );
	m_choice_dirVWR = new wxChoice( sbSizer_VWR->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_dirVWRNChoices, m_choice_dirVWRChoices, 0 );
	m_choice_dirVWR->SetSelection( 0 );
	fgSizer41131211->Add( m_choice_dirVWR, 0, wxALL, 5 );

	m_spinCtrlDouble_speedKnotVWR = new wxSpinCtrlDouble( sbSizer_VWR->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( -1,-1 ), wxSP_ARROW_KEYS, 0, 100, 0, 5 );
	m_spinCtrlDouble_speedKnotVWR->SetDigits( 1 );
	fgSizer41131211->Add( m_spinCtrlDouble_speedKnotVWR, 0, wxALL, 5 );

	m_staticText117111 = new wxStaticText( sbSizer_VWR->GetStaticBox(), wxID_ANY, _("N"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText117111->Wrap( -1 );
	fgSizer41131211->Add( m_staticText117111, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_speedMpsVWR = new wxSpinCtrlDouble( sbSizer_VWR->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0, 5 );
	m_spinCtrlDouble_speedMpsVWR->SetDigits( 1 );
	fgSizer41131211->Add( m_spinCtrlDouble_speedMpsVWR, 0, wxALL, 5 );

	m_staticText118111 = new wxStaticText( sbSizer_VWR->GetStaticBox(), wxID_ANY, _("M"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText118111->Wrap( -1 );
	fgSizer41131211->Add( m_staticText118111, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_speedKphVWR = new wxSpinCtrlDouble( sbSizer_VWR->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0, 5 );
	m_spinCtrlDouble_speedKphVWR->SetDigits( 1 );
	fgSizer41131211->Add( m_spinCtrlDouble_speedKphVWR, 0, wxALL, 5 );

	m_staticText2031 = new wxStaticText( sbSizer_VWR->GetStaticBox(), wxID_ANY, _("K"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2031->Wrap( -1 );
	fgSizer41131211->Add( m_staticText2031, 0, wxALIGN_CENTER|wxALL, 5 );


	sbSizer_VWR->Add( fgSizer41131211, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_VWR, 0, wxEXPAND, 5 );

	sbSizer_WPL = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("WPL") ), wxHORIZONTAL );

	wxBoxSizer* bSizer1211;
	bSizer1211 = new wxBoxSizer( wxVERTICAL );


	bSizer1211->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_sendWPL = new wxButton( sbSizer_WPL->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendWPL->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer1211->Add( m_button_sendWPL, 0, wxALL, 5 );

	m_checkBox_autoSendWPL = new wxCheckBox( sbSizer_WPL->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1211->Add( m_checkBox_autoSendWPL, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer1211->Add( 0, 0, 1, wxEXPAND, 5 );


	sbSizer_WPL->Add( bSizer1211, 0, wxEXPAND, 5 );

	m_staticline51 = new wxStaticLine( sbSizer_WPL->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL|wxLI_VERTICAL );
	sbSizer_WPL->Add( m_staticline51, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer_WPL;
	fgSizer_WPL = new wxFlexGridSizer( 2, 7, 0, 0 );
	fgSizer_WPL->SetFlexibleDirection( wxBOTH );
	fgSizer_WPL->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText191 = new wxStaticText( sbSizer_WPL->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText191->Wrap( -1 );
	fgSizer_WPL->Add( m_staticText191, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_WPL->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText91 = new wxStaticText( sbSizer_WPL->GetStaticBox(), wxID_ANY, _("Latitude"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText91->Wrap( -1 );
	m_staticText91->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	fgSizer_WPL->Add( m_staticText91, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_WPL->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText111 = new wxStaticText( sbSizer_WPL->GetStaticBox(), wxID_ANY, _("Longitude"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText111->Wrap( -1 );
	fgSizer_WPL->Add( m_staticText111, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_WPL->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText142 = new wxStaticText( sbSizer_WPL->GetStaticBox(), wxID_ANY, _("Waypoint name"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText142->Wrap( -1 );
	fgSizer_WPL->Add( m_staticText142, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_talkerWPL = new wxTextCtrl( sbSizer_WPL->GetStaticBox(), wxID_ANY, _("GP"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerWPL->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerWPL->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerWPL->SetMaxLength( 2 );
	#endif
	fgSizer_WPL->Add( m_textCtrl_talkerWPL, 0, wxALL, 5 );

	m_staticText51 = new wxStaticText( sbSizer_WPL->GetStaticBox(), wxID_ANY, _("GLL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	fgSizer_WPL->Add( m_staticText51, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_latitudeWPL = new wxTextCtrl( sbSizer_WPL->GetStaticBox(), wxID_ANY, _("0000.0000000"), wxDefaultPosition, wxSize( 95,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_latitudeWPL->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_latitudeWPL->SetMaxLength( 12 );
	}
	#else
	m_textCtrl_latitudeWPL->SetMaxLength( 12 );
	#endif
	fgSizer_WPL->Add( m_textCtrl_latitudeWPL, 0, wxALL, 5 );

	wxString m_choice_latDirWPLChoices[] = { _("N"), _("S") };
	int m_choice_latDirWPLNChoices = sizeof( m_choice_latDirWPLChoices ) / sizeof( wxString );
	m_choice_latDirWPL = new wxChoice( sbSizer_WPL->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_latDirWPLNChoices, m_choice_latDirWPLChoices, 0 );
	m_choice_latDirWPL->SetSelection( 0 );
	fgSizer_WPL->Add( m_choice_latDirWPL, 0, wxALL, 5 );

	m_textCtrl_longitudeWPL = new wxTextCtrl( sbSizer_WPL->GetStaticBox(), wxID_ANY, _("00000.0000000"), wxDefaultPosition, wxSize( 95,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_longitudeWPL->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_longitudeWPL->SetMaxLength( 13 );
	}
	#else
	m_textCtrl_longitudeWPL->SetMaxLength( 13 );
	#endif
	fgSizer_WPL->Add( m_textCtrl_longitudeWPL, 0, wxALL, 5 );

	wxString m_choice_lonDirWPLChoices[] = { _("E"), _("W") };
	int m_choice_lonDirWPLNChoices = sizeof( m_choice_lonDirWPLChoices ) / sizeof( wxString );
	m_choice_lonDirWPL = new wxChoice( sbSizer_WPL->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_lonDirWPLNChoices, m_choice_lonDirWPLChoices, 0 );
	m_choice_lonDirWPL->SetSelection( 0 );
	fgSizer_WPL->Add( m_choice_lonDirWPL, 0, wxALL, 5 );

	m_textCtrl_nameWPL = new wxTextCtrl( sbSizer_WPL->GetStaticBox(), wxID_ANY, _("WP099"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	fgSizer_WPL->Add( m_textCtrl_nameWPL, 0, wxALL, 5 );


	sbSizer_WPL->Add( fgSizer_WPL, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_WPL, 0, wxEXPAND, 5 );

	sbSizer_XDR = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("XDR") ), wxHORIZONTAL );

	wxBoxSizer* bSizer12111;
	bSizer12111 = new wxBoxSizer( wxVERTICAL );


	bSizer12111->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_sendXDR = new wxButton( sbSizer_XDR->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendXDR->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer12111->Add( m_button_sendXDR, 0, wxALL, 5 );

	m_checkBox_autoSendXDR = new wxCheckBox( sbSizer_XDR->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12111->Add( m_checkBox_autoSendXDR, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer12111->Add( 0, 0, 1, wxEXPAND, 5 );


	sbSizer_XDR->Add( bSizer12111, 0, wxEXPAND, 5 );

	m_staticline511 = new wxStaticLine( sbSizer_XDR->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL|wxLI_VERTICAL );
	sbSizer_XDR->Add( m_staticline511, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer_XDR;
	fgSizer_XDR = new wxFlexGridSizer( 2, 6, 0, 0 );
	fgSizer_XDR->SetFlexibleDirection( wxBOTH );
	fgSizer_XDR->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText1911 = new wxStaticText( sbSizer_XDR->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1911->Wrap( -1 );
	fgSizer_XDR->Add( m_staticText1911, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_XDR->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText911 = new wxStaticText( sbSizer_XDR->GetStaticBox(), wxID_ANY, _("Type"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText911->Wrap( -1 );
	m_staticText911->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	fgSizer_XDR->Add( m_staticText911, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText1111 = new wxStaticText( sbSizer_XDR->GetStaticBox(), wxID_ANY, _("Measure"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText1111->Wrap( -1 );
	fgSizer_XDR->Add( m_staticText1111, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText1501 = new wxStaticText( sbSizer_XDR->GetStaticBox(), wxID_ANY, _("Unit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1501->Wrap( -1 );
	fgSizer_XDR->Add( m_staticText1501, 0, wxALL, 5 );

	m_staticText1421 = new wxStaticText( sbSizer_XDR->GetStaticBox(), wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText1421->Wrap( -1 );
	fgSizer_XDR->Add( m_staticText1421, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_talkerXDR = new wxTextCtrl( sbSizer_XDR->GetStaticBox(), wxID_ANY, _("II"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerXDR->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerXDR->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerXDR->SetMaxLength( 2 );
	#endif
	fgSizer_XDR->Add( m_textCtrl_talkerXDR, 0, wxALL, 5 );

	m_staticText511 = new wxStaticText( sbSizer_XDR->GetStaticBox(), wxID_ANY, _("XDR"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText511->Wrap( -1 );
	fgSizer_XDR->Add( m_staticText511, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText_typeXDR = new wxStaticText( sbSizer_XDR->GetStaticBox(), wxID_ANY, _("P"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_typeXDR->Wrap( -1 );
	fgSizer_XDR->Add( m_staticText_typeXDR, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_measureXDR = new wxSpinCtrlDouble( sbSizer_XDR->GetStaticBox(), wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0.85, 1.1, 1, 0.01 );
	m_spinCtrlDouble_measureXDR->SetDigits( 2 );
	fgSizer_XDR->Add( m_spinCtrlDouble_measureXDR, 0, wxALL, 5 );

	m_staticText_unitXDR = new wxStaticText( sbSizer_XDR->GetStaticBox(), wxID_ANY, _("B"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_unitXDR->Wrap( -1 );
	fgSizer_XDR->Add( m_staticText_unitXDR, 0, wxALIGN_CENTER|wxALL, 5 );

	wxString m_choice_nameXDRChoices[] = { _("Barometer"), _("TempAir"), _("TempWater"), _("PITCH"), _("ROLL") };
	int m_choice_nameXDRNChoices = sizeof( m_choice_nameXDRChoices ) / sizeof( wxString );
	m_choice_nameXDR = new wxChoice( sbSizer_XDR->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_nameXDRNChoices, m_choice_nameXDRChoices, 0 );
	m_choice_nameXDR->SetSelection( 0 );
	fgSizer_XDR->Add( m_choice_nameXDR, 0, wxALL, 5 );


	sbSizer_XDR->Add( fgSizer_XDR, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_XDR, 0, wxEXPAND, 5 );

	sbSizer_ZDA = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow_sentenceBuilder, wxID_ANY, _("ZDA") ), wxHORIZONTAL );

	wxBoxSizer* bSizer12131;
	bSizer12131 = new wxBoxSizer( wxVERTICAL );


	bSizer12131->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_sendZDA = new wxButton( sbSizer_ZDA->GetStaticBox(), wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sendZDA->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer12131->Add( m_button_sendZDA, 0, wxALL, 5 );

	m_checkBox_autoSendZDA = new wxCheckBox( sbSizer_ZDA->GetStaticBox(), wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12131->Add( m_checkBox_autoSendZDA, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer12131->Add( 0, 0, 1, wxEXPAND, 5 );


	sbSizer_ZDA->Add( bSizer12131, 0, wxEXPAND, 5 );

	m_staticline531 = new wxStaticLine( sbSizer_ZDA->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL|wxLI_VERTICAL );
	sbSizer_ZDA->Add( m_staticline531, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer_ZDA;
	fgSizer_ZDA = new wxFlexGridSizer( 2, 8, 0, 0 );
	fgSizer_ZDA->SetFlexibleDirection( wxBOTH );
	fgSizer_ZDA->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText1931 = new wxStaticText( sbSizer_ZDA->GetStaticBox(), wxID_ANY, _("Talker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1931->Wrap( -1 );
	fgSizer_ZDA->Add( m_staticText1931, 0, wxALIGN_CENTER|wxALL, 5 );


	fgSizer_ZDA->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText9101 = new wxStaticText( sbSizer_ZDA->GetStaticBox(), wxID_ANY, _("UTC time"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText9101->Wrap( -1 );
	m_staticText9101->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	fgSizer_ZDA->Add( m_staticText9101, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText1381 = new wxStaticText( sbSizer_ZDA->GetStaticBox(), wxID_ANY, _("Day"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1381->Wrap( -1 );
	fgSizer_ZDA->Add( m_staticText1381, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText1131 = new wxStaticText( sbSizer_ZDA->GetStaticBox(), wxID_ANY, _("Month"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText1131->Wrap( -1 );
	fgSizer_ZDA->Add( m_staticText1131, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText13911 = new wxStaticText( sbSizer_ZDA->GetStaticBox(), wxID_ANY, _("Year"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13911->Wrap( -1 );
	fgSizer_ZDA->Add( m_staticText13911, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText1371 = new wxStaticText( sbSizer_ZDA->GetStaticBox(), wxID_ANY, _("Hour offset"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1371->Wrap( -1 );
	fgSizer_ZDA->Add( m_staticText1371, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText1441 = new wxStaticText( sbSizer_ZDA->GetStaticBox(), wxID_ANY, _("Minutes offset"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText1441->Wrap( -1 );
	fgSizer_ZDA->Add( m_staticText1441, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_talkerZDA = new wxTextCtrl( sbSizer_ZDA->GetStaticBox(), wxID_ANY, _("GP"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_talkerZDA->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_talkerZDA->SetMaxLength( 2 );
	}
	#else
	m_textCtrl_talkerZDA->SetMaxLength( 2 );
	#endif
	fgSizer_ZDA->Add( m_textCtrl_talkerZDA, 0, wxALL, 5 );

	m_staticText531 = new wxStaticText( sbSizer_ZDA->GetStaticBox(), wxID_ANY, _("ZDA"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText531->Wrap( -1 );
	fgSizer_ZDA->Add( m_staticText531, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_timeZDA = new wxTextCtrl( sbSizer_ZDA->GetStaticBox(), wxID_ANY, _("120000"), wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !m_textCtrl_timeZDA->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrl_timeZDA->SetMaxLength( 9 );
	}
	#else
	m_textCtrl_timeZDA->SetMaxLength( 9 );
	#endif
	fgSizer_ZDA->Add( m_textCtrl_timeZDA, 0, wxALL, 5 );

	m_spinCtrl_dayZDA = new wxSpinCtrl( sbSizer_ZDA->GetStaticBox(), wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 31, 1 );
	fgSizer_ZDA->Add( m_spinCtrl_dayZDA, 0, wxALL, 5 );

	m_spinCtrl_monthZDA = new wxSpinCtrl( sbSizer_ZDA->GetStaticBox(), wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 12, 1 );
	fgSizer_ZDA->Add( m_spinCtrl_monthZDA, 0, wxALL, 5 );

	m_spinCtrl_yearZDA = new wxSpinCtrl( sbSizer_ZDA->GetStaticBox(), wxID_ANY, wxT("2026"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1984, 2999, 2026 );
	fgSizer_ZDA->Add( m_spinCtrl_yearZDA, 0, wxALL, 5 );

	m_spinCtrl_hourOffsetZDA = new wxSpinCtrl( sbSizer_ZDA->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -13, 13, 0 );
	fgSizer_ZDA->Add( m_spinCtrl_hourOffsetZDA, 0, wxALL, 5 );

	m_spinCtrl_minuteOffsetZDA = new wxSpinCtrl( sbSizer_ZDA->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -59, 59, 0 );
	fgSizer_ZDA->Add( m_spinCtrl_minuteOffsetZDA, 0, wxALL, 5 );


	sbSizer_ZDA->Add( fgSizer_ZDA, 0, wxEXPAND, 5 );


	bSizer_NmeaList->Add( sbSizer_ZDA, 0, wxEXPAND, 5 );


	m_scrolledWindow_sentenceBuilder->SetSizer( bSizer_NmeaList );
	m_scrolledWindow_sentenceBuilder->Layout();
	bSizer_NmeaList->Fit( m_scrolledWindow_sentenceBuilder );
	bSizer9->Add( m_scrolledWindow_sentenceBuilder, 1, wxEXPAND | wxALL, 5 );

	m_staticline3 = new wxStaticLine( m_panel_list, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer9->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );


	bSizer12->Add( 0, 0, 1, wxEXPAND, 5 );

	m_toggleBtn_checkAllBuilder = new wxToggleButton( m_panel_list, wxID_ANY, _("Check all"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_toggleBtn_checkAllBuilder, 0, wxALL, 5 );


	bSizer12->Add( 0, 0, 1, wxEXPAND, 5 );

	m_searchCtrl_sentencesBuilder = new wxSearchCtrl( m_panel_list, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), 0 );
	#ifndef __WXMAC__
	m_searchCtrl_sentencesBuilder->ShowSearchButton( true );
	#endif
	m_searchCtrl_sentencesBuilder->ShowCancelButton( true );
	bSizer12->Add( m_searchCtrl_sentencesBuilder, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer12->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );

	m_checkBox_automaticSendBuilder = new wxCheckBox( m_panel_list, wxID_ANY, _("Automatic send at"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_checkBox_automaticSendBuilder, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_autoSendFreqBuilder = new wxSpinCtrlDouble( m_panel_list, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxSP_ARROW_KEYS, 0.1, 10, 1, 0.2 );
	m_spinCtrlDouble_autoSendFreqBuilder->SetDigits( 1 );
	bSizer17->Add( m_spinCtrlDouble_autoSendFreqBuilder, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText20 = new wxStaticText( m_panel_list, wxID_ANY, _("Hz"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer17->Add( m_staticText20, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer12->Add( bSizer17, 1, wxEXPAND, 5 );


	bSizer12->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_sentenceBuilderHelp = new wxButton( m_panel_list, wxID_ANY, _("Help"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_button_sentenceBuilderHelp, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer12->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer9->Add( bSizer12, 0, wxEXPAND, 5 );


	m_panel_list->SetSizer( bSizer9 );
	m_panel_list->Layout();
	bSizer9->Fit( m_panel_list );
	m_notebook->AddPage( m_panel_list, _("Sentence Builder"), true );
	m_panel_sim = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	m_scrolledWindow2 = new wxScrolledWindow( m_panel_sim, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow2->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxVERTICAL );


	bSizer26->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer_shipType;
	bSizer_shipType = new wxBoxSizer( wxHORIZONTAL );


	bSizer_shipType->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText901 = new wxStaticText( m_scrolledWindow2, wxID_ANY, _("Simulate:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText901->Wrap( -1 );
	bSizer_shipType->Add( m_staticText901, 0, wxALIGN_CENTER|wxALL, 5 );

	wxString m_choice_shipTypeChoices[] = { _("Own ship"), _("AIS target") };
	int m_choice_shipTypeNChoices = sizeof( m_choice_shipTypeChoices ) / sizeof( wxString );
	m_choice_shipType = new wxChoice( m_scrolledWindow2, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_shipTypeNChoices, m_choice_shipTypeChoices, 0 );
	m_choice_shipType->SetSelection( 0 );
	bSizer_shipType->Add( m_choice_shipType, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer_shipType->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer26->Add( bSizer_shipType, 0, wxEXPAND, 5 );


	bSizer26->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer_simPos;
	bSizer_simPos = new wxBoxSizer( wxHORIZONTAL );


	bSizer_simPos->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText83 = new wxStaticText( m_scrolledWindow2, wxID_ANY, _("Latitude"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText83->Wrap( -1 );
	bSizer_simPos->Add( m_staticText83, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_latSim = new wxTextCtrl( m_scrolledWindow2, wxID_ANY, _("0000.0000"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer_simPos->Add( m_textCtrl_latSim, 0, wxALIGN_CENTER|wxALL, 5 );

	wxString m_choice_latDirSimChoices[] = { _("N"), _("S") };
	int m_choice_latDirSimNChoices = sizeof( m_choice_latDirSimChoices ) / sizeof( wxString );
	m_choice_latDirSim = new wxChoice( m_scrolledWindow2, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_latDirSimNChoices, m_choice_latDirSimChoices, 0 );
	m_choice_latDirSim->SetSelection( 0 );
	bSizer_simPos->Add( m_choice_latDirSim, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText84 = new wxStaticText( m_scrolledWindow2, wxID_ANY, _("Longitude"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText84->Wrap( -1 );
	bSizer_simPos->Add( m_staticText84, 0, wxALIGN_CENTER|wxALL, 5 );

	m_textCtrl_lonSim = new wxTextCtrl( m_scrolledWindow2, wxID_ANY, _("00000.0000"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer_simPos->Add( m_textCtrl_lonSim, 0, wxALIGN_CENTER|wxALL, 5 );

	wxString m_choice_lonDirSimChoices[] = { _("E"), _("W") };
	int m_choice_lonDirSimNChoices = sizeof( m_choice_lonDirSimChoices ) / sizeof( wxString );
	m_choice_lonDirSim = new wxChoice( m_scrolledWindow2, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_lonDirSimNChoices, m_choice_lonDirSimChoices, 0 );
	m_choice_lonDirSim->SetSelection( 0 );
	bSizer_simPos->Add( m_choice_lonDirSim, 0, wxALIGN_CENTER|wxALL, 5 );

	m_button20 = new wxButton( m_scrolledWindow2, wxID_ANY, _("Update"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer_simPos->Add( m_button20, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer_simPos->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer26->Add( bSizer_simPos, 0, wxEXPAND, 5 );


	bSizer26->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer_dataSim;
	bSizer_dataSim = new wxBoxSizer( wxHORIZONTAL );


	bSizer_dataSim->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText902 = new wxStaticText( m_scrolledWindow2, wxID_ANY, _("Heading:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText902->Wrap( -1 );
	bSizer37->Add( m_staticText902, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText_headingSim = new wxStaticText( m_scrolledWindow2, wxID_ANY, _("0"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_staticText_headingSim->Wrap( -1 );
	bSizer37->Add( m_staticText_headingSim, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText92 = new wxStaticText( m_scrolledWindow2, wxID_ANY, _("deg"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText92->Wrap( -1 );
	bSizer37->Add( m_staticText92, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer_dataSim->Add( bSizer37, 0, wxEXPAND, 5 );


	bSizer_dataSim->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText1001 = new wxStaticText( m_scrolledWindow2, wxID_ANY, _("Course:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1001->Wrap( -1 );
	bSizer39->Add( m_staticText1001, 0, wxALL, 5 );

	m_staticText_cogSim = new wxStaticText( m_scrolledWindow2, wxID_ANY, _("0"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_staticText_cogSim->Wrap( -1 );
	bSizer39->Add( m_staticText_cogSim, 0, wxALL, 5 );

	m_staticText102 = new wxStaticText( m_scrolledWindow2, wxID_ANY, _("deg"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText102->Wrap( -1 );
	bSizer39->Add( m_staticText102, 0, wxALL, 5 );


	bSizer_dataSim->Add( bSizer39, 0, wxEXPAND, 5 );


	bSizer_dataSim->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText93 = new wxStaticText( m_scrolledWindow2, wxID_ANY, _("Speed:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText93->Wrap( -1 );
	bSizer38->Add( m_staticText93, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText_speedSim = new wxStaticText( m_scrolledWindow2, wxID_ANY, _("0"), wxDefaultPosition, wxSize( 20,-1 ), 0 );
	m_staticText_speedSim->Wrap( -1 );
	bSizer38->Add( m_staticText_speedSim, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText95 = new wxStaticText( m_scrolledWindow2, wxID_ANY, _("knots"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText95->Wrap( -1 );
	bSizer38->Add( m_staticText95, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer_dataSim->Add( bSizer38, 0, wxEXPAND, 5 );


	bSizer_dataSim->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer26->Add( bSizer_dataSim, 0, wxEXPAND, 5 );


	bSizer26->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer_commands;
	bSizer_commands = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer_turnRate;
	bSizer_turnRate = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );


	bSizer29->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText88 = new wxStaticText( m_scrolledWindow2, wxID_ANY, _("Rudder angle:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText88->Wrap( -1 );
	bSizer29->Add( m_staticText88, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText_rudderAngleSim = new wxStaticText( m_scrolledWindow2, wxID_ANY, _("0"), wxDefaultPosition, wxSize( 20,-1 ), 0 );
	m_staticText_rudderAngleSim->Wrap( -1 );
	bSizer29->Add( m_staticText_rudderAngleSim, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText90 = new wxStaticText( m_scrolledWindow2, wxID_ANY, _("deg"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText90->Wrap( -1 );
	bSizer29->Add( m_staticText90, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer29->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer_turnRate->Add( bSizer29, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxHORIZONTAL );


	bSizer36->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText99 = new wxStaticText( m_scrolledWindow2, wxID_ANY, _("-"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText99->Wrap( -1 );
	m_staticText99->SetFont( wxFont( 14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer36->Add( m_staticText99, 0, wxALIGN_CENTER|wxALL, 5 );

	m_slider_rudderSim = new wxSlider( m_scrolledWindow2, wxID_ANY, 0, -15, 15, wxDefaultPosition, wxSize( 200,-1 ), wxSL_HORIZONTAL );
	bSizer36->Add( m_slider_rudderSim, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText100 = new wxStaticText( m_scrolledWindow2, wxID_ANY, _("+"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText100->Wrap( -1 );
	bSizer36->Add( m_staticText100, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer36->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer_turnRate->Add( bSizer36, 1, wxEXPAND, 5 );

	m_button_resetRudder = new wxButton( m_scrolledWindow2, wxID_ANY, _("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer_turnRate->Add( m_button_resetRudder, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer_commands->Add( bSizer_turnRate, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer_simSpeed;
	bSizer_simSpeed = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer_simSpeed2;
	bSizer_simSpeed2 = new wxBoxSizer( wxHORIZONTAL );


	bSizer_simSpeed2->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText85 = new wxStaticText( m_scrolledWindow2, wxID_ANY, _("Throttle:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText85->Wrap( -1 );
	bSizer_simSpeed2->Add( m_staticText85, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText_throttleSim = new wxStaticText( m_scrolledWindow2, wxID_ANY, _("0"), wxDefaultPosition, wxSize( 20,-1 ), 0 );
	m_staticText_throttleSim->Wrap( -1 );
	bSizer_simSpeed2->Add( m_staticText_throttleSim, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText871 = new wxStaticText( m_scrolledWindow2, wxID_ANY, _("%"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText871->Wrap( -1 );
	bSizer_simSpeed2->Add( m_staticText871, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer_simSpeed2->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer_simSpeed->Add( bSizer_simSpeed2, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );


	bSizer35->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText971 = new wxStaticText( m_scrolledWindow2, wxID_ANY, _("-"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText971->Wrap( -1 );
	m_staticText971->SetFont( wxFont( 14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer35->Add( m_staticText971, 0, wxALIGN_CENTER|wxALL, 5 );

	m_slider_throttleSim = new wxSlider( m_scrolledWindow2, wxID_ANY, 0, -100, 100, wxDefaultPosition, wxSize( 200,-1 ), wxSL_HORIZONTAL );
	bSizer35->Add( m_slider_throttleSim, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText98 = new wxStaticText( m_scrolledWindow2, wxID_ANY, _("+"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText98->Wrap( -1 );
	bSizer35->Add( m_staticText98, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer35->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer_simSpeed->Add( bSizer35, 1, wxEXPAND, 5 );

	m_button_resetThrottle = new wxButton( m_scrolledWindow2, wxID_ANY, _("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer_simSpeed->Add( m_button_resetThrottle, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer_commands->Add( bSizer_simSpeed, 1, wxEXPAND, 5 );


	bSizer26->Add( bSizer_commands, 0, wxEXPAND, 5 );


	bSizer26->Add( 0, 0, 1, wxEXPAND, 5 );


	m_scrolledWindow2->SetSizer( bSizer26 );
	m_scrolledWindow2->Layout();
	bSizer26->Fit( m_scrolledWindow2 );
	bSizer8->Add( m_scrolledWindow2, 1, wxEXPAND | wxALL, 5 );

	m_staticline15 = new wxStaticLine( m_panel_sim, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer8->Add( m_staticline15, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer_StartStopSim;
	bSizer_StartStopSim = new wxBoxSizer( wxHORIZONTAL );


	bSizer_StartStopSim->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_startSim = new wxButton( m_panel_sim, wxID_ANY, _("START"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_startSim->SetFont( wxFont( 15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer_StartStopSim->Add( m_button_startSim, 0, wxALL, 5 );

	m_button_stopSim = new wxButton( m_panel_sim, wxID_ANY, _("STOP"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_stopSim->SetFont( wxFont( 15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer_StartStopSim->Add( m_button_stopSim, 0, wxALL, 5 );


	bSizer_StartStopSim->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer_StartStopSim, 0, wxEXPAND, 5 );


	m_panel_sim->SetSizer( bSizer8 );
	m_panel_sim->Layout();
	bSizer8->Fit( m_panel_sim );
	m_notebook->AddPage( m_panel_sim, _("Simulation"), false );

	bSizer_main->Add( m_notebook, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer_main );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyDialog::OnClose ) );
	this->Connect( m_timer_autoSendNmea.GetId(), wxEVT_TIMER, wxTimerEventHandler( MyDialog::OnTimer_autoSendNmea ) );
	this->Connect( m_timer_autoSendBuilder.GetId(), wxEVT_TIMER, wxTimerEventHandler( MyDialog::OnTimer_autoSendBuilder ) );
	this->Connect( m_timer_autoSendSim.GetId(), wxEVT_TIMER, wxTimerEventHandler( MyDialog::OnTimer_autoSendSim ) );
	m_textCtrl_sentenceInput->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyDialog::OnInputTextChanged ), NULL, this );
	m_checkBox_autoChecksum->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyDialog::OnAutoChecksumChecked ), NULL, this );
	m_button_sendSentence->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_manualSend ), NULL, this );
	m_button_clearInput->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnClearInput ), NULL, this );
	m_checkBox_automaticSend->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyDialog::OnCheckBox_AutomaticSend ), NULL, this );
	m_spinCtrlDouble_automaticSendFreq->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( MyDialog::OnSpinCtrlDouble_AutomaticSendFreq ), NULL, this );
	m_button_sendDBx->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendDBx ), NULL, this );
	m_button_sendDPT->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendDPT ), NULL, this );
	m_button_sendGGA->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendGGA ), NULL, this );
	m_button_sendGLL->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendGLL ), NULL, this );
	m_button_sendGSV->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendGSV ), NULL, this );
	m_button_sendHDG->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendHDG ), NULL, this );
	m_button_sendHDM->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendHDM ), NULL, this );
	m_button_sendHDT->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendHDT ), NULL, this );
	m_button_sendMTW->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendMTW ), NULL, this );
	m_button_sendMWD->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendMWD ), NULL, this );
	m_button_sendMWV->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendMWV ), NULL, this );
	m_button_sendOSD->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendOSD ), NULL, this );
	m_button_sendRMC->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendRMC ), NULL, this );
	m_button_sendROT->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendROT ), NULL, this );
	m_button_sendRSA->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendRSA ), NULL, this );
	m_button_sendTLL->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendTLL ), NULL, this );
	m_button_sendTHS->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendTHS ), NULL, this );
	m_button_sendVDR->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendVDR ), NULL, this );
	m_button_sendVHW->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendVHW ), NULL, this );
	m_button_sendVTG->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendVTG ), NULL, this );
	m_button_sendVWR->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendVWR ), NULL, this );
	m_button_sendWPL->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendWPL ), NULL, this );
	m_button_sendXDR->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendXDR ), NULL, this );
	m_choice_nameXDR->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog::OnChoice_UpdateXDR ), NULL, this );
	m_button_sendZDA->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_SendZDA ), NULL, this );
	m_toggleBtn_checkAllBuilder->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnToggleButton_CheckAllBuilders ), NULL, this );
	m_searchCtrl_sentencesBuilder->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyDialog::OnText_SearchSentenceBuilder ), NULL, this );
	m_checkBox_automaticSendBuilder->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyDialog::OnCheckBox_AutomaticSendBuilder ), NULL, this );
	m_spinCtrlDouble_autoSendFreqBuilder->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( MyDialog::OnSpinCtrlDouble_AutomaticSendFreqBuilder ), NULL, this );
	m_button_sentenceBuilderHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_OpenSentenceBuilderHelp ), NULL, this );
	m_button20->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_UpdateSimPos ), NULL, this );
	m_slider_rudderSim->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyDialog::OnScroll_UpdateRudderAngleSim ), NULL, this );
	m_slider_rudderSim->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyDialog::OnScroll_UpdateRudderAngleSim ), NULL, this );
	m_slider_rudderSim->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyDialog::OnScroll_UpdateRudderAngleSim ), NULL, this );
	m_slider_rudderSim->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyDialog::OnScroll_UpdateRudderAngleSim ), NULL, this );
	m_slider_rudderSim->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyDialog::OnScroll_UpdateRudderAngleSim ), NULL, this );
	m_slider_rudderSim->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyDialog::OnScroll_UpdateRudderAngleSim ), NULL, this );
	m_slider_rudderSim->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyDialog::OnScroll_UpdateRudderAngleSim ), NULL, this );
	m_slider_rudderSim->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyDialog::OnScroll_UpdateRudderAngleSim ), NULL, this );
	m_slider_rudderSim->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyDialog::OnScroll_UpdateRudderAngleSim ), NULL, this );
	m_button_resetRudder->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_ResetRudder ), NULL, this );
	m_slider_throttleSim->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyDialog::OnScroll_UpdateThrottleSim ), NULL, this );
	m_slider_throttleSim->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyDialog::OnScroll_UpdateThrottleSim ), NULL, this );
	m_slider_throttleSim->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyDialog::OnScroll_UpdateThrottleSim ), NULL, this );
	m_slider_throttleSim->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyDialog::OnScroll_UpdateThrottleSim ), NULL, this );
	m_slider_throttleSim->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyDialog::OnScroll_UpdateThrottleSim ), NULL, this );
	m_slider_throttleSim->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyDialog::OnScroll_UpdateThrottleSim ), NULL, this );
	m_slider_throttleSim->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyDialog::OnScroll_UpdateThrottleSim ), NULL, this );
	m_slider_throttleSim->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyDialog::OnScroll_UpdateThrottleSim ), NULL, this );
	m_slider_throttleSim->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyDialog::OnScroll_UpdateThrottleSim ), NULL, this );
	m_button_resetThrottle->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_ResetThrottle ), NULL, this );
	m_button_startSim->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_StartSim ), NULL, this );
	m_button_stopSim->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_StopSim ), NULL, this );
}

MyDialog::~MyDialog()
{
}
