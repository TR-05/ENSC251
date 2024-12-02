#pragma once

#include <math.h>
#include <stdio.h>

#include <vector>

#include "pose.h"
#include "cubicBezier.h"

namespace tntnlib {
/*
// Parameters: length, vi, wi, vf, vMax, wMax, acel, decel, angularAcel, dd,
trackWidth, backwards
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

class mp3 {
public:
  // generates a motion profile using the given parameters
  mp3(Path &path, float vi, float wi, float vf, float vMax, float wMax,
      float acel, float decel, float trackWidth, bool backwards);
  mp3();
  std::vector<WayPoint> wt;
  std::vector<WayPoint> wd;

  float totalTime = 0;
  bool backwards = false;

private:
  Path path;
  float vi, wi, vf, vMax, wMax, acel, decel, trackWidth, acelDist, decelDist,
      coastDist;
  float calculateDistance(float vInitial, float vFinal, float acel);
  float calculateCoastDistance(float totalDistance, float acelDistance,
                               float decelDistance);
  void initializeWaypoints();
  void forwardPass();
  void backwardPass();
  void calculateTimeIntervals();
  void interpolateWaypoints(int i, int index, float ratio, float T);
  void lerpToTimeDomain(float newDtms);
  void adjustForBackwardMotion();
};
} // namespace tntnlib
