// двунаправленный список.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
using namespace std;
struct Node  //структура элемента списка
{
    char data; //данные, которые он содержит
    Node* next = nullptr; //следующий элемент списка
    Node* prev = nullptr; // предыдущий элемент списка
};

struct List {
    Node* head = nullptr; // первый элемент списка
    Node* tail = nullptr; // последний элемент списка
};

void pushBack(List& list, const char& data) //метод добавления элемента в конец списка
{
    Node* new_node = new Node; //создаем новый элемент
    new_node->data = data; //записываем в новый элемент нужные данные
    if (list.head == nullptr) //если список пуст
    {
        //голова и хвост = новому элементу
        list.head = new_node;
        list.tail = new_node;
    }
    else {
        list.tail->next = new_node; // ставим новый элемент после хвоста
        new_node->prev = list.tail; //ставим хвост перед новым элементом
        list.tail = new_node; //новый элемент становится хвостом
    }
}
// метод добавения элемента в конец списка
void pushFront(List& list, const char& data) {
    Node* new_node = new Node; //создаем новый элемент
    new_node->data = data; // записываем в новый элемент нужные данные
    if (list.head == nullptr) //если список пуст
    {
        //голова и хвост = новому элементу
        list.head = new_node;
        list.tail = new_node;
    }
    else{
        new_node->next = list.head; // ставим голову после нового элемента 
        list.head->prev = new_node; // ставим новый элемент перед головой
        list.head = new_node; // голова = новому элементу
    }
}

void print(List& list) {
    Node* current_node = list.head; //иницилизируем переменную, которая хранит в себе текущий элемент
    if (current_node == nullptr) //если самый первый элемент списка оказался пустым
    {
        cout << "Ваш список оказался пустым" << endl;
    }
    else {
        cout << "Ваш список: " << endl;
        while (current_node != nullptr) // пока не дошли до конца списка
        {
            cout << current_node->data << " "; // выводим данные текущего элемента
            current_node = current_node->next; // переходим к следующему 
        }
        cout << endl;
    }
}

//метод удаления элемента списка по ключу
void remove(List& list, char& key) {
    Node* current_node = new Node; //инициализируем переменную текущего элемента
    current_node->next = list.head; //следующий после этого элемента - голова
    while (current_node != nullptr) //пока не дошли до конца списка
    {
        Node* tmp = current_node; //записываем текущий элемент в временный
        current_node=current_node->next; //идем дальше
        if (tmp->data == key) //если данные равны ключу
        {
            if (tmp->next == nullptr && tmp->prev == nullptr) //если в списке один элемент
            {
                //голова и хвост нулевые показатели
                list.head = nullptr;
                list.tail = nullptr;
            }
            else if (tmp== list.head) //если мы в голове
            {
                list.head = tmp->next; // голова = следующий элемент
                list.head->prev = nullptr; //предыдущий элемент головы = нулевой показатель
            }
            else if(tmp == list.tail) // если мы в хвосте
            {
                list.tail = tmp->prev; // хвост = предыдующий элемент
                list.tail->next = nullptr; //предыдущий элемент после хвоста = нулевой показатель
            }
            else{
                tmp->prev->next = tmp->next; //  следующий элемент предыдущего = следующий элемент 
                tmp->next->prev = tmp->prev; //предыдущий элемент следующего = предыдущему
            }

            delete tmp; //удаляем содержимое временной переменной
        }
    }
}

int main() {
    system("chcp 1251");
    int n;
    cout << "Введите количество элементов списка: " << endl;
    cin >> n;
    List list;
    for (int i = 0; i < n; i++) {
        char Char;
        cout << "Введите символ: " << endl;
        cin >> Char;
        pushBack(list, Char);
    }
    cout << endl;
    print(list);
    char key;
    cout << "Введите символ, который нужно удалить: " << endl;
    cin >> key;
    remove(list, key);
    print(list);
    cout << "Введите сколько еще символов вы хотите добавить в конец списка: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char Char;
        cout << "Введите символ: " << endl;
        cin >> Char;
        pushBack(list, Char);
    }
    cout << endl;
    print(list);
}