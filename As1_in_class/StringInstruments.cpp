#include "StringInstruments.h"
#include <iostream>

StringInstruments::StringInstruments() {}

StringInstruments::~StringInstruments() {}

int StringInstruments::getSize()
{
    return size;
}

std::string StringInstruments::getMaker()
{
    return maker;
}

std::array<std::string, 4> StringInstruments::getStrings()
{
    return strings;
}

void StringInstruments::setSize(int size)
{
    this->size = size;
}

void StringInstruments::setMaker(std::string maker)
{
    this->maker = maker;
}

void StringInstruments::setStrings(std::array<std::string, 4> strings)
{
    this->strings = strings;
}