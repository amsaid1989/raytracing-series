#ifndef COLOR_HPP
#define COLOR_HPP

#include "vec3.hpp"
#include <iostream>

inline void write_color(std::ostream &os, color pixel_color) {
  os << (int)(255.999 * pixel_color.x()) << ' '
     << (int)(255.999 * pixel_color.y()) << ' '
     << (int)(255.999 * pixel_color.z()) << '\n';
}

#endif // !COLOR_HPP
