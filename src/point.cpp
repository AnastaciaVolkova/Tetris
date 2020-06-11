#include "point.hpp"

Point::Point() : x(0), y(0){};
Point::Point(int xx, int yy) : x(xx), y(yy) {}
Point &Point::operator+=(const Point &ot) {
  x += ot.x;
  y += ot.y;
  return *this;
}

Point operator+(const Point &p1, const Point &p2) {
  return Point(p1.x + p2.x, p1.y + p2.y);
};