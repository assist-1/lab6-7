#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <time.h>
#include "functions.h"
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::ifstream;
using std::ofstream;
using std::string;
using std::to_string;

const char* flag[2] = { "--tofile", "--fromfile" };

class template_pattern_student_number_generator {
public:
    string sex, year, month, day, number, c, res = "";
    virtual string generate(string sex1, int year1, int month1, int day1) final {
        gender(sex1);
        date(year1, month1, day1);
        c_in_numbers();
        en();
    }
    virtual void gender(string sex1) {};
    virtual void c_in_numbers() {};
    virtual void date(int year1, int month1, int day1) {
        year = to_string(year1);
        res += year;
        if (month1 > 0 && month1 <= 12) {
            if (month1 >= 10) { month = to_string(month1); }
            else {
                month = "0" + to_string(month1);
            }
            res += month;
        }
        if (day1 >= 10 && day1 <= 31) { day = to_string(day1); }
        else if (day1 < 10 && day1 > 0) { day = "0" + to_string(day1); }
        res += day;
    }
    virtual string en() final {
        return res;
    }
};

class MIEM : public template_pattern_student_number_generator {
public:
    MIEM() {}; //default constructor
    void gender(string sex1) override {
        if (sex1 == "man") {
            res += "8";
        }
        else if (sex1 == "woman") {
            res += "4";
        }
    }
    void c_in_numbers() override {
        int sum = 0;
        int position = 1;
        srand(time(0));
        string num = to_string(rand() % 90000 + 10000);
        res += num;
        for (int i = 0; i < res.size(); i++) {
            sum += ((res[i] - '0') * position);
            position++;
        }
        for (int cnumber = 0; cnumber <= 9; cnumber++) {
            if ((sum + cnumber * 15) % 11 == 0) {
                res += to_string(cnumber);
                break;
            }
        }
    }
    ~MIEM() {}; //destructor
};


class MGTUU : public  template_pattern_student_number_generator {
public:
    MGTUU() {}; //default constructor
    void gender(string sex1) override {
        if (sex1 == "man") {
            res += "2";
        }
        else if (sex1 == "woman") {
            res += "1";
        }
    }
    void c_in_numbers() override {
        int sum = 0;
        int position = 1;
        srand(time(0));
        string num = to_string(rand() % 9000 + 1000);
        res += num;
        for (int i = 0; i < res.size(); i++) {
            sum += ((res[i] - '0') * position);
            position++;
        }
        for (int cnumber = 0; cnumber <= 9; cnumber++) {
            if ((sum + cnumber * 14) % 10 == 0) {
                res += to_string(cnumber);
                break;
            }
        }
    }
    ~MGTUU() {}; //destructor
};

class pointer {
public:
    template_pattern_student_number_generator* generator(string university1) {
        if (university1 == "MIEM") {
            MIEM* S1 = new MIEM;
            return S1;
        }
        else if (university1 == "MGTUU")
        {
            MGTUU* S2 = new MGTUU;
            return S2;
        }
        return 0;
    }
};

int main(int argc, char** argv) {
    int yearstud, monthstud, daystud;
    string universitystud, sexstud;
    if (argc == 1) {
        cerr << "Error: there are no flags" << endl;
    }
    else if (argc == 2) {
        cerr << "Error: not much segments" << endl;
    }
    else if (argc == 3) {
        char* name = argv[2];
        if (!(strcmp(argv[1], flag[0]))) {
            ofstream fout;
            fout.open(name);
            cin >> universitystud >> sexstud >> yearstud >> monthstud >> daystud;
            if (checkdata(yearstud, monthstud, daystud)) {
                pointer templateGenerator;
                string SB_1 = templateGenerator.generator(universitystud)->generate(sexstud, yearstud, monthstud, daystud);
                fout << universitystud;
                fout << ' ';
                fout << SB_1;
                fout.close();
            }
            else { cerr << "Problems with date" << endl; }
        }
        else if (!strcmp(argv[1], flag[1])) {
            ifstream fin;
            fin.open(name);
            fin >> universitystud >> sexstud >> yearstud >> monthstud >> daystud;
            if (checkdata(yearstud, monthstud, daystud)) {
                pointer templateGenerator;
                string SB_1 = templateGenerator.generator(universitystud)->generate(sexstud, yearstud, monthstud, daystud);
                cout << universitystud;
                cout << ' ';
                cout << SB_1;
                fin.close();
            }
            else { cerr << "Problems with date" << endl; }
        }
        else cerr << "Wrong flags" << endl;
    }
    else if (argc == 5) {
        if ((!strcmp(argv[1], flag[1]))) {
            if ((!strcmp(argv[3], flag[0]))) {
                char* name1 = argv[2];
                char* name2 = argv[4];
                ifstream fin;
                ofstream fout;
                fin.open(name1);
                fin >> universitystud >> sexstud >> yearstud >> monthstud >> daystud;
                if (checkdata(yearstud, monthstud, daystud)) {
                    pointer templateGenerator;
                    string SB_1 = templateGenerator.generator(universitystud)->generate(sexstud, yearstud, monthstud, daystud);
                    fout.open(name2);
                    fout << universitystud;
                    fout << ' ';
                    fout << SB_1;
                    fin.close();
                    fout.close();
                }
                else { cerr << "Problems with date" << endl; }
            }
            else {
                cerr << "Wrong flags" << endl;
            }
        }
        else {
            cerr << "Wrong flags" << endl;
        }
    }
    else {
        cerr << "Wrong flags" << endl;
    }
}
