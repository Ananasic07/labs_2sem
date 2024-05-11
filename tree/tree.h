#pragma once
#include<iostream>
#include <queue>
#include <stack>
#include <fstream>
#include <vector>
#include "tree.h"

using namespace std;
template <typename T> // Определение шаблонного класса Tree с параметром типа T
class Tree
{
private:
	class Node//вложенный класс - ячейка памяти
	{
	public:
		Node(T data = T(), Node* pLeft = nullptr, Node* pRight = nullptr)//используется параметр по умолчанию,
			//то есть если мы не передаем указатель, то он автоматически присваивается nullptr
		{//для поля data также используется параметр по умолчанию, выглядит он как вызов конструктора по умолчанию
			this->data = data; // Инициализация значения узла
			this->pLeft = pLeft; // Инициализация указателя на левого потомка
			this->pRight = pRight; // Инициализация указателя на правого потомка
		}
		Node* pLeft; //хранит указатель на следующий элемент слева
		Node* pRight; //хранит указатель на следующий элемент справа
		T data; //хранит наши данные
	};
	int _size; //количество элементов в списке.
	Node* head; //указатель на первый элемент в списке
public:
	Tree(); //Конструктор
	~Tree(); //Деструктор
	void insert(T data); //добавляет элемент в конец списка
	int size() { return this->_size; } // Метод для получения количества элементов в дереве
	bool erase(const T& data); //Удаление элемента
	void clear(); //удаляет все элементы списка (логика как у pop_front, деструктор основан на этой штуке)
	Tree<T>* find(T data); // Метод для поиска элемента в дереве

	void showWidth(); //обход в ширину
	void showStraight(); //прямой обход
	void showDepth(); //обход в глубину
	void showDepthBackward(); //обход в глубину в другую сторону (элементы идут по возрастанию)
	Tree<T>& operator=(const Tree<T>& other); // Перегрузка оператора присваивания

	int getHeight(Node* node); // Метод для получения высоты дерева/поддерева
	int getBalanceFactor(Node* node); // Метод для получения фактора балансировки узла
	typename Node* rotateLeft(Node* node); // Метод для левого вращения поддерева
	typename Node* rotateRight(Node* node); // Метод для правого вращения поддерева
	typename Node* balance(Node* node); // Метод для балансировки дерева/поддерева

private:
	void HelperDepth(Node* node); // Вспомогательный метод для обхода дерева в глубину
	void HelperDepthBackward(Node* node); // Вспомогательный метод для обратного обхода дерева в глубину
	void HelperClear(Node* node); // Вспомогательный метод для очистки дерева
	int helpDepth; // Вспомогательная переменная для обхода дерева в глубину


};

template<typename T>
Tree<T>::Tree()
{
	this->_size = 0; // Инициализация размера дерева равным 0
	head = nullptr; // Инициализация указателя на корень дерева значением nullptr
	helpDepth = 0; // Инициализация вспомогательной переменной для обхода в глубину
}

template<typename T>
Tree<T>::~Tree()
{
	this->clear(); // Вызов метода очистки дерева в деструкторе
}

template<typename T>
void Tree<T>::insert(T data)
{
	if (head == nullptr)
		head = new Node(data); // Если дерево пустое, создается новый узел в качестве корня
	else
	{
		Node* temp = this->head; // Временный указатель на корень дерева
		while (true)
		{
			if (data < temp->data)
			{
				if (temp->pLeft == nullptr)
				{
					temp->pLeft = new Node(data); // Если левый потомок отсутствует, создается новый узел в качестве левого потомка
					break;
				}
				else
					temp = temp->pLeft; // Переход к левому потомку
			}
			else if (data > temp->data)
				if (temp->pRight == nullptr)
				{
					temp->pRight = new Node(data); // Если правый потомок отсутствует, создается новый узел в качестве правого потомка
					break;
				}
				else
					temp = temp->pRight; // Переход к правому потомку

			else return; // Если значение уже существует в дереве, выход из метода
		}
	}
	++_size; // Увеличение размера дерева
	head = balance(head); // Балансировка дерева после вставки нового узла
}

