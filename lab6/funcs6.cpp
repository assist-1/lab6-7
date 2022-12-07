#include <iostream>
#include <string>
#include <fstream>

#define DATE_ERR {cerr << "Wrong date!\n"; exit(EXIT_FAILURE);}

using std::string;
using std::to_string;
using std::getline;
using std::cin;
using std::cout;
using std::cerr;

bool comp (const char *a, const char *b)
{
  for (int i=0; a[i]!='\0'; ++i)
  {
    if (a[i]!=b[i])
    {
      return false;
    }
  }
  return true;
}

bool Digit (const char& a)
{
  if (a>='0'&&a<='9') return true;
  return false;
}

void correct_date(string& sy, string& sm, string& sd)
{
  while (sy[0]==' ') sy.std::string::erase(0,1);
  while (sd[sd.length()-1]==' ') sd.std::string::erase(sd.length()-1,1);

  if (sy.length()>4||sm.length()>2||sd.length()>2) DATE_ERR

  for (int i=0;i<2;++i)
  {
    if (!(Digit(sy[2*i])&&Digit(sy[2*i+1])&&Digit(sm[i])&&Digit(sd[i]))) DATE_ERR
  }

  int y = stoi(sy), m = stoi(sm), d = stoi(sd);
  if (y>9999||y<0||m>12||m<1||d>31||d<1) DATE_ERR
  else if ((m==4||m==6||m==9||m==11)&&d>30) DATE_ERR
  else if (m==2&&(d>29||((d>28)&&!(((y%4)==0&&(y%100)!=0)||(y%400)==0)))) DATE_ERR
  
  while (sm.length()<2) sm = "0"+sm;
  while (sd.length()<2) sd = "0"+sd;
  while (sy.length()<4) sy = "0"+sy;
}

int toi(char a) {return (int)(a-'0');}

class Studs
{
  protected:
    string str;  
    virtual const string sex(string&) =0;
    virtual const string rands(const string&, const string&, const string&) =0;
    virtual const string last(const string&) =0;  
  public:
    Studs() : str(""){};
    ~Studs() {str="";};
    virtual const string& generate(string&, const string&, const string&, const string&) =0;
    virtual void print(std::ostream&)=0;
};

class MIEM: virtual Studs
{
  static const int divider=8;
  const string sex(string& a) override
  {
    while (a[0]==' ') a.std::string::erase(0,1);
    if (a=="man") return (string)"8";
    if (a=="woman") return (string)"4";
    cerr << "Wrong sex!\n";
    exit(EXIT_FAILURE);
  } 
  const string rands (const string& sy, const string& sm, const string& sd) override
  {
    int y=stoi(sy), m=stoi(sm), d=stoi(sd);
    string str = to_string(((((((y<<m)^y)&INT32_MAX)<<d)^y)&INT32_MAX)%100000);
    while (str.length()<5) str = "0" + str;
    return str;
  }
  const string last (const string& str) override
  {
    int s=0, num;
    for (int i=0; i<str.length(); ++i)
    {
      s+=(toi(str[i])*(i+1));
    }
    s%=divider;
    for (num=0; num<10;++num)
    {
      if ((s+num*15)%divider==0) break;
    }
    return to_string(num);
  }
  public:
    const string& generate (string& s, const string& y, const string& m, const string& d) override
    {
      
      str = sex(s) + y + m + d + rands(y,m,d);
      str = str + last(str);
      return str;
    }
    void print(std::ostream& out) override
    {
      out << str << std::endl;
    }
};

class MGTUU: virtual Studs
{
  static const int divider=9;
  const string sex(string& a) override
  {
    while (a[0]==' ') a.std::string::erase(0,1);
    if (a=="man") return (string)"2";
    if (a=="woman") return (string)"1";
    cerr << "Wrong sex!\n";
    exit(EXIT_FAILURE);
  } 
  const string rands (const string& sy, const string& sm, const string& sd) override
  {
    int y=stoi(sy), m=stoi(sm), d=stoi(sd);
    string str = to_string((((((((y^(m|d))<<d)^y)&INT32_MAX)<<m)^y)&INT32_MAX)%10000);
    while (str.length()<4) str = "0" + str;
    return str;
  }
  const string last (const string& str) override
  {
    int s=0, num;
    for (int i=0; i<str.length(); ++i)
    {
      s+=(toi(str[i])*(i+1));
    }
    s%=divider;
    for (num=0; num<10;++num)
    {
      if ((s+num*14)%divider==0) break;
    }
    return to_string(num);
  }
  public:
    const string& generate (string& s, const string& y, const string& m, const string& d) override
    {
      
      str = sex(s) + y + m + d + rands(y,m,d);
      str = str + last(str);
      return str;
    }
    void print(std::ostream& out) override
    {
      out << str << std::endl;
    }
};

void func(bool tf, const char* tdir, bool ff, const char* fdir)
{
  string sex, y, m, d;
  if (ff)
  {
    std::ifstream fin (fdir);
    if (!fin.is_open())
    {
      cerr << "Wrong input file directory!\n";
      exit(EXIT_FAILURE);
    }
    getline (fin,sex,' ');
    getline (fin,y,'.');
    getline (fin,m,'.');
    getline (fin,d);
    fin.close();
  }
  else 
  {
    getline (cin,sex,' ');
    getline (cin,y,'.');
    getline (cin,m,'.');
    getline (cin,d);
  }
  correct_date(y,m,d);
  
  MIEM SB_1;
  MGTUU SB_2;

  SB_1.generate(sex,y,m,d);
  SB_2.generate(sex,y,m,d);

  if (tf)
  {
    std::ofstream fout (tdir,std::ofstream::trunc);
    if (!fout.is_open())
    {
      cerr << "Wrong output file directory!\n";
      exit(EXIT_FAILURE);
    }
    SB_1.print(fout);
    SB_2.print(fout);
    fout.close();
  }
  else
  {
    SB_1.print(cout);
    SB_2.print(cout);
  }
}

#undef DATE_ERR