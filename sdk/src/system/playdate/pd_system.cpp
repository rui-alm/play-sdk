#include "system/playdate/pd_system.h"
#include "controllers/main_controller.h"
#include "pd_api.h"
#include "system/graphics.h"
#include "system/playdate/pd_graphics.h"
#include <memory>

using namespace ksdk::playdate;

std::unique_ptr<pd_system> pd_system::system;
std::unique_ptr<main_controller> pd_system::main_controller;

int pd_system::on_update(void* userdata)
{
    const int ret = main_controller->on_tick(userdata);
    return ret;
}

int pd_system::on_event(PlaydateAPI* pd, PDSystemEvent event, uint32_t arg)
{
    std::ignore = arg;
    // Initialization just creates our "game" object
    if (event == kEventInit)
    {
        system = std::make_unique<ksdk::playdate::pd_system>(*pd);
        main_controller = std::make_unique<class main_controller>(*system);

        system->pd.display->setRefreshRate(20);
        // helloWorld = std::make_unique<HelloWorld>(pd);

        // and sets the tick function to be called on update to turn off the
        // typical 'Lua'-ness.
        system->pd.system->setUpdateCallback(on_update, pd);
    }

    // Destroy the global state to prevent memory leaks
    if (event == kEventTerminate)
    {
        system->pd.system->logToConsole("Tearing down...");
        main_controller.reset();
        system.reset();
    }
    return 0;
}

pd_system::pd_system(PlaydateAPI& pd) : pd(pd), pd_graphics(*pd.graphics)
{
}

ksdk::system_display& pd_system::display()
{
    return pd_display;
}

ksdk::system_graphics& pd_system::graphics()
{
    return pd_graphics;
}

void pd_system::draw_fps(int x, int y)
{
    pd.system->drawFPS(x, y);
}