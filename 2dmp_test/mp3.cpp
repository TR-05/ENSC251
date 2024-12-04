#include "mp3.h"

#include <vector>

// more organized and versatile version of the motion profile class

using namespace tntnlib;

int sgn(float x) { return (x > 0) - (x < 0); }

void acelPass2(float &vl, float &vr, float &v, float &w, const float &lastVl,
               const float &lastVr, const float &c, const float &vMax,
               const float &wMax, const float &acel, const float &dd,
               const float &trackWidth);

mp3::mp3() {}
mp3::mp3(Path &path, float vi, float wi, float vf, float vMax, float wMax,
         float acel, float decel, float trackWidth, bool backwards)
    : path(path), vi(vi), wi(wi), vf(vf), vMax(vMax), wMax(wMax), acel(acel),
      decel(decel), trackWidth(trackWidth), backwards(backwards) {

  acelDist = calculateDistance(vi, vMax, acel);
  decelDist = calculateDistance(vMax, vf, decel);
  coastDist = calculateCoastDistance(path.length, acelDist, decelDist);

  initializeWaypoints();
  forwardPass();
  backwardPass();
  calculateTimeIntervals();
  lerpToTimeDomain(10);

  if (backwards) {
    adjustForBackwardMotion();
  }
}

float mp3::calculateDistance(float vInitial, float vFinal, float acel) {
  return fabs((vFinal * vFinal - vInitial * vInitial) / (2 * acel));
}

float mp3::calculateCoastDistance(float pathLength, float acelDist,
                                  float decelDist) {
  float coastDist = pathLength - acelDist - decelDist;
  if (coastDist < 0) {
    coastDist = 0;
    acelDist = acelDist * pathLength / (acelDist + decelDist);
    decelDist = decelDist * pathLength / (acelDist + decelDist);
  }
  return coastDist;
}

void mp3::initializeWaypoints() {
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

void mp3::forwardPass() {
  for (size_t i = 1; i < wd.size(); i++) {
    float d = i * path.pointSpacing;
    wd[i].v = vMax;
    wd[i].w = wd[i].v * path.curvature[i];
    if (fabs(wd[i].w) > wMax) {
      wd[i].w = wMax * sgn(wd[i].w);
      wd[i].v = wd[i].w / path.curvature[i];
    }
    acelPass2(wd[i].vl, wd[i].vr, wd[i].v, wd[i].w, wd[i - 1].vl, wd[i - 1].vr,
              path.curvature[i], vMax, wMax, acel, path.pointSpacing,
              trackWidth);
  }
}

void mp3::backwardPass() {
  int numPoints = wd.size();
  wd.back().v = vf;
  wd.back().vl = vf;
  wd.back().vr = vf;
  wd.back().w = 0;

  for (int i = numPoints - 2; i >= 0; i--) {
    acelPass2(wd[i].vl, wd[i].vr, wd[i].v, wd[i].w, wd[i + 1].vl, wd[i + 1].vr,
              path.curvature[i], vMax, wMax, decel, path.pointSpacing,
              trackWidth);
  }
}

void mp3::calculateTimeIntervals() {
  for (size_t i = 1; i < wd.size(); i++) {
    wd[i].dt = path.pointSpacing / ((wd[i].v + wd[i - 1].v) / 2);
    wd[i].t = wd[i - 1].t + wd[i].dt;
  }
  wd.back().dt = 0;
  wd.back().t = wd[wd.size() - 1].t;
  totalTime = wd.back().t;
}

void mp3::lerpToTimeDomain(float newDtms) {
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
    interpolateWaypoints(i, index, ratio, T);
  }
  wt.back().v = vf;
  wt.back().vl = vf;
  wt.back().vr = vf;
  wt.back().pose.x = path.x.back();
  wt.back().pose.y = path.y.back();
  wt.back().pose.theta = path.theta.back();
}

void mp3::interpolateWaypoints(int i, int index, float ratio, float T) {
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

void mp3::adjustForBackwardMotion() {
  for (size_t i = 0; i < wt.size(); i++) {
    wt[i].v *= -1;
    wt[i].curvature *= -1;
    wt[i].vl = wt[i].v * (2 + wt[i].curvature * trackWidth) / 2;
    wt[i].vr = wt[i].v * (2 - wt[i].curvature * trackWidth) / 2;
    wt[i].pose.theta += 180;
  }
}

// This should work for both forward and backward passes I think?
void acelPass2(float &vl, float &vr, float &v, float &w, const float &lastVl,
               const float &lastVr, const float &c, const float &vMax,
               const float &wMax, const float &acel, const float &dd,
               const float &trackWidth) {

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