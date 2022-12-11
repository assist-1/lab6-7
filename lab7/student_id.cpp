#include <string>
#include <iostream>
#include "student_id.h"

std::string Student_ID :: get_id(){
	return id;
}
std::string Student_ID :: get_year_for_id(){
	return std::to_string(year);
}
std::string Student_ID :: get_month_for_id(){
	if(month < 10) return "0" + std::to_string(month);
	return std::to_string(month);
}
std::string Student_ID :: get_day_for_id(){
	if(day < 10) return "0" + std::to_string(day);
	return std::to_string(day);
}


std::string Student_ID :: get_sex(){
	return sex;
}
int Student_ID :: get_year(){
	return year;
}
int Student_ID :: get_month(){
	return month;
}
int Student_ID :: get_day(){
	return day;
}


std::string msg = "You have to enter 5 correct parametres for id gneration: Name_of_university, sex, year, month, day.\n";


void Student_ID :: set_sex(std::string sex)
{	
	if(sex == "man") 
		this->sex = sex;
	else if(sex == "woman")
		this->sex = sex;
	else
	{
		std::cerr << msg << "There's no " << sex << "sex.\n";
		exit(EXIT_FAILURE);
	}
}

void Student_ID :: set_year(int year)
{
	if(year < 1000 || year > 9999)
	{
		std::cerr << msg << "Really? Were you born in " << year << "?\n";
		exit(EXIT_FAILURE);
	}
	this->year = year;

}
void Student_ID :: set_month(int month)
{
	if(month < 1 || month > 12)
	{
		std::cerr << msg << "There's no month with number " << month << ".\n";
		exit(EXIT_FAILURE);
	}
	this->month = month;
}
void Student_ID :: set_day(int day)
{
	if(day < 1 || day > 31)
	{
		std::cerr << msg << "There's no day with number " << day << ".\n";
		exit(EXIT_FAILURE);	
	}
	this->day = day;
}
void Student_ID :: set_id(std::string id)
{
	this->id = id;
}
