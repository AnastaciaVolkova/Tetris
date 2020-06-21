#include "view_qt.hpp"
#include <string>
#include <tuple>
#include <QString>

using std::cerr;
using std::get;
using std::make_unique;
using std::size_t;
using std::string;
using std::tuple;
using std::vector;

ViewQT::ViewQT(size_t screen_width, size_t screen_height, size_t cell_size) : View(screen_width, screen_height, cell_size), q_application_(argc_, argv_), window_()
{
  window_.resize(kWindowWidth_, kWindowHeight_);
  window_.show();
  window_.setWindowTitle(QString("Tetris"));
  window_.setFixedSize(window_.size());
  window_.installEventFilter(this);
  timer_.start();
  q_application_.exec();

  /*
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
  }*/
}

void ViewQT::Render(const vector<Point> &x, std::size_t cell_size, const string &message){
    /*
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

  SDL_SetWindowTitle(sdl_window_, message.c_str());*/
};

ViewQT::~ViewQT()
{ /*
  SDL_DestroyWindow(sdl_window_);
  SDL_DestroyRenderer(sdl_renderer_);
  SDL_Quit();*/
}

size_t ViewQT::GetHeight()
{
  return kWindowHeight_;
}

size_t ViewQT::GetTicks() { return timer_.elapsed(); };

int ViewQT::GetEvent(Event &event)
{
  if (key_events.size() == 0)
  {
    event = Event::kOther;
    return 0;
  }
  QKeyEvent q_event = key_events.top();
  key_events.pop();
  switch (q_event.key())
  {
  case Qt::Key_Left:
    event = Event::kLeft;
    break;
  case Qt::Key_Right:
    event = Event::kRight;
    break;
  case Qt::Key_Up:
    event = Event::kUp;
    break;
  case Qt::Key_Down:
    event = Event::kDown;
    break;
  case Qt::Key_Space:
    event = Event::kSpace;
    break;
  case Qt::Key_Escape:
  case Qt::Key_Q:
    event = Event::kQuit;
    break;
  default:
    event = Event::kOther;
    break;
  }
  return 1;
};

void ViewQT::Delay(unsigned delay_ms)
{
  QThread::msleep(delay_ms);
}

bool ViewQT::eventFilter(QObject *obj, QEvent *event)
{
  if (event->type() == QEvent::KeyPress)
  {
    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
    key_events.push(*keyEvent);
    return true;
  }
  else
  {
    return QObject::eventFilter(obj, event);
  }
};