#include "classes.h"

bool kr11(std::string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); ++i)
        sum += (s[i] - '0') * (i + 1);
    bool answer = (sum % 11 == 0); 
    return answer;
}

std::string MIEM::generate(int sex, int y, int m, int d) {
    int sum = 0;
    std::string ticket = "";
    if (!sex) {
        ticket += std::to_string(man);
        sum += man;
    }
    else {
        ticket += std::to_string(woman);
        sum += woman;
    }

    ticket += std::to_string(y * 10000 + m * 100 + d);
    for (int i = 1; i < ticket.size(); ++i) {
        sum += (ticket[i] - '0') * (i + 1);
    }

    int date = y + m + d;
    
    std::mt19937 gen(date + time(0)); // seed the generator
    std::uniform_int_distribution<> distr(10000, 99999); // define the range
    std::string id = std::to_string(distr(gen));

    for (int i = 0; i < id.size(); ++i)
        sum += (id[i] - '0') * (i + 10);
    
    if (sum % 11 == 7) {
        sum -= id[0] * 10;
        int new_d = (id[0] - '0' + 1) % 10;
        id = std::to_string(new_d) + id[1] + id[2] + id[3] + id[4];
        sum += id[0] * 10;
    }

    ticket += id;

    int ost = sum % 11;
    for (int i = 0; i < 10; i++) {
        if (ost + (i * 15) % 11 == 11) {
            ost = 0;
            ticket += std::to_string(i);
            break;
        }
    }

    std::cout << ticket << std::endl;
    std::cout << std::boolalpha << kr11(ticket) << std::endl;
    return ticket;
}


University* TicketGenerator::generator(std::string name) {
    if (name == "MIEM") {
        MIEM* university = new MIEM;
        return university;
    }
    /*else if (name == "MGTUU") {
        MGTUU* university = new MGTUU;
        return university;
    }*/
    std::cerr << "##### Wrong name of university #####\n";
    exit(1);
}
