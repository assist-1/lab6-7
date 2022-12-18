#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "uni.h"

using std::cin;
using std::cout;
using std::string;

bool IsLeap(int year){
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

int days(int i, int y) {
    if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
        return 31;
    if (i == 4 || i == 6 || i == 9 || i == 11) 
        return 30;
    return 28;
}

int main(int argc, char ** argv) {

    const char* from_file = "-1"; //> названия файлов для ввода и вывода
    const char* to_file = "-1"; //> названия файлов для ввода и вывода

    if (argc % 2 == 0 || argc > 5) { //> если четное число аргументов, или их больше, чем возможное число
        std::cerr << "Incorrect format for flags";
        return EXIT_FAILURE;
    }
    else if (argc == 3) {
        if (std::strcmp(argv[1], "--fromfile") == 0){
            from_file = argv[2];
        }
        else if (std::strcmp(argv[1], "--tofile") == 0){
            to_file = argv[2];
        }
        else {
            std::cerr << "Incorrect format for flags";
            return EXIT_FAILURE;
        }
    }
    else if (argc == 5) {
        if (std::strcmp(argv[1], "--fromfile") == 0 and std::strcmp(argv[3], "--tofile") == 0){
            from_file = argv[2];
            to_file = argv[4];
        }
        else if (std::strcmp(argv[1], "--tofile") == 0 and std::strcmp(argv[3], "--fromfile") == 0 ){
            from_file = argv[4];
            to_file = argv[2];
        }
        else {
            std::cerr << "Incorrect format for flags";
            return EXIT_FAILURE;
        }
    }

    std::map <int, int> days_in_months;
    for (int i = 1; i <= 12; ++i) {
        days_in_months[i] = days(i, 2022);
    }

    string uni, sex;
    int yy, mm, dd;

    if (strcmp(from_file, "-1") != 0) { //из файла
        std::ifstream fin;
        fin.open(from_file);

        fin >> uni >> sex >> yy >> mm >> dd;
        if (IsLeap(yy)) //если в феврале 29 дней
            days_in_months[2] = 29;

        if (!((uni == "miem" || uni == "mgtuu") && (sex == "man" || sex == "woman")
        && yy >= 0 && (mm <= 12 || mm >= 1) && (dd >= 0 && dd <= days_in_months[mm]))) {
            std::cerr << "Incorrect format";
            return EXIT_FAILURE;
        }
        cout << uni << ' ' << sex << ' ' << yy << ' ' << mm << ' ' << dd <<'\n';

    }
    else { //из консоли
        cout << "-----Please enter the university: miem or mgtuu-----\n";
        cin >> uni;
        if (!(uni == "miem" || uni == "mgtuu")) {
            std::cerr << "Incorrect format for the university";
            return EXIT_FAILURE;
        }

        cout << "-----Please enter your sex: man or woman-----\n";
        cin >> sex;
        if (!(sex == "man" || sex == "woman")) {
            std::cerr << "Incorrect format for the sex";
            return EXIT_FAILURE;
        }

        cout << "-----Enter the year of your birth-----\n";
        cin >> yy;
        if (yy < 0) {
            std::cerr << "Incorrect format for the year";
            return EXIT_FAILURE;
        }
        if (IsLeap(yy))
            days_in_months[2] = 29;

        cout << "-----Enter the month of your birth-----\n";
        cin >> mm;
        if (mm > 12 || mm < 1) {
            std::cerr << "Incorrect format for the month";
            return EXIT_FAILURE;
        }

        cout << "-----Enter the day of your birth-----\n";
        cin >> dd;
        if (dd < 0 || dd > days_in_months[mm]) {
            std::cerr << "Incorrect format for the day";
            return EXIT_FAILURE;
        }
    }
    template_pattern_student_number_generator templateGenerator;
    std::string SB = templateGenerator.generator(uni)->gen(sex, dd, mm, yy);
    
    if (strcmp(to_file, "-1") == 0){ //в консоль
        cout << SB << '\n';
    }
    else { //в файл
        std::ofstream fout;
        fout.open(to_file);
        fout << SB << '\n';
    }
    return 0;
}
