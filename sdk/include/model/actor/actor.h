#pragma once

#include <tuple>

#include "listener/tick_listener.h"

namespace ksdk {
    class actor : public tick_listener
    {
    public:
        actor(int x, int y) : x(x), y(y) {}
        actor(actor&) = delete;
        actor& operator=(const actor&) = delete;
        virtual ~actor() = default;
        virtual int on_tick(void *userdata) override
        {
            std::ignore = userdata;
            return 0;
        }
        int get_x() const { return x; }
        int get_y() const { return y; }
    protected:
        int x;
        int y;
    private:
    };
}