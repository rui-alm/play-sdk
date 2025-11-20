#include "controller/main_controller.h"

#include <memory>

#include "controller/game_controller.h"
#include "controller/input_controller.h"
#include "model/main_model.h"
#include "model/main_state.h"
#include "system/system.h"

main_controller::main_controller(ksdk::system &system)
  : system(system)
    , input_controller(system), main_model(input_controller)
    , main_view_(system.graphics(), main_model) {}

int main_controller::on_tick(void *userdata) {
  input_controller.on_tick(userdata);
  const main_state state = main_model.get_state();
  switch (state) {
  case main_menu:
    main_model.on_tick(userdata);
    main_view_.on_tick(userdata);
    break;
  case load_game:
    if (!game_controller)
      game_controller = std::make_unique<class game_controller>(input_controller, system);
    main_model.set_state(run_game);
    break;
  case run_game:
    main_model.on_tick(userdata);
    game_controller->on_tick(userdata);
    break;
  }
  system.draw_fps(0, 0);
  return 1;
}

// int main_controller::key_pressed(uint32_t key)
// {
//   const int ret = main_view_.key_pressed(key);
//   return ret;
// }