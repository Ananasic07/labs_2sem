#pragma once
#include"money.h"
#include<iostream>
#include<vector>
using namespace std;

typedef vector<Money>vec;
vec makeVector(int size) {
	vec v;
	for (int i = 1; i <= size; i++) {
		Money tmp(rand() % 100, rand() % 100);
		v.push_back(tmp);
	}
	return v;
}

void printVector(vec v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int average(vec v) {
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += (v[i].getRub() + v[i].getKop());
	}
	int n = v.size();
	cout << "Average: " << sum / n << endl;
	return sum / n;
}

void minElem(vec v) {
	Money min = v[0];
	for (int i = 0; i < v.size(); i++) {

		if (min > v[i]) { min = v[i]; }
	}
	cout << "Min element = " << min << endl;

	for (int i = 0; i < v.size(); i++) {
		v[i] = v[i] - min;
	}
	printVector(v);
}
