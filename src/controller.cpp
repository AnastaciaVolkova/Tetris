#include "controller.hpp"
#include <iostream>

using namespace std;

using std::make_unique;
using std::to_string;
using std::unique_ptr;
using std::vector;

Controller::Controller(size_t target_frame_duration, size_t screen_height)
    : target_frame_duration_(target_frame_duration),
      cell_size_(screen_height / height_cells_number_), to_continue_(true) {
  model_ = make_unique<Model>(this, width_cells_number_, height_cells_number_);
  view_ = make_unique<View>(screen_height, screen_height / proportion_,
                            cell_size_, this);
};

void Controller::Run() {
  while (to_continue_) {
    size_t start = SDL_GetTicks();
    Commands command = Input();
    Update(command);
    Render(model_->GetOccupiedSpace());
    if ((SDL_GetTicks() - start) < target_frame_duration_)
      SDL_Delay(target_frame_duration_ - (SDL_GetTicks() - start));
  }
}

Commands Controller::Input() {
  // Use this value to check if event was caught.
  size_t start_time = SDL_GetTicks();
  SDL_Event event;
  while (SDL_PollEvent(&event) &&
         ((SDL_GetTicks() - start_time) < target_frame_duration_)) {
    if (event.type == SDL_QUIT) {
      return Commands::kExit;
    } else if (event.type == SDL_KEYDOWN) {
      switch (event.key.keysym.sym) {
      case SDLK_UP:
        return Commands::kRotate;
      case SDLK_DOWN:
        return Commands::kRotate_ws;
      case SDLK_LEFT:
        return Commands::kLeft;
      case SDLK_RIGHT:
        return Commands::kRight;
      case SDLK_SPACE:
        return Commands::kDrop;
      case SDLK_q:
      case SDLK_ESCAPE:
        return Commands::kExit;
      }
    }
  }
  return Commands::kNone;
}

void Controller::Update(Commands command) {
  if (command == Commands::kExit)
    to_continue_ = false;
  if (model_->IsGameOver())
    return;
  switch (command) {
  case Commands::kRotate:
    model_->RotateCounter();
    break;
  case Commands::kRotate_ws:
    model_->Rotate();
    break;
  case Commands::kLeft:
    model_->UpdatePosition({-1, 0});
    break;
  case Commands::kRight:
    model_->UpdatePosition({1, 0});
    break;
  case Commands::kDrop:
    // Increase figure speed.
    model_->Accelerate();
    break;
  case Commands::kExit:
    to_continue_ = false;
    break;
  default:
    break;
  }

  // Set figure speed.
  float speed = float(view_->GetHeight()) / (model_->GetTimeFall() * 1000);
  distance_y_ += static_cast<size_t>(round(speed * target_frame_duration_));
  if (distance_y_ >= cell_size_) {
    model_->UpdatePosition({0, 1});
    distance_y_ = 0;
  }
}

Commands Controller::Render(const std::vector<Point> &space) {
  if (model_->IsGameOver())
    view_->Render(space, "Game Over");
  else
    view_->Render(space, string("Score: ") + to_string(model_->GetScore()));
};
