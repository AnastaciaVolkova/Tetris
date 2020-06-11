#include "model.hpp"

#include <iostream>

using std::make_unique;
using std::vector;

Model::Model(Controller *controller) : controller_(controller) {
  time_fall_ = 10;
  figure_ = make_unique<Figure>(Point({0, 0}));
};

vector<Point> Model::GetOccupiedSpace() {
  vector<Point> space = figure_->GetForm();
  for (auto &s : space)
    s += figure_->GetPosition();
  return space;
};

unsigned Model::GetTimeFall() { return time_fall_; };