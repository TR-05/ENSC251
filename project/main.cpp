#include <iostream>
#include "include/dependency.h"

int main()
{
    Parent p;
    p.print();
    Child c(5);
    c.print();
    c.print2();
}