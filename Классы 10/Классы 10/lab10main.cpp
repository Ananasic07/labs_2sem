#include<iostream>
#include <fstream>
#include"Money.h"
#include"file.h"
using namespace std;
int main() {
	system("chcp 1251 > Null");
	srand(time(0));
	int n;
	do {
		cout << "Введите количество элементов: ";
		cin >> n;
	} while (n < 1);

	cout << endl;
	error(write(n));
	bool flag = true;
	while (flag) {
		int current_action = choosing();
		int tmp_1;
		double tmp_2;

		Money p_2;
		switch (current_action) {
		case 1:
			cout << "Текущее содержимое файла" << endl;
			error(print_file());
			cout << endl;
			break;
		case 2:
			do {
				cout << "Введите количество элементов: ";
				cin >> tmp_1;
			} while (tmp_1 < 1);
			error(write(tmp_1));
			break;
		case 3:
			cout << "Введите значение, значения больше которого будут удалены: " << endl;
			cin >> p_2;
			error(remove(p_2));
			break;
		case 4:
			cout << "Уменьшим все записи в 2 раза: " << endl;
			error(decrease(2));
			cout << endl;
			break;
			
		case 5:
			int N;
			do {
				cout << "Введите номер, после которого необходимо ввести K элементов" << endl;
				cin >> N;
			} while (N < 1);

			do {
				cout << "Введите количество элементов, которые необходимо добавить: " << endl;
				cin >> tmp_1;
			} while (tmp_1 < 1);
			error(add_el(N, tmp_1));
			break;
		default:
			flag = false;
			break;
		}
	}
	return 0;
}