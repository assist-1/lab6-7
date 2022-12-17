#include <iostream>
#include <time.h>
#include <string>
#include <random>
#include <fstream>
#include <cstring>
using std::cerr;
using std::cout;
using std::endl;
using std::cin;
class University {
    public:
    virtual std::string generator() = 0;
};
class MGTU: public University
{
    int sum = 0;
    int div = 10;
    std::string sex;
    int year;
    int month;
    int day;
    std::string ticket = "";
public:
    MGTU(std::string sex,int year, int month, int day)
    {
        this->sex = sex;
        this->year = year;
        this->month = month;
        this->day = day;
    }
    std::string generator() override
    {
        if (sex == "man")
        {
            ticket+=std::to_string(0);
            sum+=0;
        }
        else
        {
            ticket+=std::to_string(1);
            sum+=1;
        }
        int date = 10000*year+100*month+ day;
        ticket+=std::to_string(date);
        for (int i = 1; i < ticket.size();i++) sum+=(ticket[i] - '0') * (i+1);
        std:: mt19937 seq(date + time(0));
        std:: uniform_int_distribution<> gap(1000,9999);
        std::string rand_number = std::to_string(gap(seq));
        for (int i = 0; i < rand_number.size();i++) sum+=(rand_number[i] - '0')*(10+i);
        while (sum % 2 == 1)
        {
            sum = sum - rand_number[2]*(10+2);
            int new_d = ((rand_number[2] - '0')+1)%10 + '0';
            rand_number = {rand_number[0],rand_number[1],(char)new_d,rand_number[3]};
            sum = sum + new_d*(10+2);
        }
        ticket+=rand_number;
        int ost = sum / div;
        for (int i = 0; i < 10;i++)
        {
            if ((ost + (14*i)%10)%10 == 0)
            {
                ost = 0;
                ticket+=std::to_string(i);
                break;
            }
        }
        return ticket;
    }
};
class MIEM : public University
{
    int sum = 0;
    int div = 11;
    std::string sex;
    int year;
    int month;
    int day;
    std::string ticket = "";
public:
    MIEM(std::string sex,int year, int month, int day)
    {
        this->sex = sex;
        this->year = year;
        this->month = month;
        this->day = day;
    }
    std::string generator() override
    {

        if (sex == "man")
        {
            ticket+=std::to_string(8);
            sum+=8;
        }
        if (sex == "woman")
        {
            ticket+=std::to_string(4);
            sum+=4;
        }
        int date = 10000*year + 100*month + day;
        ticket+=std::to_string(date);
        for (int i = 1; i < ticket.size();i++) sum+=(ticket[i] - '0') * (i+1);
        std:: mt19937 seq(date + time(0));
        std:: uniform_int_distribution<> gap(10000,99999);
        std::string rand_number = std::to_string(gap(seq));
        for (int i = 0; i < rand_number.size();i++) sum+=(rand_number[i]-'0')*(10+i);
        while (sum % div == 4)
        {
            sum = sum - rand_number[2]*(10+2);
            int new_d = ((rand_number[2] - '0')+1)%10 + '0';
            rand_number = {rand_number[0],rand_number[1],(char)new_d,rand_number[3],rand_number[4]};
            sum = sum + new_d*(10+2);
        }
        ticket+=rand_number;
        int ost = sum / div;
        for (int i = 0; i < 10;i++)
        {
            if ((ost + (15*i)%10)%10 == 0)
            {
                ost = 0;
                ticket+=std::to_string(i);
                break;
            }
        }
        return ticket;
    }
};
void FromMenu(){
    std::cout << "To output from a file, enter: ./prog --fromfile <name.txt>" << std::endl;
}
void ToMenu(){
    std::cout << "To enter the file, enter: ./prog --tofile <name.txt>" << std::endl;
}
void FromAndToMenu(){
    std::cout << "For reading from one file and out to another file enter: ./nameprog --fromfile --tofile <name1.txt> <name2.txt>" << std::endl;
}
void Menu(){
    std::cout << "Enter as follows:" << std::endl;
    FromMenu();
    ToMenu();
    FromAndToMenu();
}
bool IsDigit(char token)
{
    if (token >= '0' && token <= '9') return true;
    else return false;
}
void CheckDate(int year,int month,int day)
{
    int arr[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    if (year%4 != 0) arr[1] = 28;
    if (!(day <= arr[month-1]) )
    {
        cerr << "Enter correct date" << endl;
        exit(1);
    }
}
void ToFile(char *namefile)
{
    std::ofstream file(namefile);
    std::string name_un;
    std::string sex;
    std::string year_s;
    std::string month_s;
    std::string day_s;
    cout << "Enter name university" << endl;
    cin >> name_un;
    if (!(name_un == "MIEM" || name_un == "MGTU"))
    {
        cerr << "Enter MGTU or MIEM university" << endl;
        exit(1);
    }
    cout << "Enter sex" << endl;
    cin >> sex;
    if (!(sex == "man" || name_un == "woman") )
    {
        cerr << "Enter <man> of <woman>" << endl;
        exit(1);
    }
    cout << "Enter year of birthday " << endl;
    cin >> year_s;
    int year = stoi(year_s);
    if (year < 1900 || year > 2004)
    {
        cerr << "You need enter year in range 1900 to 2004" << endl;
        exit(1);
    }
    cout << "Enter month of birthday in number " << endl;
    cin >> month_s;

    int month = stoi(month_s);

    if (month < 1 || month > 12)
    {
        cerr << "You need enter month in range 1 to 12" << endl;
        exit(1);
    }
    cout << "Enter day of birthday " << endl;
    cin >> day_s;
    int day = stoi(day_s);
    if (day < 1 && day > 31)
    {
        cerr << "You need enter month in range 1 to 12" << endl;
        exit(1);
    }
    CheckDate(year,month,day);
    if (name_un == "MIEM")
    {
        cout << "Ya gey" << endl;
        MIEM obj(sex,year,month,day);
        file << obj.generator() << endl;
    }
    else
    {
        MGTU ob(sex,year,month,day);
        file << ob.generator() << endl;
    }
}
void FromFile(char *namefile)
{
    std::ifstream file(namefile);
    std::string name_un;
    std::string sex;
    std::string year_s;
    std::string month_s;
    std::string day_s;
    const char* stream;
    file >> stream;

    if (!(name_un == "MIEM" || name_un == "MGTU"))
    {
        cerr << "Enter MGTU or MIEM university" << endl;
        exit(1);
    }


    if (!(sex == "man" || name_un == "woman") )
    {
        cerr << "Enter <man> of <woman>" << endl;
        exit(1);
    }


    int year = stoi(year_s);
    if (year < 1900 || year > 2004)
    {
        cerr << "You need enter year in range 1900 to 2004" << endl;
        exit(1);
    }


    int month = stoi(month_s);
    if (month < 1 || month > 12)
    {
        cerr << "You need enter month in range 1 to 12" << endl;
        exit(1);
    }

    int day = stoi(day_s);
    if (day < 1 && day > 31)
    {
        cerr << "You need enter month in range 1 to 12" << endl;
        exit(1);
    }
    CheckDate(year,month,day);
    if (name_un == "MIEM")
    {
        cout << "Ya gey" << endl;
        MIEM obj(sex,year,month,day);
        cout << obj.generator() << endl;
    }
    else
    {
        MGTU ob(sex,year,month,day);
        cout << ob.generator() << endl;
    }
}

