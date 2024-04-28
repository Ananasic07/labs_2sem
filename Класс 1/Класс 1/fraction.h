#pragma once
struct fraction
{
	double first;
	int second;
	void Init(double, int); //метод для инициализации полей 
	void Read(); //метод для чтения значений полей
	void Show(); //метод для вывода значений полей 
	double Summa(); // метод для вычисления начисленной суммы за данное количество дней
};