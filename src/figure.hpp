#ifndef _FIGURE_HPP_
#define _FIGURE_HPP_
#include "point.hpp"
#include <map>
#include <vector>

//! Contains rotation positions
enum class State { k0, k90, k180, k270 };

//! Contains figure color
enum class Color { BROWN, YELLOW };

//! Class Figure represents the game figure
class Figure {
public:
  //! Constructor
  /*!
  \param [in] p point initial position of figure
  */
  Figure(Point &&p, Color color);

  //! Get form of the figure
  /*!
  \return vector with point of figure form
  */
  const std::vector<Point> &GetForm();

  //! Get current position of figure
  const Point &GetPosition();

  //! Set current position of figure
  /*!
  \param [in] p position of figure
  */
  void SetPosition(Point &&p);

  //! Rotate counter clock-wise
  virtual void RotateCounter() = 0;

  //! Rotate clock-wise
  virtual void Rotate() = 0;

protected:
  // Store in map points of figure, depending on state.
  std::map<State, std::vector<Point>> forms_;

  Point position_; // Position of left top point.
  State state_;    // Rotation state of figure.
  Color color_;    // Figure color.
};
#endif
