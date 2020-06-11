#ifndef _MODEL_HPP_
#define _MODEL_HPP_
#include "SDL.h"
#include "figure.hpp"
#include <memory>
class Controller;

//! Class implements game model
class Model {
public:
  //! Constructor
  /*!
  \param [in,out] controller controller for manipulation
  */
  Model(Controller *controller);

  //! Receive points, which represent occupied by figure space
  /*!
  \return returns points of occupied space
  */
  std::vector<Point> GetOccupiedSpace();

  //! Update position of figure
  /*!
  \param [in] point new position
  */
  void UpdatePosition(Point &point);

  //! Get fall time (s)
  unsigned GetTimeFall();

private:
  Controller *controller_;
  std::unique_ptr<Figure> figure_;
  // Time, which needs figure to reach the bottom (s).
  unsigned time_fall_;
};
#endif
