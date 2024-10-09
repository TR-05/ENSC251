/**
 * @file Package.cpp
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

#include "Package.h"

#include <iostream>

/**
 * @brief Constructs a Package object.
 *
 * @param senderName The name of the sender.
 * @param senderAddress The address of the sender.
 * @param senderCity The city of the sender.
 * @param senderState The state of the sender.
 * @param senderZip The ZIP code of the sender.
 * @param recipientName The name of the recipient.
 * @param recipientAddress The address of the recipient.
 * @param recipientCity The city of the recipient.
 * @param recipientState The state of the recipient.
 * @param recipientZip The ZIP code of the recipient.
 * @param weight The weight of the package in ounces.
 * @param costPerOunce The cost per ounce to ship the package.
 */
Package::Package(std::string senderName, std::string senderAddress,
                 std::string senderCity, std::string senderState,
                 std::string senderZip, std::string recipientName,
                 std::string recipientAddress, std::string recipientCity,
                 std::string recipientState, std::string recipientZip,
                 double weight, double costPerOunce)
    : weight(weight ? weight > 0 : 0), costPerOunce(costPerOunce ? costPerOunce > 0 : 0) {
  sender.name = senderName;
  sender.address = senderAddress;
  sender.city = senderCity;
  sender.state = senderState;
  sender.zip = senderZip;
  recipient.name = recipientName;
  recipient.address = recipientAddress;
  recipient.city = recipientCity;
  recipient.state = recipientState;
  recipient.zip = recipientZip;
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