#include <string>

#include <wx/textfile.h>
#include <wx/wx.h>

namespace ais
{
  //Convert functions
  std::string Str2Str(std::string str, const char* charsToRemove);
  float Str2Float(std::string str, const char* exc);
  int Str2Int(std::string str, const char* exc);
  std::string Int2BString(int value, int length);
  int BString2Int(char* bitlist);

  //Find functions
  int findIntFromLetter(char letter);
  char findCharFromNumber(int mp);

  //NMEA functions
  std::string nmeaEncapsulate(std::string BigString, int numsixes);
  wxString makeCheckSum(wxString mySentence);

  //Encode functions
  wxString encodeType1_2_3(wxString s_talker, int i_MMSI, int i_navStatus, int i_rot, double d_sog,
                           double d_lat, double d_lon, double d_cog, double d_heading, wxString s_channel); //Class A report

  wxString encodeType18(wxString s_talker, int i_MMSI, double d_sog, double d_lat,
                        double d_lon, double d_cog, double d_heading); //Class B position report
};
