#include<iostream>
#include<fstream>
#include<string>
#include"functions.h"
#include <ctime> 
#include<random>
class Student_id{
    protected:
    std::string sex;
    std::string date;
    std::string number;
    int intid;
    int intdate;
    std::string id;
    public:
    virtual std::string set_sex(std::string)=0;
    virtual int set_date(std::string)=0;
    virtual std::string set_number()=0;
    virtual std::string set_id(std::string)=0;
};
class MIEM: public Student_id{
    public:
    std::string set_sex(std::string s) override{
        s=="man"?sex="8":sex="4";
        return sex;
    }
    int set_date(std::string date)override{
        intdate=std::stoi( date );
        return intdate;
    }
    std::string set_number()override{
        std::mt19937 gen(intdate + time(0)); 
        std::uniform_int_distribution<> values(10000, 99999);
        number= std::to_string(values(gen));
        int intnumber=values(gen);
        return number;

    }
    std::string set_id(std::string date)override{
        id=sex+date+number;
        int sum=0;
        intid=std::stoi(id);
        int i=14;
        while(intid!=0){
            sum+=(intid%10)*i;
            intid/=10;
            i--;
        }
        int c;
        for(int i=0; i<10;i++){
            sum+=i*15;
            if(sum%11==0){
                c=i;
                break;
            }
            else{
                sum-=i*15;
            }
        }
        
        intid=intid*10+c;
        return id;
    }

};
int main(int argc, char **argv){
    FILE *fp;
    bool tofile=false;
    bool fromfile=false;
    char *name1;
    char *name2;
    bool testfile=false;
    bool tofilename=false;
    if(argc==1){
        std::cerr<<"Nothing was read\n";
            return EXIT_FAILURE;
    }
    if(argc>5){
        std::cerr<<"Too many flags\n";
            return EXIT_FAILURE;
    }
    else{
        for (int i=1;i<argc;++i){
            if(std::strcmp(argv[i],"--tofile")==0){
                tofile=true;
                if((!argv[i+1]) || (std::strcmp(argv[i],"--fromfile")==0)){
                    std::ofstream oFile("test.txt");
                    testfile=true;
                }
                else{
                    name1=argv[i+1];

                }
            }
            if(std::strcmp(argv[i],"--fromfile")==0){
                fromfile=true;
                if((!argv[i+1]) || (std::strcmp(argv[i],"--tofile"))==0){
                    std::cerr<<"File name not specified\n";
                    return EXIT_FAILURE;
                }
                else{
                    name2=argv[i+1];
                }
                
            }

        }
    if(!tofile and !fromfile){
        std::cerr<<"Wrong flags\n";
    }
    }


    if(tofile && !fromfile){
        std::string uni,sex, day, month, year;
        std::cout<<"Enter the name of the university in capital letters (MGTUU or MIEM)\n";
        std::cin>>uni;
        // if(uni!="MGTUU"&& uni!="MIEM"){
        //     std::cout<<"Wrong name\n";
        //     return EXIT_FAILURE;
        // }
        std::cout<<"Enter your sex (man or woman)\n";
            std::cin>>sex;
            // if(sex!="man"&& uni!="woman"){
            // std::cout<<"Wrong sex\n";
            // return EXIT_FAILURE;
        // }
        std::cout<<"Enter your day of birth\n";
        std::cin>>day;
        // int d;
        // d=string_to_int(day);
        // if(d<0 || d>31){
        //     std::cout<<"Wrong day\n";
        //     return EXIT_FAILURE;
        // } 
        std::cout<<"Enter your month of birth\n";
        std::cin>>month;
        // int m;
        // m=string_to_int(month);
        //  if(m<0 || m>12){
        //     std::cout<<"Wrong month\n";
        //     return EXIT_FAILURE;
        // } 
        std::cout<<"Enter your year of birth\n";
        std::cin>>year;
        // int y;
        // y=string_to_int(month);
        //  if(y<1900 || y>2022){
        //     std::cout<<"Wrong year\n";
        //     return EXIT_FAILURE;
        // } 
        std::string date=year+month+day;
        MIEM p;
            p.set_sex(sex);
            p.set_date(date);
            p.set_number();
            std::cout<<p.set_id(date);
    }

}

