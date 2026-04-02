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

}
