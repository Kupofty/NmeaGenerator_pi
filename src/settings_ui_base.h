///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6-dirty)
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
#include <wx/choice.h>
#include <wx/sizer.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class DialogSettingsBase
///////////////////////////////////////////////////////////////////////////////
class DialogSettingsBase : public wxDialog
{
	private:

	protected:
		wxNotebook* m_notebook1;
		wxPanel* m_panel_display;
		wxStaticText* m_staticText3;
		wxChoice* m_choice_notebookPage;
		wxCheckBox* m_checkBox_restoreLastTab;
		wxCheckBox* m_checkBox_restoreWindowPos;
		wxCheckBox* m_checkBox_restoreWindowSize;
		wxPanel* m_panel_options;
		wxCheckBox* m_checkBox_keepSendingData;
		wxCheckBox* m_checkBox_copyNmeaToClipboard;
		wxButton* buttonOK;
		wxButton* buttonApply;

		// Virtual event handlers, override them in your derived class
		virtual void OnInit( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnApply( wxCommandEvent& event ) { event.Skip(); }


	public:

		DialogSettingsBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("NmeaGenerator Plugin Preferences"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 352,331 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );

		~DialogSettingsBase();

};

