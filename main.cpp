#include "header.h"
#include <fstream>
#include <cstring>
int main (int argc, char *argv[]) {
    string vuz,sex, year, month,day, end;
    if(argc == 1){
        cout<<"please enter your vuz(MIEM/MGTU), sex(man/woman), year, month(01-12) and day(01-31)" << endl;
        again:
        if(cin >> vuz >> sex >> year >> month >> day){
            if(!proverkaSex(sex)){
                cerr << "Error enter, please write <man> or <woman>" << endl;
                goto again;
            }
            if(!proverkaYear(year)){
                cerr << "Error enter, please write the correct year"<< endl;
                goto again;
            }
            if(!proverkaMMDD(day,month,year)){
                cerr << "Error enter, please write the correct month and day"<< endl;
                goto again;
            }
            if(vuz == "MIEM") {
                MIEM a;
                string abc = Go(&a, sex, year, month, day);
                cout << abc << endl;
            } else if(vuz == "MGTU"){
                MGTU b;
                string abc = Go(&b, sex, year, month, day);
                cout << abc << endl;
            } else
                cout << "Error enter, please write the correct MIEM or MGTU"<< endl;
            cout << "Do you want again? (yes/no)" << endl;
            cin >> end;
            if(end == "yes")
                goto again;
            else
                exit(1);
        } else
            cerr << "please enter correctly, for example:\nMIEM man 2004 27 02"<< endl;
    } else if(argc == 3){
        if(strcmp(argv[1], "--fromfile") == 0){
            std::ifstream file(argv[2]);
            while(!file.eof()){
                while(file >> vuz >> sex >> year >> month >> day){
                    if(!proverkaSex(sex)){
                        cerr << "Error enter, please write <man> or <woman>" << endl;
                        continue;
                    }
                    if(!proverkaYear(year)){
                        cerr << "Error enter, please write the correct year"<< endl;
                        continue;
                    }
                    if(!proverkaMMDD(day,month,year)){
                        cerr << "Error enter, please write the correct month and day"<< endl;
                        continue;
                    }
                    if(vuz == "MIEM") {
                        MIEM a;
                        string abc = Go(&a, sex, year, month, day);
                        cout << abc << endl;
                    } else if(vuz == "MGTU"){
                        MGTU b;
                        string abc = Go(&b, sex, year, month, day);
                        cout << abc << endl;
                    } else
                        cout << "Error enter, please write the correct MIEM or MGTU"<< endl;
                }
            }
        } if(strcmp(argv[1], "--tofile") == 0){
            std::ofstream file(argv[2]);
            cout<<"please enter your vuz(MIEM/MGTU), sex(man/woman), year, month(01-12) and day(01-31)" << endl;
            again1:
            if(cin >> vuz >> sex >> year >> month >> day){
                if(!proverkaSex(sex)){
                    cerr << "Error enter, please write <man> or <woman>" << endl;
                    goto again1;
                }
                if(!proverkaYear(year)){
                    cerr << "Error enter, please write the correct year"<< endl;
                    goto again1;
                }
                if(!proverkaMMDD(day,month,year)){
                    cerr << "Error enter, please write the correct month and day"<< endl;
                    goto again1;
                }
                if(vuz == "MIEM") {
                    MIEM a;
                    string abc = Go(&a, sex, year, month, day);
                    file << abc << endl;
                } else if(vuz == "MGTU"){
                    MGTU b;
                    string abc = Go(&b, sex, year, month, day);
                    file << abc << endl;
                } else
                    cout << "Error enter, please write the correct MIEM or MGTU"<< endl;
                cout << "Do you want again? (yes/no)" << endl;
                cin >> end;
                if(end == "yes")
                    goto again1;
                else
                    exit(1);
            }
        }
    } else if (argc == 5){
        if(strcmp(argv[1], "--fromfile") == 0 && strcmp(argv[3], "--tofile") == 0){
            std::ifstream in(argv[2]);
            std::ofstream out(argv[4]);
            while(!in.eof()){
                while(in >> vuz >> sex >> year >> month >> day){
                    if(!proverkaSex(sex)){
                        cerr << "Error enter, please write <man> or <woman>" << endl;
                        continue;
                    }
                    if(!proverkaYear(year)){
                        cerr << "Error enter, please write the correct year"<< endl;
                        continue;
                    }
                    if(!proverkaMMDD(day,month,year)){
                        cerr << "Error enter, please write the correct month and day"<< endl;
                        continue;
                    }
                    if(vuz == "MIEM") {
                        MIEM a;
                        string abc = Go(&a, sex, year, month, day);
                        out << abc << endl;
                    } else if(vuz == "MGTU"){
                        MGTU b;
                        string abc = Go(&b, sex, year, month, day);
                        out << abc << endl;
                    } else
                        cerr << "Error enter, please write the correct MIEM or MGTU"<< endl;
                }
            }
        }
    } else
        cerr << "please enter correct flag, for example: --fromfile 1.txt --tofile 2.txt";
    return 0;
}
