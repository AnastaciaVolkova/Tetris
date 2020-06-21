#include "controller.hpp"
#include <cmath>

using std::make_unique;
using std::move;
using std::string;
using std::to_string;
using std::unique_ptr;
using std::vector;

Controller::Controller(size_t target_frame_duration, size_t screen_height, unique_ptr<Model> &&model)
    : target_frame_duration_(target_frame_duration), to_continue_(true)
{
  model_ = move(model);
  cell_size_ = static_cast<size_t>(
      round(static_cast<float>(screen_height) / model_->GetGameFieldHeight()));
  view_ = make_unique<View>(
      screen_height, cell_size_ * model_->GetGameFieldWidth(), cell_size_);
};

void Controller::Run()
{
  while (to_continue_)
  {
    size_t start = view_->GetTicks();
    Commands command = Input();
    Update(command);
    Render();
    if ((view_->GetTicks() - start) < target_frame_duration_)
      view_->Delay(target_frame_duration_ - (view_->GetTicks() - start));
  }
}

Commands Controller::Input()
{
  // Use this value to check if event was caught.
  size_t start_time = view_->GetTicks();
  Event event;
  while (view_->GetEvent(event) &&
         ((view_->GetTicks() - start_time) < target_frame_duration_))
  {
    switch (event)
    {
    case Event::kUp:
      return Commands::kRotate;
    case Event::kDown:
      return Commands::kRotate_ws;
    case Event::kLeft:
      return Commands::kLeft;
    case Event::kRight:
      return Commands::kRight;
    case Event::kSpace:
      return Commands::kDrop;
    case Event::kQ:
    case Event::kEscape:
    case Event::kQuit:
      return Commands::kExit;
    }
  }
  return Commands::kNone;
}

void Controller::Update(Commands command)
{
  if (command == Commands::kExit)
    to_continue_ = false;
  if (model_->IsGameOver())
    return;
  switch (command)
  {
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
  if (distance_y_ >= cell_size_)
  {
    model_->UpdatePosition({0, 1});
    distance_y_ = 0;
  }
}

void Controller::Render()
{
  vector<const vector<Point> *> space = model_->GetOccupiedSpace();
  vector<Point> s;
  for (auto vp : space)
    for (auto p : *vp)
      s.push_back(p);
  if (model_->IsGameOver())
    view_->Render(s, cell_size_, "Game Over");
  else
    view_->Render(s, cell_size_, string("Score: ") + to_string(model_->GetScore()));
};
