#include "class.hpp"

int main(int argc, char **argv) {
    if (argc < 2 || argc > 5) {
        std::cerr << "Incorrect enter!" << std::endl;
        return -1;
    }
    std::string university, sex, year, month, day;
    if (strcmp(argv[1], "--tofile") == 0 && strcmp(argv[2], "--fromfile") == -1 && argc < 4) {
        std::map <std::string, std::vector<int>> randomNumbers1;
        std::map <std::string, std::vector<int>> randomNumbers2;
        if (argc == 2) {
            std::ofstream out("F");
            while (std::cin >> university >> sex >> year >> month >> day) {
                if (!CheckInformation(university, sex, year, month, day)) {
                    std::cerr << "Wrong information, check your enter, please" << std::endl;
                    return -2;
                }
                CorrectInformation(year, month, day);
                if (university == "MIEM") {
                    MIEM *a = new MIEM;
                    out << a->generate(sex, year, month, day, randomNumbers1) << std::endl;
                    delete a;
                } else if (university == "MGTU") {
                    MGTU *b = new MGTU;
                    out << b->generate(sex, year, month, day, randomNumbers2) << std::endl;
                    delete b;
                }
            }
        } else {
            std::ofstream out(argv[2]);
            while (std::cin >> university >> sex >> year >> month >> day) {
                if (!CheckInformation(university, sex, year, month, day)) {
                    std::cerr << "Wrong information, check your enter, please" << std::endl;
                    return -2;
                }
                CorrectInformation(year, month, day);
                if (university == "MIEM") {
                    MIEM *a = new MIEM;
                    out << a->generate(sex, year, month, day, randomNumbers1) << std::endl;
                    delete a;
                } else if (university == "MGTU") {
                    MGTU *b = new MGTU;
                    out << b->generate(sex, year, month, day, randomNumbers2) << std::endl;
                    delete b;
                }
            }
        }
    }
    if (strcmp(argv[1], "--fromfile") == 0 && argc == 3) {
        std::map <std::string, std::vector<int>> randomNumbers1;
        std::map <std::string, std::vector<int>> randomNumbers2;
        std::ifstream in(argv[2]);
        while (in >> university >> sex >> year >> month >> day) {
            if (!CheckInformation(university, sex, year, month, day)) {
                std::cerr << "Wrong information, check your enter, please" << std::endl;
                return -2;
            }
            CorrectInformation(year, month, day);
            if (university == "MIEM") {
                MIEM *a = new MIEM;
                std::cout << a->generate(sex, year, month, day, randomNumbers1) << std::endl;
                delete a;
            } else if (university == "MGTU") {
                MGTU *b = new MGTU;
                std::cout << b->generate(sex, year, month, day, randomNumbers2) << std::endl;
                delete b;
            }
        }
    }
    if (argc >= 3 && ((strcmp(argv[1], "--fromfile") == 0 && strcmp(argv[2], "--tofile") == 0) ||
                      (strcmp(argv[2], "--fromfile") == 0 && strcmp(argv[1], "--tofile") == 0))) {
        std::map <std::string, std::vector<int>> randomNumbers1;
        std::map <std::string, std::vector<int>> randomNumbers2;
        std::vector <std::string> vec;
        if (argc == 3) {
            std::ifstream inOut("F");
            while (inOut >> university >> sex >> year >> month >> day) {
                if (!CheckInformation(university, sex, year, month, day)) {
                    std::cerr << "Wrong information, check your enter, please" << std::endl;
                    return -2;
                }
                CorrectInformation(year, month, day);
                if (university == "MIEM") {
                    MIEM *a = new MIEM;
                    vec.push_back(a->generate(sex, year, month, day, randomNumbers1));
                    delete a;
                } else if (university == "MGTU") {
                    MGTU *b = new MGTU;
                    vec.push_back(b->generate(sex, year, month, day, randomNumbers2));
                    delete b;
                }
            }
        } else {
            std::ifstream inOut(argv[3]);
            while (inOut >> university >> sex >> year >> month >> day) {
                if (!CheckInformation(university, sex, year, month, day)) {
                    std::cerr << "Wrong information, check your enter, please" << std::endl;
                    return -2;
                }
                CorrectInformation(year, month, day);
                if (university == "MIEM") {
                    MIEM *a = new MIEM;
                    vec.push_back(a->generate(sex, year, month, day, randomNumbers1));
                    delete a;
                } else if (university == "MGTU") {
                    MGTU *b = new MGTU;
                    vec.push_back(b->generate(sex, year, month, day, randomNumbers2));
                    delete b;
                }
            }
        }
        if (argc == 4) {
            std::ofstream inOut(argv[3]);
            for (size_t i = 0; i < vec.size(); ++i) {
                inOut << vec[i] << std::endl;
            }
        } else {
            std::ofstream inOut("F");
            for (size_t i = 0; i < vec.size(); ++i) {
                inOut << vec[i] << std::endl;
            }
        }
    }
    return 0;
}
