/**
 * @file RFIDShippingContainer.h
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

#include <vector>

#include "ShippingContainer.h"

/**
 * @class RFIDShippingContainer
 * @brief A class representing a shipping container with RFID capabilities.
 */
class RFIDShippingContainer : public ShippingContainer {
protected:
  std::vector<std::string>
      items;                 ///< Vector to store the items in the container.
  std::vector<int> numItems; ///< Vector to store the number of each item, using
                             ///< the same index.

public:
  /**
   * @brief Constructor for RFIDShippingContainer.
   */
  RFIDShippingContainer();

  /**
   * @brief Destructor for RFIDShippingContainer.
   */
  virtual ~RFIDShippingContainer();

  /**
   * @brief Adds an item to the container.
   * @param item The item to be added.
   */
  void add(std::string item);

  /**
   * @brief Gets the manifest of the container.
   * @return A string representing the manifest of the container.
   */
  std::string getManifest() override;
};