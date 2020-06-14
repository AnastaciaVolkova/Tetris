#ifndef _FIGURE1_HPP_
#define _FIGURE1_HPP_
#include "figure.hpp"
#include "point.hpp"
#include <map>
#include <memory>
#include <vector>

//! Class Figure1 represents the game figure with rotation 1 state
class Figure1 : public Figure {
private:
  //! Constructor
  /*!
  \param [in] p point initial position of the figure
  \param [in] c color of the figure
  */
  Figure1(Point &&p, Color c);

public:
  //! Rotate counter clock-wise
  void RotateCounter() override;

  //! Rotate clock-wise
  void Rotate() override;

  //! Makes left-s figure
  /*!
  \param [in] p point initial position of figure
  \return returns Figure1 object, which is initialized as square
  */
  static std::unique_ptr<Figure1> make_square(Point &&p);
};
#endif
