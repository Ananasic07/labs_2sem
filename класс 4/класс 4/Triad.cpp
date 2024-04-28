#include <iostream>
#include <fstream>
#include "Triad.h"
using namespace std;
//����������� ��� ���������� 
Triad::Triad(void) {
	first = 0;
	second = 0;
	third = 0;
}
//����������
Triad::~Triad(void) {}
//����������� � �����������
Triad::Triad(int F, int S, int T) {
	first = F;
	second = S;
	third = T;
}
//����������� ����������� 
Triad::Triad(const Triad& triad) {
	first = triad.first;
	second = triad.second;
	third = triad.third;
}
//������������
void Triad::setFirst(int F) {
	first = F;
}

void Triad::setSecond(int S) {
	second = S;
}

void Triad::setThird(int T) {
	third = T;
}

void Triad::addFirst() {
	first++;
}

void Triad::addSecond() {
	second++;
}

void Triad::addThird() {
	third++;
}
//���������� �������� ������������ 
Triad& Triad::operator=(const Triad& T) {
	if (&T == this) return *this;
	first = T.first;
	second = T.second;
	third = T.third;
	return *this;
}
//���������� ������� ��� ������ 
istream& operator>>(istream& in, Triad& T) {
	cout << "Enter first:";
	in >> T.first;
	cout << "Enter second:";
	in >> T.second;
	cout << "Enter third:";
	in >> T.third;
	return in;
}

ostream& operator<<(ostream& out, const Triad& T)
{
	out << "\nfirst: " << T.first;
	out << "\nsecond: " << T.second;
	out << "\nthird: " << T.third;
	out << "\n";
	return out;
}

