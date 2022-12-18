#include <iostream>
#include <string>
#include <fstream>
#include "geni.h"
using std::string;

int main (int argc, char** argv) {
    if (argc == 1) {
        cerr << "Nothing was read\n";
        return EXIT_FAILURE;
    }
    else if(argc==4) {
        cerr << "You must write adress to your file\n";
        return EXIT_FAILURE;
    }
    else {
        string flag = argv[1];

        if ((argc==5) && (flag == "--fromfile") && (string(argv[3]) == "--tofile")) {
            std::ifstream f(argv[2]);
            string st;
            if (f.is_open())
            {
                while (getline(f, st)) {}
            }
            else {cerr << "Wrong adress to file\n"; return EXIT_FAILURE;}
            f.close();
            if ((st[1] == 'i') && (st[2]== 'e')) {
                if (st.length()==22) {
                    MIEM n;
                    string y = "";
                    for (int i = 12; i < 16; ++i) y = y + st[i];
                    int year = stoi(y);
                    string month = "";
                    for (int i = 17; i < 19; ++i) month = month + st[i];
                    string day = "";
                    for (int i = 20; i < 22; ++i) day = day + st[i];
                    std::ofstream fout("TOFILE67.txt");
                    string s = n.generator("female", year, month, day);
                    for (int z = 0; z < s.length(); ++z)   fout << s[z];
                    fout.close();
                }
                else if (st.length()==20) {
                    MIEM n;
                    string y = "";
                    for (int i = 10; i < 14; ++i) y = y + st[i];
                    int year = stoi(y);
                    string month = "";
                    for (int i = 15; i < 17; ++i) month = month + st[i];
                    string day = "";
                    for (int i = 18; i < 20; ++i) day = day + st[i];
                    std::ofstream fout("TOFILE67.txt");
                    string s = n.generator("male", year, month, day);
                    for (int z = 0; z < s.length(); ++z)   fout << s[z];
                    fout.close();
                }
            }
            else if ((st[1] == 'g') && (st[2]== 't')) {
                if (st.length()==23) {
                    MGTUU n;
                    string y = "";
                    for (int i = 13; i < 17; ++i) y = y + st[i];
                    int year = stoi(y);
                    string month = "";
                    for (int i = 18; i < 20; ++i) month = month + st[i];
                    string day = "";
                    for (int i = 21; i < 23; ++i) day = day + st[i];
                    std::ofstream fout("TOFILE67.txt");
                    string s = n.generator("female", year, month, day);
                    for (int z = 0; z < s.length(); ++z)   fout << s[z];
                    fout.close();
                }
                else if (st.length()==21) {
                    MGTUU n;
                    string y = "";
                    for (int i = 11; i < 15; ++i) y = y + st[i];
                    int year = stoi(y);
                    string month = "";
                    for (int i = 16; i < 18; ++i) month = month + st[i];
                    string day = "";
                    for (int i = 19; i < 21; ++i) day = day + st[i];
                    std::ofstream fout("TOFILE67.txt");
                    string s = n.generator("male", year, month, day);
                    for (int z = 0; z < s.length(); ++z)   fout << s[z];
                    fout.close();
                }
            }
        }

        else if (argc==3) {
            if (flag == "--fromfile") {
                string adr = argv[2];

                std::ifstream f(adr);
                string st;
                if (f.is_open())
                {
                    while (getline(f, st)) {}
                }
                else {cerr << "Wrong adress to file\n"; return EXIT_FAILURE;}
                f.close();
                if ((st[1] == 'i') && (st[2]== 'e')) {
                    if (st.length()==22) {
                        MIEM n;
                        string y = "";
                        for (int i = 12; i < 16; ++i) y = y + st[i];
                        int year = stoi(y);
                        string month = "";
                        for (int i = 17; i < 19; ++i) month = month + st[i];
                        string day = "";
                        for (int i = 20; i < 22; ++i) day = day + st[i];
                        cout << n.generator("female", year, month, day) << endl;
                    }
                    else if (st.length()==20) {
                        MIEM n;
                        string y = "";
                        for (int i = 10; i < 14; ++i) y = y + st[i];
                        int year = stoi(y);
                        string month = "";
                        for (int i = 15; i < 17; ++i) month = month + st[i];
                        string day = "";
                        for (int i = 18; i < 20; ++i) day = day + st[i];
                        cout << n.generator("male", year, month, day) << endl;
                    }
                }
                else if ((st[1] == 'g') && (st[2]== 't')) {
                    if (st.length()==23) {
                        MGTUU n;
                        string y = "";
                        for (int i = 13; i < 17; ++i) y = y + st[i];
                        int year = stoi(y);
                        string month = "";
                        for (int i = 18; i < 20; ++i) month = month + st[i];
                        string day = "";
                        for (int i = 21; i < 23; ++i) day = day + st[i];
                        cout << n.generator("female", year, month, day) << endl;
                    }
                    else if (st.length()==21) {
                        MGTUU n;
                        string y = "";
                        for (int i = 11; i < 15; ++i) y = y + st[i];
                        int year = stoi(y);
                        string month = "";
                        for (int i = 16; i < 18; ++i) month = month + st[i];
                        string day = "";
                        for (int i = 19; i < 21; ++i) day = day + st[i];
                        cout << n.generator("male", year, month, day) << endl;
                    }
                }
            }
            else if (flag == "--tofile") {
                string adr = argv[2];
                cout << "WARNING: If you wrote something different from adress to file,\nthis something will become the name of your new file.txt. \nIt was your decision.\n";
                std::ofstream fout(adr);
                MIEM n;
                MGTUU p;
                string s = n.generator("female", 2003, "23", "03") + "\n" + p.generator("male", 2002, "02", "12");
                for (int z = 0; z < s.length(); ++z)   fout << s[z];
                fout.close();
            }
            else if ((argv[1] != "--fromfile") && (argv[1] != "--tofile")) {cerr << "What do you mean by writing that instead of FLAG? 0_o\n"; return EXIT_FAILURE;}
        }
    }
    return EXIT_SUCCESS;
}