#include <string>
#include <list>
#include "structs.h"

using std::string;
using namespace std;

string CheckFlags(int argc, char** argv, Flags* f);
// Разбирает параметры из командной строки
// Если что-то не так, возвращает текст ошибки
// Если все хорошо, то возвращает пустую строку
// Флаги пишет в f

sList GetStudent(Flags f);
// Получет список студентов
// Или из файла, или из консоли. В зависимости от параметров