#ifndef _BOTTOM_HPP_
#define _BOTTOM_HPP_
#include "figure.hpp"
#include "point.hpp"
#include <vector>
#include <memory>

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
  unsigned AddFigure(const Figure *figure);

  //! Get points of pile
  /*!
  \return returns points of pile
  */
  const std::vector<Point>* GetPile();

  //! Get information on pipe overload
  /*!
  \return returns true if pipe is overloaded, otherwise returns false
  */
  bool IsOverloaded();

private:
  // Indicates wheather point is occupied.
  std::vector<std::vector<bool>> pile_space_;

  // All points of pile.
  std::unique_ptr<std::vector<Point>> pile_points_space_;
  int max_y_;

  // Flag, which indicates, wheather pipe is overload.
  bool is_overloaded_;

  //! Search for line to clear and clear it
  /*!
  \return returns number of deleted lines
  */
  unsigned ClearLine();

  //! Compute points of pile
  void ComputePilePointsSpace();
};
#endif
