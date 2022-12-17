#include <iostream>
#include "uni.h"
#include <random>
#include <time.h>

using std::string;

string random_miem(int date_of_birth) {
    std::mt19937 gen(date_of_birth + time(0)); 
    std::uniform_int_distribution<> values(10000, 99999);
    return std::to_string(values(gen));
}

string random_mgtuu(int date_of_birth) {
    std::mt19937 gen(date_of_birth + time(0)); 
    std::uniform_int_distribution<> values(1000, 9999);
    return std::to_string(values(gen));
}

string id_gen(int sex, int dd, int mm, int yy) {
    string id = "111111111";
    id[0] = '0' + sex;
    for (int i = 4; i >= 1; --i) {
        id[i] = '0' + yy % 10;
        yy /= 10;
    }
    id[5] = '0' + mm / 10;
    id[6] = '0' + mm % 10;
    id[7] = '0' + dd / 10;
    id[8] = '0' + dd % 10;

    int date_of_birth = yy * 10000 + mm * 100 + dd;
    if (sex == 1 || sex == 2)
        id += random_mgtuu(date_of_birth);
    else
        id += random_miem(date_of_birth);

    return id;
}


string MIEM::gen(string sex, int dd, int mm, int yy){
    int sexx = (sex == "man" ? 8 : 4);
    string id = id_gen(sexx, dd, mm, yy);

    int sum = 0;
    for (int i = 0; i < id.size(); ++i) {
        sum += (i + 1) * (id[i] - '0');
    }
    int i = 0;
    for (; i <= 9; ++i) {
        if ((sum + 14 * i) % 11 == 0){break;}
    }
    id += std::to_string(i);


    return id;
}

string MGTUU::gen(string sex, int dd, int mm, int yy){
    int sexx = (sex == "man" ? 2 : 1);
    string id = id_gen(sexx, dd, mm, yy);

    int sum = 0;
    for (int i = 0; i < id.size(); ++i) {
        sum += (i + 1) * (id[i] - '0');
    }
    int i = 0;
    for (; i <= 9; ++i) {
        if ((sum + 14 * i) % 10 == 0){break;}
    }
    id += std::to_string(i);

    return id;
}

University* template_pattern_student_number_generator::generator(std::string name) {
    if (name == "miem") {
        MIEM* uni = new MIEM;
        return uni;
    }

    MGTUU* uni = new MGTUU;
    return uni;
}