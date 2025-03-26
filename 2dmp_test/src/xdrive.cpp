#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
/*
Goal: calculate individual wheel velocities to move the robot in a specified
linear and angular velocity in the global frame

usage:
moveToPose, where angle from robot to point is TargetAngle, RPS is the output of
a heading error PID (?). outputs are fed into a feedforward velocity controller
so it still behaves like a standard voltage PID. heading error PID clamped to
max RPS to ensure proper movement.

2dmp, similar to tank drive 2dmp, except has a secondary profile for robot
heading (eg lerp through start and end for constant angular velocity, or more
likely lerp from start to some distance along the path (or t value), then have
heading constant after that)
Q: is constant angular vel desired or is angular acel controlled through a trap profile better?
*/

constexpr float toRadians(float degrees) {
  return (90.0f - degrees) * M_PI / 180.0f;
}

std::array<float, 4> wheelVelocities(float TargetAngle, float linearVelocity,
                                     float RPS, float maxWheelVelocity,
                                     float radius, float currentAngle) {
  const float localStandardAngle = toRadians(TargetAngle - currentAngle);
  const float w = -RPS * 2 * M_PI;
  const float vx = cos(localStandardAngle) * linearVelocity;
  const float vy = sin(localStandardAngle) * linearVelocity;

  const float vfl = vy + vx - w * radius;
  const float vbl = vy - vx + w * radius;
  const float vfr = vy - vx + w * radius;
  const float vbr = vy + vx - w * radius;

  printf("initial vfl: %.2f, vbl: %.2f, vfr: %.2f, vbr: %.2f \n", vfl, vbl, vfr,
         vbr);
  std::array<float, 4> velocities = {vfl, vbl, vfr, vbr};
  // Normalize velocities if necessary
  float maxVelocity = *std::max_element(
      velocities.begin(), velocities.end(),
      [](float a, float b) { return std::abs(a) < std::abs(b); });
  float multiplier = maxWheelVelocity / std::abs(maxVelocity);
  for (auto &vel : velocities) {
    vel *= multiplier;
  }

  return velocities;
}
