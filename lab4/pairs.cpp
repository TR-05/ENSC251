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

/**
 * @brief Default constructor for Pairs
 */
Pairs::Pairs() {
  firstNumber = 0;
  secondNumber = 0;
}

/**
 * @brief Constructor for Pairs, taking in one integer input, setting the second
 * number to 0
 * @param first The first number in the pair
 */
Pairs::Pairs(int first) {
  firstNumber = first;
  secondNumber = 0;
}

/**
 * @brief Constructor for Pairs, taking in two integer inputs
 * @param first The first number in the pair
 * @param second The second number in the pair
 */
Pairs::Pairs(int first, int second) {
  firstNumber = first;
  secondNumber = second;
}

/**
 * @brief Overloaded input operator for Pairs, reads input in the form '(int,
 * int)', if formatted incorrectly, does not modify object and continues
 * @param ins The input stream
 * @param pair The Pairs object to modify
 */
istream &operator>>(istream &ins, Pairs &pair) {
  Pairs temp;
  char ch;

  ins >> ch;

  if (ch != '(') {
    cout << "Incorrect Format Inputted, Not Modifying Object And Continuing"
         << endl;
    return ins;
  }

  if (!(ins >> temp.firstNumber)) {
    cout << "Incorrect Format Inputted, Not Modifying Object And Continuing"
         << endl;
    return ins;
  }

  ins >> ch;

  if (ch != ',') {
    cout << "Incorrect Format Inputted, Not Modifying Object And Continuing"
         << endl;
    return ins;
  }

  if (!(ins >> temp.secondNumber)) {
    cout << "Incorrect Format Inputted, Not Modifying Object And Continuing"
         << endl;
    return ins;
  }

  ins >> ch;
  if (ch != ')') {
    cout << "Incorrect Format Inputted, Not Modifying Object And Continuing"
         << endl;
    return ins;
  }

  pair = temp;

  return ins;
}

/**
 * @brief Overloaded output operator for Pairs, outputs Pair in the form
 * '(int, int)'
 * @param outs The output stream
 * @param pair The Pairs object to output
 */
ostream &operator<<(ostream &outs, const Pairs &pair) {
  outs << "(" << pair.firstNumber << "," << pair.secondNumber << ")";
  return outs;
}

/**
 * @brief Overloaded addition operator for Pairs, adds two Pairs together in
 * the form (a, b) + (c, d) = (a + c, b + d)
 * @param first The first Pairs object to modify
 * @param second The second Pairs object to modify
 * @return The sum of the two Pairs
 */
Pairs operator+(const Pairs &first, const Pairs &second) {
  return Pairs(first.firstNumber + second.firstNumber,
               first.secondNumber + second.secondNumber);
}

/**
 * @brief Overloaded subtraction operator for Pairs, subtracts two Pairs
 * together in the form (a, b) - (c, d) = (a - c, b - d)
 * @param first The first Pairs object to modify
 * @param second The second Pairs object to modify
 * @return Pairs The result of the subtraction
 */
Pairs operator-(const Pairs &first, const Pairs &second) {
  return Pairs(first.firstNumber - second.firstNumber,
               first.secondNumber - second.secondNumber);
}

/**
 * @brief Overloaded multiplication operator for Pairs, multiplies two Pairs
 * together in the form (a, b) * (c, d) = (a * c, b * d)
 * @param first The first Pairs object to modify
 * @param second The second Pairs object to modify
 * @return Pairs The result of the multiplication
 */
Pairs operator*(const Pairs &first, const Pairs &second) {
  return Pairs(first.firstNumber * second.firstNumber,
               first.secondNumber * second.secondNumber);
}
