/**
 * @file ManualShippingContainer.h
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
 * @class ManualShippingContainer
 * @brief A class representing a shipping container with a manually set
 * manifest.
 */
class ManualShippingContainer : public ShippingContainer {
protected:
  std::string manifest; ///< The manifest of the container.

public:
  /**
   * @brief Constructor for ManualShippingContainer.
   */
  ManualShippingContainer();

  /**
   * @brief Destructor for ManualShippingContainer.
   */
  ~ManualShippingContainer();

  /**
   * @brief Sets the manifest of the container.
   * @param manifest The new manifest of the container.
   */
  void setManifest(std::string manifest);

  /**
   * @brief Gets the manifest of the container.
   * @return A string representing the manifest of the container.
   */
  std::string getManifest() override;
};