#include "figure_lhook.hpp"
#include "figure_square.hpp"
#include "model.hpp"
#include "pile.hpp"
#include <iostream>

using std::make_unique;
using std::vector;

Model::Model(Controller *controller, int right_boundary, int bottom_boundary)
    : controller_(controller), right_boundary_(right_boundary),
      bottom_boundary_(bottom_boundary),
      pile_(right_boundary_, bottom_boundary_) {
  time_fall_ = 10;
  figure_ = make_unique<FigureSquare>(Point({0, 0}));
  UpdateSpace();
};

const vector<Point> &Model::GetOccupiedSpace() { return space_; };

unsigned Model::GetTimeFall() { return time_fall_; };

void Model::UpdatePosition(Point &&point) {
  bool to_update = false;
  if (figure_ == nullptr)
    return;
  figure_->SetPosition(figure_->GetPosition() + point);
  // Check if figure is inside game field.
  if (!CheckBoundaries())
    figure_->SetPosition(figure_->GetPosition() - point);
  else
    to_update = true;

  // Check if figure reaches bottom.
  if (pile_.IsTouched(figure_.get())) {
    pile_.AddFigure(figure_.get());
    figure_.release();
    to_update = true;
  }
  if (to_update)
    UpdateSpace();
}

void Model::RotateCounter() {
  figure_->RotateCounter();
  // Check if figure is inside game field.
  // Rotate figure back, if check fails.
  if (!CheckBoundaries())
    figure_->Rotate();
  else
    UpdateSpace();
}

void Model::Rotate() {
  figure_->Rotate();
  // Check if figure is inside game field.
  // Rotate figure back, if check fails.
  if (!CheckBoundaries())
    figure_->RotateCounter();
  else
    UpdateSpace();
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

void Model::UpdateSpace() {
  space_.clear();
  if (figure_ != nullptr) {
    vector<Point> v = figure_->GetForm();
    copy(v.begin(), v.end(), std::back_inserter(space_));
    for (auto &s : space_)
      s += figure_->GetPosition();
  }
  vector<Point> p = pile_.GetPile();
  copy(p.begin(), p.end(), std::back_inserter(space_));
}
