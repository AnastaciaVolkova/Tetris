#include "figure.hpp"
#include "figure_lhook.hpp"

using std::move;
using std::vector;

FigureLHook::FigureLHook(Point &&point) : Figure(move(point), Color::YELLOW) {
  forms_[State::k0] = {{0, 0, Color::YELLOW},
                       {0, 1, Color::YELLOW},
                       {0, 2, Color::YELLOW},
                       {1, 2, Color::YELLOW}};
  forms_[State::k90] = {{0, 2, Color::YELLOW},
                        {1, 2, Color::YELLOW},
                        {2, 2, Color::YELLOW},
                        {2, 1, Color::YELLOW}};
  forms_[State::k180] = {{0, 0, Color::YELLOW},
                         {1, 0, Color::YELLOW},
                         {1, 1, Color::YELLOW},
                         {1, 2, Color::YELLOW}};
  forms_[State::k270] = {{0, 0, Color::YELLOW},
                         {0, 1, Color::YELLOW},
                         {1, 0, Color::YELLOW},
                         {2, 0, Color::YELLOW}};
};

void FigureLHook::RotateCounter() {
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

void FigureLHook::Rotate() {
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