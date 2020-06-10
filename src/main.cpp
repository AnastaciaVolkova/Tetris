#include "controller.hpp"
#include "model.hpp"
#include "view.hpp"

#include <iostream>

using namespace std;

int main() {
  constexpr size_t kFramesPerSecond{60};
  constexpr size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr size_t kScreenWidth{800};
  constexpr size_t kScreenHeight{kScreenWidth * 2};
  constexpr size_t kGridWidth{kScreenWidth / 10};
  constexpr size_t kGridHeight{kGridWidth};

  View view(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Model model;
  Controller controller(model, view);
  view.SetController(&controller);
  model.SetController(&controller);
  controller.Run(kMsPerFrame);
}
