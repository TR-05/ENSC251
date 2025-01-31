#include "tntnlib/ezPID.hpp"

void relativePID(Length distance, float maxPower, PIDConstants linearSettings,
                 PIDConstants angularSettings, Length exitDistance,
                 Time timeOut) {
  MotionHandler::getInstance().setMotion(relativePIDUpdate);
}

void relativePIDUpdate() {

    
}