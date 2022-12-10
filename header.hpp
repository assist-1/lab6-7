//
// Created by 79875 on 09.12.2022.
//

#ifndef LABA_PL_6_7_HEADER_HPP
#define LABA_PL_6_7_HEADER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <cstring>

size_t RandomNumber(size_t min, size_t max);


struct Interface {
    virtual std::string generate(bool sex, size_t year, size_t month, size_t day) = 0;
};

struct studentID : public Interface {
    std::vector <std::string> parametrs;

    studentID() {
        parametrs = {"S", "YYYY", "MM", "DD"};
    }
};

struct MIEM_ID : public studentID {

    MIEM_ID() : studentID() {
        parametrs.push_back("NNNNN");
    }


    std::string generate(bool sex, size_t year, size_t month, size_t day) override {
        std::string result = "";
        int sum = 0;
        if (sex) {
            parametrs[0] = std::to_string(8);
        } else {
            parametrs[0] = std::to_string(4);
        }
        parametrs[1] = std::to_string(year);
        if (month < 10) {
            parametrs[2] = "0" + std::to_string(month);
        } else {
            parametrs[2] = std::to_string(month);
        }
        if (day < 10) {
            parametrs[3] = "0" + std::to_string(day);
        } else {
            parametrs[3] = std::to_string(day);
        }
        parametrs[4] = std::to_string(RandomNumber(10000, 99999));
        result = parametrs[0] + parametrs[1] + parametrs[2] + parametrs[3] + parametrs[4];
        for (size_t i = 0; i < result.size(); ++i) {
            sum += (i + 1) * static_cast<size_t>(result[i]);
        }
        result += std::to_string((11 - (sum % 11)) % 11);
        return result;
    }
};

struct MGTU_ID : public studentID {

    MGTU_ID() : studentID() {
        parametrs.push_back("NNNN");
    }

    std::string generate(bool sex, size_t year, size_t month, size_t day) override {
        std::string result = "";
        size_t sum = 0;
        if (sex) {
            parametrs[0] = std::to_string(2);
        } else {
            parametrs[0] = std::to_string(1);
        }
        parametrs[1] = std::to_string(year);
        if (month < 10) {
            parametrs[2] = "0" + std::to_string(month);
        } else {
            parametrs[2] = std::to_string(month);
        }
        if (day < 10) {
            parametrs[3] = "0" + std::to_string(day);
        } else {
            parametrs[3] = std::to_string(day);
        }
        parametrs[4] = std::to_string(RandomNumber(1000, 9999));
        result = parametrs[0] + parametrs[1] + parametrs[2] + parametrs[3] + parametrs[4];
        for (size_t i = 0; i < result.size(); ++i) {
            sum += (i + 1) * static_cast<size_t>(result[i]);
        }
        result += std::to_string((10 - (sum % 10)) % 10);
        return result;
    }
};

struct Generator {
    Interface *generator(std::string VUZ) {
        if (VUZ == "MIEM") {
            MIEM_ID *a = new MIEM_ID;
            return a;
        } else if (VUZ == "MGTU") {
            MGTU_ID *a = new MGTU_ID;
            return a;
        }
        return nullptr;
    }

};

void read(std::vector <std::string> &studaki_MIEM, std::vector <std::string> &studaki_MGTU);

void read(std::vector <std::string> &studaki_MIEM, std::vector <std::string> &studaki_MGTU, char *name);

#endif //LABA_PL_6_7_HEADER_HPP
