#include "apriltag/apriltag.hpp"
#include "fmt/base.h"
#include <string>

int main(int argc, char* argv[]) {
  fmt::print("Hello from TagFinder!\n");

  std::string filePath{argv[1]};

  apriltag::Image image{filePath};

  return 0;
}