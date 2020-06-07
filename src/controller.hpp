#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_
#include "model.hpp"
#include "view.hpp"

class Controller {
public:
  Controller(Model &model, View &view) : model_(model), view_(view) {}

private:
  Model &model_;
  View &view_;
};
#endif