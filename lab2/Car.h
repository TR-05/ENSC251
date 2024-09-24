/**
 * @file Car.h
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

class Car {
  public: Car(int yearModel, std::string make): yearModel(yearModel),
  make(make),
  speed(0) {};
  ~Car() {};
  int getSpeed();
  int getYearModel();
  std::string getMake();
  void accelerate();
  void brake();
  private: int yearModel;
  std::string make;
  int speed;
};