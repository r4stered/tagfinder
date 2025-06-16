#include "apriltag/apriltag.hpp"
#include <fmt/format.h>
#include <stdexcept>

namespace apriltag {

int Calculator::add(int a, int b) {
    return a + b;
}

int Calculator::subtract(int a, int b) {
    return a - b;
}

int Calculator::multiply(int a, int b) {
    return a * b;
}

double Calculator::divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return static_cast<double>(a) / static_cast<double>(b);
}

std::string get_version() {
    return fmt::format("AprilTag version {}.{}.{}", 0, 0, 1);
}

} // namespace apriltag