template<typename T>
bool Tree<T>::erase(const T& data) // Метод для удаления элемента data из дерева
{
	Node* prev = head; // Указатель prev инициализируется корнем дерева
	Node* iter = head; // Указатель iter также инициализируется корнем дерева
	while (true)
	{
		if (data == iter->data) // Если значение узла совпадает с data
		{
			break;// Выход из цикла
		}
		else if (data < iter->data) // Если data меньше значения узла
		{
			if (iter->pLeft == nullptr) return false; // Если левого потомка нет, элемент не найден
			prev = iter; // Сохранение текущего узла в prev
			iter = iter->pLeft; // Переход к левому потомку
		}
		else // Если data больше значения узла
		{
			if (iter->pRight == nullptr) return false; // Если правого потомка нет, элемент не найден
			prev = iter; // Сохранение текущего узла в prev
			iter = iter->pRight; // Переход к правому потомку
		}
	}
	// Удаление найденного узла
	if (iter->pLeft == nullptr && iter->pRight == nullptr)// Если у узла нет потомков
	{
		if (iter == head) // Если удаляемый узел является корнем
		{
			delete iter; // Удаление узла
			head == nullptr; // Установка указателя на корень в nullptr
		}
		else // Если удаляемый узел не является корнем
		{
			if (prev->pLeft == iter) // Если удаляемый узел является левым потомком
				prev->pLeft = nullptr; // Устанавливаем левого потомка родителя в nullptr
			else // Если удаляемый узел является правым потомком
				prev->pRight = nullptr; // Устанавливаем правого потомка родителя в nullptr
			delete iter; // Удаление узла
		}
	}
	else if (iter->pLeft == nullptr || iter->pRight == nullptr) // Если у узла есть только один потомок
	{
		if (iter == head) // Если удаляемый узел является корнем
		{
			if (iter->pLeft != nullptr) // Если левый потомок существует
				head = head->pLeft; // Устанавливаем левого потомка в качестве корня
			else // Иначе (если существует правый потомок)
				head = head->pRight; // Устанавливаем правого потомка в качестве корня
		}
		else // Если удаляемый узел не является корнем
		{
			if (iter->pLeft != nullptr) // Если левый потомок существует
			{
				if (prev->pLeft == iter) // Если удаляемый узел является левым потомком родителя
					prev->pLeft = iter->pLeft; // Устанавливаем левого потомка удаляемого узла как левого потомка родителя
				else // Если удаляемый узел является правым потомком родителя
					prev->pRight = iter->pLeft; // Устанавливаем левого потомка удаляемого узла как правого потомка родителя
			}
			else // Если правый потомок существует
			{
				if (prev->pLeft == iter) // Если удаляемый узел является левым потомком родителя
					prev->pLeft = iter->pRight; // Устанавливаем правого потомка удаляемого узла как левого потомка родителя
				else // Если удаляемый узел является правым потомком родителя
					prev->pRight = iter->pRight; // Устанавливаем правого потомка удаляемого узла как правого потомка родителя
			}
		}
		delete iter; // Удаление узла
	}
	else // Если у узла есть оба потомка
	{
		Node* temp = iter; // Временный указатель на удаляемый узел
		prev = iter; // Сохранение удаляемого узла в prev
		iter = iter->pRight; // Переход к правому потомку удаляемого узла
		while (iter->pLeft != nullptr) // Поиск минимального элемента в правом поддереве
		{
			temp = iter; // Сохранение текущего узла в temp
			iter = iter->pLeft; // Переход к левому потомку
		}
		prev->data = iter->data; // Копирование значения минимального элемента в родительский узел
		delete iter; // Удаление минимального элемента
		temp->pLeft = nullptr; // Установка левого потомка temp в nullptr
	}
	--this->_size; // Уменьшение размера дерева
	return true; // Возвращение true, так как элемент был успешно удален
}

