/**
 * @file pairs.h
 * @author Trevor Ruttan
 * @Date 10/22/2024
 * @version 1.0
 * @section DESCRIPTION
 */
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ Trevor Ruttan ____ _____10/22/2024______________
//
// ____ 301580889 ______
//

#include <iostream>
using namespace std;

class Pairs
{
public:
Pairs( );
Pairs(int first);
Pairs(int first, int second);
//other members and friends
friend istream& operator >>(istream& ins, Pairs& second);
friend ostream& operator <<(ostream& outs, const Pairs& second);
friend Pairs operator +(const Pairs& first, const Pairs& second);
friend Pairs operator -(const Pairs& first, const Pairs& second);
friend Pairs operator *(const Pairs& first, const Pairs& second);

private:
int firstNumber;
int secondNumber;
};