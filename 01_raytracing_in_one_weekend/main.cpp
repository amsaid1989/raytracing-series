#include "color.hpp"
#include "ray.hpp"
#include "vec3.hpp"
#include <iostream>

color ray_color(const ray &r) {
  vec3 unit_direction = unit_vector(r.direction());

  double t = 0.5 * (unit_direction.y() + 1.0);

  return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

int main(int argc, char *argv[]) {
  // Image
  const double aspect_ratio = 16.0 / 9.0;
  const int width = 400;
  const int height = (int)(width / aspect_ratio);

  // Camera
  double viewport_height = 2.0;
  double viewport_width = viewport_height * aspect_ratio;
  double focal_length = 1.0;

  point3 origin = point3(0, 0, 0);
  vec3 horizontal = vec3(viewport_width, 0, 0);
  vec3 vertical = vec3(0, viewport_height, 0);
  point3 lower_left_corner =
      origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);

  // Render
  std::cout << "P3\n" << width << ' ' << height << "\n255\n";

  for (int j = height - 1; j >= 0; --j) {
    std::cerr << "\rScalines remaining: " << j << ' ' << std::flush;
    for (int i = 0; i < width; ++i) {
      double u = double(i) / (width - 1);
      double v = double(j) / (height - 1);

      ray r{origin, lower_left_corner + u * horizontal + v * vertical - origin};

      color pixel_color = ray_color(r);

      write_color(std::cout, pixel_color);
    }
  }

  std::cerr << "\nDone.\n";

  return 0;
}
