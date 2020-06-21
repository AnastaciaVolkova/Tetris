#include "controller.hpp"

#include <memory>

using std::move;
using std::unique_ptr;

int main()
{
  constexpr size_t kFramesPerSecond{60};
  constexpr size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr size_t kScreenHeight{1600};

  unique_ptr<Model> model;
  Controller controller(kMsPerFrame, kScreenHeight, move(model));
  controller.Run();
}
