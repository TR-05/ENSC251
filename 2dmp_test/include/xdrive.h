#pragma once

#include <array>

std::array<float, 4> wheelVelocities(float TargetAngle, float linearVelocity, float RPS,
    float maxWheelVelocity, float radius, float currentAngle);