#include <iostream>
#include <cstring>
#include <fstream>
#include <set>
#include "lab67.h"
using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::cerr;
std::set <string>  usedNum;
class interface {
public:
    virtual string generate(char s, int y, int m, int d) = 0;
};
class tempate_pattern_generator : public interface {
public:
protected:
    string generate(char s, int y, int m, int d) final {
        base_generation();
        gen_sex(s);
        gen_date(y, m, d);
        gen_NC();
        return take_();
    }

protected:
    string result;
    int ferr = 0;
    string sex, year, month, day, N;
    int num, C;
    ~tempate_pattern_generator() {};
    virtual void base_generation() final {
        sex = "";
        year = "";
        month = "";
        day = "";
        N = "";
        C = -1;
    }
    virtual void gen_sex(char s) {};

    virtual void gen_date(int y, int m, int d) final {
        if (y > 1000 && y < 2023) {
            year = to_str(y);
            result += year;
        }
        if (m > 0 && m < 13) {
            if (m < 10) { month = "0" + to_str(m); }
            else
            {
                month = to_str(m);
            }
            result += month;
        }
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
            if (d > 0 && d < 32) {
                if (d < 10) { day = "0" + to_str(d); }
                else
                {
                    day = to_str(d);
                }
                result += day;
            }
        }
        else if (m == 2)
        {
            if (d > 0 && d < 29) {
                if (d < 10) { day = "0" + to_str(d); }
                else
                {
                    day = to_str(d);
                }
                result += day;
            }
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11) {
            if (d > 0 && d < 31) {
                if (d < 10) { day = "0" + to_str(d); }
                else
                {
                    day = to_str(d);
                }
                result += day;
            }
        }
    };
    virtual void gen_NC() {};

    virtual string take_() final {
        return result;
    }
};

class generator_MEMA : public tempate_pattern_generator {
protected:
    ~generator_MEMA() {};
    void gen_sex(char s) override {
        if (s == 'M' || s == 'm') { sex = "8"; result += sex; }
        else if (s == 'F' || s == 'f') { sex = "4"; result += sex; }
    }

    void gen_NC() override {
        num = 11;
        while (C == -1) {
            N = to_str(randomnum(0, 99999));
            if (N.size() < 5) {
                string sn(5 - N.size(), '0');
                N = sn + N;
            }
            C = ost(result, N, num);
            if (C > -1) {
                if (usedNum.find(result + N + to_str(C)) == usedNum.end())
                {
                    result += N + to_str(C);
                    usedNum.insert(result);
                }
                else { C = -1; }
            }
        }
    }
};

class generator_MGTUU : public tempate_pattern_generator {
protected:
    ~generator_MGTUU() {};
    void gen_sex(char s) override {
        if (s == 'M' || s == 'm') { sex = "2"; result += sex; }
        else if (s == 'F' || s == 'f') { sex = "1"; result += sex; }
    }

    void gen_NC() override {
        num = 10;
        while (C == -1) {
            N = to_str(randomnum(0, 9999));
            if (N.size() < 4) {
                string sn(4 - N.size(), '0');
                N = sn + N;
            }
            C = ost(result, N, num);
            if (C > -1) {
                if (usedNum.find(result + N + to_str(C)) == usedNum.end())
                {
                    result += N + to_str(C);
                    usedNum.insert(result);
                }
                else { C = -1; }
            }
        }
    }
};

class unite {
public:
    interface* generator(string str) {
        if (str == "MIEM") {
            interface* st1 = new generator_MEMA;
            return st1;
        }
        else if (str == "MGTUU") {
            interface* st2 = new generator_MGTUU;
            return st2;
        }
    }
};
int main(int argc, char* argv[])
{
    std::ifstream fin;
    std::ofstream fout;
    string university;
    char sex;
    int year, month, day;
    int n;
    if (argc == 1)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> university >> sex >> year >> month >> day;
            if (correct_data(university, sex, year, month, day) == 0)
            {
                unite tp;
                string answer = tp.generator(university)->generate(sex, year, month, day);
                usedNum.insert(answer);
                cout << answer << endl;
            }
            else {
                cerr << "You did a mistake. I can't print anything" << endl;
            }
        }
    }
    else if (argc > 5) {
        cerr << "ERROR! Too many flags" << endl;
        return -1;
    }
    else if (argc == 3) {
        if (!strcmp(argv[1], "--tofile")) {
            fout.open(argv[2]);
            cin >> n;
            for (int i = 1; i <= n; i++)
            {
                cin >> university >> sex >> year >> month >> day;
                if (correct_data(university, sex, year, month, day) == 0)
                {
                    unite tp;
                    string answer = tp.generator(university)->generate(sex, year, month, day);
                    usedNum.insert(answer);
                    fout << answer << endl;
                }
                else {
                    cerr << "You did a mistake. I can't print anything" << endl;
                }
            }
        }
        else if (!strcmp(argv[1], "--fromfile")) {
            fin.open(argv[2]);
            fin >> n;
            for (int i = 1; i <= n; i++)
            {
                fin >> university >> sex >> year >> month >> day;
                if (correct_data(university, sex, year, month, day) == 0)
                {
                    unite tp;
                    string answer = tp.generator(university)->generate(sex, year, month, day);
                    usedNum.insert(answer);
                    cout << answer << endl;
                }
                else {
                    cerr << "You did a mistake. I can't print anything" << endl;
                }
            }
        }
        else {
            cerr << "ERROR! Flags are not correct" << endl;
            return -1;
        }
    }
    else {
        if (!strcmp(argv[3], "--tofile") && !strcmp(argv[1], "--fromfile")) {
            fin.open(argv[2]);
            fout.open(argv[4]);
            fin >> n;
            for (int i = 1; i <= n; i++)
            {
                fin >> university >> sex >> year >> month >> day;
                if (correct_data(university, sex, year, month, day) == 0)
                {
                    unite tp;
                    string answer = tp.generator(university)->generate(sex, year, month, day);
                    usedNum.insert(answer);
                    fout << answer << endl;
                }
                else {
                    cerr << "You did a mistake. I can't print anything" << endl;
                }
            }
        }
        else {
            cerr << "ERROR! Flags are not correct" << endl;
            return -1;
        }
    }
    fin.close();
    fout.close();
    return 0;
}