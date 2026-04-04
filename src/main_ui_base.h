///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/timer.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/checkbox.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/spinctrl.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include <wx/statbox.h>
#include <wx/scrolwin.h>
#include <wx/srchctrl.h>
#include <wx/notebook.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog
///////////////////////////////////////////////////////////////////////////////
class MyDialog : public wxDialog
{
	private:

	protected:
		wxTimer m_timer_autoSendNmea;
		wxTimer m_timer_autoSendBuilder;
		wxPanel* m_panel_manual;
		wxStaticText* m_staticText3;
		wxTextCtrl* m_textCtrl_sentenceInput;
		wxStaticText* m_staticText_checksum;
		wxCheckBox* m_checkBox_autoChecksum;
		wxStaticLine* m_staticline1;
		wxButton* m_button_sendSentence;
		wxButton* m_button_clearInput;
		wxCheckBox* m_checkBox_automaticSend;
		wxSpinCtrlDouble* m_spinCtrlDouble_automaticSendFreq;
		wxStaticText* m_staticText4;
		wxPanel* m_panel2;
		wxScrolledWindow* m_scrolledWindow_sentenceBuilder;
		wxBoxSizer* bSizer_NmeaList;
		wxStaticBoxSizer* sbSizer_RMC;
		wxButton* m_button_sendRMC;
		wxCheckBox* m_checkBox_autoSendRMC;
		wxStaticLine* m_staticline6;
		wxStaticText* m_staticText13;
		wxStaticText* m_staticText141;
		wxStaticText* m_staticText151;
		wxStaticText* m_staticText16;
		wxStaticText* m_staticText181;
		wxStaticText* m_staticText201;
		wxStaticText* m_staticText26;
		wxStaticText* m_staticText27;
		wxStaticText* m_staticText28;
		wxTextCtrl* m_textCtrl_talkerRMC;
		wxStaticText* m_staticText22;
		wxTextCtrl* m_textCtrl_timeRMC;
		wxChoice* m_choice_statusRMC;
		wxTextCtrl* m_textCtrl_latitudeRMC;
		wxChoice* m_choice_latDirRMC;
		wxTextCtrl* m_textCtrl_longitudeRMC;
		wxChoice* m_choice_lonDirRMC;
		wxSpinCtrlDouble* m_spinCtrlDouble_sogRMC;
		wxSpinCtrlDouble* m_spinCtrlDouble_cogRMC;
		wxTextCtrl* m_textCtrl_dateRMC;
		wxSpinCtrlDouble* m_spinCtrlDouble_magRMC;
		wxChoice* m_choice_magDirRMC;
		wxStaticBoxSizer* sbSizer_GGA;
		wxButton* m_button_sendGGA;
		wxCheckBox* m_checkBox_autoSendGGA;
		wxStaticLine* m_staticline8;
		wxStaticText* m_staticText29;
		wxStaticText* m_staticText30;
		wxStaticText* m_staticText31;
		wxStaticText* m_staticText32;
		wxStaticText* m_staticText33;
		wxStaticText* m_staticText34;
		wxStaticText* m_staticText35;
		wxStaticText* m_staticText36;
		wxStaticText* m_staticText37;
		wxTextCtrl* m_textCtrl_talkerGGA;
		wxStaticText* m_staticText40;
		wxTextCtrl* m_textCtrl_timeGGA;
		wxTextCtrl* m_textCtrl_latitudeGGA;
		wxChoice* m_choice_latDirGGA;
		wxTextCtrl* m_textCtrl_longitudeGGA;
		wxChoice* m_choice_lonDirGGA;
		wxSpinCtrl* m_spinCtrl_gpsQualityGGA;
		wxSpinCtrl* m_spinCtrl_satellitesGGA;
		wxSpinCtrlDouble* m_spinCtrlDouble_hdopGGA;
		wxSpinCtrlDouble* m_spinCtrlDouble_altitude_GGA;
		wxStaticText* m_staticText411;
		wxSpinCtrlDouble* m_spinCtrlDouble_geoidSeparationGGA;
		wxStaticText* m_staticText42;
		wxStaticBoxSizer* sbSizer_TLL;
		wxButton* m_button_sendTLL;
		wxCheckBox* m_checkBox_autoSendTLL;
		wxStaticLine* m_staticline61111;
		wxStaticText* m_staticText351111;
		wxStaticText* m_staticText361111;
		wxStaticText* m_staticText63;
		wxStaticText* m_staticText64;
		wxStaticText* m_staticText65;
		wxStaticText* m_staticText66;
		wxStaticText* m_staticText67;
		wxTextCtrl* m_textCtrl_talkerTLL;
		wxStaticText* m_staticText371111;
		wxSpinCtrl* m_spinCtrl_idTLL;
		wxTextCtrl* m_textCtrl_latitudeTLL;
		wxChoice* m_choice_latDirTLL;
		wxTextCtrl* m_textCtrl_longitudeTLL;
		wxChoice* m_choice_lonDirTLL;
		wxTextCtrl* m_textCtrl_nameTLL;
		wxTextCtrl* m_textCtrl_timeTLL;
		wxChoice* m_choice_statusTLL;
		wxStaticText* m_staticText68;
		wxStaticBoxSizer* sbSizer_GLL;
		wxButton* m_button_sendGLL;
		wxCheckBox* m_checkBox_autoSendGLL;
		wxStaticLine* m_staticline5;
		wxStaticText* m_staticText19;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText11;
		wxStaticText* m_staticText14;
		wxStaticText* m_staticText15;
		wxStaticText* m_staticText18;
		wxTextCtrl* m_textCtrl_talkerGLL;
		wxStaticText* m_staticText5;
		wxTextCtrl* m_textCtrl_latitudeGLL;
		wxChoice* m_choice_latDirGLL;
		wxTextCtrl* m_textCtrl_longitudeGLL;
		wxChoice* m_choice_lonDirGLL;
		wxTextCtrl* m_textCtrl_timeGLL;
		wxChoice* m_choice_statusGLL;
		wxChoice* m_choice_modeGLL;
		wxStaticBoxSizer* sbSizer_HDT;
		wxButton* m_button_sendHDT;
		wxCheckBox* m_checkBox_autoSendHDT;
		wxStaticLine* m_staticline61;
		wxStaticText* m_staticText351;
		wxStaticText* m_staticText361;
		wxTextCtrl* m_textCtrl_talkerHDT;
		wxStaticText* m_staticText371;
		wxSpinCtrlDouble* m_spinCtrlDouble_headingHDT;
		wxStaticText* m_staticText38;
		wxStaticBoxSizer* sbSizer_HDM;
		wxButton* m_button_sendHDM;
		wxCheckBox* m_checkBox_autoSendHDM;
		wxStaticLine* m_staticline611;
		wxStaticText* m_staticText3511;
		wxStaticText* m_staticText3611;
		wxTextCtrl* m_textCtrl_talkerHDM;
		wxStaticText* m_staticText3711;
		wxSpinCtrlDouble* m_spinCtrlDouble_headingHDM;
		wxStaticText* m_staticText381;
		wxStaticBoxSizer* sbSizer_HDG;
		wxButton* m_button_sendHDG;
		wxCheckBox* m_checkBox_autoSendHDG;
		wxStaticLine* m_staticline6112;
		wxStaticText* m_staticText35112;
		wxStaticText* m_staticText36112;
		wxStaticText* m_staticText96;
		wxStaticText* m_staticText97;
		wxTextCtrl* m_textCtrl_talkerHDG;
		wxStaticText* m_staticText37112;
		wxSpinCtrlDouble* m_spinCtrlDouble_headingHDG;
		wxSpinCtrlDouble* m_spinCtrlDouble_deviationHDG;
		wxChoice* m_choice_deviationDirHDG;
		wxSpinCtrlDouble* m_spinCtrlDouble_variationHDG;
		wxChoice* m_choice_variationDirHDG;
		wxStaticBoxSizer* sbSizer_MTW;
		wxButton* m_button_sendMTW;
		wxCheckBox* m_checkBox_autoSendMTW;
		wxStaticLine* m_staticline6111;
		wxStaticText* m_staticText35111;
		wxStaticText* m_staticText36111;
		wxTextCtrl* m_textCtrl_talkerMTW;
		wxStaticText* m_staticText37111;
		wxSpinCtrlDouble* m_spinCtrlDouble_tempMTW;
		wxStaticText* m_staticText3811;
		wxStaticBoxSizer* sbSizer_ROT;
		wxButton* m_button_sendROT;
		wxCheckBox* m_checkBox_autoSendROT;
		wxStaticLine* m_staticline61112;
		wxStaticText* m_staticText351112;
		wxStaticText* m_staticText361112;
		wxStaticText* m_staticText77;
		wxTextCtrl* m_textCtrl_talkerROT;
		wxStaticText* m_staticText371112;
		wxSpinCtrlDouble* m_spinCtrlDouble_rateROT;
		wxChoice* m_choice_statusROT;
		wxStaticBoxSizer* sbSizer_RSA;
		wxButton* m_button_sendRSA;
		wxCheckBox* m_checkBox_autoSendRSA;
		wxStaticLine* m_staticline611121;
		wxStaticText* m_staticText3511121;
		wxStaticText* m_staticText3611121;
		wxStaticText* m_staticText771;
		wxStaticText* m_staticText86;
		wxStaticText* m_staticText87;
		wxTextCtrl* m_textCtrl_talkerRSA;
		wxStaticText* m_staticText3711121;
		wxSpinCtrlDouble* m_spinCtrlDouble_starboardRSA;
		wxChoice* m_choice_starboardStatusRSA;
		wxSpinCtrlDouble* m_spinCtrlDouble_portRSA;
		wxChoice* m_choice_statusPortRSA;
		wxStaticBoxSizer* sbSizer_DPT;
		wxButton* m_button_sendDPT;
		wxCheckBox* m_checkBox_autoSendDPT;
		wxStaticLine* m_staticline61113;
		wxStaticText* m_staticText351113;
		wxStaticText* m_staticText361113;
		wxStaticText* m_staticText106;
		wxTextCtrl* m_textCtrl_talkerDPT;
		wxStaticText* m_staticText371113;
		wxSpinCtrlDouble* m_spinCtrlDouble_depthDPT;
		wxSpinCtrlDouble* m_spinCtrlDouble_offsetDPT;
		wxStaticBoxSizer* sbSizer_DBx;
		wxButton* m_button_sendDBx;
		wxCheckBox* m_checkBox_autoSendDBx;
		wxStaticLine* m_staticline611131;
		wxStaticText* m_staticText3511131;
		wxStaticText* m_staticText3611131;
		wxStaticText* m_staticText1061;
		wxStaticText* m_staticText115;
		wxTextCtrl* m_textCtrl_talkerDBx;
		wxChoice* m_choice_sentenceDBx;
		wxSpinCtrlDouble* m_spinCtrlDouble_depthFeetDBx;
		wxStaticText* m_staticText116;
		wxSpinCtrlDouble* m_spinCtrlDouble_depthMeterDBx;
		wxStaticText* m_staticText117;
		wxSpinCtrlDouble* m_spinCtrlDouble_depthFathomDBx;
		wxStaticText* m_staticText118;
		wxStaticLine* m_staticline3;
		wxButton* m_button_checkAllBuilder;
		wxButton* m_button_uncheckAllBuilder;
		wxSearchCtrl* m_searchCtrl_sentencesBuilder;
		wxCheckBox* m_checkBox_automaticSendBuilder;
		wxSpinCtrlDouble* m_spinCtrlDouble_autoSendFreqBuilder;
		wxStaticText* m_staticText20;
		wxButton* m_button_sentenceBuilderHelp;
		wxPanel* m_panel3;
		wxStaticText* m_staticText41;

		// Virtual event handlers, override them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnTimer_autoSendNmea( wxTimerEvent& event ) { event.Skip(); }
		virtual void OnTimer_autoSendBuilder( wxTimerEvent& event ) { event.Skip(); }
		virtual void OnInputTextChanged( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAutoChecksumChecked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_manualSend( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClearInput( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCheckBox_AutomaticSend( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSpinCtrlDouble_AutomaticSendFreq( wxSpinDoubleEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_SendRMC( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_SendGGA( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_SendTLL( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_SendGLL( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_SendHDT( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_SendHDM( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_SendHDG( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_SendMTW( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_SendROT( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_SendRSA( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_SendDPT( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_SendDBx( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_CheckAllBuilder( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_UncheckAllBuilder( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnText_SearchSentenceBuilder( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCheckBox_AutomaticSendBuilder( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSpinCtrlDouble_AutomaticSendFreqBuilder( wxSpinDoubleEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_OpenSentenceBuilderHelp( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxNotebook* m_notebook;

		MyDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("NMEA Generator Plugin"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 980,798 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );

		~MyDialog();

};

