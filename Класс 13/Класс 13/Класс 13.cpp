// Класс 13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include"vector.h"
#include"queue.h"
using namespace std;
int main()
{
    system("chcp 1251");
	srand(time(0));

	try {

		vector<Money> v;
		int size;
		cout << "Enter size (vector): "; cin >> size;
		v = makeVector(size);
		cout << "Vector (money): "; printVector(v);

		Money a(average(v), 0);
		v.insert(v.begin(), a);
		cout << "Result: "; printVector(v);

		int elem;
		cout << "Element to delete: "; cin >> elem;
		
		printVector(v);

		cout << "Vector - min Element" << endl;
		minElem(v);
		cout << endl;

		Money mm;
		q que;
		int sizeq;
		cout << "Enter size (queue): "; cin >> sizeq;
		que = makeQueue(sizeq);
		printQueue(que);
		averageQ(que);
		int index;
		cout << "Index: "; cin >> index;
		addQueue(que, mm, index);
		cout << "Add elem: "; printQueue(que);
		cout << endl;

		minElem(que);
		cout << "Result: "; printQueue(que);
		cout << endl;
	}

	catch (int) { cout << "Error" << endl; }

	return 0;

}

