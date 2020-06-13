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
  return ClearLine();
}

vector<Point> Pile::GetPile() {
  vector<Point> piles;
  for (int c = 0; c < pile_space_.size(); c++)
    for (int r = 0; r < pile_space_[c].size(); r++)
      if (pile_space_[c][r])
        piles.push_back(Point(c, max_y_ - r, Color::GREY));
  return piles;
}

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
    if (all_filled)
      for (int c = 0; c < pile_space_.size(); c++) {
        pile_space_[c].erase(pile_space_[c].begin() + row);
      }
    else
      row++;
  }
  return num_lines;
}