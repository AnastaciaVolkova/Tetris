#ifndef _GAME_HPP_
#define _GAME_HPP_
#include "SDL.h"

class Game {
public:
  Game() = default;
  void Run(std::size_t kMsPerFrame);
};
#endif