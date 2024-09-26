#pragma once
#include <string>

class StringInstruments
{
public:
    StringInstruments();
    ~StringInstruments();
    int getSize();
    std::string getMaker();
    std::array<std::string, 4> getStrings();
    void setSize(int size);
    void setMaker(std::string maker);
    void setStrings(std::array<std::string, 4> strings);
    
protected:
    int size;
    std::string maker;
    std::array<std::string, 4> strings = {"E", "A", "D", "G"};
};

class Violin : public StringInstruments
{
public:
    Violin();
    ~Violin();
};

class Cello : public StringInstruments
{
public:
    Cello();
    ~Cello();
};