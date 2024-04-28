// очереди через структуру.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data; //данные
    Node<T>* next; //указатель на следующий элемент
};

template <typename T>
struct Queue
{
    int size; //размер
    Node<T>* head; //укзатель на голову
    Node<T>* tail; //укзатель на хвост
};

template <typename T>
void newQueue(Queue<T>& q, int n) {
    T a;
    cout << "Введите элемент: ";
    cin >> a;
    initQueue(q, a); //инициализация первым элементом
    for (int i = 2; i <= n; i++) {
        cout << "Введите элемент: ";
        cin >> a;
        push(q, a); //вводим элемент и вставляем в конец очереди
    }
}

template <typename T>
void initQueue(Queue<T>& q, const T& value) {
    Node<T>* new_Node = new Node<T>(); //резервируем память под первый элемент 
    new_Node->data = value; //в поле ключа присваиваем передаваемое значение
    q.head = new_Node; //первый элемент - единственный,
    q.tail = new_Node; //поэтому указатели указывают на него
    q.size = 1; //всего один элемент
}

template <typename T>
void push(Queue<T>& q, const T& value) {
    Node<T>* new_Node = new Node<T>(); //резервируем память под первый элемент
    q.size++; //увеличиваем размер очереди на 1
    new_Node->data = value; //в поле ключа присваеваем передаваемое значение
    new_Node->next = nullptr; //последний элемент ни на что не указывает 
    q.tail->next = new_Node; //предпоследний элемент указывает на последний
    q.tail = new_Node; //указатель на последний элемент теперь указывает на новый
}

template <typename T>
void printQueue(Queue<T>& q) {
    Node<T>* tmp = q.head; //указатель на первый элемент
    cout << "начало -> ";
    while (tmp != nullptr) //пока не дойдем до последнего элемента
    {
        cout << tmp->data << " -> "; //обращаемся к полю элемента и выводим значение
        tmp = tmp->next; //переходим к следующему элементу 
    }
    cout << "конец" << endl;
}

template <typename T>
void pop(Queue<T>& q)
{
    Node<T>* tmp = q.head; //указатель на первый элемент
    q.head = q.head->next; //голова теперь следующий элемент 
    q.size--; //количество стало меньше на 1
    delete tmp; //очищаем память
}

template <typename T>
void deleteKey(Queue<T>& q, T k)
{
    int i = 1;
    while (i <= q.size) //пока не пройдем полный круг
    {
        if (q.head->data == k) //если первый элемент равен ключу
        {
            pop(q); //удаляем его
        }
        else {
            push(q, q.head->data);
            pop(q);
            i++;
        }
    }
}

template <typename T>
void insert(Queue<T>& q, int count, int number)
{
    int i = 1;
    while (i < number) //пока не дойдем до нужного элемента
    {
        push(q, q.head->data);
        pop(q);
        i++;
    }
    T a;
    for (int j = 1; j <= count; j++) {
        cout << "Введите элемент для добавления: ";
        cin >> a;
        push(q, a); //добавляем count новых элементов
    }
    for (i; i <= q.size - count; i++) //чтобы первый элемент оказался на своем месте
    {
        push(q, q.head->data);
        pop(q); //перставляем элементы с головы в хвост
    }
}

template <typename T>
void deleteQueue(Queue<T>& q)
{
    while (q.head->next != nullptr) //пока не дойдем до последнего элемента 
    {
        pop(q); //удаляем элемент, очищаем память
    }
    Node<T>* tmp = q.head;
    q.head = nullptr;
    q.size--;
    delete tmp; //очищаем память от последнего оставшегося элемента
}

int main()
{
    system("chcp 1251");
    Queue<char> q;
    int n;

    do
    {
        cout << "Введите количество элементов в очереди: ";
        cin >> n;
    } while (n <= 0); //количество должно быть больше 0

    newQueue(q, n); //создаём очередь
    cout << endl;
    printQueue(q); //выводим на экран

    cout << endl << "Введите ключ элемента, который необходимо удалять: ";
    char key;
    cin >> key;

    deleteKey(q, key); //удаление элемента
    cout << endl;
    printQueue(q);

    int number = q.size+1;
    cout << endl << "Введите количество элементов для добавления: ";
    int count;
    cin >> count;

    insert(q, count, number); //вставка
    cout << endl;
    printQueue(q);

    cout << endl << "Очищение динамической памяти ...";
    deleteQueue(q);
    cout << "Завершено." << endl;
    printQueue(q);
    return 0;

}