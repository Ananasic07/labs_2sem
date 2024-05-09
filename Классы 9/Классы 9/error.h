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
    WrongSizeError() { msg = "������ ��������� �������: "; }
    virtual ~WrongSizeError() {}
};

class EmptyColletionError : public WrongSizeError {
public:
    EmptyColletionError() { msg += "������ ����"; }
};

class OverflowError : public WrongSizeError {
public:
    OverflowError() { msg += "������ �� ����� ��������� ����� 30 ���������"; }
};

class WrongIndexError : public BasicError {
public:
    WrongIndexError() { msg = "������ �������: "; }
    virtual ~WrongIndexError() {}
};

class IndexOutOfRangeError : public WrongIndexError {
public:
    IndexOutOfRangeError() { msg += "������ ������ ������� ������"; }
    ~IndexOutOfRangeError() {}
};

class NegativeIndexError : public WrongIndexError {
public:
    NegativeIndexError() { msg += "������ �������������"; }
    ~NegativeIndexError() {}
};
