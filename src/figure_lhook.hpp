#ifndef _FIGURE_LHOOK_HPP_
#define _FIGURE_LHOOK_HPP_
#include "figure.hpp"
#include "point.hpp"
#include <map>
#include <vector>

//! Class FigureLHook represents the game figure Left Hook
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
