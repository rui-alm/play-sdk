#include "playdate/system/pd_system.h"
#include "controller/main_controller.h"
#include "model/keys.h"
#include "model/tick_event.h"
#include "pd_api.h"
#include "pd_api/pd_api_sys.h"
#include "system/graphics.h"
#include "system/playdate/pd_graphics.h"
#include <memory>
#include <tuple>

using namespace ksdk::playdate;

std::unique_ptr<pd_system> pd_system::system;
std::unique_ptr<main_controller> pd_system::main_controller;

unsigned int pd_system::last_timestamp = 0;

int pd_system::on_update(void* userdata)
{
    PlaydateAPI *pd = reinterpret_cast<PlaydateAPI*>(userdata);
    const unsigned int millis = pd->system->getCurrentTimeMilliseconds();
    const float delta_seconds = static_cast<float>(millis - last_timestamp) / 1000.0f;
    last_timestamp = millis;
    const tick_event tick_event(delta_seconds);
    const int ret = main_controller->on_tick(tick_event);
    return ret;
}

int pd_system::on_event(PlaydateAPI* pd, PDSystemEvent event, uint32_t arg)
{
    std::ignore = arg;
    // Initialization just creates our "game" object
    switch(event)
    {
    case kEventInit:
        system = std::make_unique<ksdk::playdate::pd_system>(*pd);
        main_controller = std::make_unique<class main_controller>(*system);

        system->pd.display->setRefreshRate(20);

        // and sets the tick function to be called on update to turn off the
        // typical 'Lua'-ness.
        system->pd.system->setUpdateCallback(on_update, pd);
        break;
    case kEventTerminate:
        system->pd.system->logToConsole("Tearing down...");
        // Destroy the global state to prevent memory leaks
        main_controller.reset();
        system.reset();
        break;
    case kEventKeyPressed:
        // main_controller->key_pressed(arg);
        break;
    default:
        break;
    }
    return 0;
}

pd_system::pd_system(PlaydateAPI& pd) : pd(pd), pd_graphics(*pd.graphics), pd_filesystem(*pd.file)
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

ksdk::file_system& pd_system::file_system()
{
    return pd_filesystem;
}

void pd_system::draw_fps(int x, int y)
{
    pd.system->drawFPS(x, y);
}

void pd_system::button_state(keys& down
                    , keys& pressed
                    , keys& released)
{
    // These are optimized to match PDButtons
    pd.system->getButtonState(reinterpret_cast<PDButtons*>(&down)
    , reinterpret_cast<PDButtons*>(&pressed)
    , reinterpret_cast<PDButtons*>(&released));
}

std::vector<ksdk::keys> pd_system::buttons_to_vector(PDButtons& buttons)
{
    std::vector<keys> vector;
    if (buttons & kButtonUp)
        vector.emplace_back(Up);
    if (buttons & kButtonDown)
        vector.emplace_back(Down);
    if (buttons & kButtonLeft)
        vector.emplace_back(Left);
    if (buttons & kButtonRight)
        vector.emplace_back(Right);
    if (buttons & kButtonA)
        vector.emplace_back(Enter);
    if (buttons & kButtonB)
        vector.emplace_back(Back);
    return vector;
}

unsigned int pd_system::get_current_time_milliseconds() const
{
    const unsigned int milliseconds = pd.system->getCurrentTimeMilliseconds();
    return milliseconds;
}
