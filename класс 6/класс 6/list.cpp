#include <iostream>
#include "list.h"
using namespace std;


bool Iterator::operator==(const Iterator& it) const {
	return elem == it.elem;
}

bool Iterator::operator!=(const Iterator& it) {
	return elem != it.elem;
}

List ::List():data(nullptr), size(0){}

List::List(int size) {
	this->size = size;
	data = new int[size];
	beg.elem = &data[0];
	end.elem = &data[size-1];
}

//конструктор копирования
List::List(const List& a) 
{
	size = a.size;
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = a.data[i];
	}
	beg = a.beg;
	end = a.end;
}
//деструктор
List::~List()
{
	delete[]data;
	data = 0;

}
//операция присваивания 
List& List::operator=(const List& a)
{
	if (this == &a)return *this;
	size = a.size;
	if (data != 0) delete[]data;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	beg = a.beg;
	end = a.end;
	return *this;
}
//операция доступа по индексу 
int& List::operator[](int index) {
	if (index >= 0 && index < size) {
		return data[index];
	}
	cout << "Ошибка!";
	return data[index];
}

//операция сложения списков
List List::operator+(const List& a) {
	List result(size + a.size);
	int i = 0;
	for (; i < size; i++) {
		result[i] = data[i];
	}
	for (int j = 0; j < a.size; j++,i++) {
		result[i] = data[i] + a.data[j];
	}
	return result;
}

//оператор сдвига итераторов влево на n элементов
void Iterator::operator-(int n) {
	for (int i = n; i>0; i--) {
		--elem;
	}
}

//функция ввода элементов списка
void List::input() {
	cout << "Введите размер списка: ";
	cin >> size;
	data = new int[size];
	cout << "Введите элементы списка: ";
	for (int i = 0; i < size; i++) {
		cin >> data[i];
	}
}

//операции для ввода-выода 
ostream& operator<<(ostream& fout, const List& other) {
	for (int i = 0; i < other.size; i++) {
		fout << other.data[i];
	}
	fout << endl;
	return fout;
}

istream& operator>>(istream& fin, List& other) {
	for (int i = 0; i < other.size; i++) {
		fin >> other.data[i];
	}
	return fin;
}