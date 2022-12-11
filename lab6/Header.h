#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
using std::string;
using std::to_string;
using std::ostream;
using std::endl;
int to_integer(char a);

class stud_tick
{
protected:
    string printer;
    string sex, y, m, d,n,c;
public:
    virtual void gender(string sex) = 0;
    virtual void complicated_numbers() = 0;
    virtual void Print(ostream&) = 0;
    virtual void date (int year,int month,int day)
    {
        if (year>1900 && year<2023)
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
};

class MIEM : virtual public stud_tick
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
    void Print(ostream& out) override
    {
        out<<"MIEM: "<<printer<<endl;;
    }
    ~MIEM(){};
};

class MGTUU : virtual public stud_tick
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
    void Print(ostream& out) override
    {
        out<<"MGTUU: "<<printer<<endl;
    }
    ~MGTUU(){};
};






