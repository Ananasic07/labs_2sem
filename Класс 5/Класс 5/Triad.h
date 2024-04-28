#pragma once
#include "Object.h"
#include <iostream>

using namespace std;

class Triad :
	public Object {
public:
	Triad(void);
public:
	virtual ~Triad(void);
	void Show() {} //функция для просмотра атрибутов класса с помощью указателя 
	Triad(int, int, int);
	Triad(const Triad&);

	int getFirst() { return first; }
	int getSecond() { return second; }
	int getThird() { return third; }

	void increaseFirst();
	void increaseSecond();
	void increaseThird();

	void setFirst(int);
	void setSecond(int);
	void setThird(int);

	Triad& operator =(const Triad&);

	friend istream& operator >>(istream& in, Triad& T);
	friend ostream& operator <<(ostream& out, const Triad& T);

protected:
	int first, second, third;
};