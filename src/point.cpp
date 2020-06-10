#include "point.hpp"

Point::Point() : x(0), y(0){};
Point::Point(int xx, int yy) : x(xx), y(yy) {}
Point &Point::operator+=(const Point &ot) {
  x += ot.x;
  y += ot.y;
  return *this;
}
