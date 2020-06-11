#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_
#include "SDL.h"
#include "model.hpp"
#include "point.hpp"
#include "view.hpp"
#include <memory>

//! Class contains user commands.
enum class Commands { kLeft, kRight, kRotate, kRotate_ws, kDrop, kNone, kExit };

//! Class takes over interacting between game and its graphical representation.
class Controller {
public:
  //! Constructor
  /*!
    \param [in] target_frame_duration duration of game loop
    \param [in] screen_height height of the window
  */
  Controller(size_t target_frame_duration, size_t screen_height);

  //! Game loop
  void Run();

private:
  std::unique_ptr<Model> model_;
  std::unique_ptr<View> view_;
  size_t target_frame_duration_;
  const size_t proportion_ = 2;
  const size_t height_cells_number_ = 20;
  const size_t width_cells_number_ = height_cells_number_ / proportion_;
  const size_t cell_size_;

  // Distance, which the figure passes within several frames (pixels)
  size_t distance_x_, distance_y_;

  //! Get user command from keyboard.
  /*!
    \return Key code
  */
  Commands Input();

  //! Update game state
  /*!
  Update game state
  */
  void Update();

  //! Draw the figure
  /*!
    \param [in] space point to draw
  */
  Commands Render(std::vector<Point> space);
};
#endif
