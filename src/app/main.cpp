#include "apriltag/apriltag.hpp"
#include <fmt/core.h>
#include <iostream>

int main() {
  fmt::print("Hello from TagFinder!\n");
  fmt::print("{}\n", apriltag::get_version());

  apriltag::Calculator calc;

  int a = 10;
  int b = 5;

  fmt::print("{} + {} = {}\n", a, b, calc.add(a, b));
  fmt::print("{} - {} = {}\n", a, b, calc.subtract(a, b));
  fmt::print("{} * {} = {}\n", a, b, calc.multiply(a, b));
  fmt::print("{} / {} = {:.2f}\n", a, b, calc.divide(a, b));

  return 0;
}