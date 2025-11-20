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

int main_controller::on_tick(const ksdk::tick_event& tick_event) {
  input_controller.on_tick(tick_event);
  const main_state state = main_model.get_state();
  switch (state) {
  case main_menu:
    main_model.on_tick(tick_event);
    main_view_.on_tick(tick_event);
    break;
  case load_game:
    if (!game_controller)
      game_controller = std::make_unique<class game_controller>(input_controller, system);
    main_model.set_state(run_game);
    break;
  case run_game:
    main_model.on_tick(tick_event);
    game_controller->on_tick(tick_event);
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