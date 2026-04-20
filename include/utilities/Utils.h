#ifndef UTILS_H
#define UTILIS_H

#include <string>
#include <ctime>
#include <vector>
using namespace std;
class Utillls{
    public:

    static string trim(const string& str);
    static string toUpperCase(const string&str);
    static string toLowerCase(const string& str);
    static bool startsWith(const string& str,const string& prefix);
    static bool endswith(const string& str,const string& suffix);

    static bool isValidInteger(const string&input);
    static bool isValidDouble(const string& input);
    static bool isValidDate(const string& date); // format : YYYY-MM-DD
    
    static string getCurrentDateTime();
    static string getCurrentDate();
    static string geCurrentTime();

    static int roundToNearest(double value);
    static double roundToDecimals(double value,int decimals);
    static int getRandomInt(int min,int max);


    static void printHeader(const string& title);
    static void printLine(int lenght = 60); // default len = 60
    static void printSperator();
    static void clearScreen();
    static void pauseExcecuation(const string& meddage = "Press Enter to continue....");

    //for files
    static bool fileExists(const string& filename);
    static void creatEmptyFile(const string& filename);
    static bool deleteFile(const string& filename);
    
    // for millitary section validations

    static bool isValidRank(const string& rank);
    static bool isValidServiceNumber(const string & sNumber);
    static bool isValidWeaponCondition(const string& consdition);
    static bool isValidOperationStatus(const string& status);
    static bool isValidSecurityClearance(const string& clearance);

};
#endif