#include "Money.h"

Money::Money(void)
{
	rubles = 0;
	kop = 0;
}

Money::Money(long r, int k)
{
	rubles = r;
	kop = k;
}

Money::Money(const Money& t)
{
	rubles = t.rubles;
	kop = t.kop;
}

Money& Money::operator=(const Money& t)
{
	rubles = t.rubles;
	kop = t.kop;
	return *this;
}

ostream& operator<<(ostream& out, const Money& t)
{
	out << t.rubles << " , " << t.kop;
	return out;
}

istream& operator>>(istream& in, Money& t)
{
	cout << "Введите рубли: "; in >> t.rubles;
	cout << "Введите копейки: "; in >> t.kop;
	return in;
}

void Money::operator!=(const Money& t)
{
	if (rubles == t.rubles && kop == t.kop) cout << "Равны" << endl;
	else cout << "Не равны" << endl;
}