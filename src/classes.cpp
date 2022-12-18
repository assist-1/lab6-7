#include "classmake.h"
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <time.h>


class University {
    public:
    virtual std::string generate() = 0;
};



class MIEM : public University {
    int year;
    int month;
    int day;
    int total = 0;
    int del = 11;
    std::string card = "";
    std::string sex;
public:
    MIEM(std::string sex, int year, int month, int day) {
        this->sex = sex;
        this->year = year;
        this->month = month;
        this->day = day;
    }
    std::string generate() override {
        if (sex == "woman") {
            card+=std::to_string(4);
            total+=4;
        }
        else {
            card+=std::to_string(8);
            total+=8;
        }

        int date = 10000*year + 100*month + day;
        card += std::to_string(date);
        for (int i = 1; i < card.size(); i++) {
            total += (card[i] - '0') * (i+1);
        }
        std:: mt19937 seq(date + time(0));
        std:: uniform_int_distribution<> gap(10000,99999);
        std::string num_random = std::to_string(gap(seq));
        for (int i = 0; i < num_random.size();i++){
            total+=(num_random[i]-'0')*(10+i);
        }
        while (total % del == 4) {
            total = total - num_random[2]*(10+2);
            int digit_new = ((num_random[2] - '0')+1)%10 + '0';
            num_random = {num_random[0],num_random[1],(char)digit_new,num_random[3],num_random[4]};
            total = total + digit_new*(10+2);
        }
        card+=num_random;
        int remain = total / del;
        for (int i = 0; i < 10;i++) {
            if ((remain + (15*i)%10)%10 == 0) {
                remain = 0;
                card+=std::to_string(i);
                break;
            }
        }
        return card;
    }
};



class MGTU: public University {
    int year;
    int month;
    int day;
    int total = 0;
    int del = 11;
    std::string card = "";
    std::string sex;
public:
    MGTU(std::string sex,int year, int month, int day) {
        this->sex = sex;
        this->year = year;
        this->month = month;
        this->day = day;
    }
    std::string generate() override {
        if (sex == "man") {
            card+=std::to_string(0);
            total+=0;
        }
        else {
            card+=std::to_string(1);
            total+=1;
        }
        int date = 10000*year+100*month+ day;
        card+=std::to_string(date);
        for (int i = 1; i < card.size();i++){
            total+=(card[i] - '0') * (i+1);
        }
        std:: mt19937 seq(date + time(0));
        std:: uniform_int_distribution<> gap(1000,9999);
        std::string num_random = std::to_string(gap(seq));
        for (int i = 0; i < num_random.size();i++){
            total+=(num_random[i] - '0')*(10+i);
        }
        while (total % 2 == 1) {
            total = total - num_random[2]*(10+2);
            int digit_new = ((num_random[2] - '0')+1)%10 + '0';
            num_random = {num_random[0],num_random[1],(char)digit_new,num_random[3]};
            total = total + digit_new*(10+2);
        }
        card+=num_random;
        int remain = total / del;
        for (int i = 0; i < 10;i++) {
            if ((remain + (14*i)%10)%10 == 0) {
                remain = 0;
                card+=std::to_string(i);
                break;
            }
        }
        return card;
    }
};


void clear(std::string file_to_clear) {
    std::ofstream file(file_to_clear);
    file<<"";
}

void CheckFunc(int year_dig,int month_dig,int day_dig) {
    if (year_dig < 1900 || year_dig > 2010){
        std::cerr << "--Enter correct year (1900-2010)--" << std::endl;
        exit(1);
    }
    if (month_dig < 1 || month_dig > 12){
        std::cerr << "--Enter correct month--" << std::endl;
        exit(1);
    }
    if (day_dig < 1 && day_dig > 31){
        std::cerr << "--Enter correct day--" << std::endl;
        exit(1);
    }

    int dnvm[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    if (year_dig%4 != 0) dnvm[1] = 28;
    if (!(day_dig <= dnvm[month_dig -1]) )
    {
        std::cerr << "--Enter correct date--" << std::endl;
        exit(1);
    }
}

std::string prog(std::string file_read){

    std::string name = "";
    std::string sex = "";
    std::string year = "";
    std::string month = "";
    std::string day = "";
    if(file_read != ""){

        std::ifstream in(file_read);
        if (in.is_open()){
            in >> name >> sex >> year >> month >> day;
        }
        else std::cout << "The file does not exist" << std::endl;
        in.close();
    }
    else{
        std::cout << "Enter university name" << std::endl;
        std::cin >> name;
        std::cout << "Enter sex" << std::endl;
        std::cin >> sex;
        std::cout << "Enter birthday year" << std::endl;
        std::cin >> year;
        std::cout << "Enter birthday month" << std::endl;
        std::cin >> month;
        std::cout << "Enter birthday day" << std::endl;
        std::cin >> day;
    }

    if (!(name == "MIEM" || name == "MGTU"))
    {
        std::cerr << "--Enter correct university name--" << std::endl;
        exit(1);
    }
    if (sex != "man" && sex != "woman") {
        std::cerr << "--Enter correct sex--" << std::endl;
        exit(1);
    }

    int year_dig = stoi(year);
    int month_dig = stoi(month);
    int day_dig = stoi(day);

    CheckFunc(year_dig,month_dig,day_dig);
    std::string ans = "";
    if (name == "MIEM"){
        MIEM obj(sex,year_dig,month_dig,day_dig);
        ans = obj.generate();
    }
    else{
        MGTU ob(sex,year_dig,month_dig,day_dig);
        ans = ob.generate();
    }


    return  ans;
}

int mon = 5;
int yea = 2005;
int da = 15;
std::string se = "man";
std::string name = "MIEM";
class GOT {
    public:
    GOT(){};
    University* generate(std::string);
};
University* GOT::generate(std::string name)
{
    if (name == "MIEM") {
        MIEM* univer = new MIEM(se,yea,mon,da);
        return univer;
    }
    else {
        MGTU* univer = new MGTU(se,yea,mon,da);
        return univer;
    }
}
