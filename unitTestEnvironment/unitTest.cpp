// test_otos.cpp
#include <gtest/gtest.h>
#include <cmath>

// Function to be tested
float updateHeading(float& normalizedHeading, float lastNormalizedHeading, int& totalRotations) {
    float bound = 20;
    if (normalizedHeading < 0) {
        normalizedHeading = 360 + normalizedHeading;
    }
    // check for rollover and adjust totalRotations to account
    if (normalizedHeading < bound && lastNormalizedHeading > 360 - bound) {
        totalRotations++;
    }
    if (normalizedHeading > 360 - bound && lastNormalizedHeading < bound) {
        totalRotations--;
    }

    float accumulatedAngle = totalRotations * 360 + normalizedHeading;
    return accumulatedAngle;
}

// Unit tests
TEST(UpdateHeadingTest, NoRollover) {
    float normalizedHeading = 45;
    float lastNormalizedHeading = 30;
    int totalRotations = 0;
    float accumulatedAngle = updateHeading(normalizedHeading, lastNormalizedHeading, totalRotations);
    EXPECT_EQ(accumulatedAngle, 45);
    EXPECT_EQ(totalRotations, 0);
}

TEST(UpdateHeadingTest, PositiveRollover) {
    float normalizedHeading = 10;
    float lastNormalizedHeading = 350;
    int totalRotations = 0;
    float accumulatedAngle = updateHeading(normalizedHeading, lastNormalizedHeading, totalRotations);
    EXPECT_EQ(accumulatedAngle, 370); // 1 * 360 + 10
    EXPECT_EQ(totalRotations, 1);
}

TEST(UpdateHeadingTest, NegativeRollover) {
    float normalizedHeading = 350;
    float lastNormalizedHeading = 10;
    int totalRotations = 1;
    float accumulatedAngle = updateHeading(normalizedHeading, lastNormalizedHeading, totalRotations);
    EXPECT_EQ(accumulatedAngle, 710); // 1 * 360 + 350
    EXPECT_EQ(totalRotations, 0);
}

TEST(UpdateHeadingTest, NegativeAngle) {
    float normalizedHeading = -30;
    float lastNormalizedHeading = 30;
    int totalRotations = 0;
    float accumulatedAngle = updateHeading(normalizedHeading, lastNormalizedHeading, totalRotations);
    EXPECT_EQ(accumulatedAngle, 330); // 360 - 30
    EXPECT_EQ(totalRotations, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}