#ifndef RENDERER_H
#define RENDERER_H

#include "SDL.h"
#include <vector>

class View {
public:
  View(const std::size_t screen_width, const std::size_t screen_height,
       const std::size_t grid_width, const std::size_t grid_height);
  ~View();

private:
  SDL_Window *sdl_window_;
  SDL_Renderer *sdl_renderer_;

  const std::size_t screen_width_;
  const std::size_t screen_height_;
  const std::size_t grid_width_;
  const std::size_t grid_height_;
};

#endif