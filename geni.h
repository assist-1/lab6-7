#ifndef __GENI_H__
#define __GENI_H__
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <stdlib.h>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::to_string;


class Generator {
    public:
    int S; //48 or 12
    int YYYY;
    string MM;
    string DD;
    string STUDAK;
    virtual string generator(string, int, string, string) = 0;
};



class MIEM : public Generator {
public:
    MIEM();
    virtual string generator(string sex, int YYYY, string MM, string DD) override{
    srand(time(NULL));
    if (sex == "female") S = 4;
    else if (sex == "male") S = 8;
    this->YYYY = YYYY;
    this->MM = MM;
    this->DD = DD;
    NNNNN = "";
    for (int i = 1; i < 6; ++i) {
    NNNNN = NNNNN+ to_string(rand()%10+0);    //generator
    }
    STUDAK = to_string(S) + to_string(YYYY) + MM + DD + NNNNN;
    int sum = 0;
    for (int i=1; i<15; ++i) sum=int(STUDAK[i-1])-i+sum;
    if (sum%11==0) STUDAK= STUDAK + "0";
    else {
        int c = 0;
        while (sum%11!=0) {++sum;++c;}
        STUDAK= STUDAK + to_string(c);
    }
    return STUDAK;
}
    string NNNNN;
};
MIEM::MIEM(){
    S = 8;
    YYYY = 1999;
    MM = "01";
    DD = "01";
    NNNNN = "00000";
    STUDAK = to_string(S) + to_string(YYYY) + MM + DD + NNNNN;

    int sum = 0;
    for (int i=1; i<15; ++i) sum=int(STUDAK[i-1])-i+sum;
    if (sum%11==0) STUDAK= STUDAK + "0";
    else {
        int c = 0;
        while (sum%11!=0) {++sum;++c;}
        STUDAK= STUDAK + to_string(c);
    }
}

class MGTUU : public Generator {
public:
    string NNNN;
    MGTUU();
    virtual string generator(string sex, int YYYY, string MM, string DD) override{
    srand(time(NULL));
    if (sex == "female") S = 1;
    else if (sex == "male") S = 2;
    this->YYYY = YYYY;
    this->MM = MM;
    this->DD = DD;
    NNNN = "";
    for (int i = 1; i < 5; ++i) {
    NNNN = NNNN+ to_string(rand()%10+0);    //generator
    }
    STUDAK = to_string(S) + to_string(YYYY) + MM + DD + NNNN;
    int sum = 0;
    for (int i=1; i<14; ++i) sum=int(STUDAK[i-1])-i+sum;
    if (sum%10==0) STUDAK= STUDAK + "0";
    else {
        int c = 0;
        while (sum%10!=0) {++sum;++c;}
        STUDAK= STUDAK + to_string(c);
    }
    return STUDAK;
}
};

MGTUU::MGTUU(){
    S = 2;
    YYYY = 1999;
    MM = "01";
    DD = "01";
    NNNN = "0000";
    STUDAK = to_string(S) + to_string(YYYY) + MM + DD + NNNN;

    int sum = 0;
    for (int i=1; i<14; ++i) sum=int(STUDAK[i-1])-i+sum;
    if (sum%10==0) STUDAK= STUDAK + "0";
    else {
        int c = 0;
        while (sum%10!=0) {++sum;++c;}
        STUDAK= STUDAK + to_string(c);
    }
}

#endif