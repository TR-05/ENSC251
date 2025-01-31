#pragma once
#include "hardware/Motor/MotorGroup.hpp"
#include "main.h"

class MotionHandler {
public:
  // Static method to get the single instance of the class
  static MotionHandler& getInstance(std::shared_ptr<lemlib::MotorGroup> leftDrive = nullptr, std::shared_ptr<lemlib::MotorGroup> rightDrive = nullptr) {
    static MotionHandler instance(leftDrive, rightDrive);
    return instance;
  }

  // Delete copy constructor and assignment operator to prevent copying
  MotionHandler(const MotionHandler&) = delete;
  MotionHandler& operator=(const MotionHandler&) = delete;

  void setMotion(std::function<void()> motionFunction);
  void initializeTask();
  void deleteTask();
  void enable();
  void disable();

private:
  // Private constructor
  MotionHandler(std::shared_ptr<lemlib::MotorGroup> leftDrive, std::shared_ptr<lemlib::MotorGroup> rightDrive);

  bool enabled;
  std::shared_ptr<lemlib::MotorGroup> leftDrive;
  std::shared_ptr<lemlib::MotorGroup> rightDrive;
  std::function<void()> motionFunction;
  pros::Task motionHandlerTask;
};