// Хэш-таблицы.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <ctime>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

const int M = 90; //количество записей
const double A = M_PI_4;
int collisionCounter = 0; //счетчик коллизей

struct Node { //структура определения данных узла
    string key = "";
    string value = "";
    Node* next = nullptr;
    Node* prev = nullptr;
};

struct HashTable { //структура определения данных хэш-таблицы
    Node* table[M];
    HashTable() {
        for (int i = 0; i < M; ++i) {
            table[i] = nullptr;
        }
    }
};

double mod1(double k) {
    int intPart = static_cast<int>(k);
    return k - intPart;
}

//метод открытой адресации для обработки коллизий.
//формула, которая преобразует ключи в числа.
int getHash(double k) {
    return static_cast<int>(M * mod1(k * A));
}

//Затем полученные числа используются для определения индекса, по которому будет располагаться запись в таблице.
int getHash(string line) {
    int n = 0;
    for (int i = 0; i < line.size(); i++) {
        n += static_cast<int>(pow(line[i], 2) * M_2_SQRTPI + abs(line[i]) * M_SQRT1_2);
    }
    return getHash(abs(n));
}

//Функция,которая добавляет новую запись в хеш-таблицу.
bool add(HashTable& table, string key, string elem) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->value = elem;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    int hash = getHash(key);
    //Если на месте рассчитанного хеш-кода еще нет записи, то новая запись будет размещена прямо в этой ячейке.
    if (table.table[hash] == nullptr) {
        table.table[hash] = newNode;
        return true;
    }
    //В противном случае происходит проход по связному списку,
    // связывающему все записи с одинаковыми хеш-кодами, и новая запись добавляется в конец этого списка.
    else {
        Node* current = table.table[hash];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        collisionCounter++;
        return true;
    }
}
//функция, которая удаляет запись из таблицы по ключу,
//В функции выполняется поиск записи по ключу и последующее удаление
bool removeByKey(HashTable& table, string key) {
    int hash = getHash(key);
    Node* current = table.table[hash];
    while (current != nullptr) {
        if (current->key == key) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            }
            else {
                table.table[hash] = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            delete current;
            return true;
        }
        current = current->next;
    }
    return false;
}

//функция, которая удаляет запись из таблицы по значению,
//В функции выполняется поиск записи только по значению
bool removeByValue(HashTable& table, string elem) {
    for (int i = 0; i < M; i++) {
        Node* current = table.table[i];
        while (current != nullptr) {
            if (current->value == elem) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                }
                else {
                    table.table[i] = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                delete current;
                return true;
            }
            current = current->next;
        }
    }
    return false;
}

//возвращает указатель на запись по заданному ключу. Если запись не найдена, функция возвращает nullptr
Node* get(HashTable& table, string key) {
    int hash = getHash(key);
    Node* current = table.table[hash];
    while (current != nullptr) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

//выводит все записи хеш-таблицы
void print(HashTable& table) {
    for (int i = 0; i < M; i++) {
        Node* current = table.table[i];
        while (current != nullptr) {
            cout << "[" << current->key << ": " << current->value << "]\n";
            current = current->next;
        }
    }
    cout << endl;
}

string surnames[] = {
    "Иванов", "Петров", "Смирнов", "Серебряков", "Кузнецов", "Попов",
    "Козлов", "Горбунов", "Васильев", "Жуланов", "Павлов", "Федоров",
    "Орлов", "Волков", "Белов", "Беляев", "Морозов", "Соловьев",
    "Ашлапов", "Дородных", "Мозжерин", "Кувалдин", "Самарин", "Борисов",
    "Соколов", "Вшивков", "Ведров", "Бачев", "Байдин", "Нохрин"
};

string names[] = {
    "Александр", "Андрей", "Артем", "Алексей", "Анатолий","Владимир",
    "Виктор", "Валентин", "Вячеслав", "Валерий","Геннадий", "Дмитрий",
    "Давид", "Роман", "Никита","Олег", "Руслан", "Юрий",
    "Станислав", "Николай","Иван", "Константин", "Кирилл", "Арсений",
    "Евгений","Михаил", "Максим", "Климентий", "Семён", "Игорь"
};

string patronymics[] = {
    "Александрович", "Андреевич", "Сергеевич", "Алексеевич", "Анатольевич","Владимирович",
    "Викторович", "Валентинович", "Вячеславович", "Валерьевич","Геннадьевич", "Дмитриевич",
    "Тимофеевич", "Романович", "Павлович","Олегович", "Русланович", "Юрьевич",
    "Станиславович", "Николаевич","Иванович", "Константинович", "Кириллович", "Григорьевич",
    "Евгеньевич","Михаилович", "Максимович", "Васильевич", "Семёнович", "Игоревич"
};

string generateFullName() {
    return surnames[rand() % 30] + ' ' + names[rand() % 30] + ' ' + patronymics[rand() % 30];
}


string correctStr(int n, int length) {
    string strn = to_string(n);
    while (strn.size() < length) {
        strn = '0' + strn;
    }
    while (strn.size() > length) {
        strn.erase(0,1);
    }
    return strn;
}

string generateBirthday() {
    return correctStr(rand() % 28 + 1, 2) + '.' + correctStr(rand() % 12 + 1, 2) + '.' + to_string(rand() % 74 + 1950);
}

string generatePhoneNumber(int k) {
    string str;
    static const char absd[] = "0123456789";
    for (int i(0); i < k; i++) {
        str += absd[rand() % 10];
    }
    return str;
}

int main()
{
    system("chcp 1251");
    srand(time(NULL));
    HashTable myTable;
    for (int i = 0; i < M; i++)
    {
        string birthDay = generateBirthday();
        string newHuman = generateFullName() + " | " + birthDay + " | " + "+7" + generatePhoneNumber(10);
        add(myTable, birthDay, newHuman);
    }
    cout << "Создана хэш-таблица: " << endl;
    print(myTable);

    int existingInd = rand() % M;
    while (myTable.table[existingInd] == nullptr) {
        existingInd = rand() % M;
    }
    Node* randomHuman = myTable.table[existingInd];
    string keyToRemove = randomHuman->key;
    cout << "Удаление по ключу " << keyToRemove << ":" << endl;
    if (removeByKey(myTable, keyToRemove)) {
        cout << "Элемент с ключом " << keyToRemove << " успешно удален." << endl;
    }
    else {
        cout << "Элемент с ключом " << keyToRemove << " не найден." << endl;
    }
    print(myTable);

    existingInd = rand() % M;
    while (myTable.table[existingInd] == nullptr) {
        existingInd = rand() % M;
    }
    randomHuman = myTable.table[existingInd];
    string valueToRemove = randomHuman->value;
    cout << "Удаление по значению " << valueToRemove << ":" << endl;
    if (removeByValue(myTable, valueToRemove)) {
        cout << "Элемент с значением " << valueToRemove << " успешно удален." << endl;
    }
    else {
        cout << "Элемент с значением " << valueToRemove << " не найден." << endl;
    }
    print(myTable);

    existingInd = rand() % M;
    while (myTable.table[existingInd] == nullptr) {
        existingInd = rand() % M;
    }
    randomHuman = myTable.table[existingInd];
    string keyToGet = randomHuman->key;
    cout << "Получение элемента по ключу " << keyToGet << ":" << endl;
    Node* node = get(myTable, keyToGet);
    if (node != nullptr) {
        cout << "Найден элемент " << node->value << endl;
    }
    else {
        cout << "Элемент с ключом " << keyToGet << " не найден." << endl;
    }
    cout << "Число коллизий: " << collisionCounter << endl;
    return 0;
}

