#include "controller.hpp"
#include "model.hpp"
#include "view.hpp"

#include <iostream>

using namespace std;

int main() {
  constexpr size_t kFramesPerSecond{60};
  constexpr size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr size_t kScreenHeight{1600};

  Controller controller(kMsPerFrame, kScreenHeight);
  controller.Run();
}
