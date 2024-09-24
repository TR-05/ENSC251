/**
 * @file Car.h
 * @author Trevor Ruttan
 * @Date 9/24/2024
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

class Car {
  public:
    // Constructor taking in yearModel and make
    Car(int yearModel, std::string make): m_yearModel(yearModel),
  m_make(make),
  m_speed(0) {};

  ~Car() {};

  // Accessors

  /*
   * @brief Gets the speed of the car.
   * @return int The current speed of the car.
   */
  int getSpeed();

  /*
   * @brief Gets the year model of the car.
   * @return int The year model of the car.
   */
  int getYearModel();

  /*
   * @brief Gets the make of the car.
   * @return std::string The make of the car.
   */
  std::string getMake();

  // Mutators

  /*
   * @brief Increases the speed of the car by 5 units.
   */
  void accelerate();

  /*
   * @brief Decreases the speed of the car by 5 units
   */
  void brake();

  private: const int m_yearModel;
  const std::string m_make;
  int m_speed;
};