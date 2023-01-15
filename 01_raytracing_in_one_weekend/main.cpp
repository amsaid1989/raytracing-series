#include "color.hpp"
#include "vec3.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  const int width = 256;
  const int height = 256;

  std::cout << "P3\n" << width << ' ' << height << "\n255\n";

  for (int j = height - 1; j >= 0; --j) {
    std::cerr << "\rScalines remaining: " << j << ' ' << std::flush;
    for (int i = 0; i < width; ++i) {
      color pixel_color{double(i) / (width - 1), double(j) / (height - 1),
                        0.25};

      write_color(std::cout, pixel_color);
    }
  }

  std::cerr << "\nDone.\n";

  return 0;
}
