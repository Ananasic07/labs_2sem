#pragma once
#include <iostream> 
#include <string> 
using namespace std;

class Car {
	string brand;
	string model;
	int price;
public:
	Car();//����������� ��� ����������
	Car(string, string, int);//����������� � ����������� 
	Car(const Car&);//����������� �����������
	~Car();//����������

	string getBrand();//��������
	void setBrand(string);//����������� 

	string getModel();//��������
	void setModel(string); //�����������

	int getPrice();//��������
	void setPrice(int); //����������� 

	void show();//�������� ���������
};
