/**
 * @file RFIDShippingContainer.cpp
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

#include "RFIDShippingContainer.h"

/**
 * @brief Constructor for the ShippingContainer class.
 * @param containerID The ID of the container.
 */
RFIDShippingContainer::RFIDShippingContainer() {}

/**
 * @brief Destructor for the ShippingContainer class.
 */
RFIDShippingContainer::~RFIDShippingContainer() {}

/**
 * @brief Gets the manifest of the container.
 * @return void
 */
std::string RFIDShippingContainer::getManifest() {
  std::string manifest = "";
  for (size_t i = 0; i < items.size(); i++) {
    manifest += std::to_string(numItems[i]) + " " + items[i] + ". ";
  }
  return manifest;
}

/**
 * @brief Adds an item to the container.
 * @param item The item to add to the container.
 * @return void
 */
void RFIDShippingContainer::add(std::string item) {
  bool found = false;
  for (size_t i = 0; i < items.size(); i++) {
    if (items[i] == item) {
      found = true;
      numItems[i]++;
      break;
    }
  }
  if (!found) {
    items.push_back(item);
    numItems.push_back(1);
  }
}