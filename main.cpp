#include <iostream>
#include <string>
#include <cstring>
#include <random>
#include <fstream>
#define flag1 "--tofile"
#define flag2 "--fromfile"
using std::to_string;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;

class Interface{
    public:
    virtual string generate(string sex, int year, int month, int day) = 0;
};

class Template: public Interface{
    protected:
        string generate(string s, int year, int month, int day) final{
        set_sex(s);
        Data(year,month,day);
        set_N();
        RandomNumber();
        set_C();
        return result;
        }

        string result, sex, year, month,day, C;

        int N, num, k;

        virtual void set_sex(string s) = 0;

        void Data(int y, int m, int d){
            y = y * 10000 + m * 100 + d;
            year = to_string(y);
            result+=year;
        }
        virtual void set_N() = 0;
        void RandomNumber(){
            std::mt19937 gen(rand());
            std::uniform_int_distribution<> dis(1, 100000);
            string x = to_string(dis(gen));
            if (x.size() < N){
                string ss(N - x.size(), '0');
                x = ss + x;
            }
            else if(x.size() > N){
                x = string(x,1,N);
            }
            result+=x;
        };
        void set_C(){
            int sum = 0, flag = 1;
            for(int i =0; i<result.size();i++)
            {
                sum+=(result[i]- '0') * (i + 1);
            }
            for (int i = 0; i<10; i++)
            {
			    if ((sum + i*k) % num ==0){
                    result+=to_string(i);
                    flag = 1;
                    break;
                }
                else flag = 0;
            }
            if (flag == 0){
                result = string(result,0,9);
                RandomNumber(); 
                set_C();}
        }
};

class MIEM: public Template{
    public:
        void set_sex(string s) override{
            if(s == "woman"){
                result+='4';
            }
            else result+='8';
        }
        void set_N() override{
            N=5;
            num = 11;
            k = 15;
        }
};

class MGTUU: public Template{
    public:
        void set_sex(string s) override{
            if(s == "woman"){
                result+='1';
            }
            else result+='2';
        }
        void set_N() override{
            N=4;
            num = 10;
            k = 14;
        }
        

};
class template_pattern_student_number_generator {
    public:
    Interface* generator(string str){
        if (str == "MIEM"){
            Interface* student = new MIEM;
            return student;
        }
        else if (str == "MGTUU"){
            Interface* student = new MGTUU;
            return student;
        }
        return 0;
    }
};


int IsRange(int value, int min, int max)
{
    if (value < min) return 0;
    if (value > max) return 0;
    return 1;
}
 
int CheckDate(string sex, string university, int year, int month, int day)
{
    if (sex != "woman" && sex!="man"){
        return 0;
    }
    if (university != "MIEM" && university !="MGTUU"){
        return 0;
    }
    if (year < 1000 || year > 2022)
        return 0;
 
    switch(month)
    {
        case 1: 
        case 3: 
        case 5: 
        case 7: 
        case 8: 
        case 10:
        case 12:
            return IsRange(day, 1, 31);
        case 2:
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) return IsRange(day, 1, 29);
            else return IsRange(day, 1, 28);
        case 4:
        case 6:
        case 9:
        case 11:
            return IsRange(day, 1, 30);
        default:
            return 0;
    }
}
string f = "0";
void Tofile(){
    int year, month, day;
    string finish, sex, university, filename;
    cout << "Enter the name of file. Write 'No', if you haven't it." << endl;
    cin >> filename;
    if (filename == "No"){filename = "out.txt";}
    else if (filename.size() > 4 && string(filename, filename.size()-4,4) == ".txt"){}
    else {filename = "out.txt";}
    f = filename;
    ofstream fout(filename);
    cout <<endl<<"tofile" << endl;
    int i = 0;
    while(true){
    cout << "if you ready to stop write 'break', else write anyything, but not the enter." << endl;
    cin >> finish;
    if (finish == "break") break;
    i+=1;
    cout << "Enter the sex of student: ";
    cin >>sex;
    cout << "Enter the university of student: ";
    cin >> university;
    cout <<"Enter the year of student: ";
    cin >> year;
    cout <<"Enter the month of stufent: ";
    cin >> month;
    cout << "Enter the day of student: ";
    cin >> day;
    if (CheckDate(sex, university, year, month, day)){
        template_pattern_student_number_generator templateGenerator;
        fout << i << ": "<< templateGenerator.generator(university)->generate(sex, year, month, day) << endl;}
    else{cout << "Write please normal data " << endl;};
    }
    fout.close();
}

void fromFile(string filename,string file){
    std::ifstream fin(file);
    ofstream fout(filename, std::ios_base::app);
    string str;
    string y , m ,d;
    string sex , university;
    int year = 0,month = 0 ,day = 0 , j =1;
    cout << endl << "fromfile" << endl;
    if(!fin.is_open()){
        std::cerr << "I can not open your file for --fromfile";}
    int i = 0;
    while(!fin.eof()){
        if (i % 5 == 0){fin >>sex;}
        if (i % 5 == 1){fin >> university;}
        if (i % 5 == 2){
            fin >> y;
            if (!(atoi(y.c_str())))
            {
                cout << "Your file is incorrect!";
                break;
            }
            else year = atoi(y.c_str());}
        if (i % 5 == 3){
            fin >> m;
            if (!(atoi(m.c_str())))
            {
                cout << "Your file is incorrect!";
                break;
                }
            else month = atoi(m.c_str());}
        if (i % 5 == 4){
            fin >> d;
            if (!(atoi(d.c_str())))
            {
                cout << "Your file is incorrect!";
                break;
            }
            else day = atoi(d.c_str());}
        if (year !=0 && month!=0 && day!= 0){
            if (CheckDate(sex, university, year, month, day)){
                template_pattern_student_number_generator templateGenerator;
                fout << j << ": "<< templateGenerator.generator(university)->generate(sex, year, month, day) << endl;}
            else{cout << "Your file is uncorrect!";break;};}
        i+=1;
    }
    fout.close();
    fin.close();
}
int main(int argc, char ** argv){
    string filename;
    if (argc == 1){
        cout << "Nothing have entered" << endl;
        return 0;
    }
    else if (argc ==4 && !strcmp(argv[1], flag1) && !strcmp(argv[2], flag2)){
        Tofile();
        fromFile(f, argv[3]);
    }
    else if (argc == 2 && !strcmp(argv[1], flag1)){
        Tofile();
    }
    else if (argc == 3 && !strcmp(argv[1], flag2)){
        string s = argv[2];
        filename = "out.txt";
        ofstream ofs;
        ofs.open("out.txt", std::ofstream::out | std::ofstream::trunc);
        ofs.close();
        fromFile(filename, s);
        }
    else {cout << "Enter error!";}
return 0;
}