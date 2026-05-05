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

  int BString2Int(char* bitlist)
  {
    int s = std::bitset<6>(bitlist).to_ulong();
    return s;
  }


  //Finders
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


  //NMEA
  string nmeaEncapsulate(string BigString, int numsixes)
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

  wxString makeChecksum(wxString mySentence)
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
  wxString encodeType1_2_3(wxString s_talker, wxString s_id, int i_MMSI, int i_navStatus, int i_rot, double d_sog, double d_lat, double d_lon, double d_cog, double d_heading, int i_maneuver, wxString s_channel)
  {
    //Get data
    string talker = (const char*)s_talker.mb_str();

    string id = (const char*)s_id.mb_str();

    int i_messageID = 1;
    string messageID = Int2BString(i_messageID, 6);

    int i_repeatIndicator = 0;
    string repeatIndicator = Int2BString(i_repeatIndicator, 2);

    string MMSI = Int2BString(i_MMSI, 30);

    string navStatus = Int2BString(i_navStatus, 4);

    string rotRaw = Int2BString(i_rot, 8);

    int sog_scaled = static_cast<int>(d_sog * 10.0);
    std::string sog = Int2BString(sog_scaled, 10);

    int i_posAccuracy = 0;
    string posAccuracy = Int2BString(i_posAccuracy, 1);

    int lon_scaled = static_cast<int>(d_lon * 600000.0);
    std::string longitude = Int2BString(lon_scaled, 28);

    int lat_scaled = static_cast<int>(d_lat * 600000.0);
    std::string latitude = Int2BString(lat_scaled, 27);

    int cog_scaled = static_cast<int>(d_cog * 10.0);
    std::string cog = Int2BString(cog_scaled, 12);

    int i_heading = static_cast<int>(d_heading);
    std::string heading = Int2BString(i_heading, 9);

    int tSecond = wxGetUTCTime();
    string timeStamp = Int2BString(tSecond, 6);

    string specialManoeuver = Int2BString(i_maneuver, 2);

    int i_spare = 0;
    string spare = Int2BString(i_spare, 3);

    int i_raim = 1;
    string raim = Int2BString(i_raim, 1);

    int i_syncState = 0;
    string syncState = Int2BString(i_syncState, 2);

    int timeout = 0;
    string slotTimeout = Int2BString(timeout, 3);

    int offset = 0;
    string slotOffset = Int2BString(offset, 14);

    //Payload
    string bigString = messageID + repeatIndicator + MMSI + navStatus + rotRaw + sog +
                       posAccuracy + longitude + latitude + cog + heading + timeStamp +
                       specialManoeuver + spare + raim + syncState + slotTimeout + slotOffset;

    int bigStringSize = bigString.size();
    int numSixes = (bigStringSize / 6);

    string channel = (const char*)s_channel.mb_str();

    //Encode payload
    string encodedPayload = nmeaEncapsulate(bigString, numSixes);

    //Create NMEA
    string sentence = talker + id + ",1,1,," + channel + "," + encodedPayload + ",O";
    wxString checksum = makeChecksum(sentence);
    wxString myNMEA = "!" + sentence + "*" + checksum;

    return myNMEA;
  }

  wxString encodeType18(wxString s_talker, wxString s_id, int i_MMSI, double d_sog, double d_lat, double d_lon, double d_cog, double d_heading, wxString s_channel)
  {
    //Get data
    string talker = (const char*)s_talker.mb_str();

    string id = (const char*)s_id.mb_str();

    int i_MessageID = 18;
    string MessageID(Int2BString(i_MessageID, 6));

    int i_repeatIndicator = 0;
    string repeatIndicator = Int2BString(i_repeatIndicator, 2);

    string MMSI = Int2BString(i_MMSI, 30);

    int i_spare1 = 0;
    string spare1 = Int2BString(i_spare1, 8);

    int sog_scaled = static_cast<int>(d_sog * 10.0);
    string sog = Int2BString(sog_scaled, 10);

    int i_posAccuracy = 1;
    string posAccuracy = Int2BString(i_posAccuracy, 1);

    int lon_scaled = static_cast<int>(d_lon * 600000.0);
    std::string longitude = Int2BString(lon_scaled, 28);

    int lat_scaled = static_cast<int>(d_lat * 600000.0);
    std::string latitude = Int2BString(lat_scaled, 27);

    int cog_scaled = static_cast<int>(d_cog * 10.0);
    std::string cog = Int2BString(cog_scaled, 12);

    int i_heading = static_cast<int>(d_heading);
    std::string heading = Int2BString(i_heading, 9);

    int tSecond = wxGetUTCTime();
    string timeStamp = Int2BString(tSecond, 6);

    int i_spare2 = 0;
    string spare2 = Int2BString(i_spare2, 2);

    int i_state = 393222;
    string state = Int2BString(i_state, 27);

    string channel = (const char*)s_channel.mb_str();

    //Payload
    string bigString = MessageID + repeatIndicator + MMSI + spare1 + sog + posAccuracy + longitude +
                       latitude + cog + heading + timeStamp + spare2 + state;

    //Encode payload
    string encodedPayload = nmeaEncapsulate(bigString, 28);

    //Create NMEA
    string sentence = talker + id + ",1,1,,"  + channel + "," + encodedPayload + ",O";
    wxString checksum = makeChecksum(sentence);
    wxString myNMEA = "!" + sentence + "*" + checksum;

    return myNMEA;
  }

}
