#ifndef _POINT_HPP_
#define _POINT_HPP_

//! Struct Point implements operations with points
struct Point {
  int x, y; // x,y coordinates
  Point();
  Point(int xx, int yy);
  Point &operator+=(const Point &ot);
};
#endif