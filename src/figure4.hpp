#ifndef _FIGURE4_HPP_
#define _FIGURE4_HPP_
#include "figure.hpp"
#include "point.hpp"
#include <map>
#include <memory>
#include <vector>

//! Class Figure4 represents the game figure with rotation 4 states
class Figure4 : public Figure {
private:
  //! Constructor
  /*!
  \param [in] p point initial position of the figure
  \param [in] c color of the figure
  */
  Figure4(Point &&p, Color c);

public:
  //! Rotate counter clock-wise
  void RotateCounter() override;

  //! Rotate clock-wise
  void Rotate() override;
  //! Makes left hook figure
  /*!
  \param [in] p point initial position of figure
  \return Figure4 object, which is initialized as left-hook figure
  */
  static std::unique_ptr<Figure4> make_lhook(Point &&p);
  //! Make right hook figure
  /*!
  \param [in] p point initial position of figure
  \return Figure4 object, which is initialized as right-hook figure
  */
  static std::unique_ptr<Figure4> make_rhook(Point &&p);

  //! Make T figure
  /*!
  \param [in] p point initial position of figure
  \return Figure4 object, which is initialized as T figure
  */
  static std::unique_ptr<Figure4> make_t(Point &&p);
};
#endif
