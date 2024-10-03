/**
 * @file lab2.cpp
 * @author Trevor Ruttan
 * @Date 9/24/2024
 * @version 1.0
 * @section DESCRIPTION
 */
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ Trevor Ruttan ____ _____9/24/2024______________
//
// ____ 301580889 ______
//

#include <iostream>

#include "ShippingContainer.h"

int main() {
  ManualShippingContainer container;
  RFIDShippingContainer rfidContainer;
  container.setContainerID(27);
  rfidContainer.setContainerID(35);
  std::cout << container.getContainerID() << std::endl;
  std::cout << rfidContainer.getContainerID() << std::endl;
  container.setManifest("This is a manifest");
  rfidContainer.add("crate of pears");
  rfidContainer.add("crate of apples");
  rfidContainer.add("crate of pears 1");

  std::cout << container.getManifest() << std::endl;
  std::cout << rfidContainer.getManifest() << std::endl;

}