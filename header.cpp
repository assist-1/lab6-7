#include "header.h"

bool proverkaSex(std::string &text){
    if (text == "man" || text == "woman")
        return true;
    return false;
}
bool proverkaYear(string &val){
    if(atoi(val.c_str()) > 1900 && atoi(val.c_str()) <2023)
        return true;
    return false;
}
bool proverkaMMDD(string &DD, string &MM, string &YYYY){
    int year = atoi(YYYY.c_str()), month = atoi(MM.c_str()), day = atoi(DD.c_str());
    if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day <= 31)
        return true;
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day <= 30)
        return true;
    else if(month == 2 && (day <= 28 ||(day<=29 && year%4==0)))
        return true;
    return false;
}

string MIEM_S(string pol){
    if(pol == "man")
        return "8";
    else
        return "4";
}

string Go (Studak* st, string &sex, string &year, string &month, string &day){
    return st->generate(sex,year,month,day);
}