#include <iostream>
#include <cstring>
#include "classes.h"
#include <fstream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ofstream;
using std::ifstream;
bool data_verification(string u,string s,int y,int m,int d);
bool tofile=false;
bool fromfile=false;
int main(int argc, char **argv) {
    string sex;
    string university;
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
        cout<<"Write university, your gender, year, month and day of birth."<<endl<<"Example: MIEM female 2002 10 29"<<endl;
        cin>> university>> sex >> year >> month >> day;
        if (data_verification(university,sex,year, month,day)==true)
        {
            temp gen;
            string studb = gen.generator(university)->generate(sex,year,month,day);
            fout<<university<<"\n"<<studb<<endl;
            fout.close();
        }
    }
    else if (argc==3 && !strcmp(argv[1],"--fromfile"))
    {
        fromfile=true;
        ifstream fin;
        fin.open(argv[2]);
        fin>> university >>sex >> year >> month >> day;
        if (data_verification(university,sex,year, month,day)==true)
        {
            temp gen;
            string studb = gen.generator(university)->generate(sex,year,month,day);
            cout<<university<<"\n"<<studb<<endl;
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
        fin>> university >> sex >> year >> month >> day;
        if (data_verification(university,sex,year, month,day)==true)
        {
            temp gen;
            string studb = gen.generator(university)->generate(sex,year,month,day);
            fout.open(argv[4]);
            fout<<university<<"\t"<<studb<<endl;
            fin.close();
            fout.close();
        }
    }
    else
    {
        cerr<<"The flag was entered incorrectly."<<endl;
        return EXIT_FAILURE;
    }
}
        
