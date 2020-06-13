#include "figure1.hpp"
#include "figure2.hpp"
#include "figure4.hpp"
#include "model.hpp"
#include "pile.hpp"
#include <iostream>

using std::make_unique;
using std::mt19937;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;

Model::Model(Controller *controller, int right_boundary, int bottom_boundary)
    : controller_(controller), right_boundary_(right_boundary),
      bottom_boundary_(bottom_boundary),
      pile_(right_boundary_, bottom_boundary_) {

  // Ignite random engine.
  random_device random_device;
  random_engine_ = mt19937(random_device());
  dist_ = uniform_int_distribution<int>(1, 6);

  // Generate first figure.
  FigureGenerator();

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
    FigureGenerator();
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

void Model::Accelerate() { time_fall_ = kMinFallTime; }

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

void Model::FigureGenerator() {
  int d = dist_(random_engine_);
  switch (d) {
  case 0:
    figure_ = Figure1::make_square({5, 0});
    break;
  case 1:
    figure_ = Figure2::make_stick({5, 0});
    break;
  case 2:
    figure_ = Figure2::make_ls({5, 0});
    break;
  case 3:
    figure_ = Figure2::make_rs({5, 0});
    break;
  case 4:
    figure_ = Figure4::make_lhook({5, 0});
    break;
  case 5:
    figure_ = Figure4::make_rhook({5, 0});
    break;
  case 6:
    figure_ = Figure4::make_t({5, 0});
    break;
  default:
    break;
  }
  time_fall_ = kFallTime;
}
