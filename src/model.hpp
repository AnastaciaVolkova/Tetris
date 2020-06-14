#ifndef _MODEL_HPP_
#define _MODEL_HPP_
#include "SDL.h"
#include "figure.hpp"
#include "pile.hpp"
#include <memory>
#include <random>
class Controller;

//! Class implements game model
class Model {
public:
  //! Constructor
  /*!
  \param [in,out] controller controller for manipulation
  \param [in] right_boundary right boundary of the game field
  \param [in] bottom_boundary bottom boundry of the game field
  */
  Model(Controller *controller, int right_boundary, int bottom_boundary);

  //! Receive points, which represent occupied by figure space
  /*!
  \return returns points of occupied space
  */
  std::vector<const std::vector<Point> *> GetOccupiedSpace();

  //! Update position of figure
  /*!
  \param [in] point difference between new position and previous one
  */
  void UpdatePosition(Point &&point);

  //! Get fall time (s)
  unsigned GetTimeFall();

  //! Rotate counter clock-wise figure
  void RotateCounter();

  //! Rotate clock-wise figure
  void Rotate();

  //! Accelerate falling figure
  void Accelerate();

  //! Get player score
  /*!
  \return returns player score
  */
  unsigned GetScore();

  //! Check if game over
  /*!
  \return returns true if game over has happened, otherwise returns false
  */
  bool IsGameOver();

private:
  const int kFallTime = 10;
  const int kMinFallTime = 1;
  Controller *controller_;
  std::unique_ptr<Figure> figure_;
  std::unique_ptr<Figure> next_figure_;

  // Flag of game over.
  bool game_over_;

  // Random engine for figure generator.
  std::mt19937 random_engine_;
  // Distribution for figure generator.
  std::uniform_int_distribution<int> dist_;

  // Points to draw.
  std::vector<Point> space_;
  // Time, which needs figure to reach the bottom (s).
  unsigned time_fall_;
  const int right_boundary_, bottom_boundary_;

  // Flag is pile was touched
  bool was_touched_;

  // Pile of fallen figures
  Pile pile_;

  // Player score. Score is 2 power of deleted lines number multiplied by 10.
  unsigned score_;

  //! Check if figure is in boundaries of game field
  bool CheckBoundaries();

  // Update point to draw.
  void UpdateSpace();

  //! Get new figure
  void FigureGenerator();

  //! Compute score
  /*!
  \param [in] num_del_lines number of deleted lines
  */
  void ComputeScore(unsigned num_del_lines);
};
#endif
