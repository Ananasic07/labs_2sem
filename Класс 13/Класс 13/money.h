#pragma once
#include<iostream>

using namespace std;

class Money {

	long int rub;
	int kop;

public:

	Money() { rub = 0; kop = 0; };
	Money(long int r, int k) { rub = r; kop = k; };
	Money(const Money& temp) { rub = temp.rub; kop = temp.kop; };
	~Money() {};

	int getRub() { return rub; };
	int getKop() { return kop; };

	void setRub(long int r) { rub = r; }
	void setKop(int k) { kop = k; }

	Money& operator =(const Money&);
	Money& operator ++();
	Money operator / (const Money&);
	Money operator / (const int&);
	Money operator ++(int);
	Money& operator -(const Money&);
	Money operator +(const Money&);
	bool operator > (const Money&);
	bool operator < (const Money&);
	bool operator ==(Money&);

	friend istream& operator >>(istream& in, Money& temp);
	friend ostream& operator <<(ostream& out, const Money& temp);
};