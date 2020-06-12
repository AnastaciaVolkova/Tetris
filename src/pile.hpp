#ifndef _BOTTOM_HPP_
#define _BOTTOM_HPP_
#include "figure.hpp"
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
  \param [in] figure figure to check if touches pile
  \return returns true if figure touches bottom
  */
  bool IsTouched(const Figure *figure);

  //! Add figure to pile
  /*!
  \param [in] space points of figure
  \return returns number of deleted lines
  */
  int AddFigure(const Figure *figure);

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