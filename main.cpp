#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

int magic_number() { //make a random digit
    static int seed{ 3856 };
    seed = 8253729 * seed + 2396403;
    int a = seed % 10;
    return a;
}

std::string magic_numbers(int length) { //make a random number
    std::string s_num;
    if (length == 4) {
        int a1 = magic_number();
        if (a1 == 0) {
            while (a1 == 0) {
                a1 = magic_number();
            }
        }
        int a2 = magic_number();
        int a3 = magic_number();
        int a4 = magic_number();
        s_num += ('0' + a1) + ('0' + a2) + ('0' + a3) + ('0' + a4);
    } else if (length == 5) {
        int a1 = magic_number();
        if (a1 == 0) {
            while (a1 == 0) {
                a1 = magic_number();
            }
        }
        int a2 = magic_number();
        int a3 = magic_number();
        int a4 = magic_number();
        int a5 = magic_number();
        s_num += ('0' + a1) + ('0' + a2) + ('0' + a3) + ('0' + a4);
    }
    return s_num;
}

class generator {
protected:
    char s;
    std::string birthday;
    std::string mn;
public:
    virtual void set_sex(char s_given) = 0;
    virtual void set_birthday(int dd, int mm, int yyyy) = 0;
    virtual void set_magic_n() = 0;
    virtual std::string ticket() = 0;
};

class MIEM : private generator {
public:
    void set_sex(char s_given) override {
        if (s_given == 'M') {
            s = '8';
        } else if (s_given == 'W') {
            s = '4';
        }
    }
    void set_birthday(int dd, int mm, int yyyy) override {
        std::string birth = "00000000";
        int d1 = dd / 10; int d2 = dd % 10;
        int m1 = mm / 10; int m2 = mm % 10;
        int y1 = yyyy / 1000; int y2 = (yyyy / 100) % 10;
        int y3 = (yyyy / 10) % 10; int y4 = yyyy % 10;
        birth[0] = '0' + y1;
        birth[1] = '0' + y2;
        birth[2] = '0' + y3;
        birth[3] = '0' + y4;
        birth[4] = '0' + m1;
        birth[5] = '0' + m2;
        birth[6] = '0' + d1;
        birth[7] = '0' + d2;
        birthday = birth;
    }
    void set_magic_n() override {
        mn = magic_numbers(5);
    }
    std::string ticket() override {
        std::string ticket_miem = "0";
        ticket_miem[0] = s;
        ticket_miem = ticket_miem + birthday + mn;
        int sum = 0;
        for (int i = 0; i < 14; i++) {
            int k = ticket_miem[i] - '0';
            sum += (i+1)*k;
        }
        for (int i = 0; i < 10; i++) {
            if (((sum+(15*i)) % 11) == 0) {
                ticket_miem += '0' + i;
            }
        }
        return ticket_miem;
    }
};

class MGTUU : private generator {
public:
    void set_sex(char s_given) override
    {
        if (s_given == 'M') {
            s = '2';
        } else if (s_given == 'W') {
            s = '1';
        }
    }
    void set_birthday(int dd, int mm, int yyyy) override
    {
        std::string birth = "11111111";
        int d1 = dd / 10; int d2 = dd % 10;
        int m1 = mm / 10; int m2 = mm % 10;
        int y1 = yyyy / 1000; int y2 = (yyyy / 100) % 10;
        int y3 = (yyyy / 10) % 10; int y4 = yyyy % 10;
        birth[0] = '0' + y1; birth[1] = '0' + y2; birth[2] = '0' + y3; birth[3] = '0' + y4;
        birth[4] = '0' + m1; birth[5] = '0' + m2; birth[6] = '0' + d1; birth[7] = '0' + d2;
        birthday = birth;
    }
    void set_magic_n() override
    {
        mn = magic_numbers(4);
    }
    std::string ticket() override
    {
        std::string ticket_mgtuu = "0";
        ticket_mgtuu[0] = s;
        ticket_mgtuu += birthday + mn;
        int sum = 0;
        for (int i = 0; i < 13; i++) {
            int k = ticket_mgtuu[i] - '0';
            sum += (i+1)*k;
        }
        for (int i = 0; i < 10; i++) {
            if (((sum+(i*14)) % 10) == 0) {
                ticket_mgtuu += '0' + i;
            }
        }
        return ticket_mgtuu;
    }
};


