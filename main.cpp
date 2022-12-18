#include "classes.h"
#include <fstream>
#include <cstring>
#include <algorithm>

namespace sex{
    char man = 'm';
    char woman = 'w';
};

std::string name;
std::string _sex;
int y;
int m;
int d;


int check_date(int y, int m, int d){
    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (!(y % 4) && (y % 100)){
        days_in_month[1] = 29;
    }
    if (y > 2022 || y < 1900){
        std::cerr << "Wrong year";
        return 0;
    }
    else if (m > 12 || m < 1){
        std::cerr << "Wrong month";
        return 0;
    }
    else if (d < 0 || d > days_in_month[m - 1]){
        std::cerr << "Wrong date";
        return 0;
    }
    return 1;
}

int check_university_name(std::string name){
    if (name == "MIEM" || name == "MGTUU"){
        return 1;
    }
    std::cerr << "Wrong university name";
    return 0;
}

int check_sex(std::string sex){
    if (sex == "man" || sex == "woman"){
        return 1;
    }
    std::cerr << "Wrong sex";
    return 0;
}

char to_upper(char c) { return std::toupper(c); }
char to_lower(char c) { return std::tolower(c); }


int read() {
    std::cin >> name;
    std::transform(name.begin(), name.end(), name.begin(), to_upper);
    std::cin >> _sex;
    std::transform(_sex.begin(), _sex.end(), _sex.begin(), to_lower);
    std::cin >> y >>  m >> d;

    return check_date(y, m, d) && check_sex(_sex) && check_university_name(name);
}

int read(std::string filename) {
    std::ifstream file (filename);
    if (!file.is_open()) {
        std::cerr << "Wrong file name";
        return 1;
    }

    std::getline(file, name);
    std::transform(name.begin(), name.end(), name.begin(), to_upper);
    std::getline(file, _sex);
    std::transform(_sex.begin(), _sex.end(), _sex.begin(), to_lower);
    file >> y >> m >> d;

    file.close();

    return check_date(y, m, d) && check_sex(_sex) && check_university_name(name);    
}

void print(std::string ticket) { std::cout << "Ticket: " << ticket << std::endl; }

void print(std::string ticket, std::string filename) {
    std::ofstream file (filename);
    file << "Ticket: " << ticket << '\n';
    file.close();
}

std::string generate_ticket() {
    ticketGenerator ticket_generator;
    std::string ticket;
    if (_sex == "man")
        ticket = ticket_generator.generator(name)->generate(sex::man, y, m, d);
    else
        ticket = ticket_generator.generator(name)->generate(sex::woman, y, m, d);
    return ticket;
}


int main(int argc, char ** argv){
    std::string ticket;
    switch (argc){
        case 1:
            if (!read()){
                exit(1);
            }
            ticket = generate_ticket();
            print(ticket);
            break;
        case 2:
            if (!strcmp(argv[1], "--fromfile")) {
                if (!read(argv[2])) exit(1);
                ticket = generate_ticket();
                print(ticket);
            }
            else if (!strcmp(argv[1], "--tofile")) {
                if (!read()) exit(1);
                ticket = generate_ticket();
                print(ticket, argv[2]);
            }
            else {
                std::cerr << "Wrong flags";
                exit(1);
            }
            break;
        case 5:
            if (!strcmp(argv[1], "--tofile") && !strcmp(argv[3], "--fromfile")) {
                if (!read(argv[4])) exit(1);
                ticket = generate_ticket();
                print(ticket, argv[2]);
            }
            else if  (!strcmp(argv[3], "--tofile") && !strcmp(argv[1], "--fromfile")) {
                if (!read(argv[2])) exit(1);
                ticket = generate_ticket();
                print(ticket, argv[4]);
            }
            else {
                std::cerr << "Wrong flags";
                exit(1);
            }
            break;
        default:
            std::cerr << "Wrong flags";
            exit(1);
            break;
    }
    return 1;
}