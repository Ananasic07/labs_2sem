#include <iostream>
#include "student.h"

using namespace std;

Student::Student() { rating = 0; }
Student::~Student() {}
void Student::Show() {
	cout << "\nStudent name: " << name << "\n";
	cout << "\nStudent age: " << age << "\n";
	cout << "\nStudent rating: " << rating << "\n";
}

void Student::Input() {
	cout << "\nEnter student name: "; cin >> name;
	cout << "\nEnter student age: "; cin >> age;
	cout << "\nEnter student rating: "; cin >> rating;
}

Student::Student(string N, int A, float R) {
	name = N;
	age = A;
	rating = R;
}

Student::Student(const Student& student) {
	name = student.name;
	age = student.age;
	rating = student.rating;
}
Student& Student::operator=(const Student& student) {
	if (&student == this) { return *this; }
	name = student.name;
	age = student.age;
	rating = student.rating;
	return *this;
}
void Student::set_rating(float R) {
	rating = R;
}