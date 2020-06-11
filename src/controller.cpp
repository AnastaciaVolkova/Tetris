#include "controller.hpp"
#include "figure.hpp"
#include <iostream>

using namespace std;
void Controller::Run(size_t target_frame_duration) {
  Figure fig;
  bool to_continue = true;
  while (to_continue) {
    size_t start = SDL_GetTicks();
    Commands command = Input(target_frame_duration);
    switch (command) {
    case Commands::kLeft:
      cout << "left" << endl;
      break;
    case Commands::kRight:
      cout << "right" << endl;
      break;
    case Commands::kRotate:
      cout << "rotate" << endl;
      break;
    case Commands::kRotate_ws:
      cout << "rotate ws" << endl;
      break;
    case Commands::kDrop:
      cout << "drop" << endl;
      break;
    case Commands::kNone:
      cout << "None" << endl;
      break;
    default:
      to_continue = false;
    }
    view_.Render(model_.GetOccupiedSpace());
    if ((SDL_GetTicks() - start) < target_frame_duration)
      SDL_Delay(target_frame_duration - (SDL_GetTicks() - start));
  }
}

Commands Controller::Input(size_t target_frame_duration) {
  // Use this value to check if event was caught.
  size_t start_time = SDL_GetTicks();
  SDL_Event event;
  while (SDL_PollEvent(&event) &&
         ((SDL_GetTicks() - start_time) < target_frame_duration)) {
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
    Render(model_.GetOccupiedSpace());
  }
  return Commands::kNone;
}

Commands Controller::Render(std::vector<Point> space) { view_.Render(space); };