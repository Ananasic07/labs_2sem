#include "Money.h" 
#include <iostream> 
using namespace std;

/*//перегрузка операции присваивания 
Money& Money::operator=(const Money& t)
{
	//проверка на самоприсваивание 
	if (&t == this) return *this;
	roubles = t.roubles;
	penny = t.penny;
	return *this;
}
*/

bool Money::operator>(const Money& p) {
	if (roubles == p.roubles) {
		return penny > p.penny;
	}
	return roubles > p.roubles ;
}

bool Money::operator<(const Money& p) {
	if (roubles == p.roubles) {
		return  penny < p.penny;
	}
	return roubles < p.roubles;
}


//перегрузка префиксной операции инкремент 
Money& Money::operator++()
{
	int temp = roubles * 100 + penny;
	temp++;
	roubles = temp / 100;
	penny = temp % 100;
	return *this;
}

//перегрузка постфиксной операции инкремент 
Money Money::operator ++(int)
{
	int temp = roubles * 100 + penny;
	temp++;
	Money t(roubles, penny);
	roubles = temp / 100;
	penny = temp % 100;
	return t;
}

//перегрузка бинарной операции сложения 
Money Money::operator+(const Money& t)
{
	int temp1 = roubles * 100 + penny;
	int temp2 = t.roubles * 100 + t.penny;
	Money p;
	p.roubles = (temp1 + temp2) / 100;
	p.penny = (temp1 + temp2) % 100;
	return p;
}

//перегрузка глобальной функции-операции ввода 
istream& operator>>(istream& in, Money& t)
{
	cout << "Roubles: "; in >> t.roubles;
	cout << "Penny: "; in >> t.penny;
	return in;
}

//перегрузка глобальной функции-операции вывода 
ostream& operator<<(ostream& out, const Money& t)
{
	return (out << t.roubles << "," << t.penny);
}