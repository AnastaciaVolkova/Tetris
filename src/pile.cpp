#include "pile.hpp"
#include <algorithm>
#include <stdexcept>

using std::find_if;
using std::vector;

Pile::Pile(int width, int height)
    : pile_space_(width), max_y_(height - 1), is_overloaded_(false) {}

bool Pile ::IsTouched(const Figure *figure) {
  bool is_touched = false;
  auto pile = GetPile();
  for (auto c : figure->GetForm()) {
    c += figure->GetPosition();
    // Find points of pile, which are right beneath current figure point.
    auto touch = find_if(pile.begin(), pile.end(), [&](auto it) {
      return ((c.x == it.x) && ((c.y + 1) == it.y));
    });
    is_touched = is_touched || (touch != pile.end()) || (c.y >= max_y_);
  }
  if (is_touched) {
    // Find out if points with negative y coordinate exist.
    auto a = find_if(
        figure->GetForm().begin(), figure->GetForm().end(),
        [&](const auto a) { return (a.y + figure->GetPosition().y) < 0; });
    if (a != figure->GetForm().end())
      is_overloaded_ = true;
  }
  return is_touched;
}

unsigned Pile::AddFigure(const Figure *figure) {
  vector<Point> point = figure->GetForm();
  for (auto p : point) {
    p += figure->GetPosition();
    if ((max_y_ - p.y + 1) > pile_space_[p.x].size())
      pile_space_[p.x].resize((max_y_ - p.y + 1), false);
    pile_space_[p.x][max_y_ - p.y] = true;
  }
  unsigned num_deleted_lines = ClearLine();
  ComputePilePointsSpace(); // Update space points of pile.
  return num_deleted_lines;
}

vector<Point> &Pile::GetPile() { return pile_points_space_; }

unsigned Pile::ClearLine() {
  unsigned num_lines = 0;
  unsigned row = 0;
  bool to_stop = false;
  while (!to_stop) {
    bool all_filled = true;
    for (int c = 0; c < pile_space_.size(); c++) {
      if (pile_space_[c].size() < (row + 1)) {
        to_stop = true;
        all_filled = false;
        break;
      } else
        all_filled = all_filled && pile_space_[c][row];
    }
    // Remove row
    if (all_filled) {
      for (int c = 0; c < pile_space_.size(); c++)
        pile_space_[c].erase(pile_space_[c].begin() + row);
      num_lines++;
    } else
      row++;
  }
  return num_lines;
}

bool Pile::IsOverloaded() { return is_overloaded_; };

void Pile::ComputePilePointsSpace() {
  pile_points_space_.clear();
  for (int c = 0; c < pile_space_.size(); c++)
    for (int r = 0; r < pile_space_[c].size(); r++)
      if (pile_space_[c][r])
        pile_points_space_.push_back(Point(c, max_y_ - r, Color::kGrey));
}