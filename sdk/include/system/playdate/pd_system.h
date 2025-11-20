#pragma once

#include <memory>

#include "pd_api.h"
#include "system/graphics.h"
#include "system/playdate/pd_graphics.h"
#include "system/system.h"
#include "system/playdate/pd_display.h"

class main_controller;

namespace ksdk
{
    namespace playdate
    {
        class pd_system : public ksdk::system
        {
        public:
            pd_system(PlaydateAPI& pd);
            virtual ~pd_system() = default;

            static int on_event(PlaydateAPI* pd, PDSystemEvent event, uint32_t arg);
            static int on_update(void* userdata);

            virtual system_display& display() override;
            virtual system_graphics& graphics() override;
            virtual void draw_fps(int x, int y) override;
        private:
            static std::unique_ptr<pd_system> system;
            static std::unique_ptr<class main_controller> main_controller;
            PlaydateAPI& pd;
            ksdk::playdate::display pd_display;
            ksdk::playdate::graphics pd_graphics;
        };
    };
};

