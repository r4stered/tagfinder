#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "apriltag/apriltag.hpp"

using namespace apriltag;

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}