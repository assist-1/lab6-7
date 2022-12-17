#include <iostream> 
#include<string> 
#include <random> 
#include<fstream>
std::string name; 
int sex; 
std::string year; 
std::string month; 
std::string day; 
 
 
 
 
 
class uni { 
public: 
    int sex; 
    std::string year; 
    std::string month; 
    std::string day; 
 
    virtual std::string propusk(int, std::string, std::string, std::string) = 0; 
}; 
 
 
class Miem :public uni { 
    std::string propusk(int sex, std::string year, std::string month, std::string day) override{ 
        int sm = 0; 
        std::string s = ""; 
        if (sex == 0) { 
            s += std::to_string(8); 
 
        } 
        else if(sex == 1) { 
            s += std::to_string(4); 
            sm += 4; 
        } 
        else{
            std::cout<<"wrong args";
            return 0;
        }
        if (stoi(year) >= 1955 && stoi(year) <= 2022 && stoi(month) >= 1 && stoi(month) <= 12 && stoi(day) >= 1 && stoi(day) <= 30) { 
            s = s + (year)+(month)+(day); 
        } 
        else { 
            std::cout<<"wrong args";
            return 0; 
        } 
        int id = rand() % (99999 - 10000) + 10000; 
     
        std::string s1 = s+std::to_string(id);
        int sm1 = 0;
        for (int i = 0; i < s1.size(); ++i) 
            sm1 += (s1[i] - '0') * (i + 1);
        if (sm1 % 11 == 4){
            id +=1;
        
        }
        s = s + std::to_string(id); 
        for (int i = 0; i < s.size(); ++i) 
            sm += (s[i] - '0') * (i + 1);
        for (int i = 0; i < 10; ++i) { 
            if ((sm  % 11 + (i*15)%11)%11 == 0) { 
                s += std::to_string(i); 
                return s; 
                break; 
            } 
        } 
        return 0; 
 
    } 
}; 
 
 
 
class MGTUU : public uni { 
    std::string propusk(int sex, std::string year, std::string month, std::string day) override { 
        int sm = 0; 
        std::string s = "";
        if (sex == 0) { 
            s += std::to_string(2); 
 
        } 
        else if(sex == 1) { 
            s += std::to_string(1); 
        } 
        else{
            std::cout<<"wrong args";
            return 0;
        }
        if (stoi(year) >= 1955 && stoi(year) <= 2022 && stoi(month) >= 1 && stoi(month) <= 12 && stoi(day) >= 1 && stoi(day) <= 30) { 
            s = s + (year)+(month)+(day); 
        } 
        else { 
            return 0; 
        } 
        int id = rand() % (9999 - 1000) + 1000; 
        std::string s1 = s+std::to_string(id);
        int sm1 = 0;
        for (int i = 0; i < s1.size(); ++i) 
            sm1 += (s1[i] - '0') * (i + 1);
        if (((sm1 % 10)%2)!=0){
            id +=1;
        
        }
        s = s + std::to_string(id); 
        for (int i = 0; i < s.size(); ++i) 
            sm += (s[i] - '0') * (i + 1);
        for (int i = 0; i < 10; ++i) { 
            if ((sm  % 10 + (i*14)%10)%10 == 0) { 
                s += std::to_string(i); 
                return s; 
                break; 
            } 
        } 
        return 0; 
 
    } 
}; 

class aboba{
public:
    uni* method(std::string name){
        if (name == "MIEM"){
            Miem *a = new Miem;
            return a;
        }
        else if( name == "MGTUU"){
            MGTUU *a = new MGTUU;
            return a;
        }
        exit(1);

    }

};




 
 
int read_cin( int flag) { 
    std::cout << "ENTER UNIVETRISTY: "; 
    std::string name; 

    std::cin >> name; 
    std::cout << "ENTER SEX 0 FOR MEN AND 1 FOR WOMEN: "; 
    int sex; 
    std::cin >> sex; 
    std::cout << "ENTER YEAR: "; 
    std::string year; 
    std::cin >> year; 
    std::cout << "ENTER MONTH: "; 
    std::string month; 
    std::cin >> month; 
    std::cout << "ENTER DAY: "; 
    std::string day; 
    std::cin >> day; 
    if (flag == 0){ 
        if (name == "MIEM") { 
            aboba uri;
            std::cout << uri.method("MIEM")->propusk(sex, year, month, day);
        }
        else if (name == "MGTUU") { 
            aboba uri;
            std::cout << uri.method("MGTUU")->propusk(sex, year, month, day);
        }
        else{
            std::cout<<"wrong args";
        }

    } 
    else if (flag == 1) { 
        std::ofstream out; 
        out.open("tofile.txt"); 
        if (name == "MIEM") { 
            aboba uri;
            out << uri.method("MIEM")->propusk(sex, year, month, day);
            out.close();
        } 
        else if(name == "MGTUU") { 
            aboba uri;
            std::cout << uri.method("MGTUU")->propusk(sex, year, month, day);
            out.close(); 
        } 
        else{
            std::cout<<"wrong args";
        }
    }
    return 0; 
} 
 



 
 
int read_file(int flag) { 
    std::ifstream file("fromfile.txt"); 
    if (!file.is_open()) { 
        std::cout << "MISTAKE"; 
    } 
    std::string name; 
    file >> name; 
    int sex; 
    file >> sex; 
    std::string year; 
    file >> year; 
    std::string month; 
    file >> month; 
    std::string day; 
    file >> day; 
    if (flag == 0) { 
        if (name == "MIEM") { 
            aboba uri;
            std::cout << uri.method("MIEM")->propusk(sex, year, month, day);
 
 
        } 
        else if (name == "MGTUU") { 
            aboba uri;
            std::cout << uri.method("MGTUU")->propusk(sex, year, month, day);
        } 
        else{
            std::cout<<"wrong args";
        }
    }
    else if(flag == 1){
        std::ofstream out; 
        out.open("tofile.txt"); 
        if (name == "MIEM") { 
            aboba uri;
            out << uri.method("MIEM")->propusk(sex, year, month, day);
            out.close();
        } 
        else if(name == "MGTUU") { 
            aboba uri;
            std::cout << uri.method("MGTUU")->propusk(sex, year, month, day);
            out.close(); 
        } 
        else{
            std::cout<<"wrong args";
        }

    } 
    return 0; 
 
 
} 
 