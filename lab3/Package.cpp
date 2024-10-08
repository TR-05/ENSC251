/**
 * @file Package.cpp
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

#include "Package.h"

#include <iostream>

/**
 * @brief Constructs a Package object.
 * 
 * @param name The name of the sender and recipient.
 * @param address The address of the sender and recipient.
 * @param city The city of the sender and recipient.
 * @param state The state of the sender and recipient.
 * @param zip The ZIP code of the sender and recipient.
 * @param weight The weight of the package in ounces.
 * @param costPerOunce The cost per ounce to ship the package.
 */
Package::Package(std::string name, std::string address, std::string city,
                 std::string state, std::string zip, double weight,
                 double costPerOunce)
    : weight(weight), costPerOunce(costPerOunce) {
  sender.name = name;
  sender.address = address;
  sender.city = city;
  sender.state = state;
  sender.zip = zip;
  recipient.name = name;
  recipient.address = address;
  recipient.city = city;
  recipient.state = state;
  recipient.zip = zip;
}

/**
 * @brief Gets the weight of the package.
 * 
 * @return double The weight of the package in ounces.
 */
double Package::getWeight() { return weight; }

/**
 * @brief Gets the cost per ounce to ship the package.
 * 
 * @return double The cost per ounce to ship the package.
 */
double Package::getCostPerOunce() { return costPerOunce; }

/**
 * @brief Calculates the cost of shipping the package.
 * 
 * @return double The total cost of shipping the package.
 */
double Package::calculateCost() { return weight * costPerOunce; }