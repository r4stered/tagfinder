#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "apriltag/apriltag.hpp"

using namespace apriltag;

class CalculatorTest : public ::testing::Test {
protected:
    Calculator calc;
};

TEST_F(CalculatorTest, AddPositiveNumbers) {
    EXPECT_EQ(calc.add(2, 3), 5);
    EXPECT_EQ(calc.add(10, 20), 30);
}

TEST_F(CalculatorTest, AddNegativeNumbers) {
    EXPECT_EQ(calc.add(-2, -3), -5);
    EXPECT_EQ(calc.add(-10, 5), -5);
}

TEST_F(CalculatorTest, SubtractNumbers) {
    EXPECT_EQ(calc.subtract(5, 3), 2);
    EXPECT_EQ(calc.subtract(3, 5), -2);
}

TEST_F(CalculatorTest, MultiplyNumbers) {
    EXPECT_EQ(calc.multiply(3, 4), 12);
    EXPECT_EQ(calc.multiply(-3, 4), -12);
    EXPECT_EQ(calc.multiply(0, 100), 0);
}

TEST_F(CalculatorTest, DivideNumbers) {
    EXPECT_DOUBLE_EQ(calc.divide(10, 2), 5.0);
    EXPECT_DOUBLE_EQ(calc.divide(7, 2), 3.5);
}

TEST_F(CalculatorTest, DivideByZeroThrows) {
    EXPECT_THROW(calc.divide(10, 0), std::invalid_argument);
}

TEST(VersionTest, GetVersion) {
    std::string version = get_version();
    EXPECT_THAT(version, ::testing::HasSubstr("AprilTag version"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}