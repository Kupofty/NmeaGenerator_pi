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

	checkBoxBoolean = new wxCheckBox( this, wxID_ANY, _("Some Boolean Value"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerSettings->Add( checkBoxBoolean, 0, wxALL, 5 );

	labelInteger = new wxStaticText( this, wxID_ANY, _("Some Integer Value"), wxDefaultPosition, wxDefaultSize, 0 );
	labelInteger->Wrap( -1 );
	sizerSettings->Add( labelInteger, 0, wxALL, 5 );

	sliderInteger = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_MIN_MAX_LABELS|wxSL_VALUE_LABEL );
	sizerSettings->Add( sliderInteger, 0, wxALL|wxEXPAND, 5 );

	labelString = new wxStaticText( this, wxID_ANY, _("Some String Value"), wxDefaultPosition, wxDefaultSize, 0 );
	labelString->Wrap( -1 );
	sizerSettings->Add( labelString, 0, wxALL, 5 );

	textString = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sizerSettings->Add( textString, 0, wxALL|wxEXPAND, 5 );


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

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( DialogSettingsBase::OnInit ) );
	checkBoxBoolean->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettingsBase::OnCheckBoolean ), NULL, this );
	sliderInteger->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( DialogSettingsBase::OnSliderChanged ), NULL, this );
	sliderInteger->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( DialogSettingsBase::OnSliderChanged ), NULL, this );
	sliderInteger->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( DialogSettingsBase::OnSliderChanged ), NULL, this );
	sliderInteger->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( DialogSettingsBase::OnSliderChanged ), NULL, this );
	sliderInteger->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( DialogSettingsBase::OnSliderChanged ), NULL, this );
	sliderInteger->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( DialogSettingsBase::OnSliderChanged ), NULL, this );
	sliderInteger->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( DialogSettingsBase::OnSliderChanged ), NULL, this );
	sliderInteger->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( DialogSettingsBase::OnSliderChanged ), NULL, this );
	sliderInteger->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( DialogSettingsBase::OnSliderChanged ), NULL, this );
	textString->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( DialogSettingsBase::OnTextChanged ), NULL, this );
	buttonOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettingsBase::OnOK ), NULL, this );
	buttonApply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettingsBase::OnApply ), NULL, this );
	buttonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettingsBase::OnCancel ), NULL, this );
}

DialogSettingsBase::~DialogSettingsBase()
{
}
