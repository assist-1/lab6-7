#include <iostream>
#include <cstring>
#include "Header.h"
#include <fstream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ofstream;
using std::ifstream;
bool data_verification(string s,int y,int m,int d);
bool tofile=false;
bool fromfile=false;
int main(int argc, char **argv) {
    string sex;
    int year,month,day;
    if (argc==1){
        cerr << "Nothing was read!"<<endl;
        return EXIT_FAILURE;
    }
    if (argc==3 && !strcmp(argv[1],"--tofile"))
    {
        tofile=true;
        ofstream fout;
        fout.open(argv[2]);
        cout<<"Write your gender, year, month and day of birth."<<endl<<"Example: female 2002 10 29"<<endl;
        cin>> sex >> year >> month >> day;
        if (data_verification(sex,year, month,day)==true)
        {
            MIEM st1;
            st1.gender(sex);
            st1.date(year,month,day);
            st1.complicated_numbers();
            MGTUU st2;
            st2.gender(sex);
            st2.date(year,month,day);
            st2.complicated_numbers();
            st1.Print(fout);
            st2.Print(fout);
            fout.close();
        }
    }
    else if (argc==3 && !strcmp(argv[1],"--fromfile"))
    {
        fromfile=true;
        ifstream fin;
        fin.open(argv[2]);
        fin>> sex >> year >> month >> day;
        if (data_verification(sex,year, month,day)==true)
        {
            MIEM st1;
            st1.gender(sex);
            st1.date(year,month,day);
            st1.complicated_numbers();
            MGTUU st2;
            st2.gender(sex);
            st2.date(year,month,day);
            st2.complicated_numbers();
            st1.Print(cout);
            st2.Print(cout);
            fin.close();
        }
    }
    else if (argc==5 && !strcmp(argv[1],"--fromfile") && !strcmp(argv[3],"--tofile"))
    {
        tofile=true;
        fromfile=true;
        ifstream fin;
        ofstream fout;
        fin.open(argv[2]);
        fin>> sex >> year >> month >> day;
        if (data_verification(sex,year, month,day)==true)
        {
            MIEM st1;
            st1.gender(sex);
            st1.date(year,month,day);
            st1.complicated_numbers();
            MGTUU st2;
            st2.gender(sex);
            st2.date(year,month,day);
            st2.complicated_numbers();
            fout.open(argv[4]);
            st1.Print(fout);
            st2.Print(fout);
            fin.close();
            fout.close();
        }
    }
    else
    {
        cerr<<"The flag was entered incorrectly"<<endl;
        return EXIT_FAILURE;
    }
}
