#ifndef guard
#define guard

#include <string>
#include <ctime>
#include <iomanip>
#include <random>
#include <iostream>

class studentTicket{
    public:
        virtual std::string generate(char, int, int, int) = 0;
};

class MIEMTicket: public studentTicket{
        int man = 8;
        int woman = 4;

    public:
        MIEMTicket(){}
        std::string generate(char, int, int, int) override;
};

class MGTUUTicket: public studentTicket{
        int man = 2;
        int woman = 1;

    public:
        MGTUUTicket(){}
        std::string generate(char, int, int, int) override;
};

class ticketGenerator{
    public:
        ticketGenerator(){}
        studentTicket *generator(std::string);
};

#endif