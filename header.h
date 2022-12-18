#ifndef LR_6_HEADER_H
#define LR_6_HEADER_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <unistd.h>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
string MIEM_S(string pol);

class Studak {
public:
    virtual string generate (string &sex, string &year, string &month, string &day) = 0;
};

class MIEM : public Studak{
public:
    string generate(string &sex, string &year, string &month, string &day) override{
        string str = "";
        str = MIEM_S(sex) + year + month + day + random();
        str+= end(str);
        return str;
    }
private:
    string random (){
        string NNNNN = "";
        srand(time(NULL));
        sleep(1);
        int val;
        for(int i = 0; i < 5; i ++){
            val = rand() % 10;
            NNNNN += std::to_string(val);
        }
        return NNNNN;
    }
    string end (string str){
        int sum = 0, val;
        char a;
        for(int i = 14; i > 0; i--){
            a = str[i-1];
            val = int(a-48);
            sum += val * i;
        }
        return std::to_string((11-sum%11)%11);
    }
};

class MGTU : public Studak{
public:
    string generate(string &sex, string &year, string &month, string &day) override {
        string str = "";
        str = MGTU_S(sex) + year + month + day + random();
        str += end(str);
        return str;
    }
private:
    string MGTU_S(string pol){
        if(pol == "man")
            return "2";
        else
            return "1";
    }
    string random (){
        string NNNN = "";
        srand(time(NULL));
        int val;
        for(int i = 0; i < 4; i ++){
            val = rand() % 10;
            NNNN += std::to_string(val);
        }
        return NNNN;
    }
    string end (string str){
        int sum = 0, val;
        char a;
        for(int i = 13; i > 0; i--){
            a = str[i-1];
            val = int(a-48);
            sum += val * i;
        }
        return std::to_string((10-sum%10)%10);
    }
};

string Go (Studak* st, string &sex, string &year, string &month, string &day);

bool proverkaSex(string &text);
bool proverkaYear(string &val);
bool proverkaMMDD(string &DD, string &MM, string &YYYY);

#endif //LR_6_HEADER_H
