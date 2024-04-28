#pragma once
#include <iostream>
#include "Triad.h"

using namespace std;

class Time :
	public Triad {
public:
	Time(void);
public:
	~Time(void);
	Time(int, int, int);
	Time(const Time&);
	void Show();

	int getHour() { return hour; }
	int getMin() { return min; }
	int getSec() { return sec; }

	void increaseHour();
	void increaseMin();
	void increaseSec();

	void increaseBySec(int n);
	void increaseByMin(int n);

	void setHour(int);
	void setMin(int);
	void setSec(int);

	Time& operator =(const Time&);

	friend istream& operator >>(istream& in, Time& time);
	friend ostream& operator <<(ostream& out, const Time& time);

protected:
	int hour, min, sec;
};