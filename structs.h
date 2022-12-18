#ifndef STRUCTS_H
#define STRUCTS_H
#include <string>
#include <list>

using std::string;
using namespace std;

struct Student {
    int sex;
    int year;
    int month;
    int day;
    int university; // 1 - MIEM 0 - MGTUU

};

struct Flags {
    bool fromFile;
    string fromFileName;
    bool toFile;
    string toFileName;
};

typedef list<Student> sList; 
#endif