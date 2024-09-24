/**
 * @file Car.cpp
 * @author Trevor Ruttan
 * @Date 9/23/2024
 * @version 1.0
 * @section DESCRIPTION
 */
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ Trevor Ruttan ____ _____9/23/2024______________
//
// ____ 301580889 ______
//

#include <string>

#include "Car.h"

int Car::getSpeed() {
  return speed;
}
int Car::getYearModel() {
  return yearModel;
}
std::string Car::getMake() {
  return make;
}
void Car::accelerate() {
  speed += 5;
}
void Car::brake() {
  speed -= 5;
}