#ifndef UNIVERSITY
#define UNIVERSITY

#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <iomanip>

class University {
public:
    virtual std::string generate(int, int, int, int) = 0;
};

class MIEM: public University {
    int man   = 8;
    int woman = 4;
public:
    MIEM() {}
    std::string generate(int, int, int, int) override; 
};

class MGTUU: public University {
    int man   = 2;
    int woman = 1;
public:
    MGTUU() {}
    std::string generate(int, int, int, int) override; 
};


class TicketGenerator {
public:
    TicketGenerator() {};
    University* generator(std::string);
};

#endif
