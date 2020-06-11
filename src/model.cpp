#include "model.hpp"

#include <iostream>

using std::make_unique;
using std::vector;

Model::Model() {
  time_fall_ = 10;
  figure_ = make_unique<Figure>(Point({0, 0}));
};

vector<Point> Model::GetOccupiedSpace() {
  vector<Point> space = figure_->GetForm();
  for (auto &s : space)
    s += figure_->GetPosition();
  return space;
};

void Model::SetController(Controller *controller) { controller_ = controller; };

unsigned Model::GetTimeFall() { return time_fall_; };