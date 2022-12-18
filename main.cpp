#include "header.h"

int main(int argc, char **argv) {
    std::cout << "Please, in the first line print how many students";
    if (argc < 2 || argc > 5) {
        std::cout << "Incorrect enter! \n";
        return 0;
    }
    std::string univer, sex, year, month, day;
    if (strcmp(argv[1], "--fromfile") == 0 && argc == 3) {
        std::ifstream inp(argv[2]);
        if (!inp.is_open()) {
            return -1;
        }
        int k = 0;
        std::cin >> k;
        generator gen;
        std::map<std::string, std::vector<int>> rnd_num1;
        std::map<std::string, std::vector<int>> rnd_num2;
        while (inp >> univer >> sex >> year >> month >> day and k != 0) {
            if (!check_and_correct(univer, sex, year, month, day)) {
                std::cout << "Wrong information \n";
                return 0;
            }
        }
        if (univer == "MGTU") {
            std::cout << gen.gener(univer)->visual(sex, year, month, day, rnd_num1) << "\n";
        } else if (univer == "MIEM") {
            std::cout << gen.gener(univer)->visual(sex, year, month, day, rnd_num2) << "\n";
        }
        --k;
    } else if (argc >= 2 && strcmp(argv[1], "--tofile") == 0 && argc <= 3) {
        std::ofstream f;
        int k = 0;
        std::cin >> k;
        if (argc == 3) {
            f.open(argv[2]);
        } else if (argc == 2) {
            f.open("output.txt");
        }
        generator templateGenerator;
        std::map<std::string, std::vector<int>> rnd_num1;
        std::map<std::string, std::vector<int>> rnd_num2;
        while (std::cin >> univer >> sex >> year >> month >> day and k != 0) {
            if (!check_and_correct(univer, sex, year, month, day)) {
                std::cout << "Wrong information \n";
                return 0;
            }
        }
        if (univer == "MGTU") {
            std::cout << templateGenerator.gener(univer)->visual(sex, year, month, day, rnd_num1) << "\n";
        } else if (univer == "MIEM") {
            std::cout << templateGenerator.gener(univer)->visual(sex, year, month, day, rnd_num2) << "\n";
        }
        --k;
    } else if (argc >= 3) {
        std::ofstream f;
        if (strcmp(argv[1], "--tofile") == 0) {
            if (strcmp(argv[2], "--fromfile") == 0) {
                f.open("output.txt");
            } else if (strcmp(argv[2], "--fromfile") != 0) {
                f.open(argv[2]);
            }
        } else if (strcmp(argv[1], "--fromfile") == 0) {
            if (strcmp(argv[3], "--tofile") == 0 && argc == 5) {
                f.open(argv[4]);
            } else {
                f.open("output.txt");
            }
        }
        std::ifstream inp(argv[2]);
        if (!inp.is_open()) {
            return -1;
        }
        generator gen;
        std::map<std::string, std::vector<int>> rnd_num1;
        std::map<std::string, std::vector<int>> rnd_num2;
        while (inp >> univer >> sex >> year >> month >> day) {
            if (!check_and_correct(univer, sex, year, month, day)) {
                std::cout << "Wrong information \n";
                return 0;
            }
        }
        if (univer == "MGTU") {
            std::cout << gen.gener(univer)->visual(sex, year, month, day, rnd_num1) << "\n";
        } else if (univer == "MIEM") {
            std::cout << gen.gener(univer)->visual(sex, year, month, day, rnd_num2) << "\n";
        }
    }
    return 0;
}