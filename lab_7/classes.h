#include <string>


class PassTicketGenerator {
protected:
    int sex;
    int year;
    int month;
    int day;
    std::string passticket = "";
public:
    virtual std::string Generator() = 0;
};

class PASS_MIEM : public PassTicketGenerator {
public:
    PASS_MIEM(std::string sex, int year, int month, int day) {
        this->sex = (sex == "man") ? 8 : 4;
        this->year = year;
        this->month = month;
        this->day = day;
    }
    std::string Generator() override final;
};

class PASS_MGTU : public PassTicketGenerator {
public:
    PASS_MGTU(std::string sex, int year, int month, int day) {
        this->sex = (sex == "man") ? 1 : 0;
        this->year = year;
        this->month = month;
        this->day = day;
    }
    std::string Generator() override final;
};

class GenTickets {
public:
    GenTickets(){}
    PassTicketGenerator* generate(std::string, std::string, int, int, int);
};
