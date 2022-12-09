#ifndef UNTITLED_CLASS_HPP
#define UNTITLED_CLASS_HPP

#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <cstring>

class Student_Ticket_Generator {
public:
    virtual int Summurise(const std::string &str) final {
        int sum = 0;
        for (size_t i = 0; i < str.size(); ++i) {
            char c = str[i];
            sum += ((c - '0') * (i+1));
        }
        return sum;
    }

    virtual int Random(int min, int max) final {
        return min + std::rand() % (max - min);
    }

    virtual int
    Generate_random_number(std::string &year, std::string &month, std::string &day,
                           std::map <std::string, std::vector<int>> &randomNumbers) = 0;

    virtual std::string
    generate(std::string &sex, std::string &year, std::string &month, std::string &day,
             std::map <std::string, std::vector<int>> &randomNumbers) = 0;
};

class MGTU : public virtual Student_Ticket_Generator {
public:
    virtual int
    Generate_random_number(std::string &year, std::string &month, std::string &day,
                           std::map <std::string, std::vector<int>> &randomNumbers) override {
        std::string s = (year) + (month) + (day);
        int number = Random(1000, 10000);
        if (randomNumbers.find(s) != randomNumbers.end()) {
            for (size_t i = 0; i < randomNumbers.find(s)->second.size(); ++i) {
                if (randomNumbers[s][i] == number) {
                    number = Random(1000, 10000);
                } else {
                    randomNumbers[s].push_back(number);
                }
            }
        } else {
            randomNumbers[s] = {};
            randomNumbers[s].push_back(number);
        }
        return number;
    }

    virtual std::string
    generate(std::string &sex, std::string &year, std::string &month, std::string &day,
             std::map <std::string, std::vector<int>> &randomNumbers) override {
        std::string gender;
        if (sex == "man") {
            gender = "2";
        } else if (sex == "woman") {
            gender = "1";
        }
        int number = Generate_random_number(year, month, day, randomNumbers);
        std::string s =
                gender + (year) + (month) + (day) + std::to_string(number);
        int Sum = Summurise(s);
        for (size_t i = 0; i < 10; ++i) {
            if ((Sum + i*14) % 11 == 0) {
                s = s + std::to_string(i);
                break;
            }
        }
        return s;
    }
};

class MIEM : public virtual Student_Ticket_Generator {
public:
    virtual int
    Generate_random_number(std::string &year, std::string &month, std::string &day,
                           std::map <std::string, std::vector<int>> &randomNumbers) override {
        std::string s = (year) + (month) + (day);
        int number = Random(10000, 100000);
        if (randomNumbers.find(s) != randomNumbers.end()) {
            for (size_t i = 0; i < randomNumbers.find(s)->second.size(); ++i) {
                if (randomNumbers[s][i] == number) {
                    number = Random(10000, 100000);
                } else {
                    randomNumbers[s].push_back(number);
                }
            }
        } else {
            randomNumbers[s] = {};
            randomNumbers[s].push_back(number);
        }
        return number;
    }

    virtual std::string
    generate(std::string &sex, std::string &year, std::string &month, std::string &day,
             std::map <std::string, std::vector<int>> &randomNumbers) override {
        std::string gender;
        if (sex == "man") {
            gender = "8";
        } else if (sex == "woman") {
            gender = "4";
        }
        int number = Generate_random_number(year, month, day, randomNumbers);
        std::string s =
                gender + (year) + (month) + (day) + std::to_string(number);
        int Sum = Summurise(s);
        for (size_t i = 0; i < 10; ++i) {
            if ((Sum + i*15) % 11 == 0) {
                s = s + std::to_string(i);
                break;
            }
        }
        return s;
    }
};

void CorrectInformation(std::string &year, std::string &month, std::string &day);

bool
CheckInformation(std::string &university, std::string &sex, std::string &year, std::string &month, std::string &day);

#endif //UNTITLED_CLASS_HPP
