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
Package package("Craig Scratchley", "ASB 9800", "Burnaby", "BC", "123456",
                "Herbert Tsang", "AQ 3182", "Burnaby", "BC", "123456", 10, 2.5);

TwoDayPackage twoDayPackage("Mike S", "AQ 3181", "Burnaby", "BC", "123456",
                            "Mike H", "ASB 9801", "Burnaby", "BC", "123456", 10, 2.5, 5);

OvernightPackage overnightPackage("Kamala Harris", "2 Capitol Hill", "Washington DC", "DC", "205033",
                                  "Joe Biden", "1 White House St", "Washington DC", "PA", "135793", 10, 2.5, 1.5);

  std::cout << "Package cost: $" << package.calculateCost() << std::endl;
  std::cout << "Two-day package cost: $" << twoDayPackage.calculateCost() << std::endl;
  std::cout << "Overnight package cost: $" << overnightPackage.calculateCost() << std::endl;

  return 0;
}