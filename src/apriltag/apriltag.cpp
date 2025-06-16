#include "apriltag/apriltag.hpp"
#include "fmt/base.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace apriltag {
Image::Image(std::string_view filePath) {
  fmt::print("Loading image from path: {}\n", filePath);

  imageData = stbi_load(filePath.data(), &width, &height, &channels, 0);
  if (imageData != nullptr) {
    fmt::print("Loaded image! Width: {} Height: {}, Channels: {}\n", width,
               height, channels);
  } else {
    fmt::print("Oh no! Couldn't load image :(");
  }
}

Image::~Image() {
  if (imageData != nullptr) {
    stbi_image_free(imageData);
  }
}
}  // namespace apriltag