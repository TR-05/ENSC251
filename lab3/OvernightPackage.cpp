/**
 * @file OvernightPackage.cpp
 * @author Trevor Ruttan
 * @Date 10/8/2024
 * @version 1.0
 * @section DESCRIPTION
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others. I acknowledged that I have read and followed
// the Academic Honesty and Integrity related policies as outlined in the
// syllabus.
//
// _____ Trevor Ruttan ____ _____10/8/2024______________
//
// ____ 301580889 ______
//

#include "OvernightPackage.h"

#include <iostream>

/**
 * @brief Constructs an OvernightPackage object.
 *
 * @param name The name of the recipient.
 * @param address The address of the recipient.
 * @param city The city of the recipient.
 * @param state The state of the recipient.
 * @param zip The ZIP code of the recipient.
 * @param weight The weight of the package in ounces.
 * @param costPerOunce The cost per ounce to ship the package.
 * @param additionalFeePerOunce The additional fee per ounce for overnight
 * delivery.
 */
OvernightPackage::OvernightPackage(std::string name, std::string address,
                                   std::string city, std::string state,
                                   std::string zip, double weight,
                                   double costPerOunce,
                                   double additionalFeePerOunce)
    : Package(name, address, city, state, zip, weight, costPerOunce),
      additionalFeePerOunce(additionalFeePerOunce) {}

/**
 * @brief Calculates the cost of shipping the package with the overnight fee.
 *
 * @return double The total cost of shipping the package.
 */
double OvernightPackage::calculateCost() {
  return getWeight() * (getCostPerOunce() + additionalFeePerOunce);
}