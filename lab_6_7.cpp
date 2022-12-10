#include <iostream>
#include <ctime>
#include <string>
#include "Header.h"
#include <fstream>
#include <cstring>
int arc;
char** arg;

int main(int argc, char**argv) {
	arc = argc;
	arg = argv;
	if (argc == 1) Consol();
	else if (argc >= 4 && argc <= 5 && strcmp(argv[1], "--fromfile") == 0 && strcmp(argv[2], "--tofile") == 0) Fromtofile();
	else if (argc == 3 && strcmp(argv[1], "--fromfile") == 0) Fromfile();
	else if (argc >= 2 && argc <= 3 && strcmp(argv[1], "--tofile") == 0) Tofile();
	else std::cout << "Error! You entered incorrectly" << std::endl;
	return 0;
}
class Styd {
public:
	virtual std::string generator(char gender, int year,int month, int day) = 0;
};
class Generator : public Styd{
public: 
	bool error;
	int year, day, month, gender;
protected:
	virtual void gen() = 0;
	virtual std::string gener_styd(char gend, int y, int mon, int d) = 0;
	std::string generator(char gender, int year, int month, int day) final {
		gen();
		gener_styd(gender, year,month, day);
		return gener_styd(gender, year, month, day);
	}
	virtual void gener(char gend, int y, int mon, int d) final {}
};

class Styd_MGTUU : public Generator {
	int gender;
	long long styd;
protected:
	std::string Num;
	bool error = true;
	void gen() override{
		gender = 0;
		year = 0;
		month = 0;
		day = 0;
	}
	std::string gener_styd(char gend, int y, int mon, int d) override {
		if (gend == 'm') gender = 2;
		else if (gend == 'w') gender = 1;
		year = y;
		month = mon;
		day = d;
		Num = numT(gender, year, month, day);
		return Num;
	}

};
class Styd_MIEM : public Generator {
	int gender, year, month, day, Num;
	long long styd;
protected:
	bool error = true;
	void gen() override {
		gender = 0;
		year = 0;
		month = 0;
		day = 0;
	}
	std::string gener_styd(char gend, int y, int mon, int d) override {
		if (gend == 'm') gender = 8;
		else if (gend == 'w') gender = 4;
		year = y;
		month = mon;
		day - d;
		std::string Num = numM(gender, year, month, day);
		return Num;
	}
};
class vyz {
public:
	Styd* gen(std::string str) {
		if (str == "MIEM") {
			Styd* s1 = new Styd_MIEM;
			return s1;
		}
		else{
			Styd* s2 = new Styd_MGTUU;
			return s2;
		}
	}
};
void Consol() {
	std::cout << "Enter the number of students." << std::endl;
	int n,i=0;
	std::cin >> n;
	while (i < n) {
		std::cout << "Enter the University (MIAMI or MGTU),gender (m,w), your year of birth, month and day." << std::endl;
		std::string v;
		int year, month, day;
		char gender;
		std::cin >> v >> gender >> year >> month >> day;
		if (proverka(v, gender, year, month, day) == false) {
			std::cout << "Data entered incorrectly." << std::endl; return;
		}
		vyz s;
		std::string stydak = s.gen(v)->generator(gender, year, month, day);
		std::cout << stydak << std::endl;
		i += 1;
	}
	return;
}
void Fromtofile() {
	std::ifstream file;
	file.open(arg[3]);
	if (!file) {
		std::cout << "Error! The file did not open." << std::endl; return;
	}
	std::ofstream file2;
	if (arc == 5) file2.open(arg[4]);
	else file2.open("Tofile.txt");
	if (!file2) {
		std::cout << "Error! The file did not open." << std::endl; return;
	}
	std::string v;
	int year, month, day;
	char gender;
	while (!file.eof()) {
		file >> v >> gender >> year >> month >> day;
		if (proverka(v, gender, year, month, day) == false) {
			std::cout << "Data entered incorrectly." << std::endl; return;
		}
		vyz s;
		std::string stydak = s.gen(v)->generator(gender, year, month, day);
		file2 << stydak << std::endl;
	}
	std::cout << "Check your file or Tofile.txt" << std::endl;
	file.close();
	file2.close();
	return;
}
void Fromfile() {
	std::ifstream file;
	file.open(arg[2]);
	if (!file) {
		std::cout << "Error! The file did not open." << std::endl; return;
	}
	std::string v;
	int year, month, day;
	char gender;
	while (!file.eof()) {
		file >> v >> gender >> year >> month >> day;
		if (proverka(v, gender, year, month, day) == false) {
			std::cout << "Data entered incorrectly." << std::endl; return;
		}
		vyz s;
		std::string stydak = s.gen(v)->generator(gender, year, month, day);
		std::cout << stydak << std::endl;
	}
	file.close();
	return;
}
void Tofile() {
	std::ofstream file2;
	if (arc == 5) file2.open(arg[4]);
	else file2.open("Tofile.txt");
	if (!file2) {
		std::cout << "Error! The file did not open." << std::endl; return;
	}
	std::cout << "Enter the number of students." << std::endl;
	int n, i = 0;
	std::cin >> n;
	while (i < n) {
		std::cout << "Enter the University (MIAMI or MGTU),gender (m,w), your year of birth, month and day." << std::endl;
		std::string v;
		int year, month, day;
		char gender;
		std::cin >> v >> gender >> year >> month >> day;
		if (proverka(v, gender, year, month, day) == false) {
			std::cout << "Data entered incorrectly." << std::endl; return;
		}
		vyz s;
		std::string stydak = s.gen(v)->generator(gender, year, month, day);
		file2 << stydak << std::endl;
		i += 1;
	}
	file2.close();
	std::cout << "Check your file or Tofile.txt" << std::endl;
	return;
}