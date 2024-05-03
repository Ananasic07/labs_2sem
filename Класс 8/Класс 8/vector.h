#pragma once
#include "person.h"
#include "student.h"
#include "event.h"
#include<iostream>
class Vector
{
public:
	Vector(int);//����������� � �����������
public:
	~Vector(void);//����������
	Vector();
	void Add();//���������� �������� � ������ 
	void Del();
	void Show();
	void Find(int);
	int operator()();//������ �������
	void HandleEvent(const TEvent& y) {
		if (y.what == evMessage) {
			Object** p = this->beg;
			for (int i = 0; i < this->cur; i++) {
				(*p)->HandleEvent(y);
				p++;
			}
		}
	};
protected:
	Object** beg;//��������� �� ������ ������� ������� 
	int size;//������
	int cur;//������� �������
};