/*
 * Project: OpenCPN
 * Author:  Mike Rossiter - ShipDriver.
 * Source:  AIS encoding ported from AISConverter Python code by @transmitterdan
*/

#include "ais_encoder.h"

#include <algorithm>
#include <bitset>
#include <cstdint>
#include <time.h>
#include <vector>
#include <sstream>

using namespace std;


//Encoding tables
static const std::vector<std::pair<char, uint32_t>> NMEA_TABLE = {
    {'0', 0},  {'1', 1},  {'2', 2},  {'3', 3},  {'4', 4},  {'5', 5},  {'6', 6},
    {'7', 7},  {'8', 8},  {'9', 9},  {':', 10}, {';', 11}, {'<', 12}, {'=', 13},
    {'>', 14}, {'?', 15}, {'@', 16}, {'A', 17}, {'B', 18}, {'C', 19}, {'D', 20},
    {'E', 21}, {'F', 22}, {'G', 23}, {'H', 24}, {'I', 25}, {'J', 26}, {'K', 27},
    {'L', 28}, {'M', 29}, {'N', 30}, {'O', 31}, {'P', 32}, {'Q', 33}, {'R', 34},
    {'S', 35}, {'T', 36}, {'U', 37}, {'V', 38}, {'W', 39}, {'`', 40}, {'a', 41},
    {'b', 42}, {'c', 43}, {'d', 44}, {'e', 45}, {'f', 46}, {'g', 47}, {'h', 48},
    {'i', 49}, {'j', 50}, {'k', 51}, {'l', 52}, {'m', 53}, {'n', 54}, {'o', 55},
    {'p', 56}, {'q', 57}, {'r', 58}, {'s', 59}, {'t', 60}, {'u', 61}, {'v', 62},
    {'w', 63}};

static const std::vector<std::pair<uint8_t, char>> SIXBIT_ASCII_TABLE = {
    {0, '@'},  {1, 'A'},  {2, 'B'},  {3, 'C'},   {4, 'D'},   {5, 'E'},
    {6, 'F'},  {7, 'G'},  {8, 'H'},  {9, 'I'},   {10, 'J'},  {11, 'K'},
    {12, 'L'}, {13, 'M'}, {14, 'N'}, {15, 'O'},  {16, 'P'},  {17, 'Q'},
    {18, 'R'}, {19, 'S'}, {20, 'T'}, {21, 'U'},  {22, 'V'},  {23, 'W'},
    {24, 'X'}, {25, 'Y'}, {26, 'Z'}, {27, '['},  {28, '\\'}, {29, ']'},
    {30, '^'}, {31, '_'}, {32, ' '}, {33, '!'},  {34, '\"'}, {35, '#'},
    {36, '$'}, {37, '%'}, {38, '&'}, {39, '\''}, {40, '('},  {41, ')'},
    {42, '*'}, {43, '+'}, {44, ','}, {45, '-'},  {46, '.'},  {47, '/'},
    {48, '0'}, {49, '1'}, {50, '2'}, {51, '3'},  {52, '4'},  {53, '5'},
    {54, '6'}, {55, '7'}, {56, '8'}, {57, '9'},  {58, ':'},  {59, ';'},
    {60, '<'}, {61, '='}, {62, '>'}, {63, '?'},
};


// AIS related
namespace ais
{
  //Converters
  string Str2Str(string str, const char* charsToRemove)
  {
    for (unsigned int i = 0; i < strlen(charsToRemove); ++i) {
      str.erase(remove(str.begin(), str.end(), charsToRemove[i]), str.end());
    }
    return str;
  }

  float Str2Float(string str, const char* exc)
  {
    float result;
    string floatString = Str2Str(str, exc);
    result = strtof((floatString).c_str(), 0);  // string to float

    return result;
  }

  int Str2Int(string str, const char* exc)
  {
    int result;
    string intString = Str2Str(str, exc);
    result = atoi((intString).c_str());  // string to float
    return result;
  }

  string Int2BString(int value, int length)
  {
    string result = "";
    bitset<100> myBitset(value);
    result = myBitset.to_string();

    result = result.substr(result.size() - length, length);
    return result;
  }

