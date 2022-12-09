#include <iostream>
#include "student_id.hpp"
#include <string>
using std::string;

string random(int un, int year, int month, int day)
//un = 1 for miem; 0 for mgttu
{
	string ans;
	if(un) ans = std::to_string((year*23456-month*6789+day*1203)%100000);
	else   ans = std::to_string((year*3456 -month*2345+day*678) %10000 );
	for(int i = sizeof(ans); i < 5 + un; i ++) ans = "9" + ans;
	return ans;
}

// S YYYY MM DD NNNNN C 
string MIEM :: generate(int sex, int year, int month, int day)
{
	std::string sd;
	sd += std::to_string(sex) + std::to_string(year);
	if(month < 10) sd += "0" + std::to_string(month);
	else sd += std::to_string(month);
	if(day < 10) sd += "0" + std::to_string(day);
	else sd += std::to_string(day);
	sd += random(1, year, month, day);

	int c = 0;
	for(int i = 0; i < 14; i++) c += (sd[i] - '0') * (i+1);
	sd += std::to_string((11 - c % 11)%11);

	return sd;
}


//S YYYY MM DD NNNN C
string MGTUU :: generate(int sex, int year, int month, int day)
{
	string sd;
	sd += std::to_string(sex / 4) + std::to_string(year);
	if(month < 10) sd += "0" + std::to_string(month);
	else sd += std::to_string(month);
	if(day < 10) sd += "0" + std::to_string(day);
	else sd += std::to_string(day);
	sd += random(0, year, month, day);

	int c = 0;
	for(int i = 0; i < 13; i++) c += (sd[i] - '0') * (i+1);
	sd += std::to_string((10 - c % 10)%10);

	return sd;
}