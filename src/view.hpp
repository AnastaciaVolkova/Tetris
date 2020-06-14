#ifndef _VIEW_HPP_
#define _VIEW_HPP_

#include "SDL.h"
#include "point.hpp"
#include <vector>
class Controller;

//! Provides graphical part of the game.
class View {
public:
  //! Constructor
  /*!
  \param [in] screen_width width of the screen
  \param [in] screen_height height of the screen
  \param [in] cell_size size of quadratic cell
  \param [in,out] controller controller for interaction
  */
  View(const std::size_t screen_width, const std::size_t screen_height,
       const std::size_t cell_size);

  ~View();

  //! Draw the points
  /*!
  \param [in] x points to draw
  \param [in] title window title
  */
  void Render(const std::vector<Point> &x, const std::string &title);

  //! Getter for height of the game field
  /*!
  \return returns height of the game field
  */
  size_t GetHeight();

private:
  SDL_Window *sdl_window_;
  SDL_Renderer *sdl_renderer_;

  const std::size_t game_field_width_;
  const std::size_t game_field_height_;
  const std::size_t border_width_;
  const std::size_t game_info_width_proportion_ = 2;
  const std::size_t info_field_width_;
  const std::size_t info_field_height_;
  const std::size_t cell_size_;
  const std::size_t window_width_;
  const std::size_t window_height_;
};

#endif
