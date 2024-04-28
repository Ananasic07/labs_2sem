#pragma once
#include <iostream> 
#include <string> 
using namespace std;

class Car {
	string brand;
	string model;
	int price;
public:
	Car();//конструктор без параметров
	Car(string, string, int);//конструктор с параметрами 
	Car(const Car&);//конструктор копирования
	~Car();//деструктор

	string getBrand();//селектор
	void setBrand(string);//модификатор 

	string getModel();//селектор
	void setModel(string); //модификатор

	int getPrice();//селектор
	void setPrice(int); //модификатор 

	void show();//просмотр атрибутов
};
