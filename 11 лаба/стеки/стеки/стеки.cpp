// стеки.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

struct Node //структура элемента стека
{
    char data; //данные элемента
    Node* next = nullptr; //переход к следующему элементу
};

struct Stack //Структура стека
{
    Node* head = nullptr; //Голова стека
    int size = 0; //Размер стека

    void pushFront(char data) //Метод для добавления элемента в начало стека 
    {
        Node* node = new Node; //Создаем новый элемент стека
        node->data = data; //Записываем в новый элемент нужные данные

        if (head == nullptr) //Если стек пуст
            head = node; //Новый элемент становится головой стека
        else
        {
            node->next = head; //Ставим голову после нового элемента
            head = node; //Делаем новый элемент головой
        }

        size++; //Увеличиваем размер
    }

    void pushBack(char data) //Метод для добавления элемента в конец стека 
    {
        Stack* buffer = new Stack; //Создаем стек - буффер

        for (int i = 0; i < size; i++)
        {
            buffer->pushFront(head->data); //Записываем в буфеер текущую голову

            //Сносим текущую голову, новая голова = следующий элемент
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }

        size = 0; //Размер нашего стека = 0
        pushFront(data); //Добавляем новый элемент в наш стек
        Node* current = buffer->head; //Начинаем поход по буфферному стеку

        for (int i = 0; i < buffer->size; i++)
        {
            //Каждый элемент буфферного стека записываем в наш
            pushFront(current->data);
            current = current->next;
        }

        buffer->Clear(); //Очищаем буфферный стек
        delete buffer; //И удаляем его
    }

    void print()
    {
        if (size == 0) //Если размер стека = 0
            cout << "Ваш стек пуст" << endl; //То просто сообщаем, что стек пуст
        else //Иначе
        {
            cout << "Ваш стек:" << endl;

            Node* current = head; //Начинаем поход по стеку

            for (int i = 0; i < size; i++)
            {
                //Печатаем каждый элемент стека
                cout << current->data << " ";
                current = current->next;
            }

            cout << endl;
        }
    }
    void remove(char key)
    {
        Stack* buffer = new Stack; //Буфферный стек

        for (int i = 0; i < size; i++) //Проходим по всему стеку 
        {
            if (head->data != key) //Если данные головы не равны ключу
                buffer->pushFront(head->data); //Записываем его в буфферный стек

            //Сносим текущую голову, новая голова = следующий элемент
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }

        size = 0; //Размер нашего стека = 0
        Node* current = buffer->head; //Начинаем поход по буфферному стеку

        for (int i = 0; i < buffer->size; i++)
        {
            //Каждый элемент буфферного стека записываем в наш
            pushFront(current->data);
            current = current->next;
        }

        buffer->Clear(); //Очищаем буфферный стек
        delete buffer; //И удаляем его
    }

    void Clear() //Метод на очистку стека
    {
        for (int i = 0; i < size; i++)
        {
            Node* tmp = head; //Заносим голову в временную переменную
            head = head->next; //Переносим голову на элемент ниже
            delete tmp; //Убиваем временную переменную
        }

        head = nullptr; //Голова = нулевой указатель

        size = 0; //Размер = 0
    }
};


int main()
{
    system("chcp 1251");
    int n;
    cout << "Введите количество элементов стека: " << endl;
    cin >> n;
    Stack* stack = new Stack;
    for (int i = 0; i < n; i++) {
        char Char;
        cout << "Введите символ: " << endl;
        cin >> Char;
        stack->pushBack(Char);
    }
    cout << endl;
    stack->print();
    char key;
    cout << "Введите какой элемент стека нужно удалить: " << endl;
    cin >> key;
    stack->remove(key);
    stack->print();
    cout << "Введите сколько элементов нужно добавить в стек: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char Char;
        cout << "Введите символ: " << endl;
        cin >> Char;
        stack->pushBack(Char);
    }
    cout << endl;
    stack->print();
}

