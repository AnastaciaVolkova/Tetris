#ifndef _FIGURE_SQUARE_HPP_
#define _FIGURE_SQUARE_HPP_
#include "figure.hpp"
#include "point.hpp"
#include <map>
#include <vector>

//! Class FigureHook represents the game figure
class FigureLHook : public Figure {
public:
  //! Constructor
  /*!
  \param [in] p point initial position of figure
  */
  FigureLHook(Point &&p);

  //! Rotate counter clock-wise
  void RotateCounter() override;

  //! Rotate clock-wise
  void Rotate() override;
};
#endif
