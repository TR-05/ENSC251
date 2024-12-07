#pragma once

#include "cubicBezier.h"
#include "pose.h"
#include <cmath>
#include <cstdio>
#include <vector>

namespace tntnlib {

/**
 * @brief 2dmp point struct, holds all the necessary information for use
 *
 */
struct WayPoint {
  Pose pose;
  float curvature;
  float s;
  float ds;
  float vl;
  float vr;
  float v;
  float w;
  float t;
  float dt;

  WayPoint() : pose(0, 0, 0) {}
  WayPoint(Pose pose, float curvature, float s, float ds, float vl, float vr,
           float v, float w, float t)
      : pose(pose), curvature(curvature), s(s), ds(ds), vl(vl), vr(vr), v(v),
        w(w), t(t) {}
};

class MotionProfile2d {
public:
  // generates a motion profile using the given parameters
  MotionProfile2d(const Path &path, float vi, float wi, float vf, float vMax,
                  float wMax, float acel, float decel, float trackWidth,
                  bool backwards, bool generateTimeProfile);
  MotionProfile2d();
  std::vector<WayPoint> wt, wd;

  float totalTime = 0;
  bool backwards = false;

private:
  Path path;
  float vi, wi, vf, vMax, wMax, acel, decel, trackWidth, acelDist, decelDist,
      coastDist;

  /**
   * @brief calculates the distance traveled during acceleration or deceleration
   *
   * @param vInitial
   * @param vFinal
   * @param acel
   * @return float
   */
  float calculateDistance(float vInitial, float vFinal, float acel);

  /**
   * @brief calculates the distance to coast at top speed given the total and
   * acel/decel phases if the coast distance is negative, the acel and decel
   * distances are scaled to fit the path
   * @param totalDistance
   * @param acelDistance
   * @param decelDistance
   * @return float
   */
  float calculateCoastDistance(float totalDistance, float acelDistance,
                               float decelDistance);

  /**
   * @brief sets up the initial waypoints for the motion profile in the distance
   * domain
   */
  void initializeWaypoints();

  /**
   * @brief constrains the velocity and acceleration of the waypoints in the
   * distance domain
   */
  void forwardPass();

  /**
   * @brief constrains the velocity and acceleration of the waypoints in the
   * distance domain from back to front, effectively limiting the deceleration
   */
  void backwardPass();

  /**
   * @brief limits the velocity and acceleration of a waypoint in the
   * distance domain. Used for both forward and backward passes
   */
  void limitChange(float &vl, float &vr, float &v, float &w,
                   const float &lastVl, const float &lastVr, const float &c,
                   const float &vMax, const float &wMax, const float &acel,
                   const float &dd, const float &trackWidth);

  /**
   * @brief calculates the time spent between each waypoint in the distance
   * domain
   */
  void calculateTimeIntervals();

  /**
   * @brief interpolates between waypoints in the distance domain to create a
   * time domain with a fixed dt
   *
   * @param i
   * @param index
   * @param ratio
   * @param T
   */
  void interpolateWaypoint(int i, int index, float ratio, float T);

  /**
   * @brief converts the distance domain profile to time domain with a fixed dt
   */
  void lerpToTimeDomain(float newDtms);

  /**
   * @brief adjusts both distance and time profiles for backward motion
   */
  void adjustForBackwardMotion();
};
} // namespace tntnlib
