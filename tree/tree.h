#pragma once
#include<iostream>
#include <queue>
#include <stack>
#include <fstream>
#include <vector>
#include "tree.h"

using namespace std;
template <typename T> // ����������� ���������� ������ Tree � ���������� ���� T
class Tree
{
private:
	class Node//��������� ����� - ������ ������
	{
	public:
		Node(T data = T(), Node* pLeft = nullptr, Node* pRight = nullptr)//������������ �������� �� ���������,
			//�� ���� ���� �� �� �������� ���������, �� �� ������������� ������������� nullptr
		{//��� ���� data ����� ������������ �������� �� ���������, �������� �� ��� ����� ������������ �� ���������
			this->data = data; // ������������� �������� ����
			this->pLeft = pLeft; // ������������� ��������� �� ������ �������
			this->pRight = pRight; // ������������� ��������� �� ������� �������
		}
		Node* pLeft; //������ ��������� �� ��������� ������� �����
		Node* pRight; //������ ��������� �� ��������� ������� ������
		T data; //������ ���� ������
	};
	int _size; //���������� ��������� � ������.
	Node* head; //��������� �� ������ ������� � ������
public:
	Tree(); //�����������
	~Tree(); //����������
	void insert(T data); //��������� ������� � ����� ������
	int size() { return this->_size; } // ����� ��� ��������� ���������� ��������� � ������
	bool erase(const T& data); //�������� ��������
	void clear(); //������� ��� �������� ������ (������ ��� � pop_front, ���������� ������� �� ���� �����)
	Tree<T>* find(T data); // ����� ��� ������ �������� � ������

	void showWidth(); //����� � ������
	void showStraight(); //������ �����
	void showDepth(); //����� � �������
	void showDepthBackward(); //����� � ������� � ������ ������� (�������� ���� �� �����������)
	Tree<T>& operator=(const Tree<T>& other); // ���������� ��������� ������������

	int getHeight(Node* node); // ����� ��� ��������� ������ ������/���������
	int getBalanceFactor(Node* node); // ����� ��� ��������� ������� ������������ ����
	typename Node* rotateLeft(Node* node); // ����� ��� ������ �������� ���������
	typename Node* rotateRight(Node* node); // ����� ��� ������� �������� ���������
	typename Node* balance(Node* node); // ����� ��� ������������ ������/���������

private:
	void HelperDepth(Node* node); // ��������������� ����� ��� ������ ������ � �������
	void HelperDepthBackward(Node* node); // ��������������� ����� ��� ��������� ������ ������ � �������
	void HelperClear(Node* node); // ��������������� ����� ��� ������� ������
	int helpDepth; // ��������������� ���������� ��� ������ ������ � �������


};

template<typename T>
Tree<T>::Tree()
{
	this->_size = 0; // ������������� ������� ������ ������ 0
	head = nullptr; // ������������� ��������� �� ������ ������ ��������� nullptr
	helpDepth = 0; // ������������� ��������������� ���������� ��� ������ � �������
}

template<typename T>
Tree<T>::~Tree()
{
	this->clear(); // ����� ������ ������� ������ � �����������
}

template<typename T>
void Tree<T>::insert(T data)
{
	if (head == nullptr)
		head = new Node(data); // ���� ������ ������, ��������� ����� ���� � �������� �����
	else
	{
		Node* temp = this->head; // ��������� ��������� �� ������ ������
		while (true)
		{
			if (data < temp->data)
			{
				if (temp->pLeft == nullptr)
				{
					temp->pLeft = new Node(data); // ���� ����� ������� �����������, ��������� ����� ���� � �������� ������ �������
					break;
				}
				else
					temp = temp->pLeft; // ������� � ������ �������
			}
			else if (data > temp->data)
				if (temp->pRight == nullptr)
				{
					temp->pRight = new Node(data); // ���� ������ ������� �����������, ��������� ����� ���� � �������� ������� �������
					break;
				}
				else
					temp = temp->pRight; // ������� � ������� �������

			else return; // ���� �������� ��� ���������� � ������, ����� �� ������
		}
	}
	++_size; // ���������� ������� ������
	head = balance(head); // ������������ ������ ����� ������� ������ ����
}

