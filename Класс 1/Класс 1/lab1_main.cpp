// Класс 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "fraction.h"
using namespace std;

fraction make_fraction(double F, int S)
{
    fraction t;//создали временную переменную
    t.Init(F, S);//инициализировали поля переменной t с помощью параметров функции 
    return t;//вернули значение переменной t
}

int main() {
    system("chcp 1251");
    fraction A;
    A.Init(1, 1);
    A.Read();
    A.Show();
    cout << "Сумма за данное количество дней: ";
    cout << A.Summa();

    return 0;
}

