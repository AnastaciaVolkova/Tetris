#ifndef _FIGURE_RHOOK_HPP_
#define _FIGURE_RHOOK_HPP_
#include "figure.hpp"
#include "point.hpp"
#include <map>
#include <vector>

//! Class FigureRHook represents the game figure Left Hook
class FigureRHook : public Figure {
public:
  //! Constructor
  /*!
  \param [in] p point initial position of figure
  */
  FigureRHook(Point &&p);

  //! Rotate counter clock-wise
  void RotateCounter() override;

  //! Rotate clock-wise
  void Rotate() override;
};
#endif