template<typename T>
bool Tree<T>::erase(const T& data) // ����� ��� �������� �������� data �� ������
{
	Node* prev = head; // ��������� prev ���������������� ������ ������
	Node* iter = head; // ��������� iter ����� ���������������� ������ ������
	while (true)
	{
		if (data == iter->data) // ���� �������� ���� ��������� � data
		{
			break;// ����� �� �����
		}
		else if (data < iter->data) // ���� data ������ �������� ����
		{
			if (iter->pLeft == nullptr) return false; // ���� ������ ������� ���, ������� �� ������
			prev = iter; // ���������� �������� ���� � prev
			iter = iter->pLeft; // ������� � ������ �������
		}
		else // ���� data ������ �������� ����
		{
			if (iter->pRight == nullptr) return false; // ���� ������� ������� ���, ������� �� ������
			prev = iter; // ���������� �������� ���� � prev
			iter = iter->pRight; // ������� � ������� �������
		}
	}
	// �������� ���������� ����
	if (iter->pLeft == nullptr && iter->pRight == nullptr)// ���� � ���� ��� ��������
	{
		if (iter == head) // ���� ��������� ���� �������� ������
		{
			delete iter; // �������� ����
			head == nullptr; // ��������� ��������� �� ������ � nullptr
		}
		else // ���� ��������� ���� �� �������� ������
		{
			if (prev->pLeft == iter) // ���� ��������� ���� �������� ����� ��������
				prev->pLeft = nullptr; // ������������� ������ ������� �������� � nullptr
			else // ���� ��������� ���� �������� ������ ��������
				prev->pRight = nullptr; // ������������� ������� ������� �������� � nullptr
			delete iter; // �������� ����
		}
	}
	else if (iter->pLeft == nullptr || iter->pRight == nullptr) // ���� � ���� ���� ������ ���� �������
	{
		if (iter == head) // ���� ��������� ���� �������� ������
		{
			if (iter->pLeft != nullptr) // ���� ����� ������� ����������
				head = head->pLeft; // ������������� ������ ������� � �������� �����
			else // ����� (���� ���������� ������ �������)
				head = head->pRight; // ������������� ������� ������� � �������� �����
		}
		else // ���� ��������� ���� �� �������� ������
		{
			if (iter->pLeft != nullptr) // ���� ����� ������� ����������
			{
				if (prev->pLeft == iter) // ���� ��������� ���� �������� ����� �������� ��������
					prev->pLeft = iter->pLeft; // ������������� ������ ������� ���������� ���� ��� ������ ������� ��������
				else // ���� ��������� ���� �������� ������ �������� ��������
					prev->pRight = iter->pLeft; // ������������� ������ ������� ���������� ���� ��� ������� ������� ��������
			}
			else // ���� ������ ������� ����������
			{
				if (prev->pLeft == iter) // ���� ��������� ���� �������� ����� �������� ��������
					prev->pLeft = iter->pRight; // ������������� ������� ������� ���������� ���� ��� ������ ������� ��������
				else // ���� ��������� ���� �������� ������ �������� ��������
					prev->pRight = iter->pRight; // ������������� ������� ������� ���������� ���� ��� ������� ������� ��������
			}
		}
		delete iter; // �������� ����
	}
	else // ���� � ���� ���� ��� �������
	{
		Node* temp = iter; // ��������� ��������� �� ��������� ����
		prev = iter; // ���������� ���������� ���� � prev
		iter = iter->pRight; // ������� � ������� ������� ���������� ����
		while (iter->pLeft != nullptr) // ����� ������������ �������� � ������ ���������
		{
			temp = iter; // ���������� �������� ���� � temp
			iter = iter->pLeft; // ������� � ������ �������
		}
		prev->data = iter->data; // ����������� �������� ������������ �������� � ������������ ����
		delete iter; // �������� ������������ ��������
		temp->pLeft = nullptr; // ��������� ������ ������� temp � nullptr
	}
	--this->_size; // ���������� ������� ������
	return true; // ����������� true, ��� ��� ������� ��� ������� ������
}

