#include "figure4.hpp"
using std::make_unique;
using std::move;
using std::unique_ptr;

Figure4::Figure4(Point &&p, Color c) : Figure(move(p), c) {
  state_ = State::k0;
}

void Figure4::Rotate() {
  switch (state_) {
  case State::k0:
    state_ = State::k270;
    break;
  case State::k90:
    state_ = State::k0;
    break;
  case State::k180:
    state_ = State::k90;
    break;
  case State::k270:
    state_ = State::k180;
    break;
  }
}

void Figure4::RotateCounter() {
  switch (state_) {
  case State::k0:
    state_ = State::k90;
    break;
  case State::k90:
    state_ = State::k180;
    break;
  case State::k180:
    state_ = State::k270;
    break;
  case State::k270:
    state_ = State::k0;
    break;
  }
}

unique_ptr<Figure4> Figure4::make_lhook(Point &&p) {
  unique_ptr<Figure4> fig =
      make_unique<Figure4>(Figure4(move(p), Color::YELLOW));
  fig->forms_[State::k0] = {{0, 0, fig->color_},
                            {0, 1, fig->color_},
                            {0, 2, fig->color_},
                            {1, 2, fig->color_}};
  fig->forms_[State::k90] = {{0, 2, fig->color_},
                             {1, 2, fig->color_},
                             {2, 2, fig->color_},
                             {2, 1, fig->color_}};
  fig->forms_[State::k180] = {{0, 0, fig->color_},
                              {1, 0, fig->color_},
                              {1, 1, fig->color_},
                              {1, 2, fig->color_}};
  fig->forms_[State::k270] = {{0, 1, fig->color_},
                              {1, 1, fig->color_},
                              {2, 1, fig->color_},
                              {0, 2, fig->color_}};
  return fig;
}

unique_ptr<Figure4> Figure4::make_rhook(Point &&p) {
  unique_ptr<Figure4> fig = make_unique<Figure4>(Figure4(move(p), Color::PINK));
  fig->forms_[State::k0] = {{1, 0, fig->color_},
                            {1, 1, fig->color_},
                            {1, 2, fig->color_},
                            {0, 2, fig->color_}};
  fig->forms_[State::k90] = {{0, 1, fig->color_},
                             {1, 1, fig->color_},
                             {2, 1, fig->color_},
                             {2, 2, fig->color_}};
  fig->forms_[State::k180] = {{0, 0, fig->color_},
                              {0, 1, fig->color_},
                              {0, 2, fig->color_},
                              {1, 0, fig->color_}};
  fig->forms_[State::k270] = {{0, 1, fig->color_},
                              {0, 2, fig->color_},
                              {1, 2, fig->color_},
                              {2, 2, fig->color_}};
  return fig;
}

unique_ptr<Figure4> Figure4::make_t(Point &&p) {
  unique_ptr<Figure4> fig =
      make_unique<Figure4>(Figure4(move(p), Color::CRIMSON));
  fig->forms_[State::k0] = {{0, 2, fig->color_},
                            {1, 2, fig->color_},
                            {2, 2, fig->color_},
                            {1, 2, fig->color_}};
  fig->forms_[State::k90] = {{0, 1, fig->color_},
                             {1, 0, fig->color_},
                             {1, 1, fig->color_},
                             {1, 2, fig->color_}};
  fig->forms_[State::k180] = {{0, 1, fig->color_},
                              {1, 1, fig->color_},
                              {2, 1, fig->color_},
                              {1, 2, fig->color_}};
  fig->forms_[State::k270] = {{0, 0, fig->color_},
                              {0, 1, fig->color_},
                              {0, 2, fig->color_},
                              {1, 1, fig->color_}};
  return fig;
}