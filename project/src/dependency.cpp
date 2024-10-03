#include <iostream>

#include "dependency.h"

Parent::Parent() {}

void Parent::print() {
    std::cout << "default" << std::endl;
}

Child::Child(int x) :
    x(x) {}
void Child::print2() {
    std::cout << "child" << x << std::endl;
}