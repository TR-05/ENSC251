#pragma once


class Parent {
public:
    Parent();
    ~Parent() = default;
    void print();
};

class Child : public Parent {
public:
    Child(int x);
    ~Child() = default;
    void print2();
    private:
    int x;
};