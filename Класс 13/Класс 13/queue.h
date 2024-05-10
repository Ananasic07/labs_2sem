#pragma once
#include<queue>
#include<vector>
#include<cmath>
#include"money.h"

using namespace std;

typedef queue<Money> q;
typedef vector<Money> v;

q makeQueue(int size) {
	q queue;
	Money m;
	for (int i = 0; i < size; i++) {
		cin >> m;
		queue.push(m);
	}
	return queue;
}

v copyQueue(q queue) {
	v vector;
	while (!queue.empty()) {
		vector.push_back(queue.front());
		queue.pop();
	}
	return vector;
}

q copyVector(v vector) {
	q queue;
	for (int i = 0; i < vector.size(); i++) {
		queue.push(vector[i]);
	}
	return queue;
}

void printQueue(q queue) {
	cout << "Queue: ";
	while (!queue.empty()) {
		cout << queue.front() << " ";
		queue.pop();
	}
	cout << endl;
}

Money averageQ(q queue) {
	v vec = copyQueue(queue);
	int n = 1;
	Money sum = queue.front();
	queue.pop();
	while (!queue.empty()) {
		sum = sum + queue.front();
		queue.pop();
		n++;
	}
	queue = copyVector(vec);
	cout << "Average (queue): " << sum / n << endl;
	return sum / n;
}

void addQueue(q& queue, Money m, int index) {
	v vec; Money mm; int i = 1;
	while (!queue.empty()) {
		mm = queue.front();
		if (i == index) { vec.push_back(m); }
		vec.push_back(mm);
		queue.pop();
		i++;
	}
	queue = copyVector(vec);
}

Money minElem(q queue) {
	Money min = queue.front();
	v vec = copyQueue(queue);
	while (!queue.empty()) {
		if (queue.front() < min) { min = queue.front(); }
		queue.pop();
	}
	queue = copyVector(vec);
	cout << "Min elem: " << min << endl;

	v vec2; Money m;
	while (!queue.empty()) {
		m = queue.front();
		vec2.push_back(m - min);
		queue.pop();
	}
	queue = copyVector(vec2);

	return min;
}
