// интерполяционный поиск.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int size, int find) {
    int left = 0; //Левая граница области поиска
    int right = size-1; //Правая граница области поиска

    //цикл поиска по массиву, пока искомое не найдено
    //или пределы поиска еще существуют
    while (left <= right && find >= arr[left] && find <= arr[right]) {
        if (left == right) {
            if (arr[left] == find) {
                return left;
            }
            return -1;
        }
        //текущая позиция массива, с которым сравнивается искомое
        int x = left + (((double)(right - left) / (arr[right] - arr[left])) * (find - arr[left]));
        if (arr[x] == find) {
            return x;
        }
        else if (arr[x] < find) {
            left = x + 1;
        }
        else {
            right = x - 1;
        }
    }
    return -1;
}

int main()
{
    system("chcp 1251");
    int arr[]={ 1,2,5,67,89,100,145,160,1090 }; //массив значений 
    int size = 9;
    int find = 145;
    int index = interpolationSearch(arr, size, find);
    if (index != -1) {
        cout << find << " Найдено на элементе " << index << endl;
    }
    else {
        cout << "Значение не найдено(" << endl;
    }
    return 0;
}

