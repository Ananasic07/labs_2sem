#pragma once
#include <iostream> 
using namespace std;
class Money
{
	long roubles;
	int penny;
public:
	//Конструкторы + деструктор
	Money() { roubles = 0; penny = 0; };
	Money(long r, int p) { roubles = r; penny = p; }
	Money(const  Money& t) { roubles = t.roubles; penny = t.penny; }
	~Money() {};
	//Селекторы и модификаторы
	int getRoubles() { return roubles; }
	int getPenny() { return penny; }
	void setRoubles(long r) { roubles = r; }
	void setPenny(int p) { penny = p; }

	//перегруженные операции 
	bool operator>(const Money& p);
	bool operator<(const Money& p);
	//Money& operator=(const Money&);
	Money& operator++(); //префиксная операция
	Money operator++(int);//постфиксная операция 
	Money operator+(const Money&);

	//глобальные функции ввода-вывода
	friend istream& operator>>(istream& in, Money& t);
	friend ostream& operator<<(ostream& out, const Money& t);
};
