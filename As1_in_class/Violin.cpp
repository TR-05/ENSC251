#include "StringInstruments.h"
#include <iostream>

Violin::Violin()
{
    maker = "Amati";
    size = 54;
    strings[0] = 'G';
    strings[1] = 'D';
    strings[2] = 'A';
    strings[3] = 'E';
    // std::cout << "Violin constructor" << std::endl; // Commented out to unclog output
}

Violin::~Violin()
{
    // std::cout << "Violin destructor" << std::endl; // Commented out to unclog output
}