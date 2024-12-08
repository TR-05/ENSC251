#pragma once
#include <vector>

class MotionProfile1d {
private:
public:
    MotionProfile1d();
    MotionProfile1d(float distance, float maxVelocity, float acel, float decel);
    ~MotionProfile1d() {}

    std::vector<float> v,t;
    float totalTime;
};