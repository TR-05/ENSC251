#include "motionProfile2d.h"

#include <vector>

// more organized and versatile version of the motion profile class

using namespace tntnlib;

int sgn(float x) { return (x > 0) - (x < 0); }

MotionProfile2d::MotionProfile2d() {}
MotionProfile2d::MotionProfile2d(const Path &path, float vi, float wi, float vf,
                                 float vMax, float wMax, float acel,
                                 float decel, float trackWidth, bool backwards,
                                 bool generateTimeProfile)
    : path(path), vi(vi), wi(wi), vf(vf), vMax(vMax), wMax(wMax), acel(acel),
      decel(decel), trackWidth(trackWidth), backwards(backwards) {

  acelDist = calculateDistance(vi, vMax, acel);
  decelDist = calculateDistance(vMax, vf, decel);
  coastDist = calculateCoastDistance(path.length, acelDist, decelDist);

  initializeWaypoints();
  forwardPass();
  backwardPass();
  calculateTimeIntervals();
  if (generateTimeProfile) {
    lerpToTimeDomain(10);
  }

  if (backwards) {
    adjustForBackwardMotion();
  }
}

/**
 * @brief calculates the distance traveled during acceleration or deceleration
 *
 * @param vInitial
 * @param vFinal
 * @param acel
 * @return float
 */
float MotionProfile2d::calculateDistance(float vInitial, float vFinal,
                                         float acel) {
  return fabs((vFinal * vFinal - vInitial * vInitial) / (2 * acel));
}

/**
 * @brief calculates the distance to coast at top speed given the total and
 * acel/decel phases if the coast distance is negative, the acel and decel
 * distances are scaled to fit the path
 * @param totalDistance
 * @param acelDistance
 * @param decelDistance
 * @return float
 */
float MotionProfile2d::calculateCoastDistance(float pathLength, float acelDist,
                                              float decelDist) {
  float coastDist = pathLength - acelDist - decelDist;
  if (coastDist < 0) {
    coastDist = 0;
    acelDist = acelDist * pathLength / (acelDist + decelDist);
    decelDist = decelDist * pathLength / (acelDist + decelDist);
  }
  return coastDist;
}

/**
 * @brief sets up the initial waypoints for the motion profile in the distance
 * domain
 */
void MotionProfile2d::initializeWaypoints() {
  int numPoints = int(path.curvature.size() + 1);
  wd.resize(numPoints);
  wd[0] = WayPoint(Pose(path.x0, path.y0, path.theta[0]), 0, 0, 0,
                   vi + (vi * vi / wi) * trackWidth / 2,
                   vi - (vi * vi / wi) * trackWidth / 2, vi, wi, 0);
  if (wi == 0) {
    wd[0].vl = vi;
    wd[0].vr = vi;
  }
  for (size_t i = 0; i < wd.size(); i++) {
    wd[i].ds = path.pointSpacing;
    wd[i].s = i * path.pointSpacing;
  }
}

/**
 * @brief constrains the velocity and acceleration of the waypoints in the
 * distance domain
 */
void MotionProfile2d::forwardPass() {
  for (size_t i = 1; i < wd.size(); i++) {
    float d = i * path.pointSpacing;
    wd[i].v = vMax;
    wd[i].w = wd[i].v * path.curvature[i];
    if (fabs(wd[i].w) > wMax) {
      wd[i].w = wMax * sgn(wd[i].w);
      wd[i].v = wd[i].w / path.curvature[i];
    }
    limitChange(wd[i].vl, wd[i].vr, wd[i].v, wd[i].w, wd[i - 1].vl,
                wd[i - 1].vr, path.curvature[i], vMax, wMax, acel,
                path.pointSpacing, trackWidth);
  }
}

/**
 * @brief constrains the velocity and acceleration of the waypoints in the
 * distance domain from back to front, effectively limiting the deceleration
 */
void MotionProfile2d::backwardPass() {
  int numPoints = wd.size();
  wd.back().v = vf;
  wd.back().vl = vf;
  wd.back().vr = vf;
  wd.back().w = 0;

  for (int i = numPoints - 2; i >= 0; i--) {
    limitChange(wd[i].vl, wd[i].vr, wd[i].v, wd[i].w, wd[i + 1].vl,
                wd[i + 1].vr, path.curvature[i], vMax, wMax, decel,
                path.pointSpacing, trackWidth);
  }
}

