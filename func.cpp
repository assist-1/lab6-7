#include <sstream>
#include <iostream>
#include <random>
#include "lab67.h"
using std::endl;
using std::cout;
using std::cin;
using std::cerr;
using std::string;
string to_str(int x) {
	std::ostringstream str;
	str << x;
	return str.str();
}
int to_int(char str) {
	switch (str) {
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	default:
		return -1;
	}
}
int ost(string result, string N, int num) {
	int ans, sum_of_num_mult_pos;
	ans = -1;
	int j = 0;
	sum_of_num_mult_pos = 0;
	for (int i = 0; i < result.size(); i++)
	{
		sum_of_num_mult_pos += to_int(result[i]) * (i + 1);
		j = i + 1;
	}
	j += 1;
	for (int i = 0; i < N.size(); i++){
		sum_of_num_mult_pos += to_int(N[i]) * j;
		j += 1;
	}
	for (int i = 0; i < 10; i++) {
		if (num == 11) {
			ans = (sum_of_num_mult_pos + i * 15) % 11 == 0 ? i : -1;
		}
		else if (num == 10) {
			ans = (sum_of_num_mult_pos + i * 14) % 10 == 0 ? i : -1;
		}
	}
	return ans;
}
int randomnum(int min, int max) {
	std::random_device rd;
	std::mt19937 num(rd());
	std::uniform_int_distribution<int> distrib(min, max);
	return distrib(num);
}
int correct_data(string un, char s, int y, int m, int d) {
	if (un != "MIEM" && un != "MGTUU") { 
		cerr << "Incorrect univeristy entry." << endl;
		return -1;
	}
	if (s != 'M' && s != 'm' && s != 'F' && s != 'f') {
		cerr << "Incorrect sex entry. Write \'M\' or \'m\', if you want to add male. Write \'F\' or \'f\', if you want to add female." << endl;
		return -1;
	}
	if (y < 1000 || y > 2023) {
		cerr << "Incorrect year entry. You're not exist. Please, choose number between 0 and 2022" << endl;  
		return -1;
	}
	if (m < 1 || m > 12) {
		cerr << "Incorrect month entry. Who are you, stranger? Why do you have more than 12 month or less than 0" << endl; 
		return -1;
	}
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
		if (d < 1 || d > 31) {
			 cerr << "Incorrect day entry. You should write number between 1 and 31" << endl;
			 return -1;	
		}
	}
	else if (m == 2)
	{
		if (d <1 || d > 28) {
			cerr << "Incorrect day entry. I am so sorry, but if you were born on February 29, you don't exist to me" << endl; 
			return -1;
		}
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11) {
		if (d < 1 || d > 30) {
			cerr << "Incorrect day entry. You should write number between 1 and 30" << endl;
			return -1;
		}
	}
	return 0;
}