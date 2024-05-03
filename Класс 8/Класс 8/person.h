#pragma once

#include <iostream>
#include <string>
#include "object.h"
#include "event.h"

using namespace std;

class Person : public Object {
protected:
	string name;
	int age;
public:
	Person();
	Person(string name, int age);
	Person(const Person& p);
	virtual ~Person();
	string get_name();
	int get_age();
	void set_name(string name);
	void set_age(int age);
	Person& operator =(const Person& p);
	void Show();
	void Input();
	void HandleEvent(const TEvent& r);
};