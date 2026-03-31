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

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3 = new wxStaticText( this, wxID_ANY, _("NMEA sentence:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer4->Add( m_staticText3, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_textCtrl_sentenceInput = new wxTextCtrl( this, wxID_ANY, _("$"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl_sentenceInput->SetMinSize( wxSize( 200,-1 ) );

	bSizer4->Add( m_textCtrl_sentenceInput, 1, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );

	m_staticText_checksum = new wxStaticText( this, wxID_ANY, _("*00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_checksum->Wrap( -1 );
	bSizer4->Add( m_staticText_checksum, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer3->Add( bSizer4, 1, wxEXPAND, 5 );

	m_checkBox_autoChecksum = new wxCheckBox( this, wxID_ANY, _("Automatic checksum calculation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox_autoChecksum->SetValue(true);
	bSizer3->Add( m_checkBox_autoChecksum, 1, wxALIGN_CENTER|wxALL, 5 );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer3->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );


	bSizer5->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_sendSentence = new wxButton( this, wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button_sendSentence, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_button_clearInput = new wxButton( this, wxID_ANY, _("Clear"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button_clearInput, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer5->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer3->Add( bSizer5, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );


	bSizer7->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox_automaticSend = new wxCheckBox( this, wxID_ANY, _("Automatic send at"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_checkBox_automaticSend, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_automaticSendFreq = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0.1, 10, 1.000000, 0.5 );
	m_spinCtrlDouble_automaticSendFreq->SetDigits( 1 );
	bSizer7->Add( m_spinCtrlDouble_automaticSendFreq, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Hz"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer7->Add( m_staticText4, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer7->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer3->Add( bSizer7, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer3 );
	this->Layout();
	m_timer_autoSendNmea.SetOwner( this, m_timer_autoSendNmea.GetId() );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyDialog::OnClose ) );
	m_textCtrl_sentenceInput->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyDialog::OnInputTextChanged ), NULL, this );
	m_checkBox_autoChecksum->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyDialog::OnAutoChecksumChecked ), NULL, this );
	m_button_sendSentence->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_manualSend ), NULL, this );
	m_button_clearInput->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnClearInput ), NULL, this );
	m_checkBox_automaticSend->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyDialog::OnCheckBox_AutomaticSend ), NULL, this );
	m_spinCtrlDouble_automaticSendFreq->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( MyDialog::OnSpinCtrlDouble_AutomaticSendFreq ), NULL, this );
	this->Connect( m_timer_autoSendNmea.GetId(), wxEVT_TIMER, wxTimerEventHandler( MyDialog::OnTimer_autoSendNmea ) );
}

MyDialog::~MyDialog()
{
}
