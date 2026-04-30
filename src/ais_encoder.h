#include <algorithm>
#include <bitset>
#include <cstdint>
#include <list>
#include <string>
#include <time.h>
#include <vector>
#include <sstream>

#include <wx/textfile.h>
#include <wx/wx.h>

namespace AisEncoder
{
  //Convert functions
  std::string Str2Str(std::string str, const char* charsToRemove);
  float Str2Float(std::string str, const char* exc);
  int Str2Int(std::string str, const char* exc);
  std::string Int2BString(int value, int length);
  std::string Str2Six(std::string str, int length);
  int BString2Int(char* bitlist);

  //Find functions
  int findIntFromLetter(char letter);
  char findCharFromNumber(int mp);

  //NMEA functions
  std::string NMEAencapsulate(std::string BigString, int numsixes);
  wxString makeCheckSum(wxString mySentence);

  //Encode functions
  wxString nmeaEncode(wxString type, int iMMSI, wxString status, double speed, double ilat,
                      double ilon, double course, double hdg, wxString channel, wxString timestamp);

  wxString nmeaEncode1_2_3(int message_id, int iMMSI, int nav_status, float sog, double ilat,
                           double ilon, double cog, double true_heading, wxString channel);
};
