#ifndef DIALOG_MAIN_GUI
#define DIALOG_MAIN_GUI


#include "main_ui_base.h"
#include <vector>
#include <wx/timer.h>

#include "ais_encoder.h"
#include "nmea_builder.h"

class NmeaGeneratorPlugin;


struct SectionItem
{
  wxString name;
  wxStaticBoxSizer* sizer;
};

struct TimerItem
{
  wxTimer* timer;
  wxCheckBox* checkbox;
};

struct SimVessel
{
  double lat = 0;
  double lon = 0 ;
  double heading = 0;
  double cog = 0;
  double speed = 0;
  double throttle = 0;
  double rudderAngle = 0;
  int directionSign = 1;
};

enum class VesselType { OwnShip, AisTarget };


// Main class
class DialogMainGui : public MyDialog
{
  public:
    DialogMainGui(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("NmeaGenerator Plugin GUI"),
                  const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE);
    ~DialogMainGui();

    void updateSimStartPosition(double lat, double lon);
    void stopTimers();

    NmeaGeneratorPlugin* plugin = nullptr;

  protected:
    void OnClose(wxCloseEvent& event) override;

    void OnButtonClick_manualSend(wxCommandEvent& event) override;
    void OnClearInput(wxCommandEvent& event) override;
    void OnInputTextChanged(wxCommandEvent& event) override;
    void OnAutoChecksumChecked(wxCommandEvent& event) override;
    void OnCheckBox_AutomaticSend( wxCommandEvent& event ) override;
    void OnSpinCtrlDouble_AutomaticSendFreq(wxSpinDoubleEvent& event) override;
    void OnTimer_autoSendNmea(wxTimerEvent& event) override;
    void OnToggleButton_CheckAllBuilders(wxCommandEvent& event) override;
    void OnCheckBox_AutomaticSendBuilder(wxCommandEvent& event) override;
    void OnSpinCtrlDouble_AutomaticSendFreqBuilder(wxSpinDoubleEvent& event) override;
    void OnTimer_autoSendBuilder(wxTimerEvent& event) override;
    void OnText_SearchSentenceBuilder(wxCommandEvent& event) override;
    void OnButtonClick_OpenSentenceBuilderHelp(wxCommandEvent& event) override;
    void OnTimer_autoSendSim(wxTimerEvent& event) override;
    void OnToggleButton_StartStopSim(wxCommandEvent& event) override;
    void OnButtonClick_UpdateSimPos(wxCommandEvent& event) override;
    void OnScroll_UpdateThrottleSim(wxScrollEvent& event) override;
    void OnScroll_UpdateRudderAngleSim(wxScrollEvent& event) override;
    void OnButtonClick_ResetRudder(wxCommandEvent& event) override;
    void OnButtonClick_ResetThrottle(wxCommandEvent& event) override;
    void OnChoice_UpdateXDR(wxCommandEvent& event) override;
    void OnButtonClick_copyManualSentence(wxCommandEvent& event) override;
    void OnSpinCtrlDouble_UpdateFreqTimerSim(wxSpinDoubleEvent& event) override;
    void OnChoice_controlledVesselSimChanged(wxCommandEvent& event) override;

    void OnButtonClick_SendGLL(wxCommandEvent& event) override;
    void OnButtonClick_SendRMC(wxCommandEvent& event) override;
    void OnButtonClick_SendGGA(wxCommandEvent& event) override;
    void OnButtonClick_SendHDT(wxCommandEvent& event) override;
    void OnButtonClick_SendHDM(wxCommandEvent& event) override;
    void OnButtonClick_SendHDG(wxCommandEvent& event) override;
    void OnButtonClick_SendMTW(wxCommandEvent& event) override;
    void OnButtonClick_SendTLL(wxCommandEvent& event) override;
    void OnButtonClick_SendROT(wxCommandEvent& event) override;
    void OnButtonClick_SendRSA(wxCommandEvent& event) override;
    void OnButtonClick_SendDPT(wxCommandEvent& event) override;
    void OnButtonClick_SendDBx(wxCommandEvent& event) override;
    void OnButtonClick_SendTHS(wxCommandEvent& event) override;
    void OnButtonClick_SendWPL(wxCommandEvent& event) override;
    void OnButtonClick_SendVTG(wxCommandEvent& event) override;
    void OnButtonClick_SendGSV(wxCommandEvent& event) override;
    void OnButtonClick_SendXDR(wxCommandEvent& event) override;
    void OnButtonClick_SendOSD(wxCommandEvent& event) override;
    void OnButtonClick_SendMWV(wxCommandEvent& event) override;
    void OnButtonClick_SendMWD(wxCommandEvent& event) override;
    void OnButtonClick_SendVDM(wxCommandEvent& event) override;
    void OnButtonClick_SendVDR(wxCommandEvent& event) override;
    void OnButtonClick_SendVHW(wxCommandEvent& event) override;
    void OnButtonClick_SendVWR(wxCommandEvent& event) override;
    void OnButtonClick_SendZDA(wxCommandEvent& event) override;

  private:
    void copyToClipboard(wxString text);
    void sendNmeaToOCPN(wxString sentence);
    void sendManualInput();
    void updateAutoSendBuildersCheckboxes(bool check);
    void sendAndMaybeCopy(const wxString& msg);
    SimVessel* getControlledVessel();

    //Create nmea from SentenceBuilder tab
    wxString createFromGuiGLL();
    wxString createFromGuiRMC();
    wxString createFromGuiGGA();
    wxString createFromGuiHDT();
    wxString createFromGuiHDM();
    wxString createFromGuiHDG();
    wxString createFromGuiMTW();
    wxString createFromGuiTLL();
    wxString createFromGuiROT();
    wxString createFromGuiRSA();
    wxString createFromGuiDPT();
    wxString createFromGuiDBx();
    wxString createFromGuiTHS();
    wxString createFromGuiWPL();
    wxString createFromGuiVTG();
    wxString createFromGuiGSV();
    wxString createFromGuiXDR();
    wxString createFromGuiOSD();
    wxString createFromGuiMWV();
    wxString createFromGuiMWD();
    wxString createFromGuiVDM();
    wxString createFromGuiVDR();
    wxString createFromGuiVHW();
    wxString createFromGuiVWR();
    wxString createFromGuiZDA();

    bool addAutoChecksum;
    std::vector<SectionItem> sbSizerListSentenceBuilder;

    //Simulation
    VesselType controlledVessel = VesselType::OwnShip;
    SimVessel shipSimu;
    SimVessel aisSimu;
};

#endif //DIALOG_MAIN_GUI
