#include <iostream>
#include "fraction.h"
using namespace std;

//���������� ������ ��� ������������� ����� ��������� 
void fraction::Init(double F, int S)
{
	first = F; second = S;
}

//���������� ������ ��� ������ �������� ����� ���������
void fraction::Read()
{
	cout << "������� �����: "; cin >> first;
	cout << "������� ���������� ������������ ����: "; cin >> second;
}

//���������� ������ ��� ������ �������� ����� ��������� 
void fraction::Show()
{
	cout << "�����: " << first << " ; ";
	cout << "���������� ������������ ����: " << second;
	cout << "\n";
}

//����� �� ���������� ����� �� ������ ���������� ������� ����
double fraction::Summa()
{
	//return (first * second) / 30;
	return first / 30 * second;
}
