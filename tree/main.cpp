// SFML пробный.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>
#include <stack>
#include <fstream>
#include <vector>
#include "tree.h"

using namespace std; // Использование стандартного пространства имен std
using namespace sf; // Использование пространства имен sf (SFML)
int main()
{
    //RenderWindow MainWindow(VideoMode(800, 600), "MainWindow");
	system("chcp 1251 >> null");
	//system("color F0");
	cout << "Создание дерева и вывод консоль." << endl;
	cout << "Обход в ширину:" << endl;
	Tree<int> tr, tr1;
	tr.insert(1); // Вставка элемента 1 в дерево tr
	tr.insert(2); // Вставка элемента 2 в дерево tr
	tr.insert(3); // Вставка элемента 3 в дерево tr
	tr.insert(4); // Вставка элемента 4 в дерево tr
	tr.insert(5); // Вставка элемента 5 в дерево tr
	tr.insert(8); // Вставка элемента 8 в дерево tr
	tr.insert(9); // Вставка элемента 9 в дерево tr
	tr.insert(10); // Вставка элемента 10 в дерево tr
	tr.insert(11); // Вставка элемента 11 в дерево tr
	tr.showWidth(); // Вывод дерева tr в порядке обхода в ширину
	cout << endl << endl;

	cout << "Удаление элемента и попытка добавления элемента со значением, которое существует в дереве:" << endl;
	if (tr.erase(2)) cout << "Уделение успешно." << endl; // Удаление элемента 2 из дерева tr и вывод результата
	else cout << "Удаление невозможно." << endl;
	tr.insert(8); // Попытка вставки элемента 8 в дерево tr (элемент уже существует)
	cout << "Прямой обход." << endl; 
	tr.showStraight(); // Вывод дерева tr в прямом порядке обхода
	cout << endl << endl;
	cout << "Выполнение оператора присваивания" << endl;
	tr1 = tr;// Присваивание дереву tr1 значения дерева tr
	cout << "Вывод скопированного дерева." << endl;
	cout << "Обход в глубину." << endl;
	tr1.showDepth(); // Вывод дерева tr1 в порядке обхода в глубину
	cout << endl << endl;

	cout << "Отрисовка полученного дерева." << endl;
	cout << "Внимание на окно." << endl;

	sf::RenderWindow window(sf::VideoMode(1000, 800), "Binary Tree"); // Создание окна для отрисовки дерева
	window.setFramerateLimit(10); // Установка ограничения частоты кадров в 10 FPS

	sf::CircleShape shape(40.f); // Создание круговой формы для отрисовки узлов дерева
	shape.setFillColor(sf::Color::White); // Установка заливки формы узла белым цветом
	shape.setOutlineThickness(3.0f); // Установка толщины контура формы узла
	shape.setOutlineColor(sf::Color::Black); // Установка цвета контура формы узла черным
	shape.setOrigin(shape.getLocalBounds().width / 2, shape.getLocalBounds().height / 2); // Установка центра формы узла в ее геометрический центр
	shape.setPosition(500.f, 48.f); // Установка начальной позиции формы узла

	sf::Font font; // Создание объекта шрифта для отображения текста
	if (!font.loadFromFile("arial.ttf")) // Попытка загрузить шрифт Arial из файла
	{
		cout << "Ошибка" << endl; // Вывод сообщения об ошибке, если загрузка шрифта не удалась
	}

	sf::Text text; // Создание объекта текста для отображения значений узлов
	text.setFont(font); // Установка загруженного шрифта для текста
	text.setString("8"); // Установка начального значения текста как "8"
	text.setCharacterSize(18); // Установка размера символов в 18 пикселей
	text.setFillColor(sf::Color::Black); // Установка цвета текста в черный
	text.setStyle(sf::Text::Bold); // Установка стиля текста в полужирный
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2); // Установка центра текста в его геометрический центр
	text.setPosition(shape.getPosition().x - 3, shape.getPosition().y - 3); // Установка начальной позиции текста относительно формы узла

	vector<pair<sf::CircleShape, sf::Text>> vec; // Создание вектора пар форм узлов и текста
	vec.resize(8); // Установка размера вектора в 8 элементов
	vec[0] = make_pair(shape, text); // Добавление начальной формы узла и текста в вектор

	shape.setPosition(300.f, 118.f); // Установка позиции формы узла
	text.setString("4"); // Установка значения текста как "4"
	text.setPosition(shape.getPosition().x - 3, shape.getPosition().y - 3); // Установка позиции текста относительно формы узла
	vec[1] = make_pair(shape, text); // Добавление формы узла и текста в вектор

	shape.setPosition(700.f, 118.f); // Установка позиции формы узла
	text.setString("9"); // Установка значения текста как "9"
	text.setPosition(shape.getPosition().x - 3, shape.getPosition().y - 3); // Установка позиции текста относительно формы узла
	vec[2] = make_pair(shape, text); // Добавление формы узла и текста в вектор

	shape.setPosition(200.f, 188.f); // Установка позиции формы узла
	text.setString("2"); // Установка значения текста как "2"
	text.setPosition(shape.getPosition().x - 3, shape.getPosition().y - 3); // Установка позиции текста относительно формы узла
	vec[3] = make_pair(shape, text); // Добавление формы узла и текста в вектор

	shape.setPosition(400.f, 188.f); // Установка позиции формы узла
	text.setString("3"); // Установка значения текста как "3"
	text.setPosition(shape.getPosition().x - 3, shape.getPosition().y - 3); // Установка позиции текста относительно формы узла
	vec[4] = make_pair(shape, text); // Добавление формы узла и текста в вектор

	shape.setPosition(600.f, 188.f); // Установка позиции формы узла
	text.setString("10"); // Установка значения текста как "10"
	text.setPosition(shape.getPosition().x - 3, shape.getPosition().y - 3); // Установка позиции текста относительно формы узла
	vec[5] = make_pair(shape, text); // Добавление формы узла и текста в вектор

	shape.setPosition(800.f, 188.f); // Установка позиции формы узла
	text.setString("11"); // Установка значения текста как "11"
	text.setPosition(shape.getPosition().x - 3, shape.getPosition().y - 3); // Установка позиции текста относительно формы узла
	vec[6] = make_pair(shape, text); // Добавление формы узла и текста в вектор

	shape.setPosition(130.f, 290.f); // Установка позиции формы узла
	text.setString("1"); // Установка значения текста как "1"
	text.setPosition(shape.getPosition().x - 3, shape.getPosition().y - 3); // Установка позиции текста относительно формы узла
	vec[7] = make_pair(shape, text); // Добавление формы узла и текста в вектор

	sf::RectangleShape line(sf::Vector2f(211, 3)); // Создание прямоугольной формы для линии с размерами 211x3 пикселей
	vector<sf::RectangleShape> vec_lines; // Создание вектора для хранения линий (связей между узлами дерева)
	vec_lines.resize(7); // Установка размера вектора vec_lines на 7 элементов (количество линий)

	vec_lines[0].setSize(sf::Vector2f(211, 3)); // Установка размера первой линии на 211x3 пикселей
	vec_lines[0].setFillColor(sf::Color::Black); // Установка цвета заливки первой линии в черный
	vec_lines[0].setPosition(vec[0].first.getPosition()); // Установка позиции первой линии из позиции первого узла
	vec_lines[0].setRotation(160); // Установка угла поворота первой линии на 160 градусов

	vec_lines[1].setSize(sf::Vector2f(211, 3)); // Установка размера первой линии на 211x3 пикселей
	vec_lines[1].setFillColor(sf::Color::Black); // Установка цвета заливки первой линии в черный
	vec_lines[1].setPosition(vec[0].first.getPosition()); // Установка позиции первой линии из позиции первого узла
	vec_lines[1].setRotation(20); // Установка угла поворота первой линии на 20 градусов

	vec_lines[2].setSize(sf::Vector2f(122, 3)); // Установка размера первой линии на 211x3 пикселей
	vec_lines[2].setFillColor(sf::Color::Black); // Установка цвета заливки первой линии в черный
	vec_lines[2].setPosition(vec[1].first.getPosition()); // Установка позиции первой линии из позиции первого узла
	vec_lines[2].setRotation(145); // Установка угла поворота первой линии на 145 градусов

	vec_lines[3].setSize(sf::Vector2f(122, 3)); // Установка размера первой линии на 211x3 пикселей
	vec_lines[3].setFillColor(sf::Color::Black); // Установка цвета заливки первой линии в черный
	vec_lines[3].setPosition(vec[1].first.getPosition()); // Установка позиции первой линии из позиции первого узла
	vec_lines[3].setRotation(35); // Установка угла поворота первой линии на 35 градусов

	vec_lines[4].setSize(sf::Vector2f(122, 3)); // Установка размера первой линии на 211x3 пикселей
	vec_lines[4].setFillColor(sf::Color::Black); // Установка цвета заливки первой линии в черный
	vec_lines[4].setPosition(vec[2].first.getPosition()); // Установка позиции первой линии из позиции первого узла
	vec_lines[4].setRotation(145); // Установка угла поворота первой линии на 145 градусов

	vec_lines[5].setSize(sf::Vector2f(123, 3)); // Установка размера первой линии на 211x3 пикселей
	vec_lines[5].setFillColor(sf::Color::Black); // Установка цвета заливки первой линии в черный
	vec_lines[5].setPosition(vec[2].first.getPosition()); // Установка позиции первой линии из позиции первого узла
	vec_lines[5].setRotation(35); // Установка угла поворота первой линии на 35 градусов

	vec_lines[6].setSize(sf::Vector2f(122, 3)); // Установка размера первой линии на 211x3 пикселей
	vec_lines[6].setFillColor(sf::Color::Black); // Установка цвета заливки первой линии в черный
	vec_lines[6].setPosition(vec[3].first.getPosition()); // Установка позиции шестой линии из позиции первого узла
	vec_lines[6].setRotation(125); // Установка угла поворота первой линии на 125 градусов

	while (window.isOpen()) // Цикл, выполняющийся пока окно открыто
	{
		sf::Event event; // Объект для обработки событий окна
		while (window.pollEvent(event)) // Цикл обработки событий окна
		{
			if (event.type == sf::Event::Closed) // Если событие - закрытие окна
				window.close(); // Закрыть окно
		}
		window.clear(sf::Color::White); // Очистка окна белым цветом
		for (size_t i = 0; i < vec_lines.size(); i++) // Цикл для отрисовки всех линий
		{
			window.draw(vec_lines[i]); // Отрисовка текущей линии
		}

		for (int i = 0; i < vec.size(); i++) // Цикл для отрисовки всех узлов и текста
		{
			window.draw(vec[i].first); // Отрисовка формы узла
			window.draw(vec[i].second); // Отрисовка текста узла
		}


		window.display(); // Отображение содержимого окна на экране
	}

	/*
    while (MainWindow.isOpen()) {
        Event event;
        while (MainWindow.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                MainWindow.close();
                break;
            case Event::GainedFocus:
                //Действия, если окно в фокусе
                cout << "Focused" << endl;
                break;
            case Event::LostFocus:
                //Действия, если окно потеряло фокус
                cout << "Lost focus" << endl;
                break;
            case Event::Resized:
                //Действия, если был изменен размер окна
                cout << "Window resized" << endl;
                break;
            }
        }
    };
	*/
    return 0;
}

