#include "controller.hpp"
#include "view_sdl.hpp"
#include "model.hpp"

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
  //cell_size_ * model_->GetGameFieldWidth(), screen_height, cell_size_
  unique_ptr<View> view = make_unique<ViewSDL>(
      kScreenHeight / (model->GetGameFieldHeight() / model->GetGameFieldWidth()),
      kScreenHeight,
      kScreenHeight / model->GetGameFieldHeight());
  Controller controller(kMsPerFrame, kScreenHeight, move(model), move(view));
  controller.Run();
}
