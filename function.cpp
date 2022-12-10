#include "header.hpp"

size_t RandomNumber(size_t min, size_t max) {
    std::srand(static_cast<size_t>(std::time(nullptr)));
    static constexpr double devider{1.0 / (RAND_MAX + 1.0)};
    return min + static_cast<size_t>((max - min + 1) * (std::rand() * devider));
}

void read(std::vector <std::string> &studaki_MIEM, std::vector <std::string> &studaki_MGTU) {
    Generator templateGenerator;
    std::string result;
    std::string stroke;
    bool sex;
    size_t year, month, day;
    while (std::cin >> stroke) {
        static int i = 0;
        if (i % 5 == 0) {
            if (stroke == "M") {
                sex = true;
            } else {
                sex = false;
            }
        } else if (i % 5 == 1) {
            year = std::stoi(stroke);
        } else if (i % 5 == 2) {
            month = std::stoi(stroke);
        } else if (i % 5 == 3) {
            day = std::stoi(stroke);
        } else {
            if (stroke == "MIEM") {
                result = templateGenerator.generator(stroke)->generate(sex, year, month, day);
                while (std::find(studaki_MIEM.begin(), studaki_MIEM.end(), result) != studaki_MIEM.end()) {
                    result = templateGenerator.generator(stroke)->generate(sex, year, month, day);
                }
                studaki_MIEM.push_back(result);
            } else if (stroke == "MGTU") {
                result = templateGenerator.generator(stroke)->generate(sex, year, month, day);
                while (std::find(studaki_MGTU.begin(), studaki_MGTU.end(), result) != studaki_MGTU.end()) {
                    result = templateGenerator.generator(stroke)->generate(sex, year, month, day);
                }
                studaki_MGTU.push_back(result);
            }
        }
        ++i;
        i %= 5;
    }
}

void read(std::vector <std::string> &studaki_MIEM, std::vector <std::string> &studaki_MGTU, char *name) {
    std::ifstream file(name);
    std::string stroke;
    Generator templateGenerator;
    std::string result;
    bool sex;
    size_t year, month, day;
    while (file >> stroke) {
        static int i = 0;
        if (i % 5 == 0) {
            if (stroke == "M") {
                sex = true;
            } else {
                sex = false;
            }
        } else if (i % 5 == 1) {
            year = std::stoi(stroke);
        } else if (i % 5 == 2) {
            month = std::stoi(stroke);
        } else if (i % 5 == 3) {
            day = std::stoi(stroke);
        } else {
            if (stroke == "MIEM") {
                result = templateGenerator.generator(stroke)->generate(sex, year, month, day);
                while (std::find(studaki_MIEM.begin(), studaki_MIEM.end(), result) != studaki_MIEM.end()) {
                    result = templateGenerator.generator(stroke)->generate(sex, year, month, day);
                }
                studaki_MIEM.push_back(result);
            } else if (stroke == "MGTU") {
                result = templateGenerator.generator(stroke)->generate(sex, year, month, day);
                while (std::find(studaki_MGTU.begin(), studaki_MGTU.end(), result) != studaki_MGTU.end()) {
                    result = templateGenerator.generator(stroke)->generate(sex, year, month, day);
                }
                studaki_MGTU.push_back(result);
            }
        }
        ++i;
        i %= 5;
    }
    file.close();
}