#include "Functions.h"

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cerr << "Enter the '--tofile' or '--fromfile'";
        return 0;
    }
    if ((strcmp(argv[1], "--tofile") == 1 && strcmp(argv[1], "--fromfile") == 1) || argc > 3) {
        std::cerr << "Wrong command, try again";
        return 0;
    }
    if ((strcmp(argv[1], "--tofile") == 0) && argc == 2) {
        std::ofstream output;
        output.open("laba6-7_output.txt");
        if (output.is_open()) {
            int n;
            std::cout << "Введите количество студенческих, которые хотите сгенерировать: ";
            std::cin >> n;
            for (int i = 0; i < n; i++) {
                output << "Введите ВУЗ: ";
                std::string s;
                std::cin >> s;
                output << "Введите пол, дату рождения через пробел: ";
                std::string a;
                int y, m, d;
                std::cin >> a >> y >> m >> d;
                Generator templategenerator;
                std::string B_1 = templategenerator.generator(s)->generate(a, y, m, d);
                output << "Сгенерированный студенческий: " << B_1 << std::endl;
            }
        }
        output.close();
    }
    if ((strcmp(argv[1], "--fromfile") == 0) && argc == 2) {
        std::ifstream input;
        input.open("laba6-7_input.txt");
        if (input.is_open()) {
            int n;
            std::cout << "Введите количество студенческих, которые хотите сгенерировать: ";
            input >> n;
            for (int i = 0; i < n; i++) {
                std::cout << "Введите ВУЗ: ";
                std::string s;
                input >> s;
                std::cout << "Введите пол, дату рождения через пробел: ";
                std::string a;
                int y, m, d;
                input >> a >> y >> m >> d;
                Generator templategenerator;
                std::string B_1 = templategenerator.generator(s)->generate(a, y, m, d);
                std::cout << "Сгенерированный студенческий: " << B_1 << std::endl;
            }
        }
        input.close();
    }
    if ((strcmp(argv[1], "--fromfile") == 0) && (strcmp(argv[2], "--tofile") == 0)&& argc == 2) {
        std::ifstream input;
        std::ofstream output;
        input.open("labaz6-7_input.txt");
        output.open("laba6-7_output.txt");
        if (input.is_open() && output.is_open()) {
            int n;
            output << "Введите количество студенческих, которые хотите сгенерировать: ";
            input >> n;
            for (int i = 0; i < n; i++) {
                output << "Введите ВУЗ: ";
                std::string s;
                input >> s;
                output << "Введите пол, дату рождения через пробел: ";
                std::string a;
                int y, m, d;
                input >> a >> y >> m >> d;
                Generator templategenerator;
                std::string B_1 = templategenerator.generator(s)->generate(a, y, m, d);
                output << "Сгенерированный студенческий: " << B_1 << std::endl;
            }
        }
        input.close();
        output.close();
    }
    else{
        std::cerr << "Wrong command, try again";
    }
}
