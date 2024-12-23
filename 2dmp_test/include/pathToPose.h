#pragma once

#include "cubicBezier.h"
#include "pose.h"

using namespace tntnlib;


/**
 * @brief Generates a cubic bezier curve between 2 poses, with 3 tuning factors
 * @param c1Gain scales how far to lead the first carrot in front of the bot (0.5 is a good start)
 * @param c2Gain scales how far to lead the second carrot in from the target (0.5 is a good start)
 * @param angularGain scales both carrots lead depending on the change in pose angle (1 is a good start)
 */
 Path pathToPose(Pose start, Pose target, float c1Gain, float c2Gain, float angularGain, bool backwards);