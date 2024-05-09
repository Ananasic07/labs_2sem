#pragma once
#include <string>
#include <iostream>
using namespace std;
class BasicError {
public:
    BasicError() {}
    virtual ~BasicError() {}
    void PrintError() {
        cout << msg << endl;
    }

protected:
    string msg;
};

class WrongSizeError : public BasicError {
public:
    WrongSizeError() { msg = "Ошибка неверного размера: "; }
    virtual ~WrongSizeError() {}
};

class EmptyColletionError : public WrongSizeError {
public:
    EmptyColletionError() { msg += "Список пуст"; }
};

class OverflowError : public WrongSizeError {
public:
    OverflowError() { msg += "Список не может содержать более 30 элементов"; }
};

class WrongIndexError : public BasicError {
public:
    WrongIndexError() { msg = "Ошибка индекса: "; }
    virtual ~WrongIndexError() {}
};

class IndexOutOfRangeError : public WrongIndexError {
public:
    IndexOutOfRangeError() { msg += "Индекс больше размера списка"; }
    ~IndexOutOfRangeError() {}
};

class NegativeIndexError : public WrongIndexError {
public:
    NegativeIndexError() { msg += "Индекс отрицательный"; }
    ~NegativeIndexError() {}
};
