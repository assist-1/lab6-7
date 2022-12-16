#include <iostream>
class University {
    protected:
    std::string ticket;
    public:
    virtual std::string generator(std::string,int,int,int) = 0;
};
class EMGETUU: public University
{
    int sum = 0;
    int div = 10;
public:
    generator(std::string sex, int year,int month, int day) override
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
        std:: mt19937 seq(date, time(0));
        std:: uniform_int_distribution<> gap(1000,9999);
        std::string rand_number = std::to_string(gap(seq));
        for (int i = 0; i < rand_number.size();i++) sum+=(rand[i] - '0') * (10+i);
        while (sum % 2 == 1)
        {
            sum = sum - rand_number[2]*(10+2);
            new_d = ((rand_number[2] - '0')%100 + '00');
            rand_number = {rand_number[0],rand_number[1],new_d,rand_number[3],rand_number[4]};
            sum = sum + new_d*(10+2);
        }
        ticket+=std::to_string(rand_number);
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
public:
    generator(std::string sex,int year, int month, int day) override
    {

    }

};
