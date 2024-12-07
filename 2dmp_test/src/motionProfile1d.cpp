#include "../include/motionProfile1d.h"
#include <cmath>
#include <vector>

MotionProfile1d::MotionProfile1d() {}

MotionProfile1d::MotionProfile1d(double distance, double maxVelocity,
                                 double acel, double decel) {
  const bool backwards = distance < 0;
  distance = fabs(distance);
  double acelTime = maxVelocity / acel;
  double acelDist = 0.5 * acel * acelTime * acelTime;
  double decelTime = maxVelocity / decel;
  double decelDist = 0.5 * decel * decelTime * decelTime;
  double cruiseDist, cruiseTime;

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
  double currentTime = 0;
  double currentDistance = 0;
  double currentVelocity = 0;
  const double dt = 0.01;

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