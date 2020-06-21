#include "view_sdl.hpp"
#include <iostream>
#include <string>
#include <tuple>

using std::cerr;
using std::get;
using std::size_t;
using std::string;
using std::tuple;
using std::vector;

ViewSDL::ViewSDL(size_t screen_width, size_t screen_height, size_t cell_size) : View(screen_width, screen_height, cell_size)
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    cerr << "SDL could not initialize.\n";
    cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window_ =
      SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       kWindowWidth_, kWindowHeight_, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window_)
  {
    cerr << "Window could not be created.\n";
    cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer_ = SDL_CreateRenderer(sdl_window_, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer_)
  {
    cerr << "Renderer could not be created.\n";
    cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

void ViewSDL::Render(const vector<Point> &x, std::size_t cell_size, const string &message)
{
  SDL_Rect block;
  block.w = cell_size;
  block.h = cell_size;

  // Draw border
  SDL_Rect field;
  field.w = cell_size;
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
  field.x = game_field_width_ + cell_size;
  field.y = 0;
  SDL_SetRenderDrawColor(sdl_renderer_, 0x1e, 0x1e, 0x1e, 0xff);
  SDL_RenderFillRect(sdl_renderer_, &field);

  // Render block
  for (const auto &i : x)
  {
    auto color = i.GetRgba();
    SDL_SetRenderDrawColor(sdl_renderer_, get<0>(color), get<1>(color),
                           get<2>(color), get<3>(color));
    block.x = i.x * block.w;
    block.y = i.y * block.h;
    SDL_RenderFillRect(sdl_renderer_, &block);
  }

  // Update Screen
  SDL_RenderPresent(sdl_renderer_);

  SDL_SetWindowTitle(sdl_window_, message.c_str());
};

ViewSDL::~ViewSDL()
{
  SDL_DestroyWindow(sdl_window_);
  SDL_DestroyRenderer(sdl_renderer_);
  SDL_Quit();
}

size_t ViewSDL::GetHeight() { return game_field_height_; }

size_t ViewSDL::GetTicks() { return SDL_GetTicks(); };

int ViewSDL::GetEvent(Event &event)
{
  SDL_Event sdl_event;
  event = Event::kOther;
  int r = SDL_PollEvent(&sdl_event);
  if (sdl_event.type == SDL_QUIT)
    event = Event::kQuit;
  else if (sdl_event.type == SDL_KEYDOWN)
  {
    switch (sdl_event.key.keysym.sym)
    {
    case SDLK_UP:
      event = Event::kUp;
      break;
    case SDLK_DOWN:
      event = Event::kDown;
      break;
    case SDLK_LEFT:
      event = Event::kLeft;
      break;
    case SDLK_RIGHT:
      event = Event::kRight;
      break;
    case SDLK_SPACE:
      event = Event::kSpace;
      break;
    case SDLK_q:
    case SDLK_ESCAPE:
      event = Event::kEscape;
      break;
    default:
      event = Event::kOther;
      break;
    }
  }
  return r;
};

void ViewSDL::Delay(unsigned delay_ms)
{
  SDL_Delay(delay_ms);
}
