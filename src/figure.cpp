#include "figure.hpp"

using std::vector;

Figure::Figure(Point &&p, Color color) : position_(p), color_(color){};

const std::vector<Point> &Figure::GetForm() const { return forms_.at(state_); };

const Point &Figure::GetPosition() const { return position_; };

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
