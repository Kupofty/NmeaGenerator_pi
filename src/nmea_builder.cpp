#include "nmea_builder.h"
#include "utils.h"


namespace nmea
{
  wxString createGLL(wxString talker, wxString lat, wxString latDir, wxString lon, wxString lonDir, wxString time, wxString status, wxString mode)
  {
    wxString payload =
        talker + "GLL" + "," +
        lat + "," +
        latDir + "," +
        lon + "," +
        lonDir + "," +
        time + "," +
        status + "," +
        mode;

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createRMC(wxString talker, wxString time, wxString status, wxString lat, wxString latDir, wxString lon, wxString lonDir, wxString sogKnot, wxString cogDeg, wxString date, wxString magVarDeg, wxString magVarDir)
  {
    wxString payload =
        talker + "RMC" + "," +
        time + "," +
        status + "," +
        lat + "," +
        latDir + "," +
        lon + "," +
        lonDir + "," +
        sogKnot + "," +
        cogDeg + "," +
        date + "," +
        magVarDeg + "," +
        magVarDir;

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createGGA(wxString talker, wxString time, wxString lat, wxString latDir, wxString lon, wxString lonDir, wxString gpsFix, wxString satellitesNb, wxString hdop, wxString altitudeMeter, wxString geoid)
  {
    wxString payload =
        talker + "GGA" + "," +
        time + "," +
        lat + "," +
        latDir + "," +
        lon + "," +
        lonDir + "," +
        gpsFix + "," +
        satellitesNb + "," +
        hdop + "," +
        altitudeMeter + ",M," +
        geoid + ",M,,";

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createHDT(wxString talker, wxString headingDeg)
  {
    wxString payload =
        talker + "HDT" + "," +
        headingDeg + ",T";

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createHDM(wxString talker, wxString headingDeg)
  {
    wxString payload =
        talker + "HDM" + "," +
        headingDeg + ",M";

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createHDG(wxString talker, wxString headingDeg, wxString deviationDeg, wxString deviationDir, wxString variationDeg, wxString variationDir)
  {
    wxString payload =
        talker + "HDG" + "," +
        headingDeg + "," +
        deviationDeg + "," +
        deviationDir + "," +
        variationDeg + "," +
        variationDir;

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createMTW(wxString talker, wxString tempCelsius)
  {
    wxString payload =
        talker + "MTW" + "," +
        tempCelsius + ",C";

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createTLL(wxString talker, wxString targetID, wxString lat, wxString latDir, wxString lon, wxString lonDir, wxString name, wxString time, wxString status, wxString ref)
  {
    wxString payload =
        talker + "TLL" + "," +
        targetID + "," +
        lat + "," +
        latDir + "," +
        lon + "," +
        lonDir + "," +
        name + "," +
        time + "," +
        status + "," +
        ref;

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createROT(wxString talker, wxString rateDegPerMin, wxString status)
  {
    wxString payload =
        talker + "ROT" + "," +
        rateDegPerMin + "," +
        status;

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createRSA(wxString talker, wxString stbdAngleDeg, wxString stbdStatus, wxString portAngleDeg, wxString portStatus)
  {
    wxString payload =
        talker + "RSA" + "," +
        stbdAngleDeg + "," +
        stbdStatus + "," +
        portAngleDeg + "," +
        portStatus;

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createDPT(wxString talker, wxString depthMeter, wxString offsetMeter)
  {
    wxString payload =
        talker + "DPT" + "," +
        depthMeter + "," +
        offsetMeter;

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createDBx(wxString talker, wxString nmeaType, wxString depthFeet, wxString depthMeter, wxString depthFathom)
  {
    wxString payload =
        talker +
        nmeaType + "," + //same structure for DBT/DBS/DBK
        depthFeet + ",f," +
        depthMeter + ",M," +
        depthFathom + ",F";

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createTHS(wxString talker, wxString heading, wxString mode)
  {
    wxString payload =
        talker + "THS" + "," +
        heading + "," +
        mode;

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createWPL(wxString talker, wxString lat, wxString latDir, wxString lon, wxString lonDir, wxString wpName)
  {
    wxString payload =
        talker + "WPL" + "," +
        lat + "," +
        latDir + "," +
        lon + "," +
        lonDir + "," +
        wpName;

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createVTG(wxString talker, wxString cogTrue, wxString cogMag, wxString sogKnot, wxString sogKph, wxString mode)
  {
    wxString payload =
        talker + "VTG" + "," +
        cogTrue + ",T," +
        cogMag + ",M," +
        sogKnot + ",N," +
        sogKph + ",K," +
        mode;

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createGSV(wxString talker, wxString totalSentences, wxString sentenceNumber, wxString totalSatellites, wxString PRN, wxString elevationDeg, wxString azimuthDeg, wxString SNR)
  {
    wxString payload =
        talker + "GSV" + "," +
        totalSentences + "," +
        sentenceNumber + "," +
        totalSatellites + "," +
        PRN + "," +
        elevationDeg + "," +
        azimuthDeg + "," +
        SNR;

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createXDR(wxString talker, wxString type, wxString measurement, wxString unit, wxString name)
  {
    wxString payload =
        talker + "XDR" + "," +
        type + "," +
        measurement + "," +
        unit + "," +
        name;

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createOSD(wxString talker, wxString heading, wxString status, wxString course, wxString courseRef, wxString speed, wxString speedRef, wxString driftAngle, wxString driftSpeed, wxString speedUnit)
  {
    wxString payload =
        talker + "OSD" + "," +
        heading + "," +
        status + "," +
        course + "," +
        courseRef + "," +
        speed + "," +
        speedRef + "," +
        driftAngle + "," +
        driftSpeed + "," +
        speedUnit;

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createMWV(wxString talker, wxString angle, wxString reference, wxString speed, wxString unit, wxString status)
  {
    wxString payload =
        talker + "MWV" + "," +
        angle + "," +
        reference + "," +
        speed + "," +
        unit + "," +
        status;

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createMWD(wxString talker, wxString direction1, wxString direction2, wxString speed1, wxString speed2)
  {
    wxString payload =
        talker + "MWD" + "," +
        direction1 + ",T," +
        direction2 + ",M," +
        speed1 + ",N," +
        speed2 + ",M";

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createVDR(wxString talker, wxString directionTrue, wxString directionMag, wxString currentSpeedKnot)
  {
    wxString payload =
        talker + "VDR" + "," +
        directionTrue + ",T," +
        directionMag + ",M," +
        currentSpeedKnot + ",N";

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createVHW(wxString talker, wxString headingTrue, wxString headingMag, wxString stwKnot, wxString stwKph)
  {
    wxString payload =
        talker + "VHW" + "," +
        headingTrue + ",T," +
        headingMag + ",M," +
        stwKnot + ",N," +
        stwKph + ",K";

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createVWR(wxString talker, wxString angle, wxString direction, wxString speedKnot, wxString speedMps, wxString speedKph)
  {
    wxString payload =
        talker + "VWR" + "," +
        angle + "," +
        direction + "," +
        speedKnot + ",N," +
        speedMps + ",M," +
        speedKph + ",K";

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

  wxString createZDA(wxString talker, wxString time, wxString day, wxString month, wxString year, wxString hourOffset, wxString minuteOffset)
  {
    wxString payload =
        talker + "ZDA" + "," +
        time + "," +
        day + "," +
        month + "," +
        year + "," +
        hourOffset + "," +
        minuteOffset;

    wxString checksum = utils::calculateChecksumString(payload);

    wxString sentence = "$" + payload + checksum;
    return sentence;
  }

}
