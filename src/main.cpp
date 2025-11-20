/**
 * Hello World CPP
 *
 * Reproduces the Hello World Example from the Playdate C SDK, but with C++
 * instead. A full game can be built from similar principles.
 *
 * MrBZapp 9/2023
 */
#include <memory>
#include <string>
#include <pd_api.h>
#include <pdcpp/pdnewlib.h>

#include "playdate/system/pd_system.h"

constexpr int TEXT_WIDTH = 86;
constexpr int TEXT_HEIGHT = 16;

/**
 * This Class contains the entire logic of the "game"
 */
class HelloWorld
{
public:
    explicit HelloWorld(PlaydateAPI* api)
        : pd(api)
        , fontpath("/System/Fonts/Asheville-Sans-14-Bold.pft")
        , x((400 - TEXT_WIDTH) / 2)
        , y((240 - TEXT_HEIGHT) / 2)
        , dx(1) , dy(2)
        , positive_delta(true)
        , offset(0)
    {
        const char* err;
        font = pd->graphics->loadFont(fontpath.c_str(), &err);

        if (font == nullptr)
            pd->system->error("%s:%i Couldn't load font %s: %s", __FILE__, __LINE__, fontpath.c_str(), err);
        const std::string sprite_path("sprites/one");
        bitmap = pd->graphics->loadBitmap(sprite_path.c_str(), &err);
        if (!bitmap)
            pd->system->error("Failed to load bitmap. Path: %s. Err: %s", sprite_path.c_str(), err);
    }

    ~HelloWorld()
    {
        if (bitmap)
            pd->graphics->freeBitmap(bitmap);
    }

    void update()
    {
        const std::string msg = "Hello Andjela! I love you!";
        pd->graphics->clear(kColorWhite);
        // pd->graphics->setFont(font);
        // pd->graphics->drawText(msg.c_str(), msg.size(), kASCIIEncoding, x, y);
        static float scale = 1.0f;
        static float increment = 0.1f;
        for (int columns = 0; columns < 1; columns+=32)
        {
            for (int rows = 0; rows < 1; rows+=32)
            {
                pd->graphics->drawScaledBitmap(bitmap, columns + offset, rows + offset, scale, scale);
            }
        }
        scale += increment;
        if (scale >= 4.0f || scale <= 0.0f) increment = -increment;
        offset++;
        offset %= 10;

        const float crank_angle_delta = pd->system->getCrankChange();
        if ((positive_delta && crank_angle_delta < 0 && crank_angle_delta > -180.0f)
            || (!positive_delta && crank_angle_delta > 0 && crank_angle_delta < 180.0f))
        {
            dx = -dx;
            dy = -dy;
            positive_delta = positive_delta ? false : true;
        }
        if (crank_angle_delta != 0)
        {
            x += dx;
            y += dy;
        }

        if ( x < 0 || x > LCD_COLUMNS - TEXT_WIDTH )
        {
            dx = -dx;
        }

        if ( y < 0 || y > LCD_ROWS - TEXT_HEIGHT )
        {
            dy = -dy;
        }

        pd->system->drawFPS(0,0);
    }

private:
    PlaydateAPI* pd;
    std::string fontpath;
    LCDFont* font;
    int x, y, dx, dy;
    bool positive_delta;
    LCDBitmap* bitmap;
    int offset;
};

/**
 * You can use STL containers! Be careful with some stdlib objects which rely
 * on an OS though, those will cause your app to crash on launch.
 */
std::unique_ptr<HelloWorld> helloWorld;

std::unique_ptr<ksdk::playdate::pd_system> pd_system;
/**
 * The Playdate API requires a C-style, or static function to be called as the
 * main update function. Here we use such a function to delegate execution to
 * our class.
 */
// static int gameTick(void* userdata)
// {
//     std::ignore = userdata;
//     helloWorld->update();
//     return 1;
// };


/**
 * the `eventHandler` function is the entry point for all Playdate applications
 * and Lua extensions. It requires C-style linkage (no name mangling) so we
 * must wrap the entire thing in this `extern "C" {` block
 */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * This is the main event handler. Using the `Init` and `Terminate` events, we
 * allocate and free the `HelloWorld` handler accordingly.
 *
 * You only need this `_WINDLL` block if you want to run this on a simulator on
 * a windows machine, but for the sake of broad compatibility, we'll leave it
 * here.
 */
#ifdef _WINDLL
__declspec(dllexport)
#endif
int eventHandler(PlaydateAPI* pd, PDSystemEvent event, uint32_t arg)
{
    /*
     * This is required, otherwise linker errors abound
     */
    eventHandler_pdnewlib(pd, event, arg);

    const int ret = ksdk::playdate::pd_system::on_event(pd, event, arg);

    // // Initialization just creates our "game" object
    // if (event == kEventInit)
    // {
    //     pd->display->setRefreshRate(20);
    //     helloWorld = std::make_unique<HelloWorld>(pd);

    //     // and sets the tick function to be called on update to turn off the
    //     // typical 'Lua'-ness.
    //     pd->system->setUpdateCallback(gameTick, pd);
    // }

    // // Destroy the global state to prevent memory leaks
    // if (event == kEventTerminate)
    // {
    //     pd->system->logToConsole("Tearing down...");
    //     helloWorld = nullptr;
    // }
    return ret;
}
#ifdef __cplusplus
}
#endif
