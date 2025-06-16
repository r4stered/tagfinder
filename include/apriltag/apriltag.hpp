#pragma once

#include <string_view>

namespace apriltag {
class Image {
 public:
  Image(std::string_view filePath);
  virtual ~Image();

 private:
  unsigned char* imageData{nullptr};
  int width;
  int height;
  int channels;
};
}  // namespace apriltag