#include "utils.h"


namespace utils
{

  unsigned char calculateChecksum(const wxString s)
  {
    unsigned char cs = 0;
    for (char c : s)
      cs ^= static_cast<unsigned char>(c);

    return cs;
  }

  wxString checksumToString(uint8_t checksum)
  {
    wxString str;
    str.Printf("*%02X", checksum);
    return str;
  }

  wxString calculateChecksumString(const wxString s)
  {
    return checksumToString(calculateChecksum(s));
  }
  GeoPos updatePosition(double lat, double lon, double speed_knots, double heading_deg, double dt_msec)
  {
    double latRad = lat * DEG2RAD;
    double lonRad = lon * DEG2RAD;
    double heading = heading_deg * DEG2RAD;

    double d = speed_knots * KNOT2METER * dt_msec / 1000.0;

    double newLatRad = latRad + (d / EARTH_RADIUS) * cos(heading);

    double cosLat = cos(newLatRad);
    if (fabs(cosLat) < 1e-6)
      cosLat = 1e-6;

    double newLonRad = lonRad + (d / EARTH_RADIUS) * sin(heading) / cosLat;

    GeoPos out;
    out.lat = newLatRad * RAD2DEG;
    out.lon = newLonRad * RAD2DEG;

    return out;
  }

  wxString toNMEA_lat(double lat)
  {
    int deg = (int)lat;
    double min = (lat - deg) * 60.0;
    return wxString::Format("%02d%07.4f", deg, min);
  }

  wxString toNMEA_lon(double lon)
  {
    int deg = (int)lon;
    double min = (lon - deg) * 60.0;
    return wxString::Format("%03d%07.4f", deg, min);
  }

  wxString getLatDir(double lat)
  {
    return (lat < 0.0) ? "S" : "N";
  }

  wxString getLonDir(double lon)
  {
    return (lon < 0.0) ? "W" : "E";
  }

  double NMEA_to_decimal(double nmea)
  {
    int degrees = static_cast<int>(nmea / 100);
    double minutes = nmea - (degrees * 100);
    return degrees + minutes / 60.0;
  }

}
