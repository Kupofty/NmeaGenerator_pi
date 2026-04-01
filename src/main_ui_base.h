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
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/checkbox.h>
#include <wx/spinctrl.h>
#include <wx/timer.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog
///////////////////////////////////////////////////////////////////////////////
class MyDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText41;
		wxBoxSizer* bSizer_inputList;
		wxStaticLine* m_staticline2;
		wxButton* m_button_addNewInput;
		wxButton* m_button_eraseAllManualInputs;
		wxCheckBox* m_checkBox_automaticSendManual;
		wxSpinCtrlDouble* m_spinCtrlDouble_manualTimerFreq;
		wxStaticText* m_staticText4;
		wxTimer m_timer_autoSendNmea;

		// Virtual event handlers, override them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_AddNewInput( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClick_DeleteAllManualInputs( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCheckBox_AutomaticSendManual( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSpinCtrlDouble_UpdateManualTimerFreq( wxSpinDoubleEvent& event ) { event.Skip(); }
		virtual void OnTimer_AutoSendNmea( wxTimerEvent& event ) { event.Skip(); }


	public:

		MyDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("NMEA Generator Plugin"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 514,310 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );

		~MyDialog();

};

