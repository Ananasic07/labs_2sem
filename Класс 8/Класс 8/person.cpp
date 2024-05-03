#include <iostream>
#include "person.h"

using namespace std;

Person::Person() {
	name = " ";
	age = 0;
}

Person::Person(string N, int A) {
	name = N;
	age = A;
}

Person::Person(const Person& person) {
	name = person.name;
	age = person.age;
}

Person::~Person() {}

string Person::get_name() { return name; }

int Person::get_age() { return age; }

void Person::set_name(string N) { name = N; }

void Person::set_age(int A) { age = A; }

Person& Person::operator=(const Person& person) {
	if (&person == this) { return *this; }
	name = person.name;
	age = person.age;
	return *this;
}

void Person::Show() {
	cout << "\nPerson name: " << name << endl;
	cout << "\nPerson age: " << age << endl;
}

void Person::Input() {
	cout << "\nEnter name: "; cin >> name;
	cout << "\nEnter age: "; cin >> age;
}

void Person::HandleEvent(const TEvent& r) {
	if (r.what == evMessage) {
		switch (r.command) {
		case cmGet:cout << "Автор = " << this->get_age() << endl;
			cout << "Имя = " << this->get_name() << endl;
			break;
		}
	}
}