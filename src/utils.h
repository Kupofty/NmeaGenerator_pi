#ifndef UTILS_H
#define UTILS_H

#include <wx/string.h>

namespace utils
{
  //Calculate the checksum from NMEA payload
  unsigned char calculateChecksum(const wxString s);

  //Convert checksum to "*XX" wxString format
  wxString checksumToString(uint8_t checksum);

  //Calculate the checksum from NMEA payload
  wxString calculateChecksumString(const wxString s);
}

#endif  // UTILS_H
