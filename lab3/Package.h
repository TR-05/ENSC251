/**
 * @file Package.h
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

/**
 * @struct Info
 * @brief A struct to store address information.
 *
 * @details This struct contains fields for storing the name, address, city,
 * state, and ZIP code of an individual.
 */
struct Info {
  std::string name;    ///< The name of the individual
  std::string address; ///< The address of the individual
  std::string city;    ///< The city of the individual
  std::string state;   ///< The state of the individual
  std::string zip;     ///< The ZIP code of the individual
};

/**
 * @class Package
 * @brief A class to represent a package with sender and recipient information.
 *
 * @details This class contains information about the sender and recipient, the
 * weight of the package, and the cost per ounce to ship the package. It
 * provides methods to get the weight, get the cost per ounce, and calculate the
 * total cost of shipping the package.
 */

class Package {
private:
  Info sender;         ///< Information about the sender
  Info recipient;      ///< Information about the recipient
  double weight;       ///< The weight of the package in ounces
  double costPerOunce; ///< The cost per ounce to ship the package

public:
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
  Package(std::string name, std::string address, std::string city,
          std::string state, std::string zip, double weight,
          double costPerOunce);

  /**
   * @brief Gets the weight of the package.
   *
   * @return double The weight of the package in ounces.
   */
  double getWeight();

  /**
   * @brief Gets the cost per ounce to ship the package.
   *
   * @return double The cost per ounce to ship the package.
   */
  double getCostPerOunce();

  /**
   * @brief Calculates the cost of shipping the package.
   *
   * @return double The total cost of shipping the package.
   */
  virtual double calculateCost();

  /**
   * @brief Default destructor.
   */
  virtual ~Package() = default;
};