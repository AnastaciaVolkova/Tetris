#ifndef _MODEL_HPP_
#define _MODEL_HPP_
#include "SDL.h"

class Controller;

class Model {
public:
  Model() = default;
  void Run(std::size_t kMsPerFrame);
  void SetController(Controller *controller) { controller_ = controller; };

private:
  Controller *controller_;
};
#endif