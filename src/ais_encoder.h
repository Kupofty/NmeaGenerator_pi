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
  std::string Str2Six(std::string str, int length);
  int BString2Int(char* bitlist);

  //Find functions
  int findIntFromLetter(char letter);
  char findCharFromNumber(int mp);

  //NMEA functions
  std::string NMEAencapsulate(std::string BigString, int numsixes);
  wxString makeCheckSum(wxString mySentence);

  //Encode functions
  wxString encodeType1_2_3(wxString talker, int iMMSI, int nav_status, int rot, float sog, double ilat, double ilon,
                           double cog, double true_heading, wxString channel); //Class A report
  wxString encodeType18(wxString talker, int iMMSI, double spd, double ilat,
                        double ilon, double course, double hdg); //Class B position report
};
