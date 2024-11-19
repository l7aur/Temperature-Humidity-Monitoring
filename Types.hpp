#ifndef TYPES_HPP
#define TYPES_HPP

#include <stdint.h>

struct Color {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  Color(uint8_t r, uint8_t g, uint8_t b) : red(r), green(g), blue(b) {}
};

enum Notes {FULL = 1, HALF = 2, QUARTER = 4, EIGTH = 8};

const Color RED(0xFF, 0x00, 0x00);
const Color GREEN(0x00, 0xFF, 0x00);
const Color BLUE(0x00, 0x00, 0xFF);
const Color CYAN(0x00, 0xFF, 0xFF);
const Color MAGENTA(0xFF, 0x00, 0xFF);
const Color YELLOW(0xFF, 0xFF, 0x00);

#endif