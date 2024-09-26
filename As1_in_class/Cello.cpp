#include "StringInstruments.h"
#include <iostream>

Cello::Cello()
{
    maker = "SpongeBob";
    size = 76;
    strings[0] = 'C';
    strings[1] = 'G';
    strings[2] = 'D';
    strings[3] = 'A';
    //std::cout << "Cello constructor" << std::endl; // Commented out to unclog output
}

Cello::~Cello()
{
    //std::cout << "Cello destructor" << std::endl; // Commented out to unclog output
}