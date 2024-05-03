// Класс 7).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "list.h"
#include "money.h"

using namespace std;

int main() {
	system("chcp 1251");
	int size;
	cout << "Введите размер списка: " << endl;
	cin >> size;
	List<int> A(size);
	cout << "Список A: "; A.show();
	int k;
	cout << "Введите индекс: " << endl;
	cin >> k;
	cout << "A[k] элемент: " << A[k] << endl;
	cout << "Размер списка A: " << A() << endl;
	cout << endl;
	cout << "Введите размер списка: " << endl;
	cin >> size;
	List<int> B(size);
	cout << "Список B: "; B.show();
	cout << "Размер списка B: " << B() << endl;
	cout << endl;

	List<int> C(size);
	C = A + B;
	cout << "Список C = A + B: "; C.show();
	cout << "Размер списка C: " << C() << endl;
	cout << endl;

	cout << "Тестирование класса Money:" << endl;

	Money t1;
	cin >> t1;
	cout << "Первый экземпляр класса Money:" << endl;
	cout << t1; cout << endl;

	Money t2;
	cin >> t2;
	cout << "Второй экзепляр класса Money: " << endl;
	cout << t2; cout << endl;

	cout << "Проверка их на неравенство: " << endl;
	t1 != t2;

	return 0;
}
