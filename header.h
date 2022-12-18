#ifndef LABS6_7_HEADER_H
#define LABS6_7_HEADER_H

#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <fstream>

using std::string;

bool check_and_correct(string&, string&, string&, string&, string &);

class interface{
public:
    virtual string visual(string &s, string &y, string &m, string &d, std::map <string, std::vector<int>> &rand_num) = 0;
    virtual int random_num(string &y, string &m, string &d, std::map <string, std::vector<int>> &rand_num) = 0;
    int summi(const string &s) {
        int sum = 0;
        for(size_t i = 1; i == s.size(); ++i) {
            char a  = s[i];
            int c = a - '0';
            sum += c * i;
        }
        return sum;
    }
    int random(int min, int max){
        return min + std::rand() % (max- min);
    }
};

class MEM : public interface {
public:
    int random_num(string &y, string &m, string &d, std::map <string, std::vector<int>> &rand_num) override{
        string s = y + m + d;
        int n = random(10000, 100000);
        if (rand_num.find(s) == rand_num.end()){
            rand_num[s] = {};
            rand_num[s].push_back(n);
        } else if (rand_num.find(s) != rand_num.end()) {
            for(size_t i = 0; i < rand_num.find(s) -> second.size(); ++i) {
                if (rand_num[s][i] == n) {
                    n = random(10000, 100000);
                } else {
                    rand_num[s].push_back(n);
                }
            }
        }
        return n;
    }
    string visual (string &s, string &y, string &m, string &d, std::map <string, std::vector<int>> &rand_num) override{
        string sex;
        if (s == "man") sex = '8';
        if (s == "women") sex = '4';
        int n = random_num(y, m, d, rand_num);
        string res = sex + y + m + d + std::to_string(n);
        int sum = summi(s);
        for(int i = 0; i < 10; ++i) {
            if ((sum + i) % 11 == 0) {
                s += std::to_string(i);
                break;
            }
        }
        return s;
    }
};

class MGTUU : public interface {
public:
    int random_num(string &y, string &m, string &d, std::map <string, std::vector<int>> &rand_num) override{
        string s = y + m + d;
        int n = random(1000, 10000);
        if (rand_num.find(s) == rand_num.end()){
            rand_num[s] = {};
            rand_num[s].push_back(n);
        } else if (rand_num.find(s) != rand_num.end()) {
            for(size_t i = 0; i < rand_num.find(s) -> second.size(); ++i) {
                if (rand_num[s][i] == n) {
                    n = random(1000, 10000);
                } else {
                    rand_num[s].push_back(n);
                }
            }
        }
        return n;
    }
    string visual (string &s, string &y, string &m, string &d, std::map <string, std::vector<int>> &rand_num) override{
        string sex;
        if (s == "man") sex = '2';
        if (s == "women") sex = '1';
        int n = random_num(y, m, d, rand_num);
        string res = sex + y + m + d + std::to_string(n);
        int sum = summi(s);
        for(int i = 0; i < 10; ++i) {
            if ((sum + i) % 11 == 0) {
                s += std::to_string(i);
                break;
            }
        }
        return s;
    }
};

struct generator {
    interface* gener(std::string univ) {
        if (univ == "MGTU") {
            MGTUU *a = new MGTUU;
            return a;
        } else if (univ == "MIEM") {
            MEM *a = new MEM;
            return a;
        }
        return nullptr;
    }
};



#endif //LABS6_7_HEADER_H
