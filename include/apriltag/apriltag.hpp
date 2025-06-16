#pragma once

#include <string>

namespace apriltag {

class Calculator {
public:
    int add(int a, int b);
    int subtract(int a, int b);
    int multiply(int a, int b);
    double divide(int a, int b);
};

std::string get_version();

} // namespace apriltag