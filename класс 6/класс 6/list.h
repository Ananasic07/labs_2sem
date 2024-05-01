#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Iterator
{
	friend class List;//дружественный класс 
private:
	int* elem;//указатель на элемент типа int
public:
	Iterator() { elem = nullptr; }//конструктор без параметров
	Iterator(const Iterator& it) { elem = it.elem; }//конструктор копирования
	//перегруженная операция разыменования
	int& operator *() const { return*elem; }
	//перегруженные операции сравнения
	bool operator==(const Iterator& it) const; //{ return elem == it.elem; }
	bool operator!=(const Iterator& it);// { return elem != it.elem; };
	//перегруженная операция инкремент(переход к следующему элементу)
	void operator++() { ++elem; }
	//перегруженная операция декремент(переход к предыдущему элементу) 
	void operator--() { --elem; }
	//сдвиг итератора влево на n элементов
	void operator-(int n);
};

class List
{
private:
	int size;//размер вектора
	int* data;//укзатель на динамический массив значений вектора
	Iterator beg, end;
public:
	List();
	List(int size);
	//конструктор с параметрами 
	List(const List& a);
	//деструктор
	~List();
	//оператор присваивания
	List& operator=(const List& a);
	//операция доступа по индексу
	int& operator[](int index);
	//
	List& operator+(const int a) {};
	//операция сложения списков
	List operator+ (const List& a);
	//операция приведения типа к int(возвращает размер списка)
	operator int() const { return size; }
	//Функция ввода элементво списка
	void input();
	//перегруженные операции ввода-вывода
	friend ostream& operator<<(ostream& out, const List& a);
	friend istream& operator>>(istream& in, List& a);
	Iterator first() { return beg; }
	Iterator last() { return end; }

};