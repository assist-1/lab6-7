#include "objects.cpp"
#include <cstring>
#include <string>
#include <fstream>

int main(int argc, char* argv[]) {
    char* input_path;
    char* output_path;
    bool flags[2] = {false,  // --fromfile
                     false}; // --tofile
    int input_path_index;
    int output_path_index;
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            if (strcmp("--fromfile", argv[i]) == 0) {
                input_path = argv[i + 1];
                flags[0] = true;
                ++i;
            }
            if (strcmp("--tofile", argv[i]) == 0) {
                output_path = argv[i + 1];
                flags[1] = true;
                ++i;
            }
        }
    }
    
    std::ifstream input(input_path);
    std::ofstream output(output_path);

    if (!input && flags[0]) {
        std::cerr << "Wrong input file name. Try again." << std::endl;
        return EXIT_FAILURE;
    }

    int uni;
    if (flags[0]) input >> uni;
    else {
        std::cout << "Select university (0 for miem, 1 for mgtu): ";
        std::cin >> uni;
    }
    if (uni != 0 && uni != 1) {
        std::cerr << "Wrong university name. Try again." << std::endl;
        return EXIT_FAILURE;
    }

    int sex;
    if (flags[0]) input >> sex;
    else {
        std::cout << "Enter your sex (0 for women, 1 for men): ";
        std::cin >> sex;
    }
    if (sex != 0 && sex != 1) {
        std::cerr << "Wrong sex choice. Try again." << std::endl;
        return EXIT_FAILURE;
    }

    int year;
    if (flags[0]) input >> year;
    else {
        std::cout << "Enter your year of birth: ";
        std::cin >> year;
    }
    if (year < 1950 || year > 2010) {
        std::cerr << "Wrong year choice. Try again." << std::endl;
        return EXIT_FAILURE;
    }

    int month;
    if (flags[0]) input >> month;
    else {
        std::cout << "Enter your month of birth: ";
        std::cin >> month;

    }
    if (month < 1 || month > 12) {
        std::cerr << "Wrong month choice. Try again." << std::endl;
        return EXIT_FAILURE;
    }

    int day;
    if (flags[0]) input >> day;
    else {
        std::cout << "Enter your day of birth: ";
        std::cin >> day;
    }
    if ((day < 1 || day > 31) || (month == 2 && day > 29)) {
        std::cerr << "Wrong day choice. Try again." << std::endl;
        return EXIT_FAILURE;
    }
    
    if (flags[0]) input.close();

    if (uni == 0) { 
        Miem id(sex, year, month, day);
        if (flags[1]) {
        output << id.generator();
        output.close();
        }
        else std::cout << id.generator() << std::endl;
    } else {
        Mgtu id(sex, year, month, day);
        if (flags[1]) {
        output << id.generator();
        output.close();
        }
        else std::cout << id.generator() << std::endl; 
    }
    
    return EXIT_SUCCESS;
}
