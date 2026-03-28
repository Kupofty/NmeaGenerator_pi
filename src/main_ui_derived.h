#ifndef DIALOG_MAIN_GUI
#define DIALOG_MAIN_GUI


#include "main_ui_base.h"

class DialogMainGui : public MyDialog
{
  public:
    DialogMainGui(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("NmeaGenerator Plugin GUI"),
                  const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE);
    ~DialogMainGui();
};

#endif //DIALOG_MAIN_GUI
