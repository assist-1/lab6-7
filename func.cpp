#include "header.h"

bool check_and_correct(std::string &univer, std::string &sex, std::string &year, std::string &month, std::string &day){
    if (univer != "MIEM" && univer != "MGTU") {
        return false;
    }
    if (sex != "man" && sex != "woman") {
        return false;
    }
    if (std::stoi(year) > 9999) {
        return false;
    } else {
        while (year.size() < 4) {
            year = "0" + year;
        }
    }
    if (std::stoi(month) < 1 && std::stoi(month) > 12) {
        return false;
    } else if (month.size() == 1) {
        month = "0" + month;
    }
    if (std::stoi(day) > 31) {
        return false;
    } else if(day.size() == 1) {
        day = "0" + day;
    }
    return true;
}