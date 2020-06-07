#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_
#include "SDL.h"
#include "model.hpp"
#include "view.hpp"

enum class Commands { kLeft, kRight, kRotate, kRotate_ws, kDrop, kNone, kExit };

class Controller {
public:
  Controller(Model &model, View &view) : model_(model), view_(view) {}
  void Run(size_t target_frame_duration);

private:
  Model &model_;
  View &view_;
  Commands Input(size_t target_frame_duration);
};
#endif