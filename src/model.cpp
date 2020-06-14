#include "figure1.hpp"
#include "figure2.hpp"
#include "figure4.hpp"
#include "model.hpp"
#include "pile.hpp"
#include <algorithm>
#include <iostream>

using std::make_unique;
using std::max_element;
using std::mt19937;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;

Model::Model(Controller *controller, int right_boundary, int bottom_boundary)
    : controller_(controller), right_boundary_(right_boundary),
      bottom_boundary_(bottom_boundary),
      pile_(right_boundary_, bottom_boundary_), was_touched_(false), score_(0),
      game_over_(false) {

  // Ignite random engine.
  random_device random_device;
  random_engine_ = mt19937(random_device());
  dist_ = uniform_int_distribution<int>(0, 6);

  // Generate first figures.
  FigureGenerator(); // First on game field.
  FigureGenerator(); // Next of first figure.
  UpdateSpace();
};

vector<const vector<Point> *> Model::GetOccupiedSpace() {
  vector<const vector<Point> *> space;
  space.push_back(&space_);
  space.push_back(&next_figure_space_);
  return space;
};

unsigned Model::GetTimeFall() { return time_fall_; };

void Model::UpdatePosition(Point &&point) {
  bool to_update = false;
  figure_->SetPosition(figure_->GetPosition() + point);
  // Check if figure is inside game field.
  if (!CheckBoundaries())
    figure_->SetPosition(figure_->GetPosition() - point);
  else
    to_update = true;

  // Check if figure reached bottom during previous update.
  if (was_touched_) {
    ComputeScore(pile_.AddFigure(figure_.get()));
    figure_.release();
    FigureGenerator();
    to_update = true;
    was_touched_ = false;
  }
  was_touched_ = pile_.IsTouched(figure_.get());
  if ((to_update) && (!game_over_))
    UpdateSpace();
  game_over_ = pile_.IsOverloaded();
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
  vector<Point> pile = pile_.GetPile();
  for (const auto &f : figure_->GetForm()) {
    Point a = f + figure_->GetPosition();
    // Find if figure and pile intersect.
    auto common = find_if(pile.begin(), pile.end(), [&](auto it) {
      return (it.x == a.x) && (it.y == a.y);
    });
    inside_boundaries =
        inside_boundaries &&
        ((a.x >= 0) && (a.x < right_boundary_) && (a.y < bottom_boundary_)) &&
        (common == pile.end());
  }
  return inside_boundaries;
}

void Model::UpdateSpace() {
  space_.clear();
  for (auto iv : figure_->GetForm()) {
    iv += figure_->GetPosition();
    space_.push_back(iv);
  }
  /*for (auto iv : next_figure_->GetForm()) {
    iv += next_figure_->GetPosition();
    space_.push_back(iv);
  }*/
  vector<Point> p = pile_.GetPile();
  copy(p.begin(), p.end(), std::back_inserter(space_));
}

void Model::FigureGenerator() {
  if (next_figure_ != nullptr) {
    figure_ = move(next_figure_);
    // Find the lowest point of the figure.
    auto fig_max_coor_y =
        max_element(figure_->GetForm().begin(), figure_->GetForm().end(),
                    [](auto a, auto b) { return a.y < b.y; });
    figure_->SetPosition({4, -fig_max_coor_y->y});
  }

  int d = dist_(random_engine_);
  switch (d) {
  case 0:
    next_figure_ = Figure1::make_square({12, 5});
    break;
  case 1:
    next_figure_ = Figure2::make_stick({12, 5});
    break;
  case 2:
    next_figure_ = Figure2::make_ls({12, 5});
    break;
  case 3:
    next_figure_ = Figure2::make_rs({12, 5});
    break;
  case 4:
    next_figure_ = Figure4::make_lhook({12, 5});
    break;
  case 5:
    next_figure_ = Figure4::make_rhook({12, 5});
    break;
  case 6:
    next_figure_ = Figure4::make_t({12, 5});
    break;
  default:
    break;
  }

  next_figure_space_.clear();
  for (auto it : next_figure_->GetForm()) {
    it += next_figure_->GetPosition();
    next_figure_space_.push_back(it);
  }
  time_fall_ = kFallTime;
}

unsigned Model::GetScore() { return score_; }

void Model::ComputeScore(unsigned num_deleted_lines) {
  if (num_deleted_lines != 0)
    score_ += 10 * (1 << num_deleted_lines);
}

bool Model::IsGameOver() { return game_over_; }
