// Многофазная сортировка.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream> //подключение библиотеки для ввода и вывода данных
#include <vector> //подключение библиотеки для использования векторов
using namespace std;
void create_mas(vector<int>& ptr) { // заполнение массива рандомными числами
    for (int i = 0; i < ptr.size(); i++) { //цикл для прохода по элементам вектора ptr
        ptr[i] = rand() % 1000 + 1; // присваивание элементу значения
    }
}
void print(vector<int>& ptr) { // вывод массива
    for (int i = 0; i < ptr.size(); i++) {
        cout << ptr[i] << " "; // вывод элемента
    }
    cout << endl;
}
void fast_sort(vector<int>& vect, int start, int support) { //быстрая сортировка
    if (start < support) {
        int cur = start;
        for (int i = cur; i < support; i++) {
            if (vect[i] <= vect[support]) {
                swap(vect[i], vect[cur++]); // замена элементов
            }
        }
        swap(vect[cur], vect[support]);
        fast_sort(vect, start, cur - 1); // вызов функции с другими границами и ключом в левой стороне
        fast_sort(vect, cur + 1, support); // вызов функции с другими границами и ключом в правой стороне
    }
}
int max_ind(vector < vector <int>>& a, vector <vector<int>>& b, vector <vector<int>>& c, int zero) {
    if (zero == 2) {
        if (a.size() > b.size())
            return 0;
        return 1;
    }
    else if (zero == 1) {
        if (a.size() > c.size())
            return 0;
        return 2;
    }
    else {
        if (b.size() > c.size())
            return 1;
        return 2;
    }
}
int min_ind(vector < vector <int>>& a, vector <vector<int>>& b, vector <vector<int>>& c, int zero) {
    if (zero == 2) {
        if (a.size() <= b.size())
            return 0;
        return 1;
    }
    if (zero == 1) {
        if (a.size() <= c.size())
            return 0;
        return 2;
    }
    else {
        if (b.size() <= c.size())
            return 1;
        return 2;
    }
}
void clear_vector(vector < vector <int>>& vec) { // очищение памяти от двумерного вектора
    for (auto& inner_vec : vec)
        inner_vec.clear();
    vec.clear();
}
void clear_vector(vector < vector < vector <int>>>& vec) { // очищение памяти от трехмерного вектора
    for (auto& innerVec : vec) {
        for (auto& innerInnerVec : innerVec)
            innerInnerVec.clear();
        innerVec.clear();
    }
    vec.clear();
}
vector<int> new_ser(vector <int>& a, vector<int>& b) { // создание новой серии, содержащей две старые серии
    int inda = 0, indb = 0;
    int absize = a.size() + b.size();
    vector<int> temp;
    while (inda + indb != absize) {
        if (inda == a.size())
            temp.push_back(b[indb++]);
        else if (indb == b.size())
            temp.push_back(a[inda++]);
        else {
            if (a[inda] < b[indb])
                temp.push_back(a[inda++]);
            else
                temp.push_back(b[indb++]);
        }
    }
    return temp;
}
//Определяется, какой из переданных векторов (a, b, c) содержит пустой головной элемент
// Возвращается соответствующий индекс : 0, 1 или 2
int empty_ind(vector < vector <int>> a, vector <vector<int>> b, vector <vector<int>> c) { // нахождение пустого головного элемента
    if (a.empty())
        return 0;
    else if (b.empty())
        return 1;
    return 2;
}

//Ищется не пустая последовательность среди переданных векторов (a, b, c).
//Если оба вектора пусты, возвращается головной элемент вектора c, иначе непустой головной элемент из a или b.
vector<int> not_empty_head(vector < vector <int>> a, vector <vector<int>> b, vector <vector<int>> c) { // поиск не пустой последовательности
    if (a.empty() && b.empty())
        return c[0];
    else if (a.empty() && c.empty())
        return b[0];
    return a[0];
}void sort(vector<int>& vect) { // многофазная сортировка
    vector < vector <int> > vect_series;
    int size_ser = 5, cnt = 0; // size_ser - размер серии, cnt - счетчик
    bool flag = true;
    for (int i = 0; i < size_ser; ++i) { // создание 5 серий
        vector <int> temp;
        for (int j = 0; j < size_ser; ++j) // создание 5 серий по 5 элементов
            temp.push_back(vect[i * size_ser + j]);
        vect_series.push_back(temp);
    }
    for (int i = 0; i < size_ser; ++i) // сортировка каждой серии
        fast_sort(vect_series[i], 0, size_ser - 1);
    vector < vector < vector <int>>> stack_series;
    for (int k = 0; k < 2; ++k) { // расфасовка серий
        vector < vector <int>> pointer;
        for (int i = 0 + k; i < 3; ++i)
            pointer.push_back(vect_series[cnt++]);
        stack_series.push_back(pointer);
    }
    clear_vector(vect_series); // освобождение памяти
    vector < vector <int>> pointer;
    stack_series.push_back(pointer);
    clear_vector(pointer); // освобождение памяти
    while (flag == true) {
        int zero_ind = empty_ind(stack_series[0], stack_series[1], stack_series[2]); // индекс пустой головы
        int mn_ind = min_ind(stack_series[0], stack_series[1], stack_series[2], zero_ind); // индекс с наименьшим числом серий
        int mx_ind = max_ind(stack_series[0], stack_series[1], stack_series[2], zero_ind); // индекс с наибольшим числом серий
        int cur_min = stack_series[mn_ind].size(); // количество серий для сливания
        for (int i = 0; i < cur_min; i++) {
            vector<int> temp = new_ser(stack_series[mn_ind][stack_series[mn_ind].size() - 1],
                stack_series[mx_ind][stack_series[mx_ind].size() - 1]); // сливание серий
            if (temp.size() == 25)
                flag = false; // смена флага когда все серии слиты
            stack_series[zero_ind].push_back(temp); // добавление отсортированной серии
            stack_series[mn_ind].erase(stack_series[mn_ind].end() - 1); // избавление от слитой серии
            stack_series[mx_ind].erase(stack_series[mx_ind].end() - 1); // избавление от слитой серии
        }
    }
    vect = not_empty_head(stack_series[0], stack_series[1], stack_series[2]);
    clear_vector(stack_series); // освобождение памяти
}
int main() {
    system("chcp 1251");
    srand(time(0));
    int mas_size = 25; // создание массива на 25 элементов
    vector<int> vect(mas_size);
    create_mas(vect); // заполнение массива
    cout << "Текущий массив: " << endl;
    print(vect); // вывод массива
    sort(vect); // многофазная сортировка массива
    cout << "Отсортированный массив: " << endl;
    print(vect); // вывод массива
    return 0;
}