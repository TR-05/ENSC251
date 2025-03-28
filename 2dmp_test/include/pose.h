#pragma once

#include <string>

namespace tntnlib
{
class Pose
{
   public:
    /** @brief x value*/
    float x;
    /** @brief y value*/
    float y;
    /** @brief theta value*/
    float theta;
    /**
     * @brief Create a new pose
     *
     * @param x component
     * @param y component
     * @param theta heading. Defaults to 0
     */
    Pose(float x, float y, float theta = 0);

    /**
     * @brief Add a pose to this pose
     *
     * @param other other pose
     * @return Pose
     */
    Pose operator+(const Pose &other);
    /**
     * @brief Subtract a pose from this pose
     *
     * @param other other pose
     * @return Pose
     */
    Pose operator-(const Pose &other);
    /**
     * @brief Multiply a pose by this pose
     *
     * @param other other pose
     * @return Pose
     */
    float operator*(const Pose &other);
    /**
     * @brief Multiply a pose by a float
     *
     * @param other float
     * @return Pose
     */
    Pose operator*(const float &other);
    /**
     * @brief Divide a pose by a float
     *
     * @param other float
     * @return Pose
     */
    Pose operator/(const float &other);
    /**
     * @brief Check if two poses are equal
     *
     * @param other the other pose
     * @return bool
     */
    bool operator==(const Pose &other);
    /**
     * @brief Check if two poses are not equal
     *
     * @param other the other pose
     * @return bool
     */
    bool operator!=(const Pose &other);
    /**
     * @brief Linearly interpolate between two poses
     *
     * @param other the other pose
     * @param t t value
     * @return Pose
     */
    Pose lerp(Pose other, float t);
    /**
     * @brief Get the distance between two poses
     *
     * @param other the other pose
     * @return float
     */
    float distance(Pose other);
    /**
     * @brief Get the angle between two poses
     *
     * @param other the other pose
     * @return float in radians
     */
    float angle(Pose other);
    /**
     * @brief Rotate a pose by an angle
     *
     * @param angle angle in radians
     * @return Pose
     */
    Pose rotate(float angle);
};  // class Pose

}  // namespace tntnlib