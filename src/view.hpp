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
  \param [in] screen_width width of screen
  \param [in] screen_height height of screen
  \param [in] grid_width width of element to draw
  \param [in] grid_height height of element to draw
  */
  View(const std::size_t screen_width, const std::size_t screen_height,
       const std::size_t grid_width, const std::size_t grid_height);

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
  returns height of the game field
  */
  size_t GetHeight();

private:
  SDL_Window *sdl_window_;
  SDL_Renderer *sdl_renderer_;

  const std::size_t screen_width_;
  const std::size_t screen_height_;
  const std::size_t grid_width_;
  const std::size_t grid_height_;
  Controller *controller_;
};

#endif
