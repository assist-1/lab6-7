#include <iostream> 
#include<string> 
#include <random> 
#include<fstream>
#include<cstring>
#include "func.h"
class uni { 
public: 
    int sex; 
    std::string year; 
    std::string month; 
    std::string day; 
 
    virtual std::string propusk(int, std::string, std::string, std::string) = 0; 
}; 
 
 
class Miem :public uni { 
    std::string propusk(int sex, std::string year, std::string month, std::string day) override{ 
        int sm = 0; 
        std::string s = ""; 
        if (sex == 0) { 
            s += std::to_string(8); 
            sm += 8; 
 
        } 
        else { 
            s += std::to_string(4); 
            sm += 4; 
        } 
        if (stoi(year) >= 1955 && stoi(year) <= 2022 && stoi(month) >= 1 && stoi(month) <= 12 && stoi(day) >= 1 && stoi(day) <= 30) { 
            s = s + (year)+(month)+(day); 
            sm = sm + stoi(year) + stoi(month) + stoi(day); 
        } 
        else { 
            return 0; 
        } 
        int id = rand() % (99999 - 10000) + 10000; 
        if (id % 10 == 8) { 
            id += 1; 
            s = s + std::to_string(id); 
        } 
        else { 
            s = s + std::to_string(id); 
        } 
        for (int i = 0; i < s.size(); ++i) 
            sm += (s[i] - '0') * (i + 1); 
        for (int i = 0; i < 10; ++i) { 
            if ((sm + i) % 11 == 0) { 
                s += std::to_string(i); 
                return s; 
                break; 
            } 
        } 
        return 0; 
 
    } 
}; 
 
 
 
class MGTUU : public uni { 
    std::string propusk(int sex, std::string year, std::string month, std::string day) override { 
        int sm = 0; 
        std::string s = ""; 
        if (sex == 0) { 
            s += std::to_string(1); 
            sm += 1; 
 
        } 
        else { 
            s += std::to_string(2); 
            sm += 2; 
        } 
        if (stoi(year) >= 1955 && stoi(year) <= 2022 && stoi(month) >= 1 && stoi(month) <= 12 && stoi(day) >= 1 && stoi(day) <= 30) { 
            s = s + (year)+(month)+(day); 
            sm = sm + stoi(year) + stoi(month) + stoi(day); 
        } 
        else { 
            return 0; 
        } 
        int id = rand() % (99999 - 10000) + 10000; 
        if (id % 10 == 8) { 
            id += 1; 
            s = s + std::to_string(id); 
        } 
        else { 
            s = s + std::to_string(id); 
        } 
        for (int i = 0; i < s.size(); ++i) 
            sm += (s[i] - '0') * (i + 1); 
        for (int i = 0; i < 10; ++i) { 
            if ((sm + i) % 11 == 0) { 
                s += std::to_string(i); 
                return s; 
                break; 
            } 
        } 
        return 0; 
 
    } 
}; 
 



int main(int argc, char** argv) 
{ 
    if (argc == 1){
        read_cin(0);
        exit(0);
    }
    else { 
        if (strcmp(argv[1], "--tofile") == 0) { 
            read_cin(1);
            exit(0); 
        } 
        else if (strcmp(argv[1], "--fromfile") == 0) { 
            read_file(0); 
            exit(0);
            
        }
         
    }
 

     
 
 
}