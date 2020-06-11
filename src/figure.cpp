#include "figure.hpp"

using std::vector;

Figure::Figure() : position_(0, 0) {
  forms_[State::k0] = {{0, 0}, {0, 1}, {0, 2}, {1, 2}};
  forms_[State::k90] = {{0, 2}, {1, 2}, {2, 2}, {2, 1}};
  forms_[State::k180] = {{0, 0}, {1, 0}, {1, 1}, {1, 2}};
  forms_[State::k270] = {{0, 0}, {0, 1}, {1, 0}, {2, 0}};
};

Figure::Figure(Point &&p) : Figure() { position_ = p; };

const std::vector<Point> &Figure::GetForm() { return forms_[state_]; };

const Point &Figure::GetPosition() { return position_; };

void Figure::SetPosition(Point &&p) { position_ = p; };

void Figure::RotateCounter() {
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
    state_ = State::k0;
    break;
  }
}

void Figure::Rotate() {
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