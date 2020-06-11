#ifndef _FIGURE_HPP_
#define _FIGURE_HPP_
#include "point.hpp"
#include <map>
#include <vector>

//! Contains rotation positions
enum class State { k0, k90, k180, k270 };

//! Class Figure represents the game figure
class Figure {
public:
  //! Default constructor
  Figure();

  //! Constructor
  /*!
  \param [in] p point initial position of figure
  */
  Figure(Point &&p);

  //! Get form of the figure
  /*!
  \return vector with point of figure form
  */
  std::vector<Point> GetForm();

  //! Get current position of figure
  const Point &GetPosition() const;

  //! Set current position of figure
  /*!
  \param [in] p position of figure
  */
  void SetPosition(Point &&p);

  //! Rotate counter clock-wise
  void RotateCounter();

  //! Rotate clock-wise
  void Rotate();

private:
  // Store in map points of figure, depending on state.
  std::map<State, std::vector<Point>> forms_;

  Point position_; // Position of left top point.
  State state_;    // Rotation state of figure.
};
#endif
