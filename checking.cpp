#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "structs.h"

using std::string;
using namespace std;


string CheckFlags(int argc, char** argv, Flags* f) {
// Рутинный разбор всех параметров
// Учитываем, что параметры --fromFile и --toFile могут идти 
// в разном порядке. Если все хорошо, заполняем структуру f
// для более удобного использования дальше.
// Если параметры ошибочные, возвращаем текст ошибки. Иначе пустую строку

    if (argc != 1 && argc != 3 && argc != 5) {
        return "Wrong number of parameters";
    }

    if (argc == 3 && (string)argv[1] != "--fromFile" && (string)argv [1] != "--toFile") {
        return "Not valid flag: " + (string)argv[1];
    }

    if (argc == 5 && (string)argv[3] != "--fromFile" && (string)argv [3] != "--toFile") {
        return "Not valid flag: " + (string)argv[3];
    }

    if (argc == 5 && (string)argv[3] == (string)argv[1]) {
        return "Flag is duplicated: " + (string)argv[3];
    }

    if (argc == 1) {
        (*f).fromFile = false;
        (*f).toFile = false;
    }

    if (argc == 3) {
        if ((string)argv[1] == "--fromFile") {
            (*f).fromFile = true;
            (*f).fromFileName = (string)argv[2];
            (*f).toFile = false;
        }

        if ((string)argv[1] == "--toFile") {
            (*f).toFile = true;
            (*f).toFileName = (string)argv[2];
            (*f).fromFile = false;
        }

    }
    
    if (argc == 5) {
        (*f).fromFile = true;
        (*f).toFile = true;
        if ((string)argv[1] == "--fromFile") {
            (*f).fromFileName = (string)argv[2];
            (*f).toFileName = (string)argv[4];
        }

        if ((string)argv[1] == "--toFile") {
            (*f).fromFileName = (string)argv[4];
            (*f).toFileName = (string)argv[2];
        }

    }

    return "";
}

sList GetStudent(Flags f) {
// Получаем список студентов из файла или из консоли и возвращаем его

    list<Student> sl = {};
    Student s;
    s.day = 0;

    if (f.fromFile) {
        ifstream fl;
        fl.open(f.fromFileName);
        if (!fl) {

            cout << endl << "Could not open file: " << f.fromFileName << endl;
            return sl; // day == 0 in this case
        }
        while (!fl.eof()) {
            // Читаем очередную строку по словам.
            // Если в какой-то момент очередного слова нет,
            // выдаем ошибку и возвращаем текущий список студентов

            string word;
            if (!(fl >> word)) {
                "Wrong file";
                return sl;
            }

            if (word != "man" && word != "woman") {
                cout << "Wrong sex";
                return sl;
            }

            if (word == "man") {
                s.sex = 1;
            } else {
                s.sex = 0;
            }

            if (!(fl >> word)) {
                cout << "Wrong file" << endl;
                return sl;
            }
            
            s.year = stoi(word);

            if (!(fl >> word)) {
                cout << "Wrong file" << endl;
                return sl;
            }
            
            s.month = stoi(word);
            if (s.month < 1 || s.month > 12) {
                cout << "Wrong month" << endl;
                s.day = 0;
                return sl;
            }
            if (!(fl >> word)) {
                cout << "Wrong file" << endl;
                return sl;
            }

            s.day = stoi(word);
            if (!(fl >> word)) {
                cout << "Wrong file" << endl;
                return sl;
            }
            s.university = stoi(word);

            sl.push_back(s); // Если все удачно, добавляем студента в список
        }

    }

    if (!f.fromFile) {
        // Если соответствующего параметра нет, читаем из консоли

        string word;
        cout << "Укажите пол студента" << endl;
        cin >> word;
        if (word == "man") {
            s.sex = 1;
        } else {
            if (word == "woman") {
                s.sex = 0;
            } else {
                cout << "Wrong sex" << endl;
                return sl;
            }
        }
        cout << "Укажите год рождения студента" << endl;
        cin >> word;
        s.year = stoi(word);

        cout << "Укажите месяц рождения студента" << endl;
        cin >> word;
        s.month = stoi(word);

        cout << "Укажите день рождения студента" << endl;
        cin >> word;
        s.day = stoi(word);
        sl.push_back(s);


    }

    return sl;
}