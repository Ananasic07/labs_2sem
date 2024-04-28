#pragma once
#include <iostream>
#include "Object.h"

using namespace std;

class Vector {
public:
	Vector(void);
	Vector(int);
public:
	~Vector(void);
	void Add(Object*); // добавление элемента в вектор
	friend ostream& operator <<(ostream& out, const Vector&);
private:
	Object** ptr; // указатель на первый элемент вектора
	int size, cur; //размер, текущая позиция
};
