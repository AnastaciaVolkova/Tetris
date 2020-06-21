#include "controller.hpp"

#include <memory>

using std::make_unique;
using std::move;
using std::unique_ptr;

int main()
{
  constexpr size_t kFramesPerSecond{60};
  constexpr size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr size_t kScreenHeight{1600};

  unique_ptr<Model> model = make_unique<Model>();
  Controller controller(kMsPerFrame, kScreenHeight, move(model));
  controller.Run();
}
