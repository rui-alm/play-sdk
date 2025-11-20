#pragma once

#include <memory>

#include "main_controller.h"
#include "pd_api.h"
#include "system/system.h"

class main_controller;

namespace ksdk
{
    namespace playdate
    {
        class pd_system : public ksdk::system
        {
        public:
            pd_system(PlaydateAPI& pd) : pd_(pd)
            {
            }
            virtual ~pd_system() = default;

            static int on_event(PlaydateAPI* pd, PDSystemEvent event, uint32_t arg);
            static int on_update(void* userdata);

            virtual system_display* display() override;
            virtual void drawFPS(int x, int y) override;
        private:
            static std::unique_ptr<pd_system> system;
            static std::unique_ptr<class main_controller> main_controller;
            PlaydateAPI& pd_;
        };
    };
};

