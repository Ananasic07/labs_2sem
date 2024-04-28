// Естественное слияние.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void merge(int* v, int r, int t) {
    int p = 1; //количество элементов в первой серии
    int k = 1; //количество элементов во второй серии
    int i = 0;
    bool flag = false; //флажок для определения надобности второй серии 

    while (v[i] <= v[i + 1] && i < r - 1) { //счетчик количества элементов 1 серии
        p++;
        i++;
    }
    if (v[i] > v[i + 1] && i < r - 1) {
        i++;
        flag = true;
        while (v[i] <= v[i + 1] && i < r - 1) {
            k++;
            i++;
        }
    }
    int num = i + 1; 
    int* a = new int[p]; //1 серия
    int* b = new int[k]; //2 серия

    for (int i = 0; i < p; i++) {
        a[i] = v[i];
    }

    int g = 0;
    if (flag == true) {
        for (int i = p; i < p + k; i++) { //заполнение 2 серии
            b[g] = v[i];
            g++;
        }
    }
    int j = 0;
    int l = 0;
    if (flag == true) { //проверка на наличие второй надобности слияния
        for (int i = 0; i < num; i++) {
            if ((a[l] < b[j] || j >= k) && l < p) {
                v[i] = a[l];
                l++;
            }
            else 
            if ((a[l] > b[j] || l >= p) && j < k) {
                v[i] = b[j];
                j++;
            }
            else
            if (a[l] == b[j] && j < k && l < p) {
                v[i] = a[l];
                v[i + 1] = b[j];
                l++;
                j++;
                i++;
            }
        }
    }
    delete[] a;
    delete[] b;

}
void mergeSort(int* v, int r, int i) {
    if (i < r) {
        merge(v, r, i); //функция сортировки
        mergeSort(v, r, i + 1); //рекурсия
    }
}


int main()
{
    system("chcp 1251");
    int array[25] = {1,2,3,4,5,5,5,5,5,5,0,0,0,0,0,3,3,3,3,4,5,3,1,1,1};

    cout << "Исходный массив: " << endl;
    for (int i = 0; i < 25; i++) {
        cout << array[i];
    }
    cout << endl;
    mergeSort(array, 25, 0);
    cout << "Отсортированный массив: " << endl;
    for (int i = 0; i < 25; i++) {
        cout << array[i];
    }
}

