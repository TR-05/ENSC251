/**
 * @file lab2.cpp
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

#include <iostream>

#include <memory>

#include "ShippingContainer.h"

#include "ManualShippingContainer.h"

#include "RFIDShippingContainer.h"

int main() {
  ShippingContainer * containers[6];

  // Instantiate the array with three ManualShippingContainer objects
  for (int i = 0; i < 3; ++i) {
    containers[i] = new ManualShippingContainer();
    containers[i] -> setContainerID(i);
  }

  // Instantiate the array with three RFIDShippingContainer objects
  for (int i = 3; i < 6; ++i) {
    containers[i] = new RFIDShippingContainer();
    containers[i] -> setContainerID(i);
  }

  // Set the manifest for each container by explicitly casting the pointer to the appropriate type
  dynamic_cast < ManualShippingContainer * > (containers[0]) -> setManifest(
      "1 crate of pears. 1 crate of pineapples. 1 crate of coconuts");
  dynamic_cast < ManualShippingContainer * > (containers[1]) -> setManifest(
      "1 crate of soup. 1 crate of oranges. 1 crate of bananas");
  dynamic_cast < ManualShippingContainer * > (containers[2]) -> setManifest(
      "1 crate of apples. 1 crate of oranges. 1 crate of bananas");

  // Check that add function works correctly on container 3
  dynamic_cast < RFIDShippingContainer * > (containers[3]) -> add("crate of Oranges");
  dynamic_cast < RFIDShippingContainer * > (containers[3]) -> add("crate of Oranges");
  dynamic_cast < RFIDShippingContainer * > (containers[3]) -> add("crate of Pears");

  dynamic_cast < RFIDShippingContainer * > (containers[4]) -> add("crate of Apples");
  dynamic_cast < RFIDShippingContainer * > (containers[5]) -> add("crate of Bananas");

  // Print the manifest for each container
  for (size_t i = 0; i < 6; ++i) {
    std::cout << "containerID #" << containers[i] -> getContainerID() << ": ";
    std::cout << "Manifest: " << containers[i] -> getManifest() << std::endl;
  }

  // Clean up dynamically allocated memory
  for (int i = 0; i < 6; ++i) {
    delete containers[i];
  }

  return 0;
}