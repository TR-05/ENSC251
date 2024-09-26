#include <iostream>

#include "include/dependency.h"

void Parent::print() {
    std::cout << "Parent" << std::endl;
}

Child::Child(int x) :
    x(x) {}
void Child::print2() {
    std::cout << "child" << x << std::endl;
}