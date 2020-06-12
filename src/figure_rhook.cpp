#include "figure.hpp"
#include "figure_rhook.hpp"

using std::move;
using std::vector;

FigureRHook::FigureRHook(Point &&point) : Figure(move(point), Color::PINK) {
  forms_[State::k0] = {{0, 2, Color::PINK},
                       {1, 0, Color::PINK},
                       {1, 1, Color::PINK},
                       {1, 2, Color::PINK}};
  forms_[State::k90] = {{0, 1, Color::PINK},
                        {1, 1, Color::PINK},
                        {2, 1, Color::PINK},
                        {2, 2, Color::PINK}};
  forms_[State::k180] = {{0, 0, Color::PINK},
                         {0, 1, Color::PINK},
                         {0, 2, Color::PINK},
                         {1, 0, Color::PINK}};
  forms_[State::k270] = {{0, 1, Color::PINK},
                         {0, 2, Color::PINK},
                         {1, 2, Color::PINK},
                         {2, 2, Color::PINK}};
};

void FigureRHook::RotateCounter() {
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

void FigureRHook::Rotate() {
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