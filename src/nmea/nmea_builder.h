#include <wx/string.h>

namespace nmea
{
  wxString createGLL(wxString talker, wxString lat, wxString latDir, wxString lon, wxString lonDir, wxString time, wxString status, wxString mode);
  wxString createRMC(wxString talker, wxString time, wxString status, wxString lat, wxString latDir, wxString lon, wxString lonDir, wxString sogKnot, wxString cogDeg, wxString date, wxString magVarDeg, wxString magVarDir);
  wxString createGGA(wxString talker, wxString time, wxString lat, wxString latDir, wxString lon, wxString lonDir, wxString gpsFix, wxString satellitesNb, wxString hdop, wxString altitudeMeter, wxString geoid);
  wxString createHDT(wxString talker, wxString headingDeg);
  wxString createHDM(wxString talker, wxString headingDeg);
  wxString createHDG(wxString talker, wxString headingDeg, wxString deviationDeg, wxString deviationDir, wxString variationDeg, wxString variationDir);
  wxString createMTW(wxString talker, wxString tempCelsius);
  wxString createTLL(wxString talker, wxString targetID, wxString lat, wxString latDir, wxString lon, wxString lonDir, wxString name, wxString time, wxString status, wxString ref);
  wxString createROT(wxString talker, wxString rateDegPerMin, wxString status);
  wxString createRSA(wxString talker, wxString stbdAngleDeg, wxString stbdStatus, wxString portAngleDeg, wxString portStatus);
  wxString createDPT(wxString talker, wxString depthMeter, wxString offsetMeter);
  wxString createDBx(wxString talker, wxString nmeaType, wxString depthFeet, wxString depthMeter, wxString depthFathom);
  wxString createTHS(wxString talker, wxString heading, wxString mode);
  wxString createWPL(wxString talker, wxString latitude, wxString latDir, wxString longitude, wxString lonDir, wxString wpName);
  wxString createVTG(wxString talker, wxString cogTrue, wxString cogMag, wxString sogKnot, wxString sogKph, wxString mode);
  wxString createGSV(wxString talker, wxString totalSentences, wxString sentenceNumber, wxString totalSatellites, wxString PRN, wxString elevationDeg, wxString azimuthDeg, wxString SNR);
  wxString createXDR(wxString talker, wxString type, wxString measurement, wxString unit, wxString name);
  wxString createOSD(wxString talker, wxString heading, wxString status, wxString course, wxString courseRef, wxString speed, wxString speedRef, wxString driftAngle, wxString driftSpeed, wxString speedUnit);
  wxString createMWV(wxString talker, wxString angle, wxString reference, wxString speed, wxString unit, wxString status);
  wxString createMWD(wxString talker, wxString directionTrue, wxString directionMag, wxString speedKnot, wxString speedMph);
  wxString createVDR(wxString talker, wxString directionTrue, wxString directionMag, wxString currentSpeedKnot);
  wxString createVHW(wxString talker, wxString headingTrue, wxString headingMag, wxString stwKnot, wxString stwKph);
  wxString createVWR(wxString talker, wxString angle, wxString direction, wxString speedKnot, wxString speedMps, wxString speedKph);
  wxString createZDA(wxString talker, wxString time, wxString day, wxString month, wxString year, wxString hourOffset, wxString minuteOffset);
  };
