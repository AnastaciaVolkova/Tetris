#include "controller.hpp"
#include "model.hpp"
#include "view.hpp"

#include <iostream>

using namespace std;

int main() {
  constexpr size_t kFramesPerSecond{60};
  constexpr size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr size_t kScreenWidth{640};
  constexpr size_t kScreenHeight{640};
  constexpr size_t kGridWidth{32};
  constexpr size_t kGridHeight{32};

  View view(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Model model;
  Controller controller(model, view);
  view.SetController(&controller);
  model.SetController(&controller);
  model.Run(kMsPerFrame);
}