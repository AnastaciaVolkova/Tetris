#ifndef _POINT_HPP_
#define _POINT_HPP_

//! Contains figure color
enum class Color { BROWN, YELLOW };

//! Struct Point implements operations with points
struct Point {
  int x, y; // x,y coordinates
  Point();
  Point(int xx, int yy);
  Point &operator+=(const Point &ot);
  friend Point operator+(const Point &p1, const Point &p2);
  friend Point operator-(const Point &p1, const Point &p2);
};
#endif