/**
 * @file ManualShippingContainer.cpp
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

/*
 * @brief Constructor for the ShippingContainer class.
 * @param containerID The ID of the container.
 */
ManualShippingContainer::ManualShippingContainer() {
}

/*
 * @brief Destructor for the ShippingContainer class.
 */
ManualShippingContainer::~ManualShippingContainer() {
}

/*
 * @brief Sets the manifest of the container.
 * @param manifest The manifest of the container.
 * @return void
 */
 void ManualShippingContainer::setManifest(std::string manifest)
{
  this->manifest = manifest;
}

/*
 * @brief Gets the manifest of the container.
 * @return void
 */
std::string ManualShippingContainer::getManifest() {
  return this->manifest;
}

