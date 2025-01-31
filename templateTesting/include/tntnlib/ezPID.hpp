#pragma once

#include "tntnlib/motionHandler.hpp"
#include "units/units.hpp"
struct PIDConstants {
  float kP;
  float kI;
  float kD;
};
void relativePID(Length distance, float maxPower, PIDConstants linearSettings,
                 PIDConstants angularSettings, Length exitDistance,
                 Time timeOut);

void relativePIDUpdate();