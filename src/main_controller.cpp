#include "main_controller.h"
#include "system/system.h"
#include <tuple>

main_controller::main_controller(ksdk::system& system) : system_(system)
{
}

int main_controller::on_tick(void *userdata)
{
    std::ignore = userdata;
    system_.drawFPS(0,0);
    return 1;
}