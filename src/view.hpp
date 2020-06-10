#ifndef _VIEW_HPP_
#define _VIEW_HPP_

#include "SDL.h"
#include <vector>

#include "point.hpp"
class Controller;

class View {
public:
  View(const std::size_t screen_width, const std::size_t screen_height,
       const std::size_t grid_width, const std::size_t grid_height);
  ~View();
  void SetController(Controller *controller) { controller_ = controller; };

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
