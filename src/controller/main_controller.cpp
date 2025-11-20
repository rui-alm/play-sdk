#include "controller/main_controller.h"
#include "controller/input_controller.h"
#include "model/keys.h"
#include "model/main_model.h"
#include "model/main_state.h"
#include "system/system.h"
#include "view/main_view.h"
#include <cstdint>
#include <tuple>

main_controller::main_controller(ksdk::system &system)
  : system(system), state(main_state::main_menu),
    input_controller_(system), main_model_(input_controller_)
    , main_view_(system.graphics(), main_model_) {}

int main_controller::on_tick(void *userdata) {
  std::ignore = userdata;
  switch (state) {
  case main_menu:
    input_controller_.on_tick(userdata);
    main_model_.on_tick(userdata);
    main_view_.on_tick(userdata);
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