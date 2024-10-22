/**
 * @file pairs.cpp
 * @author Trevor Ruttan
 * @Date 10/22/2024
 * @version 1.0
 * @section DESCRIPTION
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and followed
// the Academic Honesty and Integrity related policies as outlined in the
// syllabus.
//
// _____ Trevor Ruttan ____ _____10/22/2024______________
//
// ____ 301580889 ______
//

#include <iostream>

#include "pairs.h"

using namespace std;

Pairs::Pairs() {
  firstNumber = 0;
  secondNumber = 0;
}

Pairs::Pairs(int first) {
  firstNumber = first;
  secondNumber = 0;
}

Pairs::Pairs(int first, int second) {
  firstNumber = first;
  secondNumber = second;
}

istream &operator>>(istream &ins, Pairs &second) {

  char ch;
  ins >> ch;
  ins >> second.firstNumber;
  ins >> ch;

  ins >> second.secondNumber;
  ins >> ch;

  return ins;
}

ostream &operator<<(ostream &outs, const Pairs &second) {
  outs << "(" << second.firstNumber << ", " << second.secondNumber << ")";
  return outs;
}

Pairs operator+(const Pairs &first, const Pairs &second) {
  return Pairs(first.firstNumber + second.firstNumber,
               first.secondNumber + second.secondNumber);
}

Pairs operator-(const Pairs &first, const Pairs &second) {
  return Pairs(first.firstNumber - second.firstNumber,
               first.secondNumber - second.secondNumber);
}

Pairs operator*(const Pairs &first, const Pairs &second) {
  return Pairs(first.firstNumber * second.firstNumber,
               first.secondNumber * second.secondNumber);
}
