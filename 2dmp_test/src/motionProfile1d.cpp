#include "../include/motionProfile1d.h"
#include <cmath>
#include <vector>

MotionProfile1d::MotionProfile1d() {}

MotionProfile1d::MotionProfile1d(float distance, float maxVelocity,
                                 float acel, float decel) {
  const bool backwards = distance < 0;
  distance = fabs(distance);
  float acelTime = maxVelocity / acel;
  float acelDist = 0.5 * acel * acelTime * acelTime;
  float decelTime = maxVelocity / decel;
  float decelDist = 0.5 * decel * decelTime * decelTime;
  float cruiseDist, cruiseTime;

  if (acelDist + decelDist > distance) {
    // Asymmetrical triangular profile
    acelDist = distance * (acel / (acel + decel));
    decelDist = distance * (decel / (acel + decel));
    acelTime = sqrt(2 * acelDist / acel);
    decelTime = sqrt(2 * decelDist / decel);
    maxVelocity = acel * acelTime;
    cruiseDist = 0;
    cruiseTime = 0;
  } else {
    // Trapezoidal profile
    cruiseDist = distance - acelDist - decelDist;
    cruiseTime = cruiseDist / maxVelocity;
  }

  totalTime = acelTime + decelTime + cruiseTime;
  float currentTime = 0;
  float currentDistance = 0;
  float currentVelocity = 0;
  const float dt = 0.01;

  while (currentTime < totalTime) {
    if (currentTime < acelTime) {
      currentVelocity = acel * currentTime;
    } else if (currentTime < acelTime + cruiseTime) {
      currentVelocity = maxVelocity;
    } else {
      currentVelocity =
          maxVelocity - decel * (currentTime - acelTime - cruiseTime);
    }
    currentDistance += currentVelocity * dt;
    currentTime += dt;
    v.push_back(currentVelocity);
    t.push_back(currentTime);
  }
  v.push_back(0);
  t.push_back(t.back()+dt);

  if (backwards) {
    for (auto &velocity : v) {
      velocity = -velocity;
    }
  }
}