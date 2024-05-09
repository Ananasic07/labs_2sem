#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Money {
	int rub;
	long kop;
public:
	Money() { // конструктор по умолчанию
		this->rub = 0;
		this->kop = 0;
	}
	Money(int rub, long kop) { // конструктор с параметрами
		this->rub = rub;
		this->kop = kop;
	}
	Money(const Money& other) { // конструктор копирования
		this->rub = other.rub;
		this->kop = other.kop;
	}
	~Money() { } // деструктор
	Money operator/(const int& x) {
		return (Money(this->rub / x, this->kop));
	}

	Money& operator++() { // префиксная операция прибавления
		Money x(this->rub++, this->kop);
		return x;
	}
	Money operator ++(int) { // постфиксная операция прибавления
		Money x(this->rub, this->kop++);
		return x;
	}
	bool operator<(const Money& para) { // оператор сравнения
		if (this->rub < para.rub) return true;
		else if (this->rub == para.rub) {
			if (this->kop < para.kop) return true;
			else return false;
		}
		else return false;
	}
	bool operator>(const Money& para) { // оператор сравнения
		if (this->rub < para.rub) return false;
		else if (this->rub == para.rub) {
			if (this->kop < para.kop) return false;
			else return true;
		}
		else return true;
	}
	void operator=(const Money& para) { // оператор присваивания
		this->rub = para.rub;
		this->kop = para.kop;
	}
	friend ostream& operator <<(ostream& stream, const Money& p) {
		stream << p.rub << " , " << p.kop;
		return stream;
	}
	friend istream& operator >>(istream& stream, Money& p) {
		cout << "Введите число rub и kop через пробел: ";
		stream >> p.rub >> p.kop;
		return stream;
	}
	friend fstream& operator<<(fstream& stream, Money& para) {
		stream << para.rub << endl << para.kop << endl;
		return stream;
	}
	friend fstream& operator>>(fstream& stream, Money& para) {
		stream >> para.rub;
		stream >> para.kop;
		return stream;
	}
};