template<typename T>
void Tree<T>::showWidth() // ������������ ����� ������(����� �������)
{
	if (this->head == nullptr) return; // ���� ������ ������, ����� �� ������
	int j = 0; // ������� ��� ��������� ���������
	Node* temp; // ��������� ��������� �� ����
	queue<Node*> que; // ������� ��� �������� �����
	que.push(this->head); // ���������� ��������� ���� � �������
	while (!que.empty()) // ����, ���� ������� �� �����
	{
		temp = que.front(); // ��������� ������� �������� �� �������
		cout << ++j << ". " << temp->data << endl;// ����� ������������� �������� ����
		que.pop(); // �������� ������� �������� �� �������
		if (temp->pLeft != nullptr) // ���� ����� ������� ����������
			que.push(temp->pLeft); // ���������� ������ ������� � �������
		if (temp->pRight != nullptr) // ���� ������ ������� ����������
			que.push(temp->pRight); // ���������� ������� ������� � �������
	}
}

template<typename T>
void Tree<T>::showStraight() // ����� ��� ������� ������ ������
{
	if (this->head == nullptr) return; // ���� ������ ������, ����� �� ������
	int j = 0; // ������� ��� ��������� ���������
	Node* temp; // ��������� ��������� �� ����
	stack<Node*> st; // ���� ��� �������� �����
	st.push(this->head); // ���������� ��������� ���� � ����
	while (!st.empty()) // ����, ���� ���� �� ����
	{
		temp = st.top(); // ��������� �������� �������� �� �����
		cout << ++j << ". " << temp->data << endl;// ����� ������������� �������� ����
		st.pop(); // �������� �������� �������� �� �����
		if (temp->pRight != nullptr) // ���� ������ ������� ����������
			st.push(temp->pRight); // ���������� ������� ������� � ����
		if (temp->pLeft != nullptr) // ���� ����� ������� ����������
			st.push(temp->pLeft); // ���������� ������ ������� � ����
	}
}

template<typename T>
inline void Tree<T>::HelperDepth(Node* node) // ��������������� ����� ��� ������ � �������
{
	if (node == nullptr) return; // ���� ���� ������, ����� �� ������
	HelperDepth(node->pLeft); // ����������� ����� ��� ������ ���������
	cout << ++helpDepth << ". " << node->data << endl; // ����� ������������� �������� ����
	HelperDepth(node->pRight); // ����������� ����� ��� ������� ���������
}

template<typename T>
void Tree<T>::showDepth() // ����� ��� ������ ������ � �������
{
	if (this->head != nullptr) // ���� ������ �� ������
	{
		this->helpDepth = 0; // ��������� ��������������� ����������
		this->HelperDepth(this->head); // ����� ���������������� ������ ��� ��������� ����
	}
}

template<typename T>
void Tree<T>::HelperDepthBackward(Node* node) // ��������������� ����� ��� ��������� ������ � �������
{
	if (node == nullptr) return; // ���� ���� ������, ����� �� ������
	HelperDepthBackward(node->pRight); // ����������� ����� ��� ������� ���������
	cout << ++helpDepth << ". " << node->data << endl; // ����� ������������� �������� ����
	HelperDepthBackward(node->pLeft); // ����������� ����� ��� ������ ���������
}

template<typename T>
void Tree<T>::showDepthBackward() // ����� ��� ��������� ������ ������ � �������
{
	if (this->head != nullptr) // ���� ������ �� ������
	{
		this->helpDepth = 0; // ��������� ��������������� ����������
		this->HelperDepthBackward(this->head); // ����� ���������������� ������ ��� ��������� ������ � �������
	}
}

template<typename T>
inline void Tree<T>::HelperClear(Node* node) // ��������������� ����� ��� ������� ������
{
	if (node == nullptr) return; // ���� ���� ������, ����� �� ������
	HelperClear(node->pLeft); // ����������� ����� ��� ������ ���������
	HelperClear(node->pRight); // ����������� ����� ��� ������� ���������
	node->pLeft == nullptr;// ��������� ��������� �� ������ �������
	node->pRight = nullptr; // ��������� ��������� �� ������� �������
	delete node; // �������� ����
}

template<typename T>
void Tree<T>::clear()// ����� ��� ������� ������
{
	if (head != nullptr) // ���� ������ �� ������
	{
		this->HelperClear(this->head); // ����� ���������������� ������ ��� ������� ������
		this->_size = 0; // ��������� ������� ������
		this->head = nullptr; // ��������� ��������� �� ������ ������
	}
}

