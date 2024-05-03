#include<iostream>
#include"vector.h"
#include "student.h"
Vector::~Vector(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}

Vector::Vector() {
	beg = nullptr;
	cur = 0;
	size = 0;
}

//����������� � ����������� 
Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
//���������� �������, �� ������� ��������� ��������� p � ������ 
void Vector::Add()
{
	Object* p;
	//����� �� �������� ���� ��������� ������� 
	cout << "\n1.Person\n2.Student\n������� ����� ���������� �������� >> ";
	int y;
	cin >> y; cout << "\n";
	if (y == 1)//���������� ������� ������ Car
	{
		Person* a = new Person();
		a->Input();//���� �������� ��������� 
		p = a;

		if (cur < size)
		{
			beg[cur] = p;//���������� � ������ cur++;
			cur++;
		}
	}
	else if (y == 2) //���������� ������� ������ Lorry
	{
		Student* b = new Student();
		b->Input();
		p = b;
		if (cur < size)
		{
			beg[cur] = p;
			cur++;
		}
	}
	else return;

}
//�������� �������
void Vector::Show()
{
	if (cur == 0) cout << "������" << endl;
	Object** p = beg;//��������� �� ��������� ���� Object 
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();//����� ������ Show() (������� ����������) 
		p++;//����������� ��������� �� ��������� ������
	}

}
void Vector::Find(int tmp) {
	Object** p = beg;
	for (int i = 0; i < cur; i++) {
		if (i == tmp - 1) { (*p)->Show(); }
		p++;
	}
}

//��������, ������� ���������� ������ ������� 
int Vector::operator ()()
{
	return cur;
}
//�������� �������� �� �������, ������ �� �������������! 
void Vector::Del()
{
	if (cur == 0)return;//������ 
	cur--;
}