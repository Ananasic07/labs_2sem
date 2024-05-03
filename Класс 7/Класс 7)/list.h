#include <iostream>
#pragma once

using namespace std;

template <class T>
class List {
private:
	T size;
	T* array;
public:
	List(T size);
	virtual void show();
	~List();
	int& operator ()();
	List operator +(const List& other);
	T& operator [](int index);
};

template<class T>
List<T>::List(T size) {
	this->size = size;
	array = new T[size];
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 100 + 1;
	}
}
template<class T>
void List<T>::show() {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

template<class T>
List<T>::~List() {}

template<class T>
int& List<T>::operator()() {
	return size;
}

template<class T>
List<T> List<T>::operator+(const List& other) {
	List<T> tmp(size);
	for (int i = 0; i < size; i++) {
		tmp[i] = array[i] + other.array[i];
	}
	delete[]array;
	return tmp;
}

template<class T>
T& List<T>::operator [](int index) {
	if (index >= 0 && index < size) {
		return array[index];
	}
	else {
		cout << "Îøèáêà" << endl;
	}
}