template<typename T>
Tree<T>& Tree<T>::operator=(const Tree<T>& other) // ���������� ��������� ������������
{
	this->clear(); // ������� �������� ������
	if (other.head == nullptr) return *this; // ���� ������������� ������ ������, ����� �� ������
	Node* temp; // ��������� ��������� �� ����
	stack<Node*> st; // ���� ��� �������� �����
	st.push(other.head); // ���������� ��������� ���� �������������� ������ � ����
	while (!st.empty()) // ����, ���� ���� �� ����
	{
		temp = st.top(); // ��������� �������� �������� �� �����
		this->insert(temp->data); // ������� �������� ���� � ������� ������
		st.pop(); // �������� �������� �������� �� �����
		if (temp->pRight != nullptr) // ���� ������ ������� ����������
			st.push(temp->pRight); // ���������� ������� ������� � ����
		if (temp->pLeft != nullptr) // ���� ����� ������� ����������
			st.push(temp->pLeft); // ���������� ������ ������� � ����
	}
	return *this; // ����������� ������ �� ������� ������
}

template<typename T>
inline Tree<T>* Tree<T>::find(T data) // ����� ��� ������ ���� �� ��������
{
	if (this == nullptr || this->data = data) // ���� ������ ������ ��� �������� ��������� � ������� �����
	{
		return this; // ���������� ��������� �� ������� ����
	}
	else if (data > this->data) // ���� ������� �������� ������, ��� �������� �������� ����
	{
		return this->pRight->find(data); // ����������� ����� ��� ������� ���������
	}
	else
	{
		return this->left->find(data); // ����������� ����� ��� ������ ���������
	}
}

template<typename T> // ����� ��� ���������� ������ ���������
int Tree<T>::getHeight(Node* node)
{
	if (node == nullptr)// ���� ���� ������
		return 0; // ������ ������� ���� ����� 0
	return max(getHeight(node->pLeft), getHeight(node->pRight)) + 1; // ������ ���� ����� ������������ ������ ��� ����������� ���� 1
}

template<typename T>  // ����� ��� ���������� ������� ������������ ����
int Tree<T>::getBalanceFactor(Node* node) // ���� ���� ������
{
	if (node == nullptr) // ���� ���� ������
		return 0;// ������ ������������ ������� ���� ����� 0
	return getHeight(node->pLeft) - getHeight(node->pRight); // ������ ������������ ����� �������� ����� ������ � ������� �����������
}

template<typename T>
typename Tree<T>::Node* Tree<T>::rotateLeft(Node* node) // ����� ��� ������ �������� ������ ����
{
	Node* newRoot = node->pRight; // ����� ������ ������ ������ �������
	node->pRight = newRoot->pLeft; // ����� ��������� ������ ����� ���������� ������ ���������� �������� ����
	newRoot->pLeft = node; // ������� ���� ���������� ����� �������� ������ �����
	return newRoot; // ���������� ����� ������
}

template<typename T>
typename Tree<T>::Node* Tree<T>::rotateRight(Node* node) // ����� ��� ������� �������� ������ ����
{
	Node* newRoot = node->pLeft; // ����� ������ ������ ����� �������
	node->pLeft = newRoot->pRight; // ������ ��������� ������ ����� ���������� ����� ���������� �������� ����
	newRoot->pRight = node; // ������� ���� ���������� ������ �������� ������ �����
	return newRoot; // ���������� ����� ������
}

template<typename T>
typename Tree<T>::Node* Tree<T>::balance(Node* node)// ����� ��� ������������ ����
{
	if (node == nullptr) // ���� ���� ������
		return nullptr; // ���������� nullptr

	int balanceFactor = getBalanceFactor(node); // ��������� ������ ������������

	if (balanceFactor > 1) // ���� ����� ��������� ����
	{
		if (getBalanceFactor(node->pLeft) < 0)// ���� ���������� �������������� ������������ ������ ���������
			node->pLeft = rotateLeft(node->pLeft);// ��������� ����� �������� � ����� ���������
		return rotateRight(node); // ��������� ������ �������� ������ �������� ����
	}
	else if (balanceFactor < -1)  //������ ��������� ����
	{
		if (getBalanceFactor(node->pRight) > 0) // ���� ���������� �������������� ������������ ������� ���������
			node->pRight = rotateRight(node->pRight); // ��������� ������ �������� � ������ ���������
		return rotateLeft(node); // ��������� ����� �������� ������ �������� ����
	}

	return node; // ���� ������ ��������������, ���������� ������� ����
}
