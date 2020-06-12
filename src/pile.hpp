#ifndef _BOTTOM_HPP_
#define _BOTTOM_HPP_
#include "point.hpp"
#include <vector>
//! Class implements bottom of the game field
class Pile {
public:
  //! Default constructor
  /*!
  \param [in] width width of game field
  \param [in] height height of game field
  */
  Pile(int width, int height);

  //! Checks if figure touches bottom
  /*!
  \param [in] space points of figure
  \return returns true if figure touches bottom
  */
  bool IsTouched(const std::vector<Point> &space);

  //! Add figure to pile
  /*!
  \param [in] space points of figure
  \return returns number of deleted lines
  */
  int AddFigure(const std::vector<Point> &space);

  //! Get points of pile
  /*!
  \return returns points of pile
  */
  std::vector<Point> GetPile();

private:
  std::vector<std::vector<bool>> pile_space_;
  int max_y_;
};
#endif