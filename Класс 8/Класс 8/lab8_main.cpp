// Класс 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include "dialog.h"
#include "vector.h"
#include "student.h"
using namespace std;

int main()
{
    system("chcp 1251");
    cout << "m: создать группу" << endl;
    cout << "+: добавить элемент в группу" << endl;
    cout << "-: удалить элемент из группы" << endl;
    cout << "s: вывести информацию об элементах группы" << endl;
    cout << "?: вывести информацию об элементе группы" << endl;
    cout << "q: конец работы" << endl;
    Dialog D;
    D.Execute();
    return 0;
}