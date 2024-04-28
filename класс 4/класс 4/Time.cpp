#include <iostream>
#include "Time.h"

using namespace std;

Time::Time(void) :Triad() {
	hour = 0;
	min = 0;
	sec = 0;
}

Time::~Time(void) {}

Time::Time(int H, int M, int S) {
	hour = H;
	min = M;
	sec = S;
}

Time::Time(const Time& time) {
	hour = time.hour;
	sec = time.sec;
	min = time.min;
}
/*
void Time::addFirst() {
	first++;
	if (first > 23) {
		first = 0;
	}
}

void Time::addSecond() {
	second++;
	if (second > 59) {
		second = 0;
		addFirst();
	}
}

void Time::addThird() {
	third++;
	if (third > 59) {
		third = 0;
		addSecond();
	}
}
*/

void Time::addMin(int n) {
	min+=n;
	while (min > 59) {
		min -= 60;
		hour++;
	}
}

void Time::addSec(int n) {
	sec+=n;
	while (sec > 59) {
		sec -= 60;
		min++;
	}
}

void Time::setHour(int H) {
	hour = H;
}
void Time::setMin(int M) {
	min = M;
}
void Time::setSec(int S) {
	sec = S;
}

Time& Time::operator =(const Time& time) {
	if (&time == this) {
		return *this;
	}
	first = time.first;
	second = time.second;
	third = time.third;
	hour = time.hour;
	min = time.min;
	sec = time.sec;
	return *this;
}

istream& operator >>(istream& in, Time& time) {
	/*
	cout << "Enter First:";
	in >> time.first;
	cout << "Enter Second:";
	in >> time.second;
	cout << "Enter Third:";
	in >> time.third;
	*/
	cout << "Enter Hour:";
	in >> time.hour;
	cout << "Enter Minutes:";
	in >> time.min;
	cout << "Enter Seconds:";
	in >> time.sec;
	return in;
}

ostream& operator <<(ostream& out, const Time& time) {
	/*
	out << "\nFirst: " << time.first;
	out << "\nSecond: " << time.second;
	out << "\nThird: " << time.third;
	*/
	out << "\nHour: " << time.hour;
	out << "\nMinutes: " << time.min;
	out << "\nSeconds: " << time.sec;
	return out;
}