#ifndef DIALOG_MAIN_GUI
#define DIALOG_MAIN_GUI


#include "main_ui_base.h"
#include <wx/timer.h>

class NmeaGeneratorPlugin;

struct SectionItem
{
  wxString name;
  wxStaticBoxSizer* sizer;
};

class DialogMainGui : public MyDialog
{
  public:
    DialogMainGui(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("NmeaGenerator Plugin GUI"),
                  const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE);
    ~DialogMainGui();

    void stopTimers();

    NmeaGeneratorPlugin* plugin = nullptr;

  protected:
    //window
    void OnClose(wxCloseEvent& event) override;

    void OnButtonClick_manualSend(wxCommandEvent& event) override;
    void OnClearInput(wxCommandEvent& event) override;
    void OnInputTextChanged(wxCommandEvent& event) override;
    void OnAutoChecksumChecked(wxCommandEvent& event) override;
    void OnCheckBox_AutomaticSend( wxCommandEvent& event ) override;
    void OnSpinCtrlDouble_AutomaticSendFreq(wxSpinDoubleEvent& event) override;
    void OnTimer_autoSendNmea(wxTimerEvent& event) override;
    void OnButtonClick_SendGLL(wxCommandEvent& event) override;
    void OnButtonClick_SendRMC(wxCommandEvent& event) override;
    void OnButtonClick_SendGGA(wxCommandEvent& event) override;
    void OnButtonClick_CheckAllBuilder(wxCommandEvent& event) override;
    void OnButtonClick_UncheckAllBuilder(wxCommandEvent& event) override;
    void OnCheckBox_AutomaticSendBuilder(wxCommandEvent& event) override;
    void OnSpinCtrlDouble_AutomaticSendFreqBuilder(wxSpinDoubleEvent& event) override;
    void OnTimer_autoSendBuilder(wxTimerEvent& event) override;
    void OnText_SearchSentenceBuilder(wxCommandEvent& event) override;

  private:
    void sendNmeaToOCPN(wxString sentence);
    void sendManualInput();
    void updateAutoSendBuildersCheckboxes(bool check);

    void sendGLL();
    void sendRMC();
    void sendGGA();

    bool addAutoChecksum;
    std::vector<SectionItem> sbSizerListSentenceBuilder;
};

#endif //DIALOG_MAIN_GUI
