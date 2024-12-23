#include "../include/pathToPose.h"

/**
 * @brief Generates a cubic bezier curve between 2 poses, with 3 tuning factors
 * @param c1Gain scales how far to lead the first carrot in front of the bot
 * (0.5 is a good start)
 * @param c2Gain scales how far to lead the second carrot in from the target
 * (0.5 is a good start)
 * @param angularGain scales both carrots lead depending on the change in pose
 * angle (1 is a good start)
 */
Path pathToPose(Pose start, Pose target, float c1Gain, float c2Gain,
                float angularGain, bool backwards) {
  if (backwards) {
    start.theta -= 180;
    target.theta -= 180;
  }
  double dtheta = target.theta - start.theta;
  double thetaGain = 1 + fabs(dtheta) / 135 * angularGain;

  double d = start.distance(target);
  Pose c1 = start;
  double c1Theta = (90 - start.theta) * M_PI / 180.0f;
  double c1Lead = d / 2 * c1Gain * thetaGain;
  c1.x = start.x + c1Lead * cos(c1Theta);
  c1.y = start.y + c1Lead * sin(c1Theta);

  Pose c2 = target;
  double c2Theta = (90 - target.theta) * M_PI / 180.0f;
  double c2Lead = d / 2 * c2Gain * thetaGain;
  c2.x = target.x - c2Lead * cos(c2Theta);
  c2.y = target.y - c2Lead * sin(c2Theta);

  Path path(start.x, start.y, c1.x, c1.y, c2.x, c2.y, target.x, target.y, .25);
  return path;
}