int main(int argc, char* argv[])
{
    bool tf = false;
    bool ff = false;
    char* tofilename;
    char* fromfilename;
    for (std::size_t i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "--tofile") == 0) {
            tf = true;
            tofilename = argv[i + 1];
            ++i;
        } if (std::strcmp(argv[i], "--fromfile") == 0) {
            ff = true;
            fromfilename = argv[i + 1];
            ++i;
        } else {
            std::cerr << "Unexpected argument: " << argv[i] << "\n";
            return EXIT_FAILURE;
        }
    }

    if (ff) {
        std::ifstream fromfile(fromfilename);
        if (!fromfile) {
            return EXIT_FAILURE;
        }
        std::string sex{};
        std::string university{};
        int dd, mm, yyyy;
        fromfile >> university >> sex >> yyyy >> mm >> dd;
        std::string ticket;
        if (university == "MIEM") {
            MIEM new_ticket;
            char sex_char;
            if (sex == "man") {
                sex_char = 'M';
            } else {
                sex_char = 'W';
            }
            new_ticket.set_sex(sex_char);
            new_ticket.set_birthday(dd, mm, yyyy);
            new_ticket.set_magic_n();
            ticket = new_ticket.ticket();
        } else if (university == "MGTUU") {
            MGTUU new_ticket;
            char sex_char;
            if (sex == "man") {
                sex_char = 'M';
            }
            else {
                sex_char = 'W';
            }
            new_ticket.set_sex(sex_char);
            new_ticket.set_birthday(dd, mm, yyyy);
            new_ticket.set_magic_n();
            ticket = new_ticket.ticket();
        } else {
            return EXIT_FAILURE;
        }
        if (tf) {
            std::ofstream tofile(tofilename);
            if (!tofile) {
                std::cout << "Input Error" << std::endl;
                return EXIT_FAILURE;
            }
            tofile << "Your ticket is: " << ticket << std::endl;
        } else {
            std::cout << "Your ticket is: " << ticket << std::endl;
        }
    }

    if (!ff) {
        std::string sex{};
        std::string university{};
        std::string ticket;
        int dd, mm, yyyy;
        std::cin >> university >> sex >> yyyy >> mm >> dd;
        if (university == "MIEM") {
            MIEM new_ticket;
            char sex_char;
            if (sex == "man") {
                sex_char = 'M';
            }
            else {
                sex_char = 'W';
            }
            new_ticket.set_sex(sex_char);
            new_ticket.set_birthday(dd, mm, yyyy);
            new_ticket.set_magic_n();
            ticket = new_ticket.ticket();
        } else if (university == "MGTUU") {
            MGTUU new_ticket;
            char sex_char;
            if (sex == "man") {
                sex_char = 'M';
            } else {
                sex_char = 'W';
            }
            new_ticket.set_sex(sex_char);
            new_ticket.set_birthday(dd, mm, yyyy);
            new_ticket.set_magic_n();
            ticket = new_ticket.ticket();
        } else {
            std::cout << "Input the university" << std::endl;
            return EXIT_FAILURE;
        }
        if (tf) {
            std::ofstream tofile(tofilename);
            if (!tofile) {
                std::cout << "Input Error" << std::endl;
                return EXIT_FAILURE;
            }
            tofile << "Your ticket: " << ticket << std::endl;
        } else {
            std::cout << "Your ticket: " << ticket << std::endl;
        }
    }
}
