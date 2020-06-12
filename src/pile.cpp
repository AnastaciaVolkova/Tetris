#include "pile.hpp"
#include <stdexcept>

using std::vector;

Pile::Pile(int width, int height) : pile_space_(width), max_y_(height - 1) {}

bool Pile ::IsTouched(const Figure *figure) {
  bool is_touched = false;
  for (auto c : figure->GetForm()) {
    c += figure->GetPosition();
    is_touched = is_touched || (c.y >= (max_y_ - pile_space_[c.x].size()));
  }
  return is_touched;
}

int Pile::AddFigure(const Figure *figure) {
  vector<Point> point = figure->GetForm();
  for (auto p : point) {
    p += figure->GetPosition();
    if ((max_y_ - p.y + 1) > pile_space_[p.x].size())
      pile_space_[p.x].resize((max_y_ - p.y + 1), false);
    if (pile_space_[p.x][max_y_ - p.y] == true)
      throw std::runtime_error("Error pile: cell is alread occupied");
    pile_space_[p.x][max_y_ - p.y] = true;
  }
}

vector<Point> Pile::GetPile() {
  vector<Point> piles;
  for (int c = 0; c < pile_space_.size(); c++)
    for (int r = 0; r < pile_space_[c].size(); r++)
      if (pile_space_[c][r])
        piles.push_back(Point(c, max_y_ - r));
  return piles;
}