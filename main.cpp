#include<iostream>
#include<fstream>
#include<string>
#include <ctime> 
#include<random>
std::string uni,sex, day, month, year;
class Student_id{
    protected:
    std::string sex;
    int date;
    std::string number;
    std::string id;
    public:
    virtual std::string set_sex(std::string)=0;
    virtual std::string set_number(int)=0;
    virtual std::string set_id()=0;
};
class MIEM: public Student_id{
    public:
    std::string set_sex(std::string s) override{
        s=="man"?sex="8":sex="4";
        return sex;
    }
    std::string set_number(int d)override{
        std::mt19937 gen(d + time(0)); 
        std::uniform_int_distribution<> values(10000, 99999);
        number= std::to_string(values(gen));
        date=d;
        return number;

    }
    std::string set_id()override{
        id=sex+std::to_string(date)+number;
        int sum=0;
        for(int i=0;i<id.length();i++){
            sum+=(id[i]-'0')*(i+1);
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
        
        id+=std::to_string(c);
        return id;
    }

};
class MGTUU: public Student_id{
    public:
    std::string set_sex(std::string s) override{
        s=="man"?sex="1":sex="2";
        return sex;
    }
    std::string set_number(int d)override{
        std::mt19937 gen(d + time(0)); 
        std::uniform_int_distribution<> values(1000, 9999);
        number= std::to_string(values(gen));
        date=d;
        return number;

    }
    std::string set_id()override{
        id=sex+std::to_string(date)+number;
        int sum=0;
        for(int i=0;i<id.length();i++){
            sum+=(id[i]-'0')*(i+1);
        }
        int c;
        for(int i=0; i<10;i++){
            sum+=i*14;
            if(sum%10==0){
                c=i;
                break;
            }
            else{
                sum-=i*15;
            }
        }
        
        id+=std::to_string(c);
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
        std::cout<<"Enter the name of the university in capital letters (MGTUU or MIEM)\n";
        std::cin>>uni;
        if(uni!="MGTUU"&& uni!="MIEM"){
            std::cout<<"Wrong name\n";
            return EXIT_FAILURE;
        }
        std::cout<<"Enter your sex (man or woman)\n";
            std::cin>>sex;
            if(sex!="man"&& sex!="woman"){
            std::cout<<"Wrong sex\n";
            return EXIT_FAILURE;
        }
        std::cout<<"Enter your day of birth\n";
        std::cin>>day;
        int d;
        d=std::stoi(day);
        if(d<0 || d>31){
            std::cout<<"Wrong day\n";
            return EXIT_FAILURE;
        } 
        std::cout<<"Enter your month of birth\n";
        std::cin>>month;
        int m;
        m=std::stoi(month);
         if(m<0 || m>12){
            std::cout<<"Wrong month\n";
            return EXIT_FAILURE;
        } 
        std::cout<<"Enter your year of birth\n";
        std::cin>>year;
        int y;
        y=std::stoi(year);
         if(y<1900 || y>2022){
            std::cout<<"Wrong year\n";
            return EXIT_FAILURE;
        } 
        if(testfile){
            std::ofstream out;
            out.open("test.txt");
            if(out.is_open()){
                std::string str=year+month+day+'\0';
                int date = std::stoi(str);
                if (uni=="MIEM"){
                MIEM p;
                p.set_sex(sex);
                p.set_number(date);
                out<<p.set_id();
                }
                else{
                  MGTUU p;
                p.set_sex(sex);
                p.set_number(date);
                out<<p.set_id();  
                }

            }
                        
            out.close();
            std::cout<<"Answer in file: test.txt"<<std::endl;
        }
        else{
            std::fstream output(name1);
            fp=fopen(name1,"w");
            if(output.is_open()){
                std::string str=year+month+day+'\0';
                int date = std::stoi(str);
                 if (uni=="MIEM"){
                MIEM p;
                p.set_sex(sex);
                p.set_number(date);
                output<<p.set_id();
                }
                else{
                  MGTUU p;
                p.set_sex(sex);
                p.set_number(date);
                output<<p.set_id();  
                }                     
            }
            output.close();
            std::cout<<"Answer in file: "<<name1<<std::endl;
        }

    }
    if(fromfile&&!tofile){
        std::fstream input(name2);
        fp=fopen(name2,"r");
        input>>uni>>year>>month>>day;
        std::string str=year+month+day+'\0';
        int date = std::stoi(str);

        if (uni=="MIEM"){
            MIEM p;
            p.set_sex(sex);
            p.set_number(date);
            std::cout<<p.set_id();
        }
        else{
            MGTUU p;
            p.set_sex(sex);
            p.set_number(date);
            std::cout<<p.set_id();  
        }                  
            
    }
    if(fromfile && tofile){
        if(testfile){
            std::ofstream out;
            out.open("test.txt");
            std::fstream input(name2);
            fp=fopen(name2,"r");
            input>>uni>>year>>month>>day;
            if(out.is_open()){
                std::string str=year+month+day+'\0';
                int date = std::stoi(str);
                if (uni=="MIEM"){
                MIEM p;
                p.set_sex(sex);
                p.set_number(date);
                out<<p.set_id();
                }
                else{
                  MGTUU p;
                p.set_sex(sex);
                p.set_number(date);
                out<<p.set_id();  
                }

            }
                        
            out.close();
            std::cout<<"Answer in file: test.txt"<<std::endl;
        }
        else{
            std::fstream input(name2);
            fp=fopen(name2,"r");
            input>>uni>>year>>month>>day;
             std::fstream output(name1);
            fp=fopen(name1,"w");
            if(output.is_open()){
                std::string str=year+month+day+'\0';
                int date = std::stoi(str);
                 if (uni=="MIEM"){
                MIEM p;
                p.set_sex(sex);
                p.set_number(date);
                output<<p.set_id();
                }
                else{
                  MGTUU p;
                p.set_sex(sex);
                p.set_number(date);
                output<<p.set_id();  
                }                     
            }
            output.close();
            std::cout<<"Answer in file: "<<name1<<std::endl;

        }
    }
    

}

