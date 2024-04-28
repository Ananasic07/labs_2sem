#include "Triad.h"
#include <iostream>

Triad::Triad(void) {
	first = 0;
	second = 0;
	third = 0;
	cout << "Вызван конструктор без параметров для объекта " << this << endl;
}
Triad::~Triad(void) {
	cout << "Вызван деструктор для объекта " << this << endl;
}

Triad::Triad(int F, int S, int T) {
	first = F;
	second = S;
	third = T;
}

Triad::Triad(const Triad& triad) {
	first = triad.first;
	second = triad.second;
	third = triad.third;
}

/*
void Triad::Show() {
	cout << "first = " << first << " second = " << second << " third = " << third << endl;
}
*/
void Triad::increaseFirst() { first++; }
void Triad::increaseSecond() { second++; }
void Triad::increaseThird() { third++; }

void Triad::setFirst(int F) {
	first = F;
}
void Triad::setSecond(int S) {
	second = S;
}
void Triad::setThird(int T) {
	third = T;
}

Triad& Triad::operator =(const Triad& triad) {
	if (&triad == this) {
		return *this;
	}
	first = triad.first;
	second = triad.second;
	third = triad.third;
	return *this;
}

istream& operator >>(istream& in, Triad& T) {
	cout << "\nFirst: "; in >> T.first;
	cout << "\nSecond: "; in >> T.second;
	cout << "\nThird: "; in >> T.third;
	return in;
}

ostream& operator <<(ostream& out, const Triad& T) {
	out << "\nFIRST: " << T.first;
	out << "\nSECOND: " << T.second;
	out << "\nTHIRD: " << T.third;
	return out;

}