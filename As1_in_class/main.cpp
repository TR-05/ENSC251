#include "StringInstruments.h"
#include <iostream>

int main()
{
    Cello cello;
    std::cout << "Cello size: " << cello.getSize() << std::endl;
    std::cout << "Cello Strings: ";
    for (int i = 0; i < 4; i++)
    {
        std::cout << cello.getStrings()[i] << " ";
    }

    std::cout << std::endl;
    Violin violin;
    std::cout << "Violin size: " << violin.getSize() << std::endl;
    std::cout << "Violin Strings: ";
    for (int i = 0; i < 4; i++)
    {
        std::cout << violin.getStrings()[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}