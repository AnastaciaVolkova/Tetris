#ifndef _POINT_HPP_
#define _POINT_HPP_
#include <tuple>

//! Contains figure color
enum class Color {
  BLACK,
  BROWN,
  YELLOW,
  GREY,
  PINK,
  CRIMSON,
  LIME,        //#00FF00
  GREEN_YELLOW //#ADFF2F
};

//! Struct Point implements operations with points
struct Point {
  Color color; // Color of the point.
  int x, y;    // x,y coordinates.
  Point();
  //! Constructor
  /*!
  \param [in] xx x-coordinate
  \param [in] yy y-coordinate
  \param [in] cc Color
  */
  Point(int xx, int yy, Color color = Color::BLACK);
  Point &operator+=(const Point &ot);
  friend Point operator+(const Point &p1, const Point &p2);
  friend Point operator-(const Point &p1, const Point &p2);

  //! Get tuple of rgba
  std::tuple<int, int, int, int> GetRgba() const;
};
#endif