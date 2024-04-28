#pragma once
#include <iostream>
#include "Triad.h"

using namespace std;

class Time :
	public Triad {  
public:
	Time(void); //конструктор без параметров
public:
	~Time(void); //деструктор
	Time(int, int, int); //конструктор с параметрами 
	Time(const Time&); //конструктор копирования
	//модификаторы
	int getHour() { return hour; }
	int getMin() { return min; }
	int getSec() { return sec; }
	//селекторы
	void setHour(int);
	void setMin(int);
	void setSec(int);
	//увеличение на 1
	//void addFirst();
	//void addSecond();
	//void addThird();
	//увеличение на мин и сек
	void addSec(int n);
	void addMin(int n);
	//перегрузка операции присваивания
	Time& operator =(const Time&);
	//глобальные операторы-функции ввода-вывода
	friend istream& operator >>(istream& in, Time& time);
	friend ostream& operator <<(ostream& out, const Time& time);
	//атрибуты
protected:
	int hour, min, sec;
};
