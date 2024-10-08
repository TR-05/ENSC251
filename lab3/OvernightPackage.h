/**
 * @file OvernightPackage.h
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

#pragma once

#include <string>

#include "Package.h"

/**
 * @class OvernightPackage
 * @brief A class to represent a package with an additional fee for overnight
 * delivery.
 *
 * @details This class inherits from the Package class and adds an additional
 * fee per ounce for overnight delivery.
 */
class OvernightPackage : public Package {
private:
  double additionalFeePerOunce; ///< Additional fee per ounce for overnight
                                ///< delivery

public:
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
  OvernightPackage(std::string name, std::string address, std::string city,
                   std::string state, std::string zip, double weight,
                   double costPerOunce, double additionalFeePerOunce);

  /**
   * @brief Calculates the cost of shipping the package with the overnight fee.
   *
   * @return double The total cost of shipping the package.
   */
  double calculateCost() override;

  /**
   * @brief Default destructor.
   */
  ~OvernightPackage() = default;
};