#include "game.hpp"

#include <iostream>

using namespace std;

void Game::Run(size_t kMsPerFrame) {
  bool to_continue = true;
  while (to_continue) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        to_continue = false;
      } else if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
        case SDLK_UP:
          cout << "UP" << endl;
          break;
        case SDLK_DOWN:
          cout << "DOWN" << endl;
          break;

        case SDLK_LEFT:
          cout << "LEFT" << endl;
          break;

        case SDLK_RIGHT:
          cout << "RIGHT" << endl;
          break;
        }
      }
    }
  }
}