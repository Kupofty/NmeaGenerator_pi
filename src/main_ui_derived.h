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

struct TimerItem
{
  wxTimer* timer;
  wxCheckBox* checkbox;
};

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
    void OnButtonClick_StartSim(wxCommandEvent& event) override;
    void OnButtonClick_StopSim(wxCommandEvent& event) override;
    void OnButtonClick_UpdateSimPos(wxCommandEvent& event) override;
    void OnScroll_UpdateThrottleSim(wxScrollEvent& event) override;
    void OnScroll_UpdateRudderAngleSim(wxScrollEvent& event) override;
    void OnButtonClick_ResetRudder(wxCommandEvent& event) override;
    void OnButtonClick_ResetThrottle(wxCommandEvent& event) override;
    void OnChoice_UpdateXDR(wxCommandEvent& event) override;

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
    void OnButtonClick_SendVDR(wxCommandEvent& event) override;
    void OnButtonClick_SendVHW(wxCommandEvent& event) override;
    void OnButtonClick_SendVWR(wxCommandEvent& event) override;
    void OnButtonClick_SendZDA(wxCommandEvent& event) override;

  private:
    void sendNmeaToOCPN(wxString sentence);
    void sendManualInput();
    void updateAutoSendBuildersCheckboxes(bool check);

    //Generic "send nmea" functions
    void sendGLL(wxString talker, wxString lat, wxString latDir, wxString lon, wxString lonDir, wxString time, wxString status, wxString mode);
    void sendRMC(wxString talker, wxString time, wxString status, wxString lat, wxString latDir, wxString lon, wxString lonDir, wxString sogKnot, wxString cogDeg, wxString date, wxString magVarDeg, wxString magVarDir);
    void sendGGA(wxString talker, wxString time, wxString lat, wxString latDir, wxString lon, wxString lonDir, wxString gpsFix, wxString satellitesNb, wxString hdop, wxString altitudeMeter, wxString geoid);
    void sendHDT(wxString talker, wxString headingDeg);
    void sendHDM(wxString talker, wxString headingDeg);
    void sendHDG(wxString talker, wxString headingDeg, wxString deviationDeg, wxString deviationDir, wxString variationDeg, wxString variationDir);
    void sendMTW(wxString talker, wxString tempCelsius);
    void sendTLL(wxString talker, wxString targetID, wxString lat, wxString latDir, wxString lon, wxString lonDir, wxString name, wxString time, wxString status, wxString ref);
    void sendROT(wxString talker, wxString rateDegPerMin, wxString status);
    void sendRSA(wxString talker, wxString stbdAngleDeg, wxString stbdStatus, wxString portAngleDeg, wxString portStatus);
    void sendDPT(wxString talker, wxString depthMeter, wxString offsetMeter);
    void sendDBx(wxString talker, wxString nmeaType, wxString depthFeet, wxString depthMeter, wxString depthFathom);
    void sendTHS(wxString talker, wxString heading, wxString mode);
    void sendWPL(wxString talker, wxString latitude, wxString latDir, wxString longitude, wxString lonDir, wxString wpName);
    void sendVTG(wxString talker, wxString cogTrue, wxString cogMag, wxString sogKnot, wxString sogKph, wxString mode);
    void sendGSV(wxString talker, wxString totalSentences, wxString sentenceNumber, wxString totalSatellites, wxString PRN, wxString elevationDeg, wxString azimuthDeg, wxString SNR);
    void sendXDR(wxString talker, wxString type, wxString measurement, wxString unit, wxString name);
    void sendOSD(wxString talker, wxString heading, wxString status, wxString course, wxString courseRef, wxString speed, wxString speedRef, wxString driftAngle, wxString driftSpeed, wxString speedUnit);
    void sendMWV(wxString talker, wxString angle, wxString reference, wxString speed, wxString unit, wxString status);
    void sendMWD(wxString talker, wxString directionTrue, wxString directionMag, wxString speedKnot, wxString speedMph);
    void sendVDR(wxString talker, wxString directionTrue, wxString directionMag, wxString currentSpeedKnot);
    void sendVHW(wxString talker, wxString headingTrue, wxString headingMag, wxString stwKnot, wxString stwKph);
    void sendVWR(wxString talker, wxString angle, wxString direction, wxString speedKnot, wxString speedMps, wxString speedKph);
    void sendZDA(wxString talker, wxString time, wxString day, wxString month, wxString year, wxString hourOffset, wxString minuteOffset);

    //Send nmea from SentenceBuilder tab
    void sendSentenceBuilderGLL();
    void sendSentenceBuilderRMC();
    void sendSentenceBuilderGGA();
    void sendSentenceBuilderHDT();
    void sendSentenceBuilderHDM();
    void sendSentenceBuilderHDG();
    void sendSentenceBuilderMTW();
    void sendSentenceBuilderTLL();
    void sendSentenceBuilderROT();
    void sendSentenceBuilderRSA();
    void sendSentenceBuilderDPT();
    void sendSentenceBuilderDBx();
    void sendSentenceBuilderTHS();
    void sendSentenceBuilderWPL();
    void sendSentenceBuilderVTG();
    void sendSentenceBuilderGSV();
    void sendSentenceBuilderXDR();
    void sendSentenceBuilderOSD();
    void sendSentenceBuilderMWV();
    void sendSentenceBuilderMWD();
    void sendSentenceBuilderVDR();
    void sendSentenceBuilderVHW();
    void sendSentenceBuilderVWR();
    void sendSentenceBuilderZDA();

    bool addAutoChecksum;
    std::vector<SectionItem> sbSizerListSentenceBuilder;

    //Sim data
    double latSim;
    double lonSim;
    double headingSim;
    double rudderAngleSim;
    int directionSignSim;
    double speedSim;
};

#endif //DIALOG_MAIN_GUI
