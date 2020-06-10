#ifndef _MODEL_HPP_
#define _MODEL_HPP_
#include "SDL.h"
#include "figure.hpp"
#include <memory>
class Controller;

class Model {
public:
  Model();
  void SetController(Controller *controller);
  std::vector<Point> GetOccupiedSpace();
  void UpdatePosition(Point &point);

private:
  Controller *controller_;
  std::unique_ptr<Figure> figure_;
};
#endif
