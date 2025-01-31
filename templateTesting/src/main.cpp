#include "main.h"
#include "hardware/Encoder/ADIEncoder.hpp"
#include "hardware/Encoder/V5RotationSensor.hpp"
#include "hardware/IMU/V5InertialSensor.hpp"
#include "hardware/Motor/MotorGroup.hpp"
#include "units/units.hpp"

#include "tntnlib/motionHandler.hpp"
#include <memory>

lemlib::MotorGroup leftDrive({1, -2, 3}, 360_rpm);
lemlib::MotorGroup rightDrive({-4, 5, -6}, 360_rpm);
lemlib::V5InertialSensor inertialSensor(7, 1.0);

MotionHandler& handler = MotionHandler::getInstance(std::make_shared<lemlib::MotorGroup>(leftDrive), std::make_shared<lemlib::MotorGroup>(rightDrive));

void initialize() { handler.initializeTask(); }

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
  while (true) {
    pros::delay(20); // Run for 20 ms then update
  }
}