/**
 * @file ShippingContainer.cpp
 * @author Trevor Ruttan
 * @Date 10/3/2024
 * @version 1.0
 * @section DESCRIPTION
 */
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ Trevor Ruttan ____ _____10/3/2024______________
//
// ____ 301580889 ______
//

#include <string>

#include "ShippingContainer.h"

/**
 * @brief Constructor for the ShippingContainer class.
 * @param containerID The ID of the container.
 */
ShippingContainer::ShippingContainer(): containerID(0) {}

/**
 * @brief Destructor for the ShippingContainer class.
 */
ShippingContainer::~ShippingContainer() {}

/**
 * @brief Gets the container ID.
 * @return int The container ID.
 */
int ShippingContainer::getContainerID() {
  return this -> containerID;
}

/**
 * @brief Sets the container ID.
 * @param containerID The ID of the container.
 * @return void
 */
void ShippingContainer::setContainerID(int containerID) {
  this -> containerID = containerID;
}

/**
 * @brief Gets the manifest of the container.
 * @return void
 */
std::string ShippingContainer::getManifest() {
  std::string manifest = "";
  return manifest;
}