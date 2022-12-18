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

class stud_card {
public:
    virtual void gender(string sex1) = 0;
    virtual void c_in_numbers() = 0;
    virtual void date(int year1, int month1, int day1) = 0;
};

class MIEM : virtual public stud_card {
public:
    string sex, year, month, day, number, c, res = "";
    MIEM() {}; //default constructor
    void gender(string sex1) override {
        if (sex1 == "man") {
            res += "8";
        }
        else if (sex1 == "woman") {
            res += "4";
        }
    }
    void date(int year1, int month1, int day1) override {
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


class MGTUU : virtual public stud_card {
public:
    string sex, year, month, day, number, c, res = "";
    MGTUU() {}; //default constructor
    void gender(string sex1) override {
        if (sex1 == "man") {
            res += "2";
        }
        else if (sex1 == "woman") {
            res += "1";
        }
    }
    void date(int year1, int month1, int day1) override {
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


int main(int argc, char** argv) {
    int yearstud, monthstud, daystud;
    string sexstud;
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
            cin >> sexstud >> yearstud >> monthstud >> daystud;
            if (checkdata(yearstud, monthstud, daystud)) {
                MIEM stud1;
                stud1.gender(sexstud);
                stud1.date(yearstud, monthstud, daystud);
                stud1.c_in_numbers();
                MGTUU stud2;
                stud2.gender(sexstud);
                stud2.date(yearstud, monthstud, daystud);
                stud2.c_in_numbers();
                fout << stud1.res;
                fout << '\n';
                fout << stud2.res;
                fout << '\n';
                fout.close();
            }
            else { cerr << "Problems with date" << endl; }
        }
        else if (!strcmp(argv[1], flag[1])) {
            ifstream fin;
            fin.open(name);
            fin >> sexstud >> yearstud >> monthstud >> daystud;
            if (checkdata(yearstud, monthstud, daystud)) {
                MIEM stud1;
                stud1.gender(sexstud);
                stud1.date(yearstud, monthstud, daystud);
                stud1.c_in_numbers();
                MGTUU stud2;
                stud2.gender(sexstud);
                stud2.date(yearstud, monthstud, daystud);
                stud2.c_in_numbers();
                cout << stud1.res;
                cout << '\n';
                cout << stud2.res;
                cout << '\n';
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
                fin >> sexstud >> yearstud >> monthstud >> daystud;
                if (checkdata(yearstud, monthstud, daystud)) {
                    MIEM stud1;
                    stud1.gender(sexstud);
                    stud1.date(yearstud, monthstud, daystud);
                    stud1.c_in_numbers();
                    MGTUU stud2;
                    stud2.gender(sexstud);
                    stud2.date(yearstud, monthstud, daystud);
                    stud2.c_in_numbers();
                    fout.open(name2);
                    fout << stud1.res;
                    fout << '\n';
                    fout << stud2.res;
                    fout << '\n';
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
