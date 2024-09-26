#pragma once


class Parent {
public:
    Parent();
    ~Parent();
    void print();
};

class Child : public Parent {
public:
    Child(int x);
    ~Child();
    void print2();
    private:
    int x;
};