#include <iostream>
#include <string>
#include "classes.h"
    
int main() {
    GenTickets ticket;
    int num;
    std::cout << "Enter the number of tickets: ";
    std::cin >> num;
    std::cout << "\n";
    for(int i = 0; i < num; i++) {
        std::cout << i+1 << ") ";
        std::string name, sex;
        int year, month, day;
        std::cin >> name >> sex >> year >> month >> day;
        std::cout << "   RESULT: " << ticket.generate(name, sex, year, month, day)->Generator() << std::endl;
    }
    return 0;
}