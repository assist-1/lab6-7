#include <iostream>
#include <ctime>
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

class Generator{
public:
  string year;
  string month;
  string day;
  string sex;
  string id = "";
  string sec = "";
  virtual string generate(string, int, int, int) = 0;
};

class MIEM : public Generator{
public:
  MIEM(){};

  virtual string generate(string sex, int year, int month, int day) override{
    if (sex == "male") this->sex = "8";
    else if(sex == "female") this->sex = "4";
    else{
      cout << "Wrong sex\n";
      return "Failure";
    }

    if(year >= 1000) this->year = to_string(year);
    else{
      cout << "Wrong year\n";
      return "Failure";
    }

    if ((month > 0)&&(month < 13)){
      if(month < 10) this->month = "0" + to_string(month);
      else this->month = to_string(month);
    }else{
      cout << "Wrong month\n";
      return "Failure";
    }

    if((day > 0)&&(day <= 31)){
      if(day < 10) this->day = "0" + to_string(day);
      else this->day = to_string(day);
    }else{
      cout << "Wrong day\n";
      return "Failure";
    }

    srand(year + month + day);
    int mew = 0;

    id = this->sex + this->year + this->month + this->day;

    int sum = 0;
    for(int i = 1; i <= 9; ++i){
      sum += (int)id[i-1] * i;
    }
    int tmp = 0;
    bool ch = false;

    while (!(ch)){
      int tmps = 0;
      while(tmps <= 10000)
        tmps = rand();
      sec = to_string(tmps % 100000);
      tmp = 0;

      int a[10] = {0,15,30,45,60,75,90,105,120,135};

      for(int i = 10; i < 15; ++i){
        tmp += (int)sec[i-10] * i;
      }
      for(int i = 0; i < 10; ++i){
        if((sum + tmp + a[i])%11==0){
          ch = true;
          mew = i;
        }
      }
    }
    id+= sec;
    return id + to_string(mew);
  }


};

class MGTU : public Generator{
public:
  MGTU(){};

  virtual string generate(string sex, int year, int month, int day) override{
    if (sex == "male") this->sex = "2";
    else if(sex == "female") this->sex = "1";
    else{
      cout << "Wrong sex\n";
      return "Failure";
    }

    if(year >= 1000) this->year = to_string(year);
    else{
      cout << "Wrong year\n";
      return "Failure";
    }

    if ((month > 0)&&(month < 13)){
      if(month < 10) this->month = "0" + to_string(month);
      else this->month = to_string(month);
    }else{
      cout << "Wrong month\n";
      return "Failure";
    }

    if((day > 0)&&(day <= 31)){
      if(day < 10) this->day = "0" + to_string(day);
      else this->day = to_string(day);
    }else{
      cout << "Wrong day\n";
      return "Failure";
    }

    srand(year + month + day);
    int mew = 0;

    id = this->sex + this->year + this->month + this->day;

    int sum = 0;
    for(int i = 1; i <= 9; ++i){
      sum += (int)id[i-1] * i;
    }
    int tmp = 0;
    bool ch = false;

    while (!(ch)){
      int tmps = 0;
      while(tmps <= 1000)
        tmps = rand();
      sec = to_string(tmps % 10000);
      tmp = 0;

      int a[10] = {0,14,28,42,56,70,84,98,112,126};

      for(int i = 10; i < 14; ++i){
        tmp += (int)sec[i-10] * i;
      }
      for(int i = 0; i < 10; ++i){
        if((sum + tmp + a[i])%10==0){
          ch = true;
          mew = i;
        }
      }
    }
    id+= sec;
    return id + to_string(mew);
  }

};

int main(int argc, char *argv[]){
  ifstream fin;
  ofstream fout;
  MIEM miem;
  MGTU mgt;
  string sex;
  int year, month, day;
  int type;
  if (argc == 1){
    cout << "type means university: 1 for MIEM, 2 for MGTU\n";
    cin >> sex >> year >> month >> day >> type;
    if (type == 1){
      cout << "MIEM : " << miem.generate(sex,year,month,day) << '\n';
    }else if(type == 2){
      cout << "MGTU : " <<mgt.generate(sex,year,month,day) << '\n';
    }else{
      cout << "Wrong input\n";
      return 0;
    }
  }else
  if (argc == 3){
    if((strcmp(argv[1], "--fromfile") == 0)&&!(strcmp(argv[2], "--tofile") == 0)){
      fin.open(argv[2]);
      fin >> sex >> year >> month >> day >> type;
      if (type == 1){
        cout << "MIEM : " << miem.generate(sex,year,month,day) << '\n';
      }else if(type == 2){
        cout << "MGTU : " <<mgt.generate(sex,year,month,day) << '\n';
      }else{
        cout << "Wrong input\n";
        return 0;
      }
    }else if(!(strcmp(argv[2], "--fromfile") == 0)&&(strcmp(argv[1], "--tofile") == 0)){
      fout.open(argv[2]);
      cout << "type means university: 1 for MIEM, 2 for MGTU\n";
      cin >> sex >> year >> month >> day >> type;
      if (type == 1){
        fout << "MIEM : " << miem.generate(sex,year,month,day) << '\n';
      }else if(type == 2){
        fout << "MGTU : " <<mgt.generate(sex,year,month,day) << '\n';
      }else{
        fout << "Wrong input\n";
        return 0;
      }
    }else{
      cout << "Wrong input\n";
      return 0;
    }
  }else if(argc == 5){
    if((strcmp(argv[1], "--fromfile") == 0)&&(strcmp(argv[1], "--tofile") == 0)){
        fin.open(argv[2]);
        fout.open(argv[4]);
    }else if((strcmp(argv[1], "--tofile") == 0)&&(strcmp(argv[1], "--fromfile") == 0)){
      fin.open(argv[4]);
      fout.open(argv[2]);
    }else{
      cout << "Wrong input\n";
      return 0;
    }
    fin >> sex >> year >> month >> day >> type;
    if (type == 1){
      fout << "MIEM : " << miem.generate(sex,year,month,day) << '\n';
    }else if(type == 2){
      fout << "MGTU : " <<mgt.generate(sex,year,month,day) << '\n';
    }else{
      fout << "Wrong input\n";
      return 0;
    }
  }
}
