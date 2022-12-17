#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>

using namespace std;

class University {
 protected:
  string ticket, pseudorandomNumber;
  virtual string &lastDigitGenerator(string &ticket) = 0;
  virtual string &pseudorandomNumberGenerator(string &year, string &month, string &day) = 0;
 public:
  virtual string &ticketGenerator(string &sex, string &year, string &month, string &day) = 0;
};

class MIEM : public University {
 protected:
  string &lastDigitGenerator(string &ticket) override {
    int sum = 0;
    for (int i = 0; i < ticket.size(); ++i) {
      sum += (i + 1) * (ticket[i] - '0');
    }
    return ticket += to_string(sum % 11);
  }
  string &pseudorandomNumberGenerator(string &year, string &month, string &day) override {
    srand(time(nullptr));
    ticket += to_string((rand() % stoi(year)) % 10);
    ticket += to_string((rand() % (month[0] - '0' + month[1] - '0')) % 10);
    ticket += to_string((rand() % (day[0] - '0' + day[1] - '0')) % 10);
    ticket += to_string((rand() % (day[0] - '0' + day[1] - '0' + month[0] - '0' + month[1] - '0' + stoi(year))) % 10);
    return ticket;
  }
  string &ticketGenerator(string &sex, string &year, string &month, string &day) override {
    if (sex == "man") {
      ticket += '8';
    } else {
      ticket += '4';
    }
    ticket += year + month + day;
    pseudorandomNumberGenerator(year, month, day);
    lastDigitGenerator(ticket);
    return ticket;
  }
};

class MGTUU : public University {
 protected:
  string &lastDigitGenerator(string &ticket) override {
    int sum = 0;
    for (int i = 0; i < ticket.size(); ++i) {
      sum += (i + 1) * (ticket[i] - '0');
    }
    return ticket += to_string(sum % 10);
  }
  string &pseudorandomNumberGenerator(string &year, string &month, string &day) override {
    srand(time(nullptr));
    ticket += to_string((rand() % stoi(year)) % 10);
    ticket += to_string((rand() % (month[0] - '0' + month[1] - '0')) % 10);
    ticket += to_string((rand() % (day[0] - '0' + day[1] - '0')) % 10);
    return ticket;
  }
  string &ticketGenerator(string &sex, string &year, string &month, string &day) override {
    if (sex == "man") {
      ticket += '2';
    } else {
      ticket += '1';
    }
    ticket += year + month + day;
    pseudorandomNumberGenerator(year, month, day);
    lastDigitGenerator(ticket);
    return ticket;
  }
};

class templateGenerator {
 public:
  University* generate(string& university) {
    if (university == "MIEM") {
      auto* student = new MIEM;
      return student;
    } else if (university == "MGTUU") {
      auto* student = new MGTUU;
      return student;
    } else {
      return nullptr;
    }

  }
};

int main(int argc, char *argv[]) {
  string university, sex, year, month, day, result;
  templateGenerator generator;

  if (argc == 1) { // ввод с консоли || вывод в консоль
    cout << "Enter the name of the university, sex, year, month, day:" << endl;
    cin >> university >> sex >> year >> month >> day;

    result = generator.generate(university)->ticketGenerator(sex, year, month, day);

    cout << "Your ticket:\n" << result << endl;

  } else if (((argc == 2) || (argc == 3)) & (strcmp(argv[1], "--tofile") == 0)) { // ввод с консоли || вывод в консоль
    cout << "Enter the name of the university, sex, year, month, day:" << endl;
    cin >> university >> sex >> year >> month >> day;

    result = generator.generate(university)->ticketGenerator(sex, year, month, day);

    ofstream fout;

    if (argc == 3) { // вывод в указанный файл
      fout.open(argv[2]);
      if (fout.is_open()) {
        fout << result << endl;
      } else {
        cout << "Error: Could not open the file (output)" << endl;
        return -1;
      }
    } else { // вывод в файл output.txt
      fout.open("output.txt");
      if (fout.is_open()) {
        fout << result << endl;
      } else {
        cout << "Error: Could not open the file (output)" << endl;
        return -1;
      }
    }

    fout.close();

  } else if ((argc == 3) & (strcmp(argv[1], "--fromfile") == 0)) { // ввод с файла || вывод в консоль

    fstream fin;
    fin.open(argv[2]);

    if (fin.is_open()) {
      fin >> university >> sex >> year >> month >> day;

      result = generator.generate(university)->ticketGenerator(sex, year, month, day);

      cout << "Your ticket:\n" << result << endl;
    } else {
      cout << "Error: Could not open the file (input)" << endl;
      return -1;
    }
  } else if (((argc == 5) || (argc == 4)) & ((strcmp(argv[1], "--fromfile") == 0) // ввод с файла || вывод в файл
      & (strcmp(argv[2], "--tofile") == 0))) {

    fstream fin;
    ofstream fout;
    if (argc == 4) {
      fin.open(argv[3]);
    } else {
      fin.open(argv[4]);
    }

    if (fin.is_open()) {
      fin >> university >> sex >> year >> month >> day;

      result = generator.generate(university)->ticketGenerator(sex, year, month, day);

      if (argc == 5) { // вывод в указанный файл
        fout.open(argv[3]);
        if (fout.is_open()) {
          fout << result << endl;
        } else {
          cout << "Error: Could not open the file (output)" << endl;
          return -1;
        }
      } else { // вывод в файл output.txt
        fout.open("output.txt");
        if (fout.is_open()) {
          fout << result << endl;
        } else {
          cout << "Error: Could not open the file (output)" << endl;
          return -1;
        }
      }
    } else {
      cout << "Error: Could not open the file (input)" << endl;
      return -1;
    }

    fin.close();
    fout.close();
  }
  return 0;
}

