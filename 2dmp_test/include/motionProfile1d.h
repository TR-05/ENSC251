#pragma once
#include <vector>

class MotionProfile1d {
private:
public:
    MotionProfile1d();
    MotionProfile1d(double distance, double maxVelocity, double acel, double decel);
    ~MotionProfile1d() {}

    std::vector<double> v,t;
    double totalTime;
};