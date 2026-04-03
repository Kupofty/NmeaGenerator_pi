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
		wxButton* m_button_sendGLL;
		wxCheckBox* m_checkBox_autoSendGLL;
		wxStaticLine* m_staticline5;
		wxStaticText* m_staticText19;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText11;
		wxStaticText* m_staticText14;
		wxStaticText* m_staticText15;
		wxStaticText* m_staticText18;
		wxTextCtrl* m_textCtrl_idGLL;
		wxStaticText* m_staticText5;
		wxTextCtrl* m_textCtrl_latitudeGLL;
		wxChoice* m_choice_latDirGLL;
		wxTextCtrl* m_textCtrl_longitudeGLL;
		wxChoice* m_choice_lonDirGLL;
		wxTextCtrl* m_textCtrl_timeGLL;
		wxChoice* m_choice_statusGLL;
		wxChoice* m_choice_modeGLL;
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
		wxTextCtrl* m_textCtrl_idRMC;
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
		wxStaticLine* m_staticline3;
		wxButton* m_button_checkAllBuilder;
		wxButton* m_button_uncheckAllBuilder;
		wxCheckBox* m_checkBox_automaticSendBuilder;
		wxSpinCtrlDouble* m_spinCtrlDouble_autoSendFreqBuilder;
		wxStaticText* m_staticText20;
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
		virtual void OnButtonClick_SendGLL( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_SendRMC( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_CheckAllBuilder( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_UncheckAllBuilder( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCheckBox_AutomaticSendBuilder( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSpinCtrlDouble_AutomaticSendFreqBuilder( wxSpinDoubleEvent& event ) { event.Skip(); }


	public:
		wxNotebook* m_notebook;

		MyDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("NMEA Generator Plugin"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 957,371 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );

		~MyDialog();

};

