#include "tntnlib/motionHandler.hpp"

/*
Outline of desired behavior:
 - Motions are persistent, once complete the bot should not be returned to a
default state
 - Motions can be overriden instantly
 - Motions should take in various parameters in a config step, then use those
parameters in a calculation step to control a drivetrain
 - this means there will be a primary handler task, which takes in various
settings and uses them to set drivetrain voltage / velocity
 - Question: should motor control be done by handler or should handler pass
motor groups?
 - Current scope is only for tank

Handler config:
 - left and right drivetrain motorgroups
 - Enable

Motion config:
 - pid settings, max power, reversed, etc. depends fully on the movement
*/

/*
Structure Overview:
MotionHandler class that creates its own task on construction
*/

MotionHandler::MotionHandler(std::shared_ptr<lemlib::MotorGroup> leftDrive,
                             std::shared_ptr<lemlib::MotorGroup> rightDrive)
    : leftDrive(leftDrive), rightDrive(rightDrive), motionHandlerTask([]() {}) {
  enabled = false;
  motionFunction = []() {};
}

void MotionHandler::setMotion(std::function<void()> motionFunction) {
  this->motionFunction = motionFunction;
}

void MotionHandler::enable() { enabled = true; }

void MotionHandler::disable() { enabled = false; }

void MotionHandler::initializeTask() {
  motionHandlerTask = pros::Task ([this]() {
    while (true) {
      if (enabled && motionFunction) {
        motionFunction();
      }
      pros::delay(5);
    }
  });
}

void MotionHandler::deleteTask() { motionHandlerTask.remove(); }