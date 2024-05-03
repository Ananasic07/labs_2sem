#pragma once

#include <iostream>
#include <string>
#include "person.h"

using namespace std;

class Student : public Person {
protected:
	float rating;
public:
	Student();
	Student(string name, int age, float rating);
	Student(const Student& s);
	~Student();
	float get_rating() { return rating; }
	void set_rating(float rating);
	void Show();
	void Input();
	Student& operator=(const Student&);
};
