#ifndef _FIGURE2_HPP_
#define _FIGURE2_HPP_
#include "figure.hpp"
#include "point.hpp"
#include <map>
#include <memory>
#include <vector>

//! Class Figure2 represents the game figure with rotation 2 states
class Figure2 : public Figure {
private:
  //! Constructor
  /*!
  \param [in] p point initial position of the figure
  \param [in] c color of the figure
  */
  Figure2(Point &&p, Color c);

public:
  //! Rotate counter clock-wise
  void RotateCounter() override;

  //! Rotate clock-wise
  void Rotate() override;

  //! Makes left-s figure
  /*!
  \param [in] p point initial position of figure
  \return returns Figure2 object, which is initialized as left-s figure
  */
  static std::unique_ptr<Figure2> make_ls(Point &&p);

  //! Make right-s figure
  /*!
  \param [in] p point initial position of figure
  \return returns Figure2 object, which is initialized as right-s figure
  */
  static std::unique_ptr<Figure2> make_rs(Point &&p);

  //! Make stick figure
  /*!
  \param [in] p point initial position of figure
  \return returns Figure2 object, which is initialized as stick figure
  */
  static std::unique_ptr<Figure2> make_stick(Point &&p);
};
#endif
