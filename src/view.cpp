#include "view.hpp"
#include <iostream>
#include <string>
#include <tuple>

using std::cerr;
using std::get;
using std::size_t;
using std::string;
using std::tuple;
using std::vector;

View::View(size_t screen_height, size_t screen_width, size_t cell_size)
    : game_field_height_(screen_height), game_field_width_(screen_width),
      cell_size_(cell_size), border_width_(cell_size),
      info_field_width_(screen_width / game_info_width_proportion_),
      info_field_height_(screen_height),
      window_width_(screen_width + cell_size +
                    screen_width / game_info_width_proportion_),
      window_height_(screen_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    cerr << "SDL could not initialize.\n";
    cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window_ =
      SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       window_width_, window_height_, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window_) {
    cerr << "Window could not be created.\n";
    cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer_ = SDL_CreateRenderer(sdl_window_, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer_) {
    cerr << "Renderer could not be created.\n";
    cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

void View::Render(const vector<Point> &x, const string &title) {
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

  // Draw game field
  field.w = game_field_width_;
  field.h = game_field_height_;
  field.x = 0;
  field.y = 0;
  SDL_SetRenderDrawColor(sdl_renderer_, 0x1e, 0x1e, 0x1e, 0xff);
  SDL_RenderFillRect(sdl_renderer_, &field);

  // Draw info field
  field.w = info_field_width_;
  field.h = info_field_height_;
  field.x = game_field_width_ + border_width_;
  field.y = 0;
  SDL_SetRenderDrawColor(sdl_renderer_, 0x1e, 0x1e, 0x1e, 0xff);
  SDL_RenderFillRect(sdl_renderer_, &field);

  // Render block
  for (const auto &i : x) {
    auto color = i.GetRgba();
    SDL_SetRenderDrawColor(sdl_renderer_, get<0>(color), get<1>(color),
                           get<2>(color), get<3>(color));
    block.x = i.x * block.w;
    block.y = i.y * block.h;
    SDL_RenderFillRect(sdl_renderer_, &block);
  }

  // Update Screen
  SDL_RenderPresent(sdl_renderer_);

  SDL_SetWindowTitle(sdl_window_, title.c_str());
};

View::~View() {
  SDL_DestroyWindow(sdl_window_);
  SDL_DestroyRenderer(sdl_renderer_);
  SDL_Quit();
}

size_t View::GetHeight() { return game_field_height_; }