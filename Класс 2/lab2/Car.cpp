#include "Car.h" 
#include <iostream> 
#include <string> 
using namespace std;

//����������� ��� ���������� 
Car::Car()
{
	brand = "";
	model = "";
	price = 0;
	cout << "Constructor without parameters " << this << endl;
}

//����������� � ����������� 
Car::Car(string N, string K, int S)
{
	brand = N;
	model = K;
	price = S;
	cout << "Constructor with parameters " << this << endl;
}

//����������� ����������� 
Car::Car(const Car& t)
{
	brand = t.brand;
	model = t.model;
	price = t.price;
	cout << "Copy constructor " << this << endl;
}

//���������� 
Car::~Car()
{
	cout << "Destructor " << this << endl;
}

//���������
string Car::getBrand()
{
	return brand;
}
string Car::getModel()
{
	return model;
}
int Car::getPrice()
{
	return price;
}

//������������
void Car::setBrand(string N)
{
	brand = N;
}
void Car::setModel(string K)
{
	model = K;
}
void Car::setPrice(int S)
{
	price = S;
}

//����� ��� ��������� ��������� 
void Car::show()
{
	cout << "Brand :" << brand << endl;
	cout << "Model :" << model << endl;
	cout << "Price :" << price << endl;
}