template<typename T>
void Tree<T>::showWidth() // симметричный обход дерева(слева направо)
{
	if (this->head == nullptr) return; // Если дерево пустое, выход из метода
	int j = 0; // Счетчик для нумерации элементов
	Node* temp; // Временный указатель на узел
	queue<Node*> que; // Очередь для хранения узлов
	que.push(this->head); // Добавление корневого узла в очередь
	while (!que.empty()) // Цикл, пока очередь не пуста
	{
		temp = que.front(); // Получение первого элемента из очереди
		cout << ++j << ". " << temp->data << endl;// Вывод нумерованного значения узла
		que.pop(); // Удаление первого элемента из очереди
		if (temp->pLeft != nullptr) // Если левый потомок существует
			que.push(temp->pLeft); // Добавление левого потомка в очередь
		if (temp->pRight != nullptr) // Если правый потомок существует
			que.push(temp->pRight); // Добавление правого потомка в очередь
	}
}

template<typename T>
void Tree<T>::showStraight() // Метод для прямого обхода дерева
{
	if (this->head == nullptr) return; // Если дерево пустое, выход из метода
	int j = 0; // Счетчик для нумерации элементов
	Node* temp; // Временный указатель на узел
	stack<Node*> st; // Стек для хранения узлов
	st.push(this->head); // Добавление корневого узла в стек
	while (!st.empty()) // Цикл, пока стек не пуст
	{
		temp = st.top(); // Получение верхнего элемента из стека
		cout << ++j << ". " << temp->data << endl;// Вывод нумерованного значения узла
		st.pop(); // Удаление верхнего элемента из стека
		if (temp->pRight != nullptr) // Если правый потомок существует
			st.push(temp->pRight); // Добавление правого потомка в стек
		if (temp->pLeft != nullptr) // Если левый потомок существует
			st.push(temp->pLeft); // Добавление левого потомка в стек
	}
}

template<typename T>
inline void Tree<T>::HelperDepth(Node* node) // Вспомогательный метод для обхода в глубину
{
	if (node == nullptr) return; // Если узел пустой, выход из метода
	HelperDepth(node->pLeft); // Рекурсивный вызов для левого поддерева
	cout << ++helpDepth << ". " << node->data << endl; // Вывод нумерованного значения узла
	HelperDepth(node->pRight); // Рекурсивный вызов для правого поддерева
}

template<typename T>
void Tree<T>::showDepth() // Метод для обхода дерева в глубину
{
	if (this->head != nullptr) // Если дерево не пустое
	{
		this->helpDepth = 0; // Обнуление вспомогательной переменной
		this->HelperDepth(this->head); // Вызов вспомогательного метода для корневого узла
	}
}

template<typename T>
void Tree<T>::HelperDepthBackward(Node* node) // Вспомогательный метод для обратного обхода в глубину
{
	if (node == nullptr) return; // Если узел пустой, выход из метода
	HelperDepthBackward(node->pRight); // Рекурсивный вызов для правого поддерева
	cout << ++helpDepth << ". " << node->data << endl; // Вывод нумерованного значения узла
	HelperDepthBackward(node->pLeft); // Рекурсивный вызов для левого поддерева
}

template<typename T>
void Tree<T>::showDepthBackward() // Метод для обратного обхода дерева в глубину
{
	if (this->head != nullptr) // Если дерево не пустое
	{
		this->helpDepth = 0; // Обнуление вспомогательной переменной
		this->HelperDepthBackward(this->head); // Вызов вспомогательного метода для обратного обхода в глубину
	}
}

template<typename T>
inline void Tree<T>::HelperClear(Node* node) // Вспомогательный метод для очистки дерева
{
	if (node == nullptr) return; // Если узел пустой, выход из метода
	HelperClear(node->pLeft); // Рекурсивный вызов для левого поддерева
	HelperClear(node->pRight); // Рекурсивный вызов для правого поддерева
	node->pLeft == nullptr;// Обнуление указателя на левого потомка
	node->pRight = nullptr; // Обнуление указателя на правого потомка
	delete node; // Удаление узла
}

template<typename T>
void Tree<T>::clear()// Метод для очистки дерева
{
	if (head != nullptr) // Если дерево не пустое
	{
		this->HelperClear(this->head); // Вызов вспомогательного метода для очистки дерева
		this->_size = 0; // Обнуление размера дерева
		this->head = nullptr; // Обнуление указателя на корень дерева
	}
}

template<typename T>
Tree<T>& Tree<T>::operator=(const Tree<T>& other) // Перегрузка оператора присваивания
{
	this->clear(); // Очистка текущего дерева
	if (other.head == nullptr) return *this; // Если присваиваемое дерево пустое, выход из метода
	Node* temp; // Временный указатель на узел
	stack<Node*> st; // Стек для хранения узлов
	st.push(other.head); // Добавление корневого узла присваиваемого дерева в стек
	while (!st.empty()) // Цикл, пока стек не пуст
	{
		temp = st.top(); // Получение верхнего элемента из стека
		this->insert(temp->data); // Вставка значения узла в текущее дерево
		st.pop(); // Удаление верхнего элемента из стека
		if (temp->pRight != nullptr) // Если правый потомок существует
			st.push(temp->pRight); // Добавление правого потомка в стек
		if (temp->pLeft != nullptr) // Если левый потомок существует
			st.push(temp->pLeft); // Добавление левого потомка в стек
	}
	return *this; // Возвращение ссылки на текущий объект
}

template<typename T>
inline Tree<T>* Tree<T>::find(T data) // Метод для поиска узла по значению
{
	if (this == nullptr || this->data = data) // Если дерево пустое или значение совпадает с текущим узлом
	{
		return this; // Возвращаем указатель на текущий узел
	}
	else if (data > this->data) // Если искомое значение больше, чем значение текущего узла
	{
		return this->pRight->find(data); // Рекурсивный вызов для правого поддерева
	}
	else
	{
		return this->left->find(data); // Рекурсивный вызов для левого поддерева
	}
}

template<typename T> // Метод для вычисления высоты поддерева
int Tree<T>::getHeight(Node* node)
{
	if (node == nullptr)// Если узел пустой
		return 0; // Высота пустого узла равна 0
	return max(getHeight(node->pLeft), getHeight(node->pRight)) + 1; // Высота узла равна максимальной высоте его поддеревьев плюс 1
}

template<typename T>  // Метод для вычисления фактора балансировки узла
int Tree<T>::getBalanceFactor(Node* node) // Если узел пустой
{
	if (node == nullptr) // Если узел пустой
		return 0;// Фактор балансировки пустого узла равен 0
	return getHeight(node->pLeft) - getHeight(node->pRight); // Фактор балансировки равен разности высот левого и правого поддеревьев
}

template<typename T>
typename Tree<T>::Node* Tree<T>::rotateLeft(Node* node) // Метод для левого вращения вокруг узла
{
	Node* newRoot = node->pRight; // Новым корнем станет правый потомок
	node->pRight = newRoot->pLeft; // Левое поддерево нового корня становится правым поддеревом текущего узла
	newRoot->pLeft = node; // Текущий узел становится левым потомком нового корня
	return newRoot; // Возвращаем новый корень
}

template<typename T>
typename Tree<T>::Node* Tree<T>::rotateRight(Node* node) // Метод для правого вращения вокруг узла
{
	Node* newRoot = node->pLeft; // Новым корнем станет левый потомок
	node->pLeft = newRoot->pRight; // Правое поддерево нового корня становится левым поддеревом текущего узла
	newRoot->pRight = node; // Текущий узел становится правым потомком нового корня
	return newRoot; // Возвращаем новый корень
}

template<typename T>
typename Tree<T>::Node* Tree<T>::balance(Node* node)// Метод для балансировки узла
{
	if (node == nullptr) // Если узел пустой
		return nullptr; // Возвращаем nullptr

	int balanceFactor = getBalanceFactor(node); // Вычисляем фактор балансировки

	if (balanceFactor > 1) // Если левое поддерево выше
	{
		if (getBalanceFactor(node->pLeft) < 0)// Если необходима дополнительная балансировка левого поддерева
			node->pLeft = rotateLeft(node->pLeft);// Выполняем левое вращение в левом поддереве
		return rotateRight(node); // Выполняем правое вращение вокруг текущего узла
	}
	else if (balanceFactor < -1)  //правое поддерево выше
	{
		if (getBalanceFactor(node->pRight) > 0) // Если необходима дополнительная балансировка правого поддерева
			node->pRight = rotateRight(node->pRight); // Выполняем правое вращение в правом поддереве
		return rotateLeft(node); // Выполняем левое вращение вокруг текущего узла
	}

	return node; // Если дерево сбалансировано, возвращаем текущий узел
}
