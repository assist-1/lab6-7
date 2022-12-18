#include <string>
#include <iostream>

int GetRandomNumber(int min, int max)
{
  srand(time(NULL));
  int num = min + rand() % (max - min + 1);
  return num;
}

std::string zfill(std::string str, int n) {
    std::string zeros(n - str.length(), '0');
    return zeros + str;
}

class StudentID
{
    protected:
        int sex;
        int year;
        int month;
        int day;
    public:
        virtual const std::string generator() = 0;
        virtual const int get_c(int sex, int year, int month, int day, int random_number) = 0;
};

class Miem : virtual StudentID 
{
    public:
        Miem(int sex, int year, int month, int day) {
			this -> sex = sex;
			this -> year = year;
            this -> month = month;
            this -> day = day;
		};

    const int get_c(int sex, int year, int month, int day, int random_number) override {
        int c = sex + 2 * (year / 1000) + 3 *  ((year / 100) % 10) + 4 * ((year / 10) % 10) + 5 * (year % 10)
                + 6 * (month / 10) + 7 * (month % 10) + 8 * (day / 10) + 9 * (day % 10)
                + 10 * (random_number / 10000) + 11 * ((random_number / 1000) % 10) + 12 * ((random_number / 100) % 10)
                + 13 * ((random_number / 10) % 10) + 14 * (random_number % 10);
        int i = 0;
        for (i; i <= 10; ++i) {
            if ((c + (i * 15)) % 11 == 0) break;
        }
        return i;
    };

    const std::string generator() override {
        std::string personal_number = "";
        int newsex;
        if (sex == 0) newsex = 4;
        if (sex == 1) newsex = 8;
        personal_number += std::to_string(newsex);
        personal_number += std::to_string(year);
        personal_number += zfill(std::to_string(month), 2);
        personal_number += zfill(std::to_string(day), 2);
        int random_number = GetRandomNumber(0, 99999);
        personal_number += zfill(std::to_string(random_number), 5);
        int c = get_c(newsex, year, month, day, random_number);
        personal_number += std::to_string(c);

        return personal_number;
    };
};



class Mgtu : virtual StudentID 
{
    public:
        Mgtu(int sex, int year, int month, int day) {
			this -> sex = sex;
			this -> year = year;
            this -> month = month;
            this -> day = day;
		};

    const int get_c(int sex, int year, int month, int day, int random_number) override {
        int c = sex + 2 * (year / 1000) + 3 *  ((year / 100) % 10) + 4 * ((year / 10) % 10) + 5 * (year % 10)
                + 6 * (month / 10) + 7 * (month % 10) + 8 * (day / 10) + 9 * (day % 10)
                + 10 * ((random_number / 1000) % 10) + 11 * ((random_number / 100) % 10)
                + 12 * ((random_number / 10) % 10) + 13 * (random_number % 10);
        int i = 0;
        for (int i = 0; i <= 10; ++i) {
            if ((c + (i * 15)) % 11 == 0) break;
        }
        return i;
    };

    const std::string generator() override {
        std::string personal_number = "";
        int newsex;
        if (sex == 0) newsex = 1;
        if (sex == 1) newsex = 2;
        personal_number += std::to_string(newsex);
        personal_number += std::to_string(year);
        personal_number += zfill(std::to_string(month), 2);
        personal_number += zfill(std::to_string(day), 2);
        int random_number = GetRandomNumber(0, 9999);
        personal_number += zfill(std::to_string(random_number), 4);
        int c = get_c(newsex, year, month, day, random_number);
        personal_number += std::to_string(c);

        return personal_number;
    };
};