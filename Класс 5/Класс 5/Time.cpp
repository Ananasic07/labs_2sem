#include <iostream>
#include "Time.h"

using namespace std;

Time::Time(void) :Triad() {
	hour = 0;
	min = 0;
	sec = 0;
}

Time::~Time(void) {}
Time::Time(int h, int m, int s) :Triad(first, second, third)
{
	hour = h;
	min = m;
	sec = s;
}

Time::Time(const Time& t)
{
	first = t.first;
	second = t.second;
	third = t.third;
	hour = t.hour;
	min = t.min;
	sec = t.sec;
}

void Time::increaseHour() {
	hour++;
	if (hour > 23) {
		hour = 0;
	}
}

void Time::increaseMin() {
	min++;
	if (min > 59) {
		min = 0;
		increaseHour();
	}
}

void Time::increaseSec() {
	sec++;
	if (sec > 59) {
		sec = 0;
		increaseMin();
	}
}

void Time::increaseBySec(int n) {
	sec += n;
	while (sec > 59) {
		sec -= 60;
		increaseMin();
	}
}

void Time::increaseByMin(int n) {
	min += n;
	while (min > 59) {
		min -= 60;
		increaseHour();
	}
}

// модификаторы
void Time::setHour(int F) {
	first = F;
}
void Time::setMin(int S) {
	second = S;
}
void Time::setSec(int T) {
	third = T;
}



// перегрузка оператора присваивания
Time& Time::operator=(const Time& t)
{
	if (&t == this) return *this;
	first = t.first;
	second = t.second;
	third = t.third;
	Time::hour = t.hour;
	Time::min = t.min;
	Time::sec = t.sec;
	return *this;

}
istream& operator>>(istream& in, Time& t)
{

	cout << "Часы: "; in >> t.hour;
	cout << "Минуты: "; in >> t.min;
	cout << "Секунды: "; in >> t.sec;
	cout << "\n\n";
	return in;
}
ostream& operator<<(ostream& out, const Time& t)
{

	out << "\n" << t.hour << " ч " << t.min << " мин " << t.sec << " сек ";

	out << "\n";
	return out;
}

void Time::Show()
{
	cout << hour << " ч " << min << " мин " << sec << " сек " << endl;
}
