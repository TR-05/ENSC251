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
  private: const int yearModel;
  const std::string make;
  int speed;

  public:
    // Constructor taking in yearModel and make
    Car(int yearModel, std::string make)
    : yearModel(yearModel),
    make(make),
    speed(0) {};

  ~Car() {};

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

  /*
   * @brief Increases the speed of the car by 5 units.
   */
  void accelerate();

  /*
   * @brief Decreases the speed of the car by 5 units
   */
  void brake();
};