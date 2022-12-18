#ifndef AKGENERATOR
#define AKGENERATOR
#include <iostream>
#include <string>
#include <map>
#include "structs.h"

using std::string;

class AKGenerator {
// Абстрактный класс-генератор

    public:
        string Generate(Student st);
        // Генерирует номер студенческого билета
    
    protected:
        map<string, string> codes;
        // Словарь, в котором хранятся все уже сгенерированные коды
        // для встретившихся дат рождений. Нужно для обеспечения уникальности

        int PseudoMax(int maxValue, int dobavka);
        // Возвращает псевдослучайное число в диапазоне от 0 до maxValue
        // Для генерации случайных чисел используется добавка при инициализации 
        // генератора псевдослучайных чисел. 

        string completeString(string s, int n);
        // Дополняет строку нулями слева. Используется при добавлении в номер билета
        // коротких месяцев или дней рождения, а также при получении маленьких 
        // псевдослучайных чисел.

        virtual string sex(int n) const = 0;
        // Возвращает код для пола в номер студенческого билета
        // Каждый класс-потомок должен переопределить этот метод по-своему

        virtual string Pseudo(string date) = 0;
        // Возвращает псевдослучайное число для добавления в номер студ.билета
        // Каждый класс-потомок должен переопределить этот метод по-своему

        virtual void MakeBetter(string*) {};
        // Поскольку для некоторых сгенерированных номеров студ.билетов невозможно
        // правильным образом подобрать последний символ, метод изменяет сгенерированную 
        // псевдослучайную часть номера так, чтобы последний символ можно было подобрать
        // Каждый класс-потомок должен переопределить метод, поскольку алгоритм формирования
        // последнего символа у каждого университета свой

        virtual void Finalize(string*) = 0;
        // Добавляет последний символ в номер студ.билета

        int Calc(string);
        // Вычисляет сумму произведений цифры на ее порядковый номер
        

};

class  AKMIEMGen: public virtual AKGenerator {
// Класс-генератор для МИЭМ

    public:
    protected:
        string sex(int n) const override;
        string Pseudo(string) override;
        void Finalize(string*) override;
        void MakeBetter(string*) override;
};

class  AKMGTUUGen: public virtual AKGenerator {
// Класс-генератор для МГТУУ

    public:
    protected:
    string sex(int n) const override;
    string Pseudo(string) override;
    void Finalize(string*) override;
    void MakeBetter(string*) override;
};
#endif
