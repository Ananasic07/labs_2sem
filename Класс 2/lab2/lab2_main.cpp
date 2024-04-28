// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Car.h" 
#include <iostream> 
#include <string> 
using namespace std;


//функция для возврата объекта как результата 
Car makeCar()
{
	string b;
	string m;
	int c;
	cout << "Enter brand: ";
	cin >> b;
	cout << "Enter model: ";
	cin >> m;
	cout << "Enter price: ";
	cin >> c;
	Car s(b, m, c);
	return s;
}

//функция для передачи объекта как параметра 
void printCar(Car s)
{
	s.show();
}

int main()
{
	system("chcp 1251");
	//конструктор без параметров 
	Car t1;
	t1.show();

	//коструктор с параметрами 
	Car t2("Lada ", "Vesta", 1500000);
	t2.show();

	//конструктор копирования 
	Car t3 = t2;
	t3.setBrand("Mersedes");
	t3.setModel("Benz");
	t3.setPrice(5000000);

	//конструктор копирования 
	printCar(t3);

	//конструктор копирования 
	Car t4 = makeCar();
	t4.show();
}
