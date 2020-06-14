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
  size_t cell_size_;
  float speed_;                   // Speed of figure (s)
  const float k_max_speed_ = 0.5; // Maximum speed of dropping figure (s)
  // Distance, which the figure passes within several frames (pixels)
  size_t distance_y_;

  bool to_continue_;

  //! Get user command from keyboard.
  /*!
    \return Key code
  */
  Commands Input();

  //! Update game state
  /*!
  \param [in] command command from user
  */
  void Update(Commands command);

  //! Draw the figure
  /*!
    \param [in] space point to draw
  */
  Commands Render();
};
#endif
