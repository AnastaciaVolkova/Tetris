#ifndef _FIGURE_HPP_
#define _FIGURE_HPP_
#include "point.hpp"
#include <vector>

class Figure {
private:
  // 2D vector describes the points of figure.
  std::vector<Point> form_;
  Point position_; // Position of left top point.
public:
  Figure();
  Figure(Point &&p);

  const std::vector<Point> GetForm() const;
  const Point &GetPosition() const;
  void SetPosition(Point p);
};
#endif
