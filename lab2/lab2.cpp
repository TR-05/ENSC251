/**
 * @file lab2.cpp
 * @author Trevor Ruttan
 * @Date 9/23/2024
 * @version 1.0
 * @section DESCRIPTION
 */
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ Trevor Ruttan ____ _____9/23/2024______________
//
// ____ 301580889 ______
//

#include <iostream>

#include "Car.h"

int main() {
  Car priusPrime(2001, "Honda");
  for (int i {
      0
    }; i < 7; i++) {
    priusPrime.accelerate();
    std::cout << priusPrime.getSpeed() << std::endl;
  }
  for (int i {
      0
    }; i < 5; i++) {
    priusPrime.brake();
    std::cout << priusPrime.getSpeed() << std::endl;
  }
}