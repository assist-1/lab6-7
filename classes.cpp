#include <string>
#include <iostream>
#include "function.h"

using std::string;
using std::cout;

class Generator{
public:
    virtual string generate (string& sex, string& year, string& month, string& day) = 0;
    virtual int set_sex (const string&) =  0;
    static string getstud(int sex, const string& date, int random) {
        string x = (std::to_string(sex)) + date + (std::to_string(random));
        return x;
    };
    static string set_date (const string& year, const string& month, const string& day) {
        return year + month + day;
    }
};

class MIEM : public Generator{
public:
    int set_sex (const string& sex) override {
        if (sex == "man")
            return 8;
        else
            return 4;
    }
    string generate (string& sex, string& year, string& month, string& day) override {
        if (check_date(year, month, day) && check_sex(sex)) {
            int first_sex = set_sex(sex), rch = Random(100000, 999999);
            string first_date = set_date(year, month, day), result = getstud(first_sex, first_date, rch);
            for (int i = 0; i < 10; ++i) {
                if (sum((std::stoll(result) + i)) % 11 == 0) {
                    result = result + std::to_string(i);
                    i = 10;
                }
            }
            return result;
        } else
            return "-------------------";
    }
};

class MGTU : public Generator{
public:
    int set_sex (const string& sex) override {
        if (sex == "man")
            return 2;
        else
            return 1;
    }
    string generate (string& sex, string& year, string& month, string& day) override {
        if (check_date(year, month, day) == 1) {
            int first_sex = set_sex(sex), rch = Random(10000, 99999);
            string first_date = set_date(year, month, day), result = getstud(first_sex, first_date, rch);
            while (true) {
                int flag = 0;
                for (int i = 0; i < 10; ++i) {
                    if (sum((std::stoll(result) + i)) % 10 == 0) {
                        result = result + std::to_string(i);
                        flag = 1;
                        i = 10;
                    }
                }
                if (flag) break;
                rch = Random(10000, 99999);
                result = getstud(first_sex, first_date, rch);
            }
            return result;
        }
        return "----------------";
    }
};

class invokation{
public:
    static Generator* generator(const string& VUZ){
                if (VUZ == "MIEM") {
                    MIEM *a = new MIEM;
                    return a;
                } else {
                    if (VUZ == "MGTU"){
                        MGTU *a = new MGTU;
                        return a;
                    }
                }
                cout << "Unknown VUZ, try again";
                return nullptr;
    }
};