#include "class.hpp"

void CorrectInformation(std::string &year, std::string &month, std::string &day) {
    while (year.size() < 4) {
        year = "0" + year;
    }
    if (month.size() == 1) {
        month = "0" + month;
    }
    if (day.size() == 1) {
        day = "0" + day;
    }
}

bool
CheckInformation(std::string &university, std::string &sex, std::string &year, std::string &month, std::string &day) {
    if ((university != "MIEM" && university != "MGTU") || (sex != "man" && sex != "woman") || std::stoi(year) > 9999 ||
        std::stoi(month) < 1 || std::stoi(month) > 12 ||
        std::stoi(day) < 1 ||
        std::stoi(day) > 31) {
        return false;
    }
    return true;
}