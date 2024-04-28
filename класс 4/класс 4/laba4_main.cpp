// класс 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Time.h"
#include "Triad.h"
using namespace std;

int main() {
	system("chcp 1251");
	Time time;
	cin >> time;
	cout << time << endl;
	int n;
	cout << "На сколько секунд увеличить ";
	cin >> n;
	time.addSec(n);
	cout << "После увеличения на " << n << " секунд : ";
	cout << time<<endl;

	cout << "На сколько минут увеличить ";
	cin >> n;
	time.addMin(n);
	cout << "После увеличения на " << n << " минут : ";
	cout << time<<endl;
	cout << endl;
	cout << "переопределение методов увеличения на 1" << endl;
	Triad f;
	cin >> f;
	f.addFirst();
	f.addSecond();
	f.addThird();
	cout << f;

	return 0;
}