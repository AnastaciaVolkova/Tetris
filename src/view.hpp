#ifndef _VIEW_HPP_
#define _VIEW_HPP_

#include "SDL.h"
#include <vector>

#include "point.hpp"
class Controller;

//! Provides graphical part of the game.
class View {
public:
  //! Constructor
  /*!
  \param [in] screen_height height of screen
  */
  View(const std::size_t screen_height);

  ~View();

  //! Provide the controller for interaction with it
  /*!
  \param [in,out] controller controller for interaction
  */
  void SetController(Controller *controller) { controller_ = controller; };

  //! Draw the points
  /*!
  \param [in] x points to draw
  */
  void Render(std::vector<Point> x);

  //! Getter for height of the game field
  /*!
  \return returns height of the game field
  */
  size_t GetHeight();

private:
  SDL_Window *sdl_window_;
  SDL_Renderer *sdl_renderer_;

  const std::size_t screen_width_;
  const std::size_t screen_height_;
  std::size_t cell_size_;
  Controller *controller_;
};

#endif
