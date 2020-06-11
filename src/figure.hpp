#ifndef _FIGURE_HPP_
#define _FIGURE_HPP_
#include "point.hpp"
#include <vector>

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
  const std::vector<Point> GetForm() const;

  //! Get current position of figure
  const Point &GetPosition() const;

  //! Set current position of figure
  /*!
  \param [in] p position of figure
  */
  void SetPosition(Point p);

private:
  // 2D vector describes the points of figure.
  std::vector<Point> form_;
  Point position_; // Position of left top point.
};
#endif
