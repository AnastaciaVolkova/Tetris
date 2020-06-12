#include "figure.hpp"
#include "figure_square.hpp"

using std::move;
using std::vector;

FigureSquare::FigureSquare(Point &&point) : Figure(move(point), Color::BROWN) {
  forms_[State::k0] = {{0, 0, Color::BROWN},
                       {0, 1, Color::BROWN},
                       {1, 1, Color::BROWN},
                       {1, 0, Color::BROWN}};
};

void FigureSquare::RotateCounter() {
  // Do nothing as square is symmetric.
}

void FigureSquare::Rotate() {
  // Do nothing as square is symmetric.
}