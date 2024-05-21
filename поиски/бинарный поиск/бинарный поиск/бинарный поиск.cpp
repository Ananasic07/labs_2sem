// бинарный поиск.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int BINsearch(int arr[], int left, int right, int find) {
    bool flag = false;
    //int left = 0; //левая граница множества
    //int right = Size-1; //правая граница множества
    int mid;
    while ((left <= right) && (flag != true)) {
        mid = (left+right) / 2; //вычисление индекса элемента mid
        if (arr[mid] == find) { //сравнивается заданный ключ с элементом mid
            flag = true;
            return mid;
        }
        //если искомое значение элемента множества меньше значения множества с индексом mid,
        //то алгоритм начинает новый поиск в левой половине множества
        if (arr[mid] > find) { 
            right = mid-1;
        }
        //иначе новый поиск ведется в правой половине множества
        else {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    system("chcp 1251");
    int arr[] = { 2, 3, 4, 5, 6, 7, 8 };
    int Size = 7;
    int find = 6;

    int result = BINsearch(arr,0, Size, find);

    if (result == -1) {
        cout << "Элемент не найден" << endl;
    }
    else {
        cout << "Элемент найден в позиции " << result << endl;
    }

    return 0;
}

