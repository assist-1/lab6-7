#include <iostream>
#include <cstring>
#include <ctime>
#include <map>

using std::string;

bool need_reset(std::map<string, string>& base, const string& date, const string& num){
    if (base.find(date) != base.end()){
        for (int i = 0; i < base.size(); i += 5){
            string key = base[date];
            if (key.substr(i, 5) == date.substr(9, 5)){
                return true;
            }
        }
    }
    base[date] = base[date] + num;
    return false;
}

long long sum (int ch){
    long int sum = 0, i = 1;
    while (ch > 0){
        sum = sum + ch % 10 * i;
        ch = ch / 10;
        ++i;
    }
    return sum;
}

int Random(int min, int max) {
    return min + std::rand() % (max - min);
}

bool check_flag (int argc, char** argv){
    if (argc > 3){
        std::cerr << "-----------ERROR. WRONG QUANTITY OF FLAGS-----------\n";
        return false;
    }
    if (argc == 2)
        if (strcmp(argv[1], "--fromfile") != 0 && strcmp(argv[1], "--tofile") != 0){
            std::cerr << "\n\n-----------ERROR. WRONG FLAGS-----------\n\n\n";
            return false;
        }
    if (argc == 3){
        if (strcmp(argv[1], "--fromfile") && strcmp(argv[1], "--tofile")
            || strcmp(argv[2], "--fromfile") && strcmp(argv[2], "--tofile")
            || strcmp(argv[1], argv[2]) == 0){
            std::cerr << "\n\n-----------ERROR. WRONG FLAGS-----------\n\n\n";
            return false;
        }
    }
    return true;
}

bool check_date(const string& year, const string& month, const string& day){
    time_t now;
    time ( &now );
    string time = ctime (&now);
    time.erase(0, 20);
    if (std::stoll(time) - std::stoll(year) > 116 || std::stoll(year) > std::stoll(time)){
        std::cerr << "\n\n\n-------------YEAR IS WRONG-------------\n\n\n";
        return false;
    }
    if (std::stoll(month) > 12 || std::stoll(month) < 1){
        std::cerr << "\n\n\n-------------MONTH IS WRONG-------------\n\n\n";
        return false;
    }
    int a;
    switch (std::stoll(month)) {
        case 1 :
        case 3 :
        case 5 :
        case 7 :
        case 8 :
        case 10 :
        case 12 : {
            a = 31;
            break;
        }
        case 2 : {
            if ((std::stoll(year) - 2004) % 4 == 0) {
                a = 29;
                break;
            } else {
                a = 28;
                break;
            }
        }
        default : {
            a = 30;
            break;
        }
    }
    if (std::stoll(day) > a){
        std::cerr << "\n\n\n-------------DAY IS WRONG-------------\n\n\n";
        return false;
    }
    return true;
}

bool check_sex (const string& sex){
    if (sex != "man" && sex != "woman")
        return false;
    else
        return true;
}