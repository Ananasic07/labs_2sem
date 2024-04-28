#include <iostream>
#include "Vector.h"

using namespace std;

Vector::Vector() {
	ptr = 0;
	size = 0;
	cur = 0;
}

Vector::~Vector() {
	if (ptr != 0) {
		delete[] ptr;
	}
	ptr = 0;
}

Vector::Vector(int n) {
	ptr = new Object * [n];
	cur = 0;
	size = n;
}

void Vector::Add(Object* p) {
	if (cur < size) {
		ptr[cur] = p;
		cur++;
	}
}
ostream& operator <<(ostream& out, const Vector& v) {
	if (v.size == 0) {
		out << "EMPTY" << endl;
	}
	Object** p = v.ptr; // указатель на указатель типа Object
	for (int i = 0; i < v.cur; i++) {
		(*p)->Show(); // вызов метода  Show() (позднее связыванеие)
		p++; // передвигаем указатель на следующий объект
	}
	return out;
}