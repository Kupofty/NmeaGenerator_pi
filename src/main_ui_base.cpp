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

	m_staticText41 = new wxStaticText( this, wxID_ANY, _("NMEA Sentences List"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText41->Wrap( -1 );
	m_staticText41->SetFont( wxFont( 12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxEmptyString ) );

	bSizer3->Add( m_staticText41, 0, wxALIGN_CENTER|wxALL, 5 );

	bSizer_inputList = new wxBoxSizer( wxVERTICAL );


	bSizer3->Add( bSizer_inputList, 1, wxEXPAND, 5 );


	bSizer3->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer3->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );


	bSizer4->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_addNewInput = new wxButton( this, wxID_ANY, _("Add new input"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button_addNewInput, 0, wxALIGN_CENTER|wxALL, 5 );

	m_button_eraseAllManualInputs = new wxButton( this, wxID_ANY, _("Delete all"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button_eraseAllManualInputs, 0, wxALL, 5 );


	bSizer4->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer3->Add( bSizer4, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );


	bSizer7->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox_automaticSendManual = new wxCheckBox( this, wxID_ANY, _("Automatic send at"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_checkBox_automaticSendManual, 0, wxALIGN_CENTER|wxALL, 5 );

	m_spinCtrlDouble_manualTimerFreq = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0.1, 10, 1.000000, 0.5 );
	m_spinCtrlDouble_manualTimerFreq->SetDigits( 1 );
	bSizer7->Add( m_spinCtrlDouble_manualTimerFreq, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Hz"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer7->Add( m_staticText4, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer7->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer3->Add( bSizer7, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer3 );
	this->Layout();
	m_timer_autoSendNmea.SetOwner( this, m_timer_autoSendNmea.GetId() );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyDialog::OnClose ) );
	m_button_addNewInput->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_AddNewInput ), NULL, this );
	m_button_eraseAllManualInputs->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog::OnButtonClick_DeleteAllManualInputs ), NULL, this );
	m_checkBox_automaticSendManual->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyDialog::OnCheckBox_AutomaticSendManual ), NULL, this );
	m_spinCtrlDouble_manualTimerFreq->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( MyDialog::OnSpinCtrlDouble_UpdateManualTimerFreq ), NULL, this );
	this->Connect( m_timer_autoSendNmea.GetId(), wxEVT_TIMER, wxTimerEventHandler( MyDialog::OnTimer_AutoSendNmea ) );
}

MyDialog::~MyDialog()
{
}
