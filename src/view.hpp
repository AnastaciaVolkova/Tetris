#ifndef _VIEW_HPP_
#define _VIEW_HPP_

#include "SDL.h"
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

//! Provides graphical part of the game.
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
       std::size_t cell_size);

  ~View();

  //! Draw the points
  /*!
  \param [in] x points to draw
  \param [in] title window title
  */
  void Render(const std::vector<Point> &x, std::size_t cell_size, const std::string &title);

  //! Getter for height of the game field
  /*!
  \return returns height of the game field
  */
  size_t GetHeight();

  //! Getter for ticks
  /*!
  \return returns value representing the number of milliseconds since the SDL library initialized
  */
  size_t GetTicks();

  //! Get event
  /*!
  \param [out] polled event 
  \return returns 1 if there is a pending event or 0 if there are none available
  */
  int GetEvent(Event &event);

  //! Wait a specified number of milliseconds before returning
  /*!
  \param [in] delay_ms - delay in milliseconds
  */
  void Delay(unsigned delay_ms);

private:
  SDL_Window *sdl_window_;
  SDL_Renderer *sdl_renderer_;

  const std::size_t game_field_width_;
  const std::size_t game_field_height_;
  const std::size_t kGameInfoWidthProportion_ = 2;
  const std::size_t info_field_width_;
  const std::size_t info_field_height_;
  const std::size_t kWindowWidth_;
  const std::size_t kWindowHeight_;
};

#endif
