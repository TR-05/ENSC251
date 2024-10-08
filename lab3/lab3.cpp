/**
 * @file lab3.cpp
 * @author Trevor Ruttan
 * @Date 10/8/2024
 * @version 1.0
 * @section DESCRIPTION
 */
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ Trevor Ruttan ____ _____10/8/2024______________
//
// ____ 301580889 ______
//

#include <iostream>

#include "Package.h"

#include "OvernightPackage.h"

#include "TwoDayPackage.h"

int main() {
  Package package("Stan Lee", "123 Main St", "ComicTown", "NY", "12345", 10, 2.5);
  TwoDayPackage twoDayPackage("Herbert Tsang", "456 Parkway", "Burnaby", "BC", "67890", 10, 2.5, 5);
  OvernightPackage overnightPackage("Joe Biden", "1 White House St", "Washington DC", "PA", "13579", 10, 2.5, 2.5);

  std::cout << "Package cost: $" << package.calculateCost() << std::endl;
  std::cout << "Two-day package cost: $" << twoDayPackage.calculateCost() << std::endl;
  std::cout << "Overnight package cost: $" << overnightPackage.calculateCost() << std::endl;

  return 0;
}