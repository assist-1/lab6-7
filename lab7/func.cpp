#include <iostream>
#include "classes.h"
using std::cerr;
int to_integer(char a) {
    switch (a) {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    default:
        return -1;
    }
}

bool data_verification(string u,string s,int y,int m,int d)
{
    if (u!="MIEM" && u!="MGTUU")
    {
        cerr<<"Incorrect university";
        return false;
    }
    if ((s!="Female" && s!="female") && (s!="Male" && s!="male"))
    {
        cerr<<"Incorrect gender: write female/male; Female/Male";
        return false;
    }
    if (y<1000 || y>2023)
    {
        cerr<<"Error of year";
        return false;
    }
    if (m<1 || m>12)
    {
        cerr<<"Error of month";
        return false;
    }
    if (d<1 || d>31)
    {
        cerr<<"Error of day";
        return false;
    }
    return true;
}
