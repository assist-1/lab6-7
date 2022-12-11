#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
using std::string;
using std::to_string;
int to_integer(char a);

class stud_tick
{
public:
    virtual string generate(string sex,int year, int month, int day) = 0;
    
};
class pattern_generator : public stud_tick
{
public:
    string printer;
    string sex, y, m, d, n, c;
    string generate(string sex,int year, int month,int day) final
    {
        gender(sex);
        date(year,month,day);
        complicated_numbers();
        return otv();
    }
    virtual void gender(string sex){};
    virtual void complicated_numbers(){};
    virtual void date (int year,int month,int day)
    {
        if (year>1950 && year<2023)
        {
            y=to_string(year);
            printer+=y;
        }
        if (month>0 && month<13)
        {
            if (month>9 && month<13)
                m=to_string(month);
            else if (month>0 && month<9)
                m="0" + to_string(month);
            printer+=m;
        }
        if (day>0 && day<32)
        {
            if (day>10 && day<32)
                d=to_string(day);
            else if (day<10 && day>0)
                d="0"+to_string(day);
            printer+=d;
        }
    }
    virtual string otv() final
    {
        return printer;
    }
};
class MIEM : public pattern_generator
{
public:
    MIEM() {};
    void gender(string sex) override
    {
        if (sex == "Female" || sex == "female" )
        {
            string sex= "4";
            printer+=sex;
        }
        else if (sex == "Male" || sex == "male")
        {
            string sex = "8";
            printer+=sex;
        }
    }

    void complicated_numbers() override
    {
        int tempor = 0;
        int cn=0;
        int poz=0;
        string num;
        bool flag=false;
        while (flag!=true)
        {
            srand(time(0));
            num=to_string(rand()%89999+10000);
            for(int i=0;i<printer.size();i++)
            {
                tempor+=(to_integer(printer[i]))*(i+1);
                poz+=1;
            }
            poz+=1;
            for(int i=0;i<num.size();i++)
            {
                tempor+=to_integer(num[i])*poz;
                poz+=1;
            }
            for (cn=0;cn<=9;cn++)
            {
                if ((tempor+cn*15)%11==0)
                {
                    flag=true;
                    break;
                }
            }
        }
        if (flag==true)
        {
            printer+=num;
            c=to_string(cn);
            printer+=c;
        }
    }
    ~MIEM(){};
};

class MGTUU : public pattern_generator
{
public:
    MGTUU() {};
    void gender(string sex) override
    {
        if (sex == "Female" || sex == "female" )
        {
            string sex= "1";
            printer+=sex;
        }
        else if (sex == "Male" || sex == "male")
        {
            string sex = "2";
            printer+=sex;
        }
    }
    
    void complicated_numbers() override
    {
        int tempor = 0;
        int cn=0;
        int poz=0;
        string num;
        bool flag=false;
        while (flag!=true)
        {
            srand(time(0));
            num=to_string(rand()%8999+1000);
            for(int i=0;i<printer.size();i++)
            {
                tempor+=(to_integer(printer[i]))*(i+1);
                poz+=1;
            }
            poz+=1;
            for(int i=0;i<num.size();i++)
            {
                tempor+=to_integer(num[i])*poz;
                poz+=1;
            }
            for (cn=0;cn<=9;cn++)
            {
                if ((tempor+cn*14)%10==0)
                {
                    flag=true;
                    break;
                }
            }
        }
        if (flag==true)
        {
            printer+=num;
            c=to_string(cn);
            printer+=c;
        }
    }
    ~MGTUU(){};
};
class temp
{
public:
    stud_tick* generator(string university)
    {
        if (university=="MIEM")
        {
            MIEM* S_B1 = new MIEM;
            return S_B1;
        }
        else if (university=="MGTUU")
        {
            MGTUU *S_B2 = new MGTUU;
            return S_B2;
        }
        return 0;
    }
};
