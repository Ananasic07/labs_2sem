#include <iostream>
#include "fraction.h"
using namespace std;

//реализация метода для инициализации полей структуры 
void fraction::Init(double F, int S)
{
	first = F; second = S;
}

//реализация метода для чтения значений полей структуры
void fraction::Read()
{
	cout << "Введите оклад: "; cin >> first;
	cout << "Введите количество отработанных дней: "; cin >> second;
}

//реализация метода для вывода значений полей структуры 
void fraction::Show()
{
	cout << "Оклад: " << first << " ; ";
	cout << "Количество отработанных дней: " << second;
	cout << "\n";
}

//метод ля вычисления суммы за данное количество рабочих дней
double fraction::Summa()
{
	//return (first * second) / 30;
	return first / 30 * second;
}