  int findIntFromLetter(char letter)
  {
    auto i = std::find_if(SIXBIT_ASCII_TABLE.begin(), SIXBIT_ASCII_TABLE.end(),
                          [letter](const std::pair<uint8_t, char>& p) {
                            return p.second == letter;
                          });
    return i != SIXBIT_ASCII_TABLE.end() ? i->first : 0xff;
  }

  char findCharFromNumber(int mp)
  {
    auto i = std::find_if(NMEA_TABLE.begin(), NMEA_TABLE.end(),
                          [mp](const std::pair<char, uint32_t> p) {
                            return p.second == (unsigned)mp;
                          });
    return i != NMEA_TABLE.end() ? i->first : 0xff;
  }

  string Str2Six(string str, int length)
  {
    string result;
    char letter;

    for (size_t i = 0; i < str.size(); i++) {
      letter = str[i];
      int si = findIntFromLetter(letter);
      result = result + Int2BString(si, 6);
    }
    while (result.size() < (size_t)length) {
      int sj = findIntFromLetter(' ');
      result = result + Int2BString(sj, 6);
    }
    return result;
  }

  int BString2Int(char* bitlist)
  {
    int s = std::bitset<6>(bitlist).to_ulong();
    return s;
  }

  string NMEAencapsulate(string BigString, int numsixes)
  {
    string capsule = "";
    int chindex;
    int substart = 0;
    int* intChars = (int*)calloc(numsixes, 6);
    char* myChars;  // = &BigString[0u];
    for (chindex = 0; chindex < numsixes; chindex++) {
      string StrVal = BigString.substr(substart, 6);
      // wxMessageBox(StrVal);
      myChars = &StrVal[0u];
      intChars[chindex] = BString2Int(myChars);
      substart += 6;
    }
    // Now intChars contains the encoded bits for the AIS string
    for (chindex = 0; chindex < numsixes; chindex++) {
      char plChar = findCharFromNumber(intChars[chindex]);
      capsule = capsule + plChar;
    }
    // Now we have the NMEA payload in capsule
    free(intChars);
    return capsule;
  }

  wxString makeCheckSum(wxString mySentence)
  {
    size_t i;
    unsigned char XOR;

    wxString s(mySentence);
    wxCharBuffer buffer = s.ToUTF8();
    char* Buff = buffer.data();  // data() returns const char *
    size_t iLen = strlen(Buff);
    for (XOR = 0, i = 0; i < iLen; i++) XOR ^= (unsigned char)Buff[i];
    stringstream tmpss;
    tmpss << hex << (int)XOR;
    wxString mystr = tmpss.str();
    return mystr;
  }


  //Encoders
  wxString encodeType1_2_3(wxString talker, int iMMSI, int nav_status, float sog, double ilat, double ilon, double cog, double true_heading, wxString channel)
  {
    string type = "1";
    string MessageID(Int2BString(Str2Int(type, ""), 6));

    string RepeatIndicator = Int2BString(0, 2);

    string talker1 = (const char*)talker.mb_str();

    wxString MMSI = wxString::Format("%i", iMMSI);
    string sMMSI = (const char*)MMSI.mb_str();
    string oMMSI = Int2BString(Str2Int(sMMSI, ""), 30);

    string nav_status1 =  Int2BString(nav_status, 4);  // AIS-SART (active), MOB-AIS, EPIRB-AIS

    string rot_raw = Int2BString(0, 8);

    wxString SPEED = wxString::Format("%f", sog * 10);
    string sSPEED = (const char*)SPEED.mb_str();
    float sog1 = Str2Float(sSPEED, "");
    string sog2 = Int2BString(sog1, 10);

    string position_accuracy = Int2BString(0, 1);

    wxString LON = wxString::Format("%f", ilon);
    string sLON = (const char*)LON.mb_str();
    float flon = Str2Float(sLON, "");
    string Longitude = Int2BString(int(flon * 600000), 28);

    wxString LAT = wxString::Format("%f", ilat);
    string sLAT = (const char*)LAT.mb_str();
    float flat = Str2Float(sLAT, "");
    string Latitude = Int2BString(int(flat * 600000), 27);

    wxString COURSE = wxString::Format("%f", cog);
    string sCOURSE = (const char*)COURSE.mb_str();
    float cog1 = Str2Float(sCOURSE, "");
    string COG = Int2BString(int(cog1 * 10), 12);

    wxString HEADING = wxString::Format("%f", true_heading);
    string sHEADING = (const char*)HEADING.mb_str();
    int heading = Str2Int(sHEADING, "");
    string Heading = Int2BString(heading, 9);

    int tSecond = wxGetUTCTime();
    string TimeStamp = Int2BString(tSecond, 6);

    string special_manoeuvre = Int2BString(0, 2);
    string spare = Int2BString(0, 3);

    string raim = Int2BString(0, 1);

    string sync_state = Int2BString(0, 2);

    string slot_timeout = Int2BString(0, 3);
    string slot_offset = Int2BString(0, 14);

    string BigString = MessageID;
    BigString = BigString + RepeatIndicator;
    BigString = BigString + oMMSI + nav_status1 + rot_raw + sog2 +
                position_accuracy + Longitude + Latitude + COG + Heading +
                TimeStamp + special_manoeuvre + spare + raim + sync_state +
                slot_timeout + slot_offset;

    int bsz = BigString.size();
    int numSixes = (bsz / 6);

    string channel1 = (const char*)channel.mb_str();

    string capsule = NMEAencapsulate(BigString, numSixes);
    string aisnmea = talker1 + "VDM,1,1,," + channel1 + "," + capsule + ",O";
    wxString myNMEA_SART = aisnmea;
    wxString myCheck = makeCheckSum(myNMEA_SART);

    myNMEA_SART = "!" + myNMEA_SART + "*" + myCheck;

    return myNMEA_SART;
  }

