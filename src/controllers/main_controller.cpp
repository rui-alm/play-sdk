#include "controllers/main_controller.h"
#include "model/main_state.h"
#include "system/system.h"
#include "views/main_view.h"
#include <tuple>

main_controller::main_controller(ksdk::system &system)
    : system(system), state(main_state::main_menu),
      main_view_(system.graphics()) {}

int main_controller::on_tick(void *userdata) {
  std::ignore = userdata;
  system.draw_fps(0, 0);
  switch (state) {
  case main_menu:
    main_view_.on_tick();
    break;
  }
  return 1;
}