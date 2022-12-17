#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include "classes.h"

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