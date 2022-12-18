#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <set>
#include "classes.h"

std::string stream, name_univ, s_sex, s_year, s_month, s_day;
int sex, year, month, day;

std::string PASS_MIEM::pass_generate() {
    int date = year * 10000 + month * 100 + day;
    passticket += std::to_string(sex) + std::to_string(date);
    std::mt19937 randomizer(date + std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> NNNNN(10000, 99999);
    passticket += std::to_string(NNNNN(randomizer));
    int sum = 0;
    for(int i = 0; i < passticket.size(); i++) {
        sum += (passticket[i] - '0') * (i + 1);
    }
    while(sum % 11 == 4) {
        sum -= (passticket[9] - '0') * 10;
        int new_digit = (passticket[9] - '0' + 1) % 10;
        passticket[9] = new_digit + '0';
        sum += new_digit * 10;
    }
    for(int i = 0; i < 10; i++) {
        if((sum + i * 15) % 11 == 0) {
            passticket += std::to_string(i);
            break;
        }
    }
    return passticket;
}
std::string PASS_MGTU::pass_generate() {
	int date = year * 10000 + month * 100 + day;
	passticket += std::to_string(sex) + std::to_string(date);
    std::mt19937 randomizer(date + std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> NNNN(1000, 9999);
    passticket += std::to_string(NNNN(randomizer));
    int sum = 0;
    for(int i = 0; i < passticket.size(); i++) {
    	sum += (passticket[i] - '0') * (i + 1);
    }
    while((sum % 10) % 2 != 0) {
    	sum -= (passticket[10] - '0') * 11;
    	int new_digit = (passticket[10] - '0' + 1) % 10;
    	passticket[10] = new_digit + '0';
    	sum += new_digit * 11;
    }

    for(int i = 0; i < 10; i++) {
    	if((sum + i * 14) % 10 == 0) {
    		passticket += std::to_string(i);
    		break;
    	}
    }
    return passticket;
}
std::string GetPassTicket(PassTicket &University) { return University.pass_generate(); }
bool IsDigit(char symbol) {
	if(symbol >= '0' && symbol <= '9') return true;
	return false;
}
bool IsUniversityName() {
	if(name_univ == "MIEM" || name_univ == "MGTU") return true;
	return false;
}

int GetNumberOfTickets() {
	int result = 0;
	if(stream.size()) {
		for(int i = 0; i < stream.size(); i++) {
			if(!IsDigit(stream[i])) {
				std::cerr << "ERROR: invalid symbols in natural number of pass tickets input!" << std::endl;
				exit(1);
			}
			else {
				result = result * 10 + (stream[i] - '0');
			}
		}
	}
	else {
		std::cerr << "ERROR: number of pass tickets not entered!" << std::endl;
		exit(1);
	}
	if(result) {
		stream = "";
		return result;
	}
	else {
		std::cout << "ERROR: You must enter a natural number of pass tickets!" << std::endl;
		exit(1);
	}
}
int GetSex() {
	if(s_sex.size()) {
		if(s_sex == "man") {
			return 1;
		}
		else if(s_sex == "woman") {
			return 0;
		}
		else {
			std::cerr << "ERROR: invalid symbols in sex!" << std::endl;
			exit(1);
		}
	}
	else {
		std::cerr << "ERROR: sex not entered!" << std::endl;
		exit(1);
	}
}
int GetYear() {
	int result = 0;
	if(s_year.size()) {
		for(int i = 0; i < s_year.size(); i++) {
			if(!IsDigit(s_year[i])) {
				std::cerr << "ERROR: invalid symbols in year of birth!" << std::endl;
				exit(1);
			}
			else {
				result = result * 10 + (s_year[i] - '0');
			}
		}
	}
	else {
		std::cerr << "ERROR: year of birth not entered!" << std::endl;
		exit(1);
	}
	if(result >= 1900 && result <= 2005) {
		return result;
	}
	else {
		std::cerr << "ERROR: year of birth must be in range 1900 to 2005" << std::endl;
		exit(1);
	}
}
int GetMonth() {
	int result = 0;
	if(s_month.size()) {
		for(int i = 0; i < s_month.size(); i++) {
			if(!IsDigit(s_month[i])) {
				std::cerr << "ERROR: invalid symbols in month of birth!" << std::endl;
				exit(1);
			}
			else {
				result = result * 10 + (s_month[i] - '0');
			}
		}
	}
	else {
		std::cerr << "ERROR: month of birth not entered!" << std::endl;
		exit(1);
	}
	if(result >= 1 && result <= 12) {
		return result;
	}
	else {
		std::cerr << "ERROR: month of birth must be in range 1 to 12!" << std::endl;
		exit(1);
	}
}
int GetDay() {
	int result = 0;
	if(s_day.size()) {
		for(int i = 0; i < s_day.size(); i++) {
			if(!IsDigit(s_day[i])) {
				std::cout << "ERROR: invalid symbols in day of birth!" << std::endl;
				exit(1);
			}
			else {
				result = result * 10 + (s_day[i] - '0');
			}
		}
	}
	else {
		std::cerr << "ERROR: day of birth not entered!" << std::endl;
		exit(1);
	}
	if(result >= 1 && result <= 31) {
		return result;
	}
	else {
		std::cerr << "ERROR: day of birth must be in range 1 to 31" << std::endl;
		exit(1);
	}
}
void FillFields() {
	std::cin >> name_univ >> s_sex >> s_year >> s_month >> s_day;
	if(!IsUniversityName()) {
		std::cerr << "ERROR: wrong University name!" << std::endl;
		exit(1);
	}
	sex = GetSex();
	year = GetYear();
	month = GetMonth();
	day = GetDay();
}
void CheckDate() {
	int calendar[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(!(year % 4))
		calendar[1] = 29;
	if(day > calendar[month - 1] || day < 1) {
		std::cerr << "ERROR: day in this month and year must be in range 1 to " << calendar[month - 1] << std::endl;
		exit(1);
	}
}

void CompletionToConsole(std::string group[], int num_tickets) {
	std::cout << "\nRESULT:\n" << std::endl;
	for(int i = 0; i < num_tickets; i++) {
		std::cout << i + 1 << ") " << group[i] << std::endl;
	}
}



void GetResultFromConsole() {
	std::cout << "Enter the number of pass tickets: ";
	std::cin >> stream;
	std::cout << "\n";
	int num_tickets = GetNumberOfTickets();
	std::string group[num_tickets];
	std::set <std::string> unique;
	for(int i = 0; i < num_tickets; i++) {
		std::cout << i+1 << ") ";
		FillFields();
		CheckDate();
		if(name_univ == "MIEM") {
			PASS_MIEM person(sex, year, month, day);
			std::string temp = GetPassTicket(person);
			while(unique.find(temp) != unique.end())
				temp = GetPassTicket(person);
			group[i] = temp;
			unique.insert(temp);
		}
		else if(name_univ == "MGTU") {
			PASS_MGTU person(sex, year, month, day);
			std::string temp = GetPassTicket(person);
			while(unique.find(temp) != unique.end())
				temp = GetPassTicket(person);
			group[i] = temp;
			unique.insert(temp);
		}
	}
	CompletionToConsole(group, num_tickets);
}

void GetResultFromConsole(const char * nametofile, bool is_name_file) {
	std::cout << "Enter the number of pass tickets: ";
	std::cin >> stream;
	std::cout << "\n";
	int num_tickets = GetNumberOfTickets();
	std::string group[num_tickets];
	std::set <std::string> unique;
	for(int i = 0; i < num_tickets; i++) {
		std::cout << i+1 << ") ";
		FillFields();
		CheckDate();
		if(name_univ == "MIEM") {
			PASS_MIEM person(sex, year, month, day);
			std::string temp = GetPassTicket(person);
			while(unique.find(temp) != unique.end())
				temp = GetPassTicket(person);
			group[i] = temp;
			unique.insert(temp);
		}
		else if(name_univ == "MGTU") {
			PASS_MGTU person(sex, year, month, day);
			std::string temp = GetPassTicket(person);
			while(unique.find(temp) != unique.end())
				temp = GetPassTicket(person);
			group[i] = temp;
			unique.insert(temp);
		}
	}

	if(is_name_file) {

	}
	else {

	}
}




void Help() {
	std::cout << "HELP" << std::endl;
}

