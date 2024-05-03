/*#include <iostream>
#include "tree.h"

using namespace std;

Tree::Tree(void) {
	beg = nullptr;
	size = 0;
	cur = 0;
}
Tree::Tree(int n) {
	beg = new Object * [n];
	cur = 0;
	size = n;
}
Tree::~Tree(void) {
	if (beg != 0) { delete[] beg; }
	beg = 0;
}
void Tree::Add() {
	Object* p;

	cout << "\n1.Person\n2.Student\nEnter variant >> ";
	int y;
	cin >> y; cout << "\n";

	if (y == 1) {
		Person* a = new (Person);
		a->input();
		p = a;
		if (cur < size) {
			beg[cur] = p;
			cur++;
		}
	}
	else if (y == 2) {
		Student* b = new (Student);
		b->input();
		p = b;
		if (cur < size) {
			beg[cur] = p;
			cur++;
		}
	}
	else return;
}
void Tree::Show()
{
	if (cur == 0) { cout << "\nEmpty" << endl; }
	Object** p = beg;
	for (int i = 0; i < cur; i++) {
		(*p)->show();
		p++;
	}
}
int Tree::operator()() { return cur; }
void Tree::Del(void) {
	if (cur == 0) { return; }
	cur--;
}
void Tree::Find(int tmp) {
	Object** p = beg;
	for (int i = 0; i < cur; i++) {
		if (i == tmp - 1) { (*p)->show(); }
		p++;
	}
}
void Tree::HandleEvent(const TEvent& event) {
	if (event.what == evMessage) {
		Object** p = beg;
		for (int i = 0; i < cur; i++) {
			(*p)->show();
			++p;
		}
	}
}*/