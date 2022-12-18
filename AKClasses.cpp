#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include "structs.h"
#include "AKClasses.h"

using std::string;
using namespace std;

int AKGenerator::PseudoMax(int maxValue, int dobavka) {
    int r;
    int t = (int)time(nullptr);
    srand(t + dobavka); // Добавляем к времени добавку, чтобы получать разные последовательности
    r = rand();

    r = ((double)r) / RAND_MAX * maxValue; // Изменяем r чтобы попасть в диапазон

    return r;
}

string AKGenerator::completeString(string s, int n) {
    int k = s.length();
    if (k < n) {
        // Добавляем нужное число нулей
        for (int i = 0; i < n - k; i++) {
            s = "0" + s;
        }
    }
    return s;
}

string AKGenerator::Generate(Student st) {
    string id = "";
    id += this->sex(st.sex);
    id += this->completeString(to_string(st.year), 4);
    id += this->completeString(to_string(st.month), 2);
    id += this->completeString(to_string(st.day), 2);

    string date = to_string(st.year) + to_string(st.month) + to_string(st.day);

    string code; // Строка со случайным числом
    
    map <string,string> :: iterator it;
    it = this->codes.find(date); // Ищем дату рождения в словаре
    
    if (it == this->codes.end()) {
        // Если не нашли, генерим новый код
        code = this->Pseudo(date);
        id += code; // Добавляем его в студ.билет
        this->codes[date] = code; // Добавляем в словарь
        this->MakeBetter(&id); // Решаем проблему заполняемости последнего символа
    } else {
        // Если нашли, берем то, что уже было
        code = it->second;
        id += code;
        this->MakeBetter(&id);
        // Улучшать все равно приходится, поскольку в зависимости от пола
        // в МГТУУ один и тот же код со случайным числом может не подходить
        // для генерации последнего символа
    }

    this->Finalize(&id); // Добавляем последний символ

    return id;
}

int AKGenerator::Calc(string s) {
    int n = 0;
    for (int i = 0; i < s.length(); i++) {
        n += (i + 1) * (s[i] - '0');
    }
    return n;
}

string AKMIEMGen::sex(int n) const {
    return to_string(4*(n+1));
}

string AKMIEMGen::Pseudo(string date) {
    int r;
    int d = stoi(date);
    r = this->PseudoMax(99999, d);
    // Если получили короткое число, дополняем до 5 символов нулями
    return this->completeString(to_string(r), 5);
}

string AKMGTUUGen::sex(int n) const {
    return to_string(n+1);
}

string AKMGTUUGen::Pseudo(string date) {
    int r;
    int d = stoi(date);
    r = this->PseudoMax(9999, d);
    // Если получили короткое число, дополняем до 4 символов нулями
    return this->completeString(to_string(r), 4);
}

void AKMIEMGen::Finalize(string* s) {

    int n = this->Calc(*s);
    // Перебираем все цифры, чтобы найти ту, которая подойдет под
    // правило заполнения последнего символа. 
    for (int i = 0; i < 10; i++) {
        if ((n + 15*i) % 11 == 0) {
            (*s) += i + '0';
            break;
        }
    }
}

void AKMIEMGen::MakeBetter(string* s) {
    int n = this->Calc(*s);
    int len = (*s).length();
    // Последний символ будет стоять на 15-й позиции.
    // При его подборе мы фактически решаем уравнение в целых числах
    // X + 15*C = 0 (mod 11), где X - выражение от первых 14 символов,
    // С - нужный нам последний символ. Видно, что если С получится равным 10, 
    // то мы не сможем добавить это как один символ. 10 получается, если Х дает
    // остаток 4 при делении на 11. В этом случае поменяем последний символ кода
    // на 1 и тогда остаток будет другим.

    if (n % 11 == 4) {
        if ((*s)[len-1] == '9') {
            (*s)[len-1] = '8';
        } else {
            (*s)[len-1] = '0' + ((*s)[len-1] - '0' + 1);
        }
    }

}

void AKMGTUUGen::MakeBetter(string* s) {
    int n = this->Calc(*s);
    int len = (*s).length();
    // Последний символ будет стоять на 14-й позиции.
    // При его подборе мы фактически решаем уравнение в целых числах
    // X + 14*C = 0 (mod 10), где X - выражение от первых 13 символов,
    // С - нужный нам последний символ. Видно, что если Х - нечетное, 
    // то подобрать С не получится. В этом случае поменяем последний символ кода
    // на 1 и тогда поскольку последний символ стоит на нечетной позиции, то
    // новый Х станет четным.

    if (n % 2 == 1) {
        if ((*s)[len-1] == '9') {
            (*s)[len-1] = '8';
        } else {
            (*s)[len-1] = '0' + ((*s)[len-1] - '0' + 1);
        }
    }

}

void AKMGTUUGen::Finalize(string* s) {
    int n = this->Calc(*s);
    // Перебираем все цифры, чтобы найти ту, которая подойдет под
    // правило заполнения последнего символа. 

    for (int i = 0; i < 10; i++) {
        if ((n + 14*i) % 10 == 0) {
            (*s) += i + '0';
            break;
        }
    }

}
