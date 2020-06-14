#include "point.hpp"

using std::make_tuple;
using std::tuple;

Point::Point() : x(0), y(0){};

Point::Point(int xx, int yy, Color cc) : x(xx), y(yy), color(cc) {}

Point &Point::operator+=(const Point &ot) {
  x += ot.x;
  y += ot.y;
  return *this;
}

Point operator+(const Point &p1, const Point &p2) {
  return Point(p1.x + p2.x, p1.y + p2.y);
}

Point operator-(const Point &p1, const Point &p2) {
  return Point(p1.x - p2.x, p1.y - p2.y);
}

tuple<int, int, int, int> Point::GetRgba() const {
  switch (color) {
  case Color::kBlack:
    return make_tuple(0, 0, 0, 0xFF);
  case Color::kYellow:
    return make_tuple(0xff, 0xff, 0, 0xff);
  case Color::kBrown:
    return make_tuple(0xA5, 0x2A, 0x2A, 0xff);
  case Color::kGrey:
    return make_tuple(0x80, 0x80, 0x80, 0xff);
  case Color::kPink:
    return make_tuple(0xff, 0x14, 0x93, 0xff);
  case Color::kCrimson:
    return make_tuple(0xDC, 0x14, 0x3C, 0xff);
  case Color::kLime:
    return make_tuple(0x00, 0xff, 0x00, 0xff);
  case Color::kGreenYellow:
    return make_tuple(0xAD, 0xFF, 0x2F, 0xff);
  case Color::kRed:
    return make_tuple(0xff, 0x00, 0x00, 0xff);
  case Color::kCornFlowerBlue:
    return make_tuple(0x64, 0x95, 0xED, 0xff);
  default:
    return make_tuple(0xff, 0xff, 0xff, 0xff);
  }
}