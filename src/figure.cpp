#include "figure.hpp"

Figure::Figure() : form_(4), position_(0, 0) {
  form_.push_back(Point(0, 0));
  form_.push_back(Point(0, 1));
  form_.push_back(Point(0, 2));
  form_.push_back(Point(1, 2));
};

Figure::Figure(Point &&p) : Figure() { position_ = p; };

const std::vector<Point> Figure::GetForm() const { return form_; };

const Point &Figure::GetPosition() const { return position_; };

void Figure::SetPosition(Point p) { position_ = p; };
