#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "classes.cpp"
#include "function.h"
#include <map>

using std::string;

int main(int argc, char** argv) {
    if (check_flag (argc, argv) == 0)
        return 0;
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    std::map <string, string> dictionary;
    int n;
    string VUZ, sex, year, month, day;
    if (argc == 3 || argc == 2 && (strcmp(argv[1], "--fromfile") == 0))
        fin >> n;
    else{
        cout << "Enter the number of students";
        std::cin >> n;
    }
    invokation gen;
    for (int i = 0; i < n; ++i){
        if (argc == 3 || argc == 2 && (strcmp(argv[1], "--fromfile") == 0))
            fin >> VUZ >> sex >> year >> month >> day;
        else{
            cout << "Enter: VUZ, sex and date(year, month, day):\n";
            std::cin >> VUZ >> sex >> year >> month >> day;
        }
        string& sex_ref = sex, year_ref = year, month_ref = month, day_ref = day;
        string a = gen.generator(VUZ)->generate(sex_ref,year_ref, month_ref, day_ref);
        string date = year + month + day;
        while (need_reset(dictionary, date, a.substr(9, a.size() - 9))){
            a = gen.generator(VUZ)->generate(sex_ref,year_ref, month_ref, day_ref);
        }
        if (argc == 3 || argc == 2 && (strcmp(argv[1], "--tofile") == 0))
            fout << "\n\n" << a << "\n\n\n";
        else
            cout  << "\n\n" << a << "\n\n\n";
    }
}
