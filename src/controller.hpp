#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_
#include "SDL.h"
#include "model.hpp"
#include "point.hpp"
#include "view.hpp"

//! Class contains user commands.
enum class Commands { kLeft, kRight, kRotate, kRotate_ws, kDrop, kNone, kExit };

//! Class takes over interacting between game and its graphical representation.
class Controller {
public:
  //! Constructor
  /*!
    \param [in,out] model reference to model of game
    \param [in,out] view reference to graphical representation of view
  */
  Controller(Model &model, View &view) : model_(model), view_(view) {}

  //! Game loop
  /*!
    \param [in] target_frame_duration duration of game loop (game frame)
  */
  void Run(size_t target_frame_duration);

private:
  Model &model_;
  View &view_;
  //! Get user command from keyboard.
  /*!
    \param [in] target_frame_duration duration of game loop (game frame)
    \return Key code
  */
  Commands Input(size_t target_frame_duration);

  //! Draw the figure
  /*!
    \param [in] space point to draw
  */
  Commands Render(std::vector<Point> space);
};
#endif
