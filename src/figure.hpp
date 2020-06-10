#ifndef _FIGURE_HPP_
#define _FIGURE_HPP_
#include <vector>

struct Point {
  int x, y;
  Point(int xx, int yy) : x(xx), y(yy) {}
};

class Figure {
private:
  // 2D vector describes the points of figure.
  std::vector<std::vector<bool>> form_;
  Point position_; // Position of left top point.
public:
  Figure();
  Figure(Point &p);

  const std::vector<std::vector<bool>> &GetForm() const;
  const Point &GetPosition() const;
  void SetPosition(Point p);
};
#endif