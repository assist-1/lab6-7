#include "class.hpp"

int main(int argc, char **argv) {
    if (argc < 2 || argc > 5) {
        std::cerr << "Incorrect enter!" << std::endl;
        return -1;
    }
    std::string university, sex, year, month, day;
    if (strcmp(argv[1], "--tofile") == 0 && strcmp(argv[2], "--fromfile") == -1 && argc < 4) {
        Generator templateGenerator;
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
                    out << templateGenerator.generator(university)->generate(sex, year, month, day, randomNumbers1) << std::endl;
                } else if (university == "MGTU") {
                    out << templateGenerator.generator(university)->generate(sex, year, month, day, randomNumbers2) << std::endl;
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
                    out << templateGenerator.generator(university)->generate(sex, year, month, day, randomNumbers1) << std::endl;
                } else if (university == "MGTU") {
                    out << templateGenerator.generator(university)->generate(sex, year, month, day, randomNumbers2) << std::endl;
                }
            }
        }
    }
    if (strcmp(argv[1], "--fromfile") == 0 && argc == 3) {
        Generator templateGenerator;
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
                std::cout << templateGenerator.generator(university)->generate(sex, year, month, day, randomNumbers1) << std::endl;
            } else if (university == "MGTU") {
                std::cout << templateGenerator.generator(university)->generate(sex, year, month, day, randomNumbers2) << std::endl;
            }
        }
    }
    if (argc >= 3 && ((strcmp(argv[1], "--fromfile") == 0 && strcmp(argv[2], "--tofile") == 0) ||
                      (strcmp(argv[2], "--fromfile") == 0 && strcmp(argv[1], "--tofile") == 0))) {
        Generator templateGenerator;
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
                   vec.push_back(templateGenerator.generator(university)->generate(sex, year, month, day, randomNumbers1));
                } else if (university == "MGTU") {
                    vec.push_back(templateGenerator.generator(university)->generate(sex, year, month, day, randomNumbers2));
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
                    vec.push_back(templateGenerator.generator(university)->generate(sex, year, month, day, randomNumbers1));
                } else if (university == "MGTU") {
                    vec.push_back(templateGenerator.generator(university)->generate(sex, year, month, day, randomNumbers2));
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
