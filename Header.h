#pragma once
extern int arc;
extern char** arg;
void Fromtofile();
void Fromfile();
void Tofile();
void Consol();
std::string numM(double gender, double year, double month, double day);
std::string numT(double gender, double year, double month, double day);
bool proverka(std::string v, char gender, int year, int month, int day);