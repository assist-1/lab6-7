#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "checking.h"
#include "structs.h"
#include "AKClasses.h"

using namespace std;

int main(int argc, char** argv) {
    Flags f; 
    // Опции из командной строки, переведенные в формат структуры
    sList sl; 
    // Список студентов

    if (CheckFlags(argc, argv, &f) != "") {
        cout << CheckFlags(argc, argv, &f) << endl;  
        return -1; 
        // Если нашли ошибки в параметрах, заканчиваем
    }
    
    sl = GetStudent(f); // Получаем список студентов

    if (f.toFile) {
        ofstream fl(f.toFileName);
        if (!fl) {
            cout << "can't open file" << endl;
            return 1;
        }
        for (Student const& s : sl) {

            if (s.university == 1) { 
                // В зависимости от университета используем разные классы
                AKMIEMGen *m = new AKMIEMGen;
                // Генерируем студенческий и пишем в файл
                fl << m->Generate(s) << endl; 
            } else {
                AKMGTUUGen *m = new AKMGTUUGen;
                // Генерируем студенческий и пишем в файл
                fl << m->Generate(s) << endl; 
            }
        }
    } else {
        for (Student const& s : sl) {

            if (s.university == 1) {
                AKMIEMGen *m = new AKMIEMGen;
                // Генерируем студенческий и пишем в консоль
                cout << m->Generate(s) << endl; 
            } else {
                AKMGTUUGen *m = new AKMGTUUGen;
                // Генерируем студенческий и пишем в консоль
                cout << m->Generate(s) << endl; 
            }

    }

    }

}