#pragma once
#include <iostream> 
using namespace std;
class Money
{
	long roubles;
	int penny;
public:
	//������������ + ����������
	Money() { roubles = 0; penny = 0; };
	Money(long r, int p) { roubles = r; penny = p; }
	Money(const  Money& t) { roubles = t.roubles; penny = t.penny; }
	~Money() {};
	//��������� � ������������
	int getRoubles() { return roubles; }
	int getPenny() { return penny; }
	void setRoubles(long r) { roubles = r; }
	void setPenny(int p) { penny = p; }

	//������������� �������� 
	bool operator>(const Money& p);
	bool operator<(const Money& p);
	//Money& operator=(const Money&);
	Money& operator++(); //���������� ��������
	Money operator++(int);//����������� �������� 
	Money operator+(const Money&);

	//���������� ������� �����-������
	friend istream& operator>>(istream& in, Money& t);
	friend ostream& operator<<(ostream& out, const Money& t);
};