  wxString encodeType18(wxString talker, int iMMSI, double spd, double ilat, double ilon, double course, double hdg)
  {
    string type = "18";
    string MessageID(Int2BString(Str2Int(type, ""), 6));

    string RepeatIndicator = Int2BString(0, 2);

    string talker1 = (const char*)talker.mb_str();

    wxString MMSI = wxString::Format("%i", iMMSI);
    string sMMSI = (const char*)MMSI.mb_str();
    string oMMSI = Int2BString(Str2Int(sMMSI, ""), 30);

    string Spare1 = Int2BString(0, 8);

    wxString sChannel;
    string Channel = (const char*)sChannel.mb_str();

    wxString SPEED = wxString::Format("%f", spd * 10);
    string sSPEED = (const char*)SPEED.mb_str();
    float sog = Str2Float(sSPEED, "");
    string SOG = Int2BString(sog, 10);

    string PosAccuracy = Int2BString(1, 1);

    wxString LON = wxString::Format("%f", ilon);
    string sLON = (const char*)LON.mb_str();
    float flon = Str2Float(sLON, "");
    string Longitude = Int2BString(int(flon * 600000), 28);

    wxString LAT = wxString::Format("%f", ilat);
    string sLAT = (const char*)LAT.mb_str();
    float flat = Str2Float(sLAT, "");
    string Latitude = Int2BString(int(flat * 600000), 27);

    wxString COURSE = wxString::Format("%f", course);
    string sCOURSE = (const char*)COURSE.mb_str();
    float cog = Str2Float(sCOURSE, "");
    string COG = Int2BString(int(cog * 10), 12);

    wxString HEADING = wxString::Format("%f", hdg);
    string sHEADING = (const char*)HEADING.mb_str();
    int heading = Str2Int(sHEADING, "");
    string Heading = Int2BString(heading, 9);

    wxString TIMESTAMP;
    string sTIMESTAMP = (const char*)TIMESTAMP.mb_str();
    string tStamp = sTIMESTAMP;
    int tSecond = wxGetUTCTime();
    string TimeStamp = Int2BString(tSecond, 6);

    string Spare2 = Int2BString(0, 2);

    string State = Int2BString(393222, 27);

    string BigString = MessageID;
    BigString = BigString + RepeatIndicator;
    BigString = BigString + oMMSI + Spare1 + SOG + PosAccuracy + Longitude +
                Latitude + COG + Heading + TimeStamp + Spare2;
    BigString = BigString + State;

    string capsule = NMEAencapsulate(BigString, 28);
    string aisnmea = talker1 + "VDM,1,1,," + Channel + "," + capsule + ",O";
    wxString myNMEA = aisnmea;
    wxString myCheck = makeCheckSum(myNMEA);

    myNMEA = "!" + myNMEA + "*" + myCheck;
    return myNMEA;
  }

}
