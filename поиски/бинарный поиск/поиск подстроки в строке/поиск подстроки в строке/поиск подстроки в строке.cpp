// поиск подстроки в строке.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>;
using namespace std;

int main() {
	system("chcp 1251");
	string str = "abcababa";
	string substr = "ba";

	int lenstr = str.length();
	int lensubstr = substr.length();

	int foundIndex = -1;

	for (int i = 0; i<=lenstr-lensubstr; i++) {
		bool flag = true;
		for (int j = 0; j < lensubstr; j++) {
			if (str[i + j] != substr[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			foundIndex = i;
			break;
		}
	}
	if (foundIndex != -1) {
		cout << "Подстрока найдена на позиции " << foundIndex << endl;
	}
	else {
		cout << "Подстрока не найдена (" << endl;
	}
	return 0;
}
