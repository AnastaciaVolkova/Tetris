#include "figure2.hpp"
using std::make_unique;
using std::move;
using std::unique_ptr;

Figure2::Figure2(Point &&p, Color c) : Figure(move(p), c) {
  state_ = State::k0;
}

void Figure2::Rotate() {
  switch (state_) {
  case State::k0:
    state_ = State::k90;
    break;
  case State::k90:
    state_ = State::k0;
    break;
  default:
    break;
  }
}

void Figure2::RotateCounter() { Rotate(); }

unique_ptr<Figure2> Figure2::make_ls(Point &&p) {
  unique_ptr<Figure2> fig =
      make_unique<Figure2>(Figure2(move(p), Color::kLime));
  fig->forms_[State::k0] = {{0, 0, fig->color_},
                            {0, 1, fig->color_},
                            {1, 1, fig->color_},
                            {1, 2, fig->color_}};
  fig->forms_[State::k90] = {{1, 1, fig->color_},
                             {2, 1, fig->color_},
                             {0, 2, fig->color_},
                             {1, 2, fig->color_}};
  return fig;
}

unique_ptr<Figure2> Figure2::make_rs(Point &&p) {
  unique_ptr<Figure2> fig =
      make_unique<Figure2>(Figure2(move(p), Color::kGreenYellow));
  fig->forms_[State::k0] = {{1, 0, fig->color_},
                            {0, 1, fig->color_},
                            {1, 1, fig->color_},
                            {0, 2, fig->color_}};
  fig->forms_[State::k90] = {{0, 1, fig->color_},
                             {1, 1, fig->color_},
                             {1, 2, fig->color_},
                             {2, 2, fig->color_}};

  return fig;
}

unique_ptr<Figure2> Figure2::make_stick(Point &&p) {
  unique_ptr<Figure2> fig = make_unique<Figure2>(Figure2(move(p), Color::kRed));
  fig->forms_[State::k0] = {{0, 0, fig->color_},
                            {0, 1, fig->color_},
                            {0, 2, fig->color_},
                            {0, 3, fig->color_}};
  fig->forms_[State::k90] = {{0, 3, fig->color_},
                             {1, 3, fig->color_},
                             {2, 3, fig->color_},
                             {3, 3, fig->color_}};

  return fig;
}