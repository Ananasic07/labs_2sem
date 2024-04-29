// лаба 11. Односвязный список.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstring>

using namespace std;

struct Node {
	char data;
	Node* pointer_to_next_node = nullptr;
};

struct  List {
	Node* head_node = nullptr; //первый элемент списка
	Node* tail_node = nullptr; //последний элемент списка
};


//параметр функции: список и данные, которые нужно добавить в его конец
void pushBack(List& list, const char& data) {
	Node* new_node = new Node; //динамически создаём новый узел
	new_node->data = data; //присваиваем полю узла data данные

	if (list.head_node == nullptr) { //если список пуст, новый узел становится головным узлом списка
		list.head_node = new_node;
		list.tail_node = new_node;
	}
	else {
		//связываем хвостовой узел с новым
		list.tail_node->pointer_to_next_node = new_node;
		//меняем хвостовой узел на новый 
		list.tail_node = new_node;
	}
}

//метод удаления элемента списка по ключу
void remove(List& list, char& key) {
	Node* current_node = new Node; //инициализируем переменную текущего элемента
	current_node->pointer_to_next_node = list.head_node; //следующий после этого элемента - голова
	bool flag = false;
	while (current_node->pointer_to_next_node != nullptr) //пока следующий элемент не будет пустым
	{
		if (current_node->pointer_to_next_node->data == key) //если данные следующего элемента равны ключу
		{
			Node* tmp; //выделяем память под временную переменную
			if (current_node->pointer_to_next_node == list.head_node) //если следующий элемент = голове спика
			{
				tmp = list.head_node; //записываем голову во временную переменную
				list.head_node = list.head_node->pointer_to_next_node; //делаем головой следующий элемент списка
				current_node->pointer_to_next_node = list.head_node; //следующий элемент после текущего голова
			}
			else if (current_node->pointer_to_next_node == list.tail_node) //иначе если следующий элемент хвост списка
			{
				tmp = list.tail_node; //записываем хвост во временную переменную
				list.tail_node = current_node; //хвостом теперь является текущая переменная
				current_node->pointer_to_next_node = nullptr; //после текущей переменной ничего нет
			}
			else {
				tmp = current_node->pointer_to_next_node; //записывавем следующий элемент во временную переменную
				current_node->pointer_to_next_node = tmp->pointer_to_next_node; //следующий элемент после текущего = следующему элементу временной переменной

			}
			delete tmp; //удаляем содержимое временной переменной
		}
		else {
			current_node = current_node->pointer_to_next_node; // двигаемся к следующей переменной
			flag = true;
		}
	}
	if (!flag) // флаг обозначает, что хотябы один элемент списка не был удален
	{
		delete current_node; // если удалили все элементы списка, то очищаем память переменной текущего элемента
	}
}

void popFront(List& list) {
	//если список пуст
	if (list.head_node == nullptr) {
		return;
	}
	//выбираем узел, который следует убрать
	Node* remove = list.head_node;
	//изменяем головной узел списка
	list.head_node = list.head_node->pointer_to_next_node;

	if (remove == list.tail_node) {
		list.tail_node = nullptr;
	}
	delete remove;
}

void print(List& list) //метод печати списка
{
	//иницилизируем переменную, которая хранит в себе текущий элемент списка
	Node* current_node = list.head_node;
	if (current_node == nullptr) //если самый первый элемент списка пуст
	{
		cout << "Ваш список оказался пустым" << endl;
	}
	else {
		cout << "Ваш список: " << endl;
		while (current_node != nullptr) //пока не дошли до конца списка
		{
			cout << current_node->data << " "; //выводим данные текущего элемента
			current_node = current_node->pointer_to_next_node; //переходим к следующему элементу
		}
		cout << endl;
	}
}

int main() {
	system("chcp 1251");
	int n;
	cout << "Введите количество элементов списка: " << endl;
	cin >> n;

	List list ; //иницилизируем список
	for (int i = 0; i<n; i++) {
		char Char;
		cout << "Введите символ: " << endl;
		cin >> Char;
		pushBack(list,Char);
	}
	//указатель на текущей узел
	Node* current_node = list.head_node;
	while (current_node != nullptr) {
		//выводим данные текущего узла
		cout << current_node->data << ' ';
		//переходим к следующему узлу
		current_node = current_node->pointer_to_next_node;
	}
	cout << endl;
	print(list);
	char key;
	cout << "Введите символ, который нужно удалить" << endl;
	cin >> key;
	remove(list,key);
	print(list);
	cout << "Сколько элементов добавить в конец списка: " << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char Char;
		cout<< "Введите символ: " << endl;
		cin >> Char;
		pushBack(list, Char);
	}
	cout << endl;
	print(list);
}



