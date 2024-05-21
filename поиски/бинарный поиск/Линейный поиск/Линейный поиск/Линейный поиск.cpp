// Линейный поиск.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
using namespace std;

//линейный поиск
int linSearch(int arr[], int Size, int target)
{
	for (int i = 0; i < Size; i++)
	{
		if (arr[i] == target)
			return i;
	}
	return -1;
}

int main() {
    system("chcp 1251");
    int array[] = { 6, 2, 8, 4, 5, 1, 7, 3 };
    int size = 8;
    int target = 1;

    int result = linSearch(array, size, target);

    if (result == -1) {
        cout << "Элемент не найден"<<endl;
    }
    else {
        cout << "Элемент найден в позиции " << result << endl;
    }

    return 0;
}