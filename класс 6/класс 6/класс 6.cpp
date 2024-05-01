// класс 6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "list.h"
using namespace std;

int main()
{
    system("chcp 1251");
    List list1, list2;
    list1.input();
    list2.input();
    cout << "List1: " << list1 << endl;
    cout << "List2: " << list2 << endl;
    List list3 = list1 + list2;
    cout << "list1 + list2 : " << list3 << endl;
    cout << "Вывод размера list3: " << static_cast<int>(list3) << endl;
    cout << "Вывод элемента list3 с индексом 2 : " << list3[2] << endl;

    /*cout << *(list3.first()) << endl;
	Iterator it = list3.first();
	++it;
	++it;
	cout << "*it: " << *it << endl;
	for (it = list3.first(); it != list3.last(); ++it) {
		cout << *it << "\t";
	}
	cout << endl;
	cout << list3[3] << endl;
	cout << "Enter index for it: ";
	int n;
	cin >> n;
	it = list3.first();
	it -= n;
    cout << *it << endl;
    */

    /*Iterator it = list3.first();
    while (it != list3.last()) {
        cout << *it << " ";
        ++it;
        cout << endl;
        *it = list3 - 2;
        cout << "Вывод элемента, находящегося на 2 позиции влево от начала list3: " << *it << endl;
    }
    */
    return 0;
}

