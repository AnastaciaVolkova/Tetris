#include "model.hpp"

#include <iostream>

using std::make_unique;
using std::vector;

Model::Model(Controller *controller, int right_boundary, int bottom_boundary)
    : controller_(controller), right_boundary_(right_boundary),
      bottom_boundary_(bottom_boundary) {
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

void Model::UpdatePosition(Point &&point) {
  figure_->SetPosition(figure_->GetPosition() + point);
  if (!CheckBoundaries())
    figure_->SetPosition(figure_->GetPosition() - point);
};

void Model::RotateCounter() {
  figure_->RotateCounter();
  // Check if figure is inside game field.
  // Rotate figure back, if check fails.
  if (!CheckBoundaries()) {
    figure_->Rotate();
  }
}

void Model::Rotate() {
  figure_->Rotate();
  // Check if figure is inside game field.
  // Rotate figure back, if check fails.
  if (!CheckBoundaries()) {
    figure_->RotateCounter();
  };
}

bool Model::CheckBoundaries() {
  bool inside_boundaries = true;
  for (const auto &f : figure_->GetForm()) {
    Point a = f + figure_->GetPosition();
    inside_boundaries =
        inside_boundaries &&
        ((a.x >= 0) && (a.x < right_boundary_) && (a.y < bottom_boundary_));
  }
  return inside_boundaries;
}
