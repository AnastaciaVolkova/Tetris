#include "figure1.hpp"
using std::make_unique;
using std::move;
using std::unique_ptr;

Figure1::Figure1(Point &&p, Color c) : Figure(move(p), c) {
  state_ = State::k0;
}

void Figure1::Rotate() {
  // Do nothing. Figure is symmetric.
}

void Figure1::RotateCounter() {
  // Do nothing. Figure is symmetric.
}

unique_ptr<Figure1> Figure1::make_square(Point &&p) {
  unique_ptr<Figure1> fig =
      make_unique<Figure1>(Figure1(move(p), Color::CORNFLOWER_BLUE));
  fig->forms_[State::k0] = {{0, 0, fig->color_},
                            {0, 1, fig->color_},
                            {1, 1, fig->color_},
                            {1, 0, fig->color_}};
  return fig;
}