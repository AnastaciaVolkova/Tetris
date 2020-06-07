#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_
#include "model.hpp"
#include "view.hpp"

class Controller {
public:
  Controller(Model &model, View &view) : model_(model), view_(view) {}
  void Run(size_t target_frame_duration);

private:
  Model &model_;
  View &view_;
};
#endif