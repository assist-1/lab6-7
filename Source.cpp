#include <iostream>
#include "Header.h"
#include <fstream>
#include <string>

std::string numM(double g, double y, double m, double d) {
	long long int Num;
	bool p = false;
	Num = g * 100000000000000 + y * 10000000000 + m * 100000000 + d * 1000000;
	srand(unsigned(time(0)));
	int N5 = rand() % 10000;
	while (p != true) {
		srand(unsigned(time(0)));
		int N5 = rand() % 10000;	
		Num += (N5 * 10);
		if (Num % 11 == 0) p = true;
		else if (Num % 11 < 10) {
			p = true;
			Num += (Num % 11);
		}
	}
	std::string n = std::to_string(Num);
	return n;
}
std::string numT(double g, double y, double m, double d) {
	long long Num;
	int N4;
	bool p = false;
	Num = g * 10000000000000 + y * 1000000000 + m * 10000000 + d * 100000;
	srand(unsigned(time(0)));
	N4 = rand() % 1000;
	while (p != true) {
		srand(unsigned(time(0)));
		int N5 = rand() % 1000;
		Num += (N4 * 10);
		if (Num % 10 == 0) p = true;
		else if (Num % 10 < 10) {
			p = true;
			Num += (Num % 10);
		}
	}
	std::string n = std::to_string(Num);
	return n;
}
bool proverka(std::string v, char gender, int year, int month, int day) {
	if (v != "MIEM" && v != "MGTUU") return false;
	if (gender != 'm' && gender != 'w') return false;
	if (year <= 1900 || year > 2022) return false;
	if (month <= 0 || month > 12) return false;
	if (day <= 0 || day > 31) return false;
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && day > 29) return false;
	if (month == 2 && (year % 400 != 0 || year % 4 != 0 || (year % 100 == 0&& year%400!=0)) && day > 28) return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
	return true;

}