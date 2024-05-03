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

//конструктор с параметрами 
Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
//добавление объекта, на который указывает указатель p в вектор 
void Vector::Add()
{
	Object* p;
	//выбор из объектов двух возможных классов 
	cout << "\n1.Person\n2.Student\nВведите номер выбранного варианта >> ";
	int y;
	cin >> y; cout << "\n";
	if (y == 1)//добавление объекта класса Car
	{
		Person* a = new Person();
		a->Input();//ввод значений атрибутов 
		p = a;

		if (cur < size)
		{
			beg[cur] = p;//добавление в вектор cur++;
			cur++;
		}
	}
	else if (y == 2) //добавление объекта класса Lorry
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
//просмотр вектора
void Vector::Show()
{
	if (cur == 0) cout << "Пустой" << endl;
	Object** p = beg;//указатель на указатель типа Object 
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();//вызов метода Show() (позднее связывание) 
		p++;//передвигаем указатель на следующий объект
	}

}
void Vector::Find(int tmp) {
	Object** p = beg;
	for (int i = 0; i < cur; i++) {
		if (i == tmp - 1) { (*p)->Show(); }
		p++;
	}
}

//операция, которая возвращает размер вектора 
int Vector::operator ()()
{
	return cur;
}
//удаление элемента из вектора, память не освобождается! 
void Vector::Del()
{
	if (cur == 0)return;//пустой 
	cur--;
}