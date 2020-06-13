#include "view.hpp"
#include <iostream>
#include <string>
#include <tuple>

using std::tuple;

View::View(const std::size_t screen_height, const std::size_t screen_width,
           const std::size_t cell_size, Controller *controller)
    : game_field_height_(screen_height), game_field_width_(screen_width),
      cell_size_(cell_size), controller_(controller), border_width_(cell_size),
      info_field_width_(screen_width / game_info_width_proportion_),
      info_field_height_(screen_height),
      window_width_(screen_width + cell_size +
                    screen_width / game_info_width_proportion_),
      window_height_(screen_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window_ =
      SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       window_width_, window_height_, SDL_WINDOW_SHOWN);

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

void View::Render(const std::vector<Point> &x) {
  SDL_Rect block;
  block.w = cell_size_;
  block.h = cell_size_;

  // Draw border
  SDL_Rect field;
  field.w = border_width_;
  field.h = game_field_height_;
  field.x = game_field_width_;
  field.y = 0;
  SDL_SetRenderDrawColor(sdl_renderer_, 0xff, 0xd7, 0, 0xff);
  SDL_RenderFillRect(sdl_renderer_, &field);

  // Draw field game
  field.w = game_field_width_;
  field.h = game_field_height_;
  field.x = 0;
  field.y = 0;
  SDL_SetRenderDrawColor(sdl_renderer_, 0x1e, 0x1e, 0x1e, 0xff);
  SDL_RenderFillRect(sdl_renderer_, &field);

  // Clear screen
  // SDL_SetRenderDrawColor(sdl_renderer_, 0x1E, 0x1E, 0x1E, 0xFF);
  // SDL_RenderClear(sdl_renderer_);

  // Render block
  for (const auto &i : x) {
    auto color = i.GetRgba();
    SDL_SetRenderDrawColor(sdl_renderer_, std::get<0>(color),
                           std::get<1>(color), std::get<2>(color),
                           std::get<3>(color));
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

size_t View::GetHeight() { return game_field_height_; }