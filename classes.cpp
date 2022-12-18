#include "classes.h"

std::string MIEMTicket::generate(char s, int y, int m, int d){
    std::string ticket = "";
    int summa = 0;

    if (s == 'm'){
        ticket += std::to_string(man);
        summa += man;
    }
    else{
        ticket += std::to_string(woman);
        summa += woman;
    }

    ticket += std::to_string(10000 * y + 100 * m + d);
    for (int i = 1; i < ticket.size(); ++i){
        summa += (ticket[i] - '0') * (i + 1);
    }

    std::mt19937 gen(y + m + d); 
    std::uniform_int_distribution<> distr(10000, 99999);
    std::string id = std::to_string(distr(gen));

    for (int i = 0; i < id.size(); ++i){
        summa += (id[i] - '0') * (i + 10);
    }

    if (summa % 11 == 4){
        summa -= id[0] * 10;
        char id0 = (char)(((id[0] - '0' + 1) % 10) + '0');
        ticket += id0;
        ticket += id.substr(1);
        summa += (id0 - '0') * 10;
    }

    int remainder = summa % 11;
    for (int i = 0; i < 10; ++i){
        if (!((i * 15 + remainder) % 11)){
            ticket += std::to_string(i);
            break;
        }
    }

    return ticket;
}

std::string MGTUUTicket::generate(char s, int y, int m, int d){
    std::string ticket = "";
    int summa = 0;

    if (s == 'm'){
        ticket += std::to_string(man);
        summa += man;
    }
    else{
        ticket += std::to_string(woman);
        summa += woman;
    }
    
    ticket += std::to_string(10000 * y + 100 * m + d);
    for (int i = 1; i < ticket.size(); ++i){
        summa += (ticket[i] - '0') * (i + 1);
    }

    std::mt19937 gen(y + m + d); 
    std::uniform_int_distribution<> distr(1000, 9999);
    std::string id = std::to_string(distr(gen));    

    for (int i = 0; i < id.size(); ++i){
        summa += (id[i] - '0') * (i + 10);
    }

    if ((summa % 10) % 2){
        summa -= id[1] * 11;
        char id1 = (char)(((id[1] - '0' + 1) % 10) + '0');
        ticket += id[0];
        ticket += id1 + id.substr(2);
        summa += (id1 - '0') * 11;
    }

    int remainder = summa % 10;
    for (int i = 0; i < 10; ++i){
        if (!((summa + i * 14) % 10)){
            ticket += std::to_string(i);
            break;
        }
    }

    return ticket;  
}

studentTicket *ticketGenerator::generator(std::string universityName){
    if (universityName == "MIEM"){
        MIEMTicket *ticket = new MIEMTicket;
        return ticket;
    }
    else if (universityName == "MGTUU"){
        MGTUUTicket *ticket = new MGTUUTicket;
        return ticket;
    }
    else{
        std::cerr << "Wrong university name" << std::endl;
        exit(1);
    }
}