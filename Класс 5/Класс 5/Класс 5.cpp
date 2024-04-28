// Класс 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Time.h"
#include "Object.h"
#include "Triad.h"
#include "Vector.h"
using namespace std;

int main()
{
    system("chcp 1251");

	Time time;
	cin >> time;
	cout << time << endl;
	int n;
	cout << "На сколько секунд увеличить ";
	cin >> n;
	time.increaseBySec(n);
	cout << "После увеличения на " << n << " секунд : ";
	cout << time << endl;

	cout << "На сколько минут увеличить ";
	cin >> n;
	time.increaseByMin(n);
	cout << "После увеличения на " << n << " минут : ";
	cout << time << endl;
	cout << endl;
	cout << "переопределение методов увеличения на 1" << endl;
	Triad f;
	cin >> f;
	f.increaseFirst();
	f.increaseSecond();
	f.increaseThird();
	cout << f<<endl;

	Vector v(5);
	Object* p = &f;
	v.Add(p);
	p = &time;
	v.Add(p);
	cout << v;
	return 0;
}
