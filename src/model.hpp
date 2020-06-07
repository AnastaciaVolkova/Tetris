#ifndef _MODEL_HPP_
#define _MODEL_HPP_
#include "SDL.h"

class Model {
public:
  Model() = default;
  void Run(std::size_t kMsPerFrame);
};
#endif