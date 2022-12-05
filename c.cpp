#include <fstream>
#include <iostream>
#include <cstring>
#include "lab67.h"
using std::cin;
using std::cout;
using std::endl;

int flag_read = 0;
int flag_write = 0;
int flag_error = 1;
std::ifstream fin;
std::ofstream fout;
class interface { 
public:
    virtual void generator(char sex, int year, int month, int day) = 0;
};


class template_pattern_generator : public interface { 
public:
    void generator(char sex,int year,int month,int day) override {
        gener_base(); 
        generate(sex, year, month, day); 
        print(); 
    }
protected:
    virtual void gener_base() = 0;
    virtual void generate(char s, int y, int m, int d) = 0;
    virtual void print() { cout << "template_pattern_generator is working" << endl; }
};


class generator_MEM : public template_pattern_generator {
    int sex;
    double result;
    int year, month, day, N, C;
protected:
    void gener_base() override { 
        sex = 0;
        year = 0;
        month = 0;
        day = 0;
        N = -1;
        C = -1;
    }
    void print() override { 
        if (flag_error == 1)
        {
            if (flag_write == 0)
            {
                cout.precision(0);
                cout << std::fixed << result << endl;
            }
            else { fout.precision(0); fout << std::fixed << result << endl; }
        }
        else { cout << "ERROR!" << endl; }
    }
    void generate(char s, int y, int m, int d) override { 
        if (s == 'M') { sex = 8; }
        else if (s == 'W') { sex = 4; }
        else { flag_error = 0; }

        if (y > 0 && y < 2023) { year = y; }
        else { flag_error = 0; }

        if (m > 0 && m < 13) { month = m; }
        else { flag_error = 0; }

        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
            if (d > 0 && d < 32) { day = d; }
            else { flag_error = 0; }
        }
        else if (m == 2)
        {
            if (d > 0 && d < 29) { day = d; }
            else { flag_error = 0; }
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11) {
            if (d > 0 && d < 31) { day = d; }
            else { flag_error = 0; }
        }

        while (C == -1)
        {
            result = 0;
            N = Random(0, 100000);
            if (N <= 9) { day *= 10000; result += day * 100; }
            else if (N >= 10 && N <= 99) { day *= 1000; result += day * 1000; }
            else if (N >= 100 && N <= 999) { day *= 100; result += day * 10000; }
            else if (N >= 1000 && N <= 9999) { day *= 10; result += day * 100000; }
            else { result += day * 1000000; }
            result += (double)sex * 100000000000000 + (double)year * 10000000000 + month * 100000000 + N * 10;
            C = ost(sex, year, month, day, N, 11);
            if (C > -1)
            {
                result += C;
            }
        }
    }
};


class generator_MGTUU : public template_pattern_generator {
    int sex;
    double result;
    int year, month, day, N, C;
protected:
    void gener_base() override {
        sex = 0;
        year = 0;
        month = 0;
        day = 0;
        N = -1;
        C = -1;
    }
    void print() override { 
        if (flag_error == 1)
        {
            if (flag_write == 0)
            {
                cout.precision(0);
                cout << std::fixed << result << endl;
            }
            else { fout.precision(0); fout << std::fixed << result << endl; }
        }
        else { cout << "ERROR!" << endl; }
    }
    void generate(char s, int y, int m, int d) override { 
        if (s == 'M') { sex = 2; }
        else if (s == 'W') { sex = 1; }
        else { flag_error = 0; }
        
        if (y > 0 && y < 2023) { year = y; }
        else { flag_error = 0; }

        if (m > 0 && m < 13) { month = m; }
        else { flag_error = 0; }

        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
            if (d > 0 && d < 32) { day = d; }
            else { flag_error = 0; }
        }
        else if (m == 2)
        {
            if (d > 0 && d < 29) { day = d; }
            else { flag_error = 0; }
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11) {
            if (d > 0 && d < 31) { day = d; }
            else { flag_error = 0; }
        }

        while (C == -1) 
        {
            result = 0;
            N = Random(0, 10000);
            if (N <= 9) { day *= 1000; result += day * 100; }
            else if (N >= 10 && N <= 99) { day *= 100; result += day * 1000; }
            else if (N >= 100 && N <= 999) { day *= 10; result += day * 10000; }
            else { result += day * 100000; }
            result += (double)sex * 10000000000000 + (double)year * 1000000000 + month * 10000000 + N * 10;
            C = ost(sex, year, month, day, N, 10);
            if (C > -1)
            {
                result += C;
            }         
        }
    }
};


int main(int argc, char* argv[])
{
    char sex;
    int year, month, day;
    generator_MGTUU stud1;
    generator_MEM stud2;
    interface* gr1 = &stud1;
    interface* gr2 = &stud2;
    if (argc == 1)
    { 
        flag_read = 0;
        flag_write = 0;
    }
    else if (argc > 5) {
        std::cout << "ERROR! Too many flags" << std::endl;
        return -1;
    }
    else if (argc == 3) {
        if (!strcmp(argv[1], "--tofile")) {
            flag_write = 1;
            fout.open(argv[2]);
        }
        else if (!strcmp(argv[1], "--fromfile")) {
            flag_read = 1;
            fin.open(argv[2]);
        }
        else {
            std::cout << "ERROR! Flags are not correct" << std::endl;
            return -1;
        }
    }
    else {
        if (!strcmp(argv[3], "--tofile") && !strcmp(argv[1], "--fromfile")) {
            flag_read = 1;
            flag_write = 1;
            fin.open(argv[2]);
            fout.open(argv[4]);
        }
        else {
            std::cout << "ERROR! Flags are not correct" << std::endl;
            return -1;
        }
    }
    if (flag_read == 0) {
        cin >> sex >> year >> month >> day;
    }
    else {
        fin >> sex >> year >> month >> day;
    }
    gr1->generator(sex,year,month,day);
    gr2->generator(sex, year, month, day);
    fin.close();
    fout.close();
    return 0;
}
