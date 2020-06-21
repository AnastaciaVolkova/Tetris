#ifndef _VIEW_SDL_HPP_
#define _VIEW_SDL_HPP_

#include "view.hpp"
#include "SDL.h"
#include "point.hpp"
#include <vector>

//! Provides graphical part of the game.
class ViewSDL : public View
{
public:
  //! Constructor
  /*!
  \param [in] screen_width width of the screen
  \param [in] screen_height height of the screen
  \param [in] cell_size size of quadratic cell
  */
  ViewSDL(std::size_t screen_width, std::size_t screen_height,
          std::size_t cell_size);

  // Destructor
  ~ViewSDL() override;

  //! Draw the points
  /*!
  \param [in] x points to draw
  \param [in] message message for player
  */
  void Render(const std::vector<Point> &x, std::size_t cell_size, const std::string &message) override;

  //! Getter for height of the game field
  /*!
  \return returns height of the game field
  */
  size_t GetHeight() override;

  //! Getter for ticks
  /*!
  \return returns value representing the number of milliseconds since the SDL library initialized
  */
  size_t GetTicks() override;

  //! Get event
  /*!
  \param [out] polled event 
  \return returns 1 if there is a pending event or 0 if there are none available
  */
  int GetEvent(Event &event) override;

  //! Wait a specified number of milliseconds before returning
  /*!
  \param [in] delay_ms - delay in milliseconds
  */
  void Delay(unsigned delay_ms) override;

private:
  SDL_Window *sdl_window_;
  SDL_Renderer *sdl_renderer_;
};

#endif
