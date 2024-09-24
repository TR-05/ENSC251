/**
 * @file lab2.cpp
 * @author Trevor Ruttan
 * @Date 9/24/2024
 * @version 1.0
 * @section DESCRIPTION
 */
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ Trevor Ruttan ____ _____9/24/2024______________
//
// ____ 301580889 ______
//

#include <iostream>

#include "Car.h"

int main() {
  Car oddysey(2001, "Honda");

  // Call accelerate 7 times and print the speed each time
  for (int i{0}; i < 7; i++) {
    oddysey.accelerate();
    std::cout << oddysey.getSpeed() << std::endl;
  }
  // Call brake 5 times and print the speed each time
  for (int i {
      0
    }; i < 5; i++) {
    oddysey.brake();
    std::cout << oddysey.getSpeed() << std::endl;
  }
}