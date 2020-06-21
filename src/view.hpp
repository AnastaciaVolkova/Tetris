#ifndef _VIEW_HPP_
#define _VIEW_HPP_

#include "point.hpp"
#include <vector>

enum class Event
{
  kUp,
  kDown,
  kLeft,
  kRight,
  kSpace,
  kQ,
  kEscape,
  kQuit,
  kOther
};

//! Abstract class, which defines interface for graphical representaton of game
class View
{
public:
  //! Constructor
  /*!
  \param [in] screen_width width of the screen
  \param [in] screen_height height of the screen
  \param [in] cell_size size of quadratic cell
  */
  View(std::size_t screen_width, std::size_t screen_height,
       std::size_t cell_size) : game_field_height_(screen_height), game_field_width_(screen_width),
                                info_field_width_(screen_width / kGameInfoWidthProportion_),
                                info_field_height_(screen_height),
                                kWindowWidth_(screen_width + cell_size +
                                              screen_width / kGameInfoWidthProportion_),
                                kWindowHeight_(screen_height){};

  //! Destructor
  virtual ~View(){};

  //! Draw the points
  /*!
  \param [in] x points to draw
  \param [in] title window title
  */
  virtual void Render(const std::vector<Point> &x, std::size_t cell_size, const std::string &title) = 0;

  //! Getter for height of the game field
  /*!
  \return returns height of the game field
  */
  virtual size_t GetHeight() = 0;

  //! Getter for ticks
  /*!
  \return returns value representing the number of milliseconds since the SDL library initialized
  */
  virtual size_t GetTicks() = 0;

  //! Get event
  /*!
  \param [out] polled event 
  \return returns 1 if there is a pending event or 0 if there are none available
  */
  virtual int GetEvent(Event &event) = 0;

  //! Wait a specified number of milliseconds before returning
  /*!
  \param [in] delay_ms - delay in milliseconds
  */
  virtual void Delay(unsigned delay_ms) = 0;

protected:
  const std::size_t game_field_width_;
  const std::size_t game_field_height_;
  const std::size_t kGameInfoWidthProportion_ = 2;
  const std::size_t info_field_width_;
  const std::size_t info_field_height_;
  const std::size_t kWindowWidth_;
  const std::size_t kWindowHeight_;
};

#endif
