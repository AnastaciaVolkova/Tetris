#include "figure.hpp"

Figure::Figure() : form_(4), position_(0, 0) {
  for (auto &f : form_) {
    f.resize(1);
    f[0] = true;
  }
};

Figure::Figure(Point &p) : Figure() { position_ = p; };

const std::vector<std::vector<bool>> &Figure::GetForm() const { return form_; };

const Point &Figure::GetPosition() const { return position_; };

void Figure::SetPosition(Point p) { position_ = p; };