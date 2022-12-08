
#include "header.hpp"


int main(int argc, char **argv) {
    std::srand(static_cast<size_t>(std::time(nullptr)));
    std::vector<std::string> studaki_MIEM = {};
    std::vector<std::string> studaki_MGTU = {};
    if (argc == 1) {
        std::cout << "Enter a value in the format \"gender(M/W)_year_month_day_universe\", where '_' is a space.\n";
        read(studaki_MIEM, studaki_MGTU);
        std::cout << "MIEM" << std::endl;
        for (auto &i: studaki_MIEM) {
            std::cout << i << std::endl;
        }
        std::cout << "MGTU" << std::endl;
        for (auto &i: studaki_MGTU) {
            std::cout << i << std::endl;
        }
    } else if (argc == 3) {
        if (strcmp(argv[1], "--tofile") == 0) {
            std::cout << "Enter a value in the format \"gender(M/W)_year_month_day_universe\", where '_' is a space.\n";
            std::ofstream file(argv[2]);
            read(studaki_MIEM, studaki_MGTU);
            file << "MIEM" << std::endl;
            for (auto &i: studaki_MIEM) {
                file << i << std::endl;
            }
            file << "MGTU" << std::endl;
            for (auto &i: studaki_MGTU) {
                file << i << std::endl;
            }
            file.close();
        } else if (strcmp(argv[1], "--fromfile") == 0) {
            read(studaki_MIEM, studaki_MGTU, argv[2]);
            for (auto &i: studaki_MIEM) {
                std::cout << i << std::endl;
            }
            std::cout << "MGTU" << std::endl;
            for (auto &i: studaki_MGTU) {
                std::cout << i << std::endl;
            }
        }
    } else if (argc == 5) {
        char *to_name;
        char *from_name;
        if (strcmp(argv[1], "--tofile") == 0 && strcmp(argv[3], "--fromfile") == 0) {
            to_name = argv[2];
            from_name = argv[4];
        } else if (strcmp(argv[3], "--tofile") == 0 && strcmp(argv[1], "--fromfile") == 0) {
            to_name = argv[4];
            from_name = argv[2];
        }
        read(studaki_MIEM, studaki_MGTU, from_name);
        std::ofstream file(to_name);
        file << "MIEM" << std::endl;
        for (auto &i: studaki_MIEM) {
            file << i << std::endl;
        }
        file << "MGTU" << std::endl;
        for (auto &i: studaki_MGTU) {
            file << i << std::endl;
        }
        file.close();
    }
    return 0;
}
