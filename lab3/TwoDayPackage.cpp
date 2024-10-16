/**
 * @file TwoDayPackage.cpp
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

#include "TwoDayPackage.h"

#include <iostream>

/**
 * @brief Constructs a TwoDayPackage object.
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
 * @param flatFee The flat fee for two-day delivery.
 */
TwoDayPackage::TwoDayPackage(std::string senderName, std::string senderAddress,
                             std::string senderCity, std::string senderState,
                             std::string senderZip, std::string recipientName,
                             std::string recipientAddress,
                             std::string recipientCity,
                             std::string recipientState,
                             std::string recipientZip, double weight,
                             double costPerOunce, double flatFee)
    : Package(senderName, senderAddress, senderCity, senderState, senderZip,
              recipientName, recipientAddress, recipientCity, recipientState,
              recipientZip, weight, costPerOunce),
      flatFee(flatFee) {
      }

/**
 * @brief Calculates the cost of shipping the package with the two-day delivery
 * fee.
 *
 * @return double The total cost of shipping the package.
 */
double TwoDayPackage::calculateCost() {
  return getWeight() * getCostPerOunce() + flatFee;
}