#include<iostream>
#include"money.h"
using namespace std;

bool Money::operator == (Money& m) {
	if (rub == m.rub && kop == m.kop) return 1;
	else return 0;
}

Money& Money::operator - (const Money& a) {
	Money* tmp = new Money;
	tmp->setRub(this->rub); tmp->setKop(this->kop);
	tmp->rub -= a.rub;
	tmp->kop -= a.kop;
	return  *tmp;
}

Money Money::operator / (const Money& m) {
	int tmp1 = rub * 100 + kop;
	int tmp2 = m.rub * 100 + m.kop;
	Money p;
	p.rub = (tmp1 + tmp2) / 100;
	p.kop = (tmp1 + tmp2) % 100;
	return p;
}
Money Money::operator / (const int& i) {
	Money p;
	p.rub = rub / i;
	p.kop = kop / i;
	return p;
}

bool Money::operator <(const Money& m) {
	if (rub < m.rub) return true;
	if (rub == m.rub && kop < m.kop) return true;
	return false;
}

bool Money::operator >(const Money& m) {
	if (rub > m.rub) return true;
	if (rub == m.rub && kop > m.kop) return true;
	return false;
}

Money& Money::operator =(const Money& temp) {
	if (&temp == this) {
		return *this;
	}
	rub = temp.rub;
	kop = temp.kop;
	return *this;
}

Money& Money::operator ++() {
	int temp = rub * 100 + kop;
	temp++;
	kop = temp / 100;
	kop = temp % 100;
	return *this;
}

Money Money::operator ++(int) {
	int temp = rub * 100 + kop;
	temp++;
	Money ex1(rub, kop);
	kop = temp / 100;
	kop = temp % 100;
	return ex1;
}

Money Money::operator +(const Money& temp) {
	int ex1 = rub * 100 + kop;
	int ex2 = temp.rub * 100 + temp.kop;
	Money temp2;
	temp2.rub = (ex1 + ex2) / 100;
	temp2.kop = (ex1 + ex2) % 60;
	return temp2;
}

istream& operator >>(istream& in, Money& temp) {
	cout << "rubles: ";
	in >> temp.rub;
	cout << "kopecks: ";
	in >> temp.kop;
	return in;
}

ostream& operator <<(ostream& out, const Money& temp) {
	return (out << temp.rub << "," << temp.kop);
}