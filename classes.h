#ifndef UNIVERSITY
#define UNIVERSITY

#include <iostream>
#include <string>
#include <random>
#include <time.h>

/**
 * \brief Абстрактный класс. Является суперклассом для классов MIEM и MGTUU.
*/
class University {
public:
    virtual std::string generate(int, int, int, int) = 0;
};

/**
 * \brief Является подклассом University. Отвечат за генерацию билета для МИЭМ.
*/
class MIEM: public University {
    int man   =  8;
    int woman =  4;
    int sum   =  0;
    int mult  = 11;
public:
    MIEM() {}
    std::string generate(int, int, int, int) override; 
};

/**
 * \brief Является подклассом University. Отвечат за генерацию билета для МГТУУ.
*/
class MGTUU: public University {
    int man   =  2;
    int woman =  1;
    int sum   =  0;
    int mult  = 10;
public:
    MGTUU() {}
    std::string generate(int, int, int, int) override; 
};


/**
 * \brief Вспомогательный класс, для создания студ. билетов.
*/
class TicketGenerator {
public:
    TicketGenerator() {};
    University* generator(std::string);
};

#endif
