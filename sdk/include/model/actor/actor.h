#pragma once

#include <tuple>

#include "listener/tick_listener.h"
#include "model/tick_event.h"

namespace ksdk {
    class actor : public tick_listener
    {
    public:
        actor() : actor(0, 0) {}
        actor(int x, int y) : id(id_counter++), x(x), y(y) {}
        virtual ~actor() = default;
        virtual int on_tick(const tick_event& tick_event) override
        {
            std::ignore = tick_event;
            return 0;
        }
        int get_id() const { return id; }
        int get_x() const { return x; }
        int get_y() const { return y; }
    private:
        static int id_counter;
        const int id;
    protected:
        int x;
        int y;
    };
}