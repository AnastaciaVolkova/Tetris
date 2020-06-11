#include "view.hpp"
#include <iostream>
#include <string>

View::View(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height)
    : screen_width_(screen_width), screen_height_(screen_height),
      grid_width_(grid_width), grid_height_(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window_ =
      SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       screen_width, screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window_) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer_ = SDL_CreateRenderer(sdl_window_, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer_) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

void View::Render(std::vector<Point> x) {
  SDL_Rect block;
  block.w = grid_width_;
  block.h = grid_height_;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer_, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer_);

  // Render food
  SDL_SetRenderDrawColor(sdl_renderer_, 0xFF, 0xCC, 0x00, 0xFF);
  for (const auto &i : x) {
    block.x = i.x * block.w;
    block.y = i.y * block.h;
    SDL_RenderFillRect(sdl_renderer_, &block);
  }

  // Update Screen
  SDL_RenderPresent(sdl_renderer_);
};

View::~View() {
  SDL_DestroyWindow(sdl_window_);
  SDL_DestroyRenderer(sdl_renderer_);
  SDL_Quit();
}
