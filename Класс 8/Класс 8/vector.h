#pragma once
#include "person.h"
#include "student.h"
#include "event.h"
#include<iostream>
class Vector
{
public:
	Vector(int);//конструктор с параметрами
public:
	~Vector(void);//деструктор
	Vector();
	void Add();//добавление элемента в вектор 
	void Del();
	void Show();
	void Find(int);
	int operator()();//размер вектора
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
	Object** beg;//указатель на первый элемент вектора 
	int size;//размер
	int cur;//текущая позиция
};