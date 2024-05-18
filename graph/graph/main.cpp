// graph.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "graph.h"

int main(int argc, char* argv[])
//argc (argument count) - количество аргументов командной строки
//argv (argument vector) - массив указателей на строки, содержащие аргументы командной строки.
{
    system("chcp 1251");
    makegraph(); //создание графа
    cout << endl;
    thread console(menu);// Запуск потока для работы с консолью
    // Ввод количества ребер графа в переменную amountVerts 
    glutInit(&argc, argv); //начальная инициализация окна
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    //установка режима отображения:
    // GLUT_DEPTH включает Z-буфер (буфер глубины)
    // GLUT_DOUBLE включает двойной экранный буфер
    // GLUT_RGBA включает четырехкомпонентный цвет (используется по умолчанию)
    glutInitWindowSize(800, 800); //размер окна
    glutCreateWindow("Графы"); //заголовок окна
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f); //цвет фона
    glutDisplayFunc(display); //функция которой мы передаем имя функции для отрисовки окна
    glutMainLoop(); //запускаем всё проинициализированное, проще говоря та же ф-я main
    console.join(); //Основной поток ожидает завершения потока console, созданного ранее.
    return 0;
}

