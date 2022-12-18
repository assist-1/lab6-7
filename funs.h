#include <iostream>
#include <map>
#include <fstream>
#include <cstring>
#include <string>

using std::cout;
using std::string;
using std::ofstream;
using std::map;
using std::ifstream;
using std::cin;
using std::to_string;
using std::endl;

map<int, int> dict1;
map<int, int> dict2;

string help(int n, int a) {
    string res = "";
    while (a > 0) {
        a /= 10;
        n--;
    }for (int i = 0; i < n; i++) {
        res += "0";
    }return res;
}

int number(string s) {
    int res = 0;
    for (int i = 0; i < s.length(); i++) {
        res += ((int)s[i] - (int)'0') * (i + 1);
    }return res;
}

class Base {
public:
    string res = "", ans = "";
    int date = 0;
    virtual string generate(string, int, int, int) = 0;
protected:
    virtual void first(string, int, int, int) = 0;
    virtual void getran() = 0;
    virtual void finish() = 0;
};

class GeneratorMIEM : public Base {
public:
    string generate(string s, int y, int m, int d) {
        this->first(s, y, m, d);
        this->getran();
        this->finish();
        ans = res;
        res = "";
        return ans;
    }
protected:
    void first(string s, int y, int m, int d) {
        date = y * 10000 + m * 100 + d;
        if (s.compare("man") == 0) res += "8";
        else if (s.compare("woman") == 0) res += "4";
        res += to_string(date);
    }void getran() {
        if (not (dict1.count(date))) dict1[date] = rand() % 100000;
        res += help(5, dict1[date]) + to_string(dict1[date]);
    }void finish() {
        int a = number(res);
        res += to_string((11 - a % 11) % 11);
    }
};

class GeneratorMGTUU : public Base {
public:
    string generate(string s, int y, int m, int d) {
        this->first(s, y, m, d);
        this->getran();
        this->finish();
        ans = res;
        res = "";
        return ans;
    }
protected:
    void first(string s, int y, int m, int d) {
        date = y * 10000 + m * 100 + d;
        if (s.compare("man") == 0) res += "2";
        else if (s.compare("woman") == 0) res += "1";
        res += to_string(date);
    }void getran() {
        if (not (dict1.count(date))) dict1[date] = rand() % 10000;
        res += help(4, dict1[date]) + to_string(dict1[date]);
    }void finish() {
        int a = number(res);
        res += to_string((10 - a % 10) % 10);
    }
};

void output1(string name, string s, int y, int m, int d) {
    if (name.compare("MIEM") == 0) {
        GeneratorMIEM a;
        cout << a.generate(s, y, m, d) << endl;
    }
    else {
        GeneratorMGTUU a;
        cout << a.generate(s, y, m, d) << endl;
    }
}

void output2(ofstream* file, string name, string s, int y, int m, int d) {
    if (name.compare("MIEM") == 0) {
        GeneratorMIEM a;
        *file << a.generate(s, y, m, d) << endl;
    }
    else {
        GeneratorMGTUU a;
        *file << a.generate(s, y, m, d) << endl;
    }
}