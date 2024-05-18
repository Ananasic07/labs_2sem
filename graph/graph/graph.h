#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "freeglut.h"
#include <string>
#include <thread>
using namespace std;

const int maxSize = 8;
class Graph
{
private:
    vector<int> vertList; //список вершин графа
    int adjMatrix[maxSize][maxSize]; //матрица смежности для представления ребер
public:
    Graph();
    bool isEmpty(); //проверка на пустоту графа
    bool isFull(); //проверка на заполненность
    int getVertText(int i); //получение номера вершины
    void getAdjMatrix(int(&matrix)[maxSize][maxSize]);
    int getAmountVerts(); //получение количества вершин
    int getVertPos(const int& vertex); //получение позиции вершины
    void insertVertex(const int& vertex); //добавление вершины
    void insertEdge(const int& vertex1, const int& vertex2, int weight); //добавление направленного ребра
    void insertEdgeWO(const int& vertex1, const int& vertex2, int weight); //добавление ненаправленного ребра
    void print(); //печать матрицы
    void eraseEdge(const int& vertex1, const int& vertex2); // удаление ребра
    void eraseVertex(const int& vertex); //удаление вершины
    void dijkstra(int startVertex); // дейкстра
    void BFS(int startVertex); // обход в ширину
    void DFS(int startVertex); // обход в глубину
    void dfsRec(vector<bool>& visited, int currVertex, const vector<int>& vertList, int adjMatrix[][maxSize]); //рекурсия для обхода в глубину
    void drawGraph();
};
void drawCircle(int x, int y, int R); //рисует круг на экране
void display(); //Функция отображения для графического интерфейса
void drawVertex(int n); //Рисует вершину графа
void setCoords(int i, int n); //Задает координаты вершины
void drawLine(int text, int x0, int y0, int x1, int y1, int start, int end, bool f); //Рисует линию между двумя вершинами графа
void drawText(int text, int x1, int y1, bool f); //Отображает текст на экране
void menu(); //Отображает меню
void makegraph(); //Создает и отображает граф на экране