// This should work for both forward and backward passes I think?
void MotionProfile2d::limitChange(float &vl, float &vr, float &v, float &w,
                                  const float &lastVl, const float &lastVr,
                                  const float &c, const float &vMax,
                                  const float &wMax, const float &acel,
                                  const float &dd, const float &trackWidth) {

  vl = v + w * trackWidth / 2;
  vr = v - w * trackWidth / 2;
  if (vl > vMax) {
    vl = vMax;
    v = vl * 2 / (2 + c * trackWidth);
    vr = v * (2 - c * trackWidth) / 2;
  }
  if (vl < -vMax) {
    vl = -vMax;
    v = vl * 2 / (2 + c * trackWidth);
    vr = v * (2 - c * trackWidth) / 2;
  }
  if (vr > vMax) {
    vr = vMax;
    v = vr * 2 / (2 - c * trackWidth);
    vl = v * (2 + c * trackWidth) / 2;
  }
  if (vr < -vMax) {
    vr = -vMax;
    v = vr * 2 / (2 - c * trackWidth);
    vl = v * (2 + c * trackWidth) / 2;
  }
  w = v * c;

  // if the magnitude of vl is increasing limit it to the max acceleration
  if (fabs((vl * vl - lastVl * lastVl) / (2 * dd)) > acel &&
      sgn(vl - lastVl) == sgn(vl)) {
    float inside = lastVl * lastVl + 2 * acel * dd * sgn(vl - lastVl);
    vl = sqrt(fabs(inside)) * sgn(inside);
    v = vl * 2 / (2 + c * trackWidth);
    w = v * c;
    vr = v - w * trackWidth / 2;
  }

  // if the magnitude of vr is increasing limit it to the max acceleration
  if (fabs((vr * vr - lastVr * lastVr) / (2 * dd)) > acel &&
      sgn(vr - lastVr) == sgn(vr)) {
    float inside = lastVr * lastVr + 2 * acel * dd * sgn(vr - lastVr);
    vr = sqrt(fabs(inside)) * sgn(inside);
    v = vr * 2 / (2 - c * trackWidth);
    w = v * c;
    vl = v + w * trackWidth / 2;
  }
}

/**
 * @brief calculates the time spent between each waypoint in the distance domain
 */
void MotionProfile2d::calculateTimeIntervals() {
  for (size_t i = 1; i < wd.size(); i++) {
    wd[i].dt = path.pointSpacing / ((wd[i].v + wd[i - 1].v) / 2);
    wd[i].t = wd[i - 1].t + wd[i].dt;
  }
  wd.back().dt = 0;
  wd.back().t = wd[wd.size() - 1].t;
  totalTime = wd.back().t;
}

/**
 * @brief interpolates between waypoints in the distance domain to create a time
 * domain with a fixed dt
 *
 * @param i
 * @param index
 * @param ratio
 * @param T
 */
void MotionProfile2d::interpolateWaypoint(int i, int index, float ratio,
                                          float T) {
  wt[i].v = wd[index - 1].v + ratio * (wd[index].v - wd[index - 1].v);
  wt[i].vl = wd[index - 1].vl + ratio * (wd[index].vl - wd[index - 1].vl);
  wt[i].vr = wd[index - 1].vr + ratio * (wd[index].vr - wd[index - 1].vr);
  wt[i].curvature = path.curvature[index - 1] +
                    ratio * (path.curvature[index] - path.curvature[index - 1]);
  wt[i].t = T;
  wt[i].dt = T - wt[i - 1].t;
  wt[i].pose.x =
      path.x[index - 1] + ratio * (path.x[index] - path.x[index - 1]);
  wt[i].pose.y =
      path.y[index - 1] + ratio * (path.y[index] - path.y[index - 1]);
  wt[i].pose.theta = path.theta[index - 1] +
                     ratio * (path.theta[index] - path.theta[index - 1]);
  wt[i].ds = wd[index - 1].ds + ratio * (wd[index].ds - wd[index - 1].ds);
  wt[i].s = wd[index - 1].s + ratio * (wd[index].s - wd[index - 1].s);
}

/**
 * @brief converts the distance domain profile to time domain with a fixed dt
 */
void MotionProfile2d::lerpToTimeDomain(float newDtms) {
  float newDt = newDtms / 1000.0;
  int intervals = static_cast<int>((totalTime + newDt) / newDt);
  wt.resize(intervals);
  int index = 1;
  for (size_t i = 0; i < wt.size(); i++) {
    float T = i * newDt;
    while (wd[index].t < T) {
      index++;
    }
    float ratio = (T - wd[index - 1].t) / (wd[index].t - wd[index - 1].t);
    interpolateWaypoint(i, index, ratio, T);
  }
  wt.back().v = vf;
  wt.back().vl = vf;
  wt.back().vr = vf;
  wt.back().pose.x = path.x.back();
  wt.back().pose.y = path.y.back();
  wt.back().pose.theta = path.theta.back();
}

/**
 * @brief adjusts both distance and time profiles for backward motion
 */
void MotionProfile2d::adjustForBackwardMotion() {
  if (wt.size() > 0) {
    for (size_t i = 0; i < wt.size(); i++) {
      wt[i].v *= -1;
      wt[i].curvature *= -1.0;
      float temp = wt[i].vl;
      wt[i].vl = -wt[i].vr;
      wt[i].vr = -temp;
      wt[i].pose.theta += 180;
    }
  }
  for (size_t i = 0; i < wd.size(); i++) {
    wd[i].v *= -1;
    wd[i].curvature *= -1.0;
    float temp = wd[i].vl;
    wd[i].vl = -wd[i].vr;
    wd[i].vr = -temp;
    wd[i].pose.theta += 180;
  }
}
