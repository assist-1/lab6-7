#include "Functions.h"
int summ(std::string s){
    long num = std::stol(s);
    long sum = 0;
    for (int i = 0; i < s.size(); i++){
        sum += (int(s[i]) - 48) * (i+1);
    }
    return num;
}

int last_num(std::string s, int n){
    long su = summ(s);
    for (int i = 0; i < n; i++){
        if ((su + (s.size() +1) * i) % n == 0){
            return i;
        }
    }
    return 0;
}

int Random_Number(int min, int max) {
    int num = min + rand() % (max - min + 1);
    return num;
}

bool prov_den(int y, int m, int d){
    if (y > 2022 || y < 1998 || m > 12 || m < 1 || d < 1 || d > 31){
        return false;
    }
    else if (y % 4 == 0 && y == 2 && d != 29){
        return false;
    }
    else if (y % 4 != 0 && y == 2 && d != 28){
        return false;
    }
    else if ((y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12) && d !=31){
        return false;
    }
    else if (((y == 4 || y == 6 || y == 9 || y == 11) && d !=30)){
        return false;
    }
    else{
        return true;
    }
}
