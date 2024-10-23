/**
 * @file lab4.cpp
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

using namespace std;
#include "pairs.h"

int main() {
  Pairs p1;
  Pairs p2(1);
  Pairs p3(2, 3);

  // Test overloaded output operator
  cout << "p1: " << p1 << endl;
  cout << "p2: " << p2 << endl;
  cout << "p3: " << p3 << endl;

  // Test overloaded input operator
  cout << "Enter a pair of numbers in form (a,b): ";
  Pairs pInput;
  cin >> pInput;
  cout << "Input Pair: " << pInput << endl;

  // Test overloaded arithmetic operators
  cout << "pInput+p3: " << pInput + p3 << endl;
  cout << "pInput-p3: " << pInput - p3 << endl;
  cout << "pInput*p3: " << pInput * p3 << endl;

  return 0;
}