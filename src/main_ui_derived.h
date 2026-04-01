#ifndef DIALOG_MAIN_GUI
#define DIALOG_MAIN_GUI


#include "main_ui_base.h"
#include <wx/timer.h>

class NmeaGeneratorPlugin;

struct ManualLine
{
  wxCheckBox* checkBox;
  wxTextCtrl* textCtrl;
  wxStaticText* checksumLabel;
  wxButton* sendBtn;
  wxButton* deleteBtn;
  wxBoxSizer* rowSizer;
};


class DialogMainGui : public MyDialog
{
  public:
    DialogMainGui(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("NmeaGenerator Plugin GUI"),
                  const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE);
    ~DialogMainGui();

    void stopAutomaticSendTimers();

    NmeaGeneratorPlugin* plugin = nullptr;

  protected:
    void OnClose(wxCloseEvent& event) override;
    void OnCheckBox_AutomaticSendManual( wxCommandEvent& event ) override;
    void OnSpinCtrlDouble_UpdateManualTimerFreq(wxSpinDoubleEvent& event) override;
    void OnTimer_AutoSendNmea(wxTimerEvent& event) override;
    void OnButtonClick_AddNewInput(wxCommandEvent& event) override;
    void OnButtonClick_DeleteAllManualInputs(wxCommandEvent& event) override;

  private:
    void sendNmea(wxString sentenceStr);
    void AddNewManualLine();

    std::vector<ManualLine> m_lines;

};

#endif //DIALOG_MAIN_GUI
