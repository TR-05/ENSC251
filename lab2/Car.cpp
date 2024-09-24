/**
 * @file Car.cpp
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

#include <string>

#include "Car.h"
/*
 * @brief Gets the speed of the car.
 * @return int The current speed of the car.
 */
int Car::getSpeed() {
  return m_speed;
}

/*
 * @brief Gets the year model of the car.
 * @return int The year model of the car.
 */
int Car::getYearModel() {
  return m_yearModel;
}

/*
 * @brief Gets the make of the car.
 * @return std::string The make of the car.
 */
std::string Car::getMake() {
  return m_make;
}

/*
 * @brief Increases the speed of the car by 5 units.
 */
void Car::accelerate() {
  m_speed += 5;
}

/*
 * @brief Decreases the speed of the car by 5 units
 */
void Car::brake() {
  m_speed -= 5;
}