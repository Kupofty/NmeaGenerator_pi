#ifndef UTILS_H
#define UTILS_H

#include <wx/math.h>
#include <wx/string.h>
#include <cstdint>
#include <utility>

constexpr double DEG2RAD = M_PI / 180.0;
constexpr double RAD2DEG = 180.0 / M_PI;
constexpr double EARTH_RADIUS = 6371000.0; // meters
constexpr double KNOT2METER = 0.514444;

struct GeoPos {
  double lat;
  double lon;
};

namespace utils
{

  //Calculate the checksum from NMEA payload
  unsigned char calculateChecksum(const wxString s);

  //Convert checksum to "*XX" wxString format
  wxString checksumToString(uint8_t checksum);

  //Calculate the checksum from NMEA payload
  wxString calculateChecksumString(const wxString s);

  //Return updated position lat/lon according to speed, heading and time
  GeoPos updatePosition(double lat, double lon, double speed_knots, double heading_deg, double dt_msec);

  //Convert decimal lat to ddmm.mmmm wxString format
  wxString toNMEA_lat(double lat);
  wxString toNMEA_lon(double lon);

  wxString getLatDir(double lat);
  wxString getLonDir(double lon);

  //Convert ddmm.mmmm to dd.dddd
  double NMEA_to_decimal(double nmea);
}

#endif  // UTILS_H



