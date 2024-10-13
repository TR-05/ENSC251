/**
 * @file ShippingContainer.h
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

/**
 * @class ShippingContainer
 * @brief A class representing a shipping container.
 */
class ShippingContainer {
  protected: int containerID; ///< The ID of the container.

  public:
    /**
     * @brief Default constructor for ShippingContainer.
     */
    ShippingContainer();

  /**
   * @brief Destructor for ShippingContainer.
   */
  virtual~ShippingContainer();

  /**
   * @brief Gets the container ID.
   * @return The ID of the container.
   */
  int getContainerID();

  /**
   * @brief Sets the container ID.
   * @param containerID The new ID of the container.
   */
  void setContainerID(int containerID);

  /**
   * @brief Gets the manifest of the container.
   * @return A string representing the manifest of the container.
   */
  virtual std::string getManifest();
};