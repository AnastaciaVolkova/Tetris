#ifndef _POINT_HPP_
#define _POINT_HPP_
struct Point {
  int x, y;
  Point();
  Point(int xx, int yy);
  Point &operator+=(const Point &ot);
};
#endif