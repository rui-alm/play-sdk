#pragma once

#include "event/actor_move_event.h"
#include "event/event.h"
#include "event/event_producer.h"
#include <controller/controller.h>
#include <listener/input_listener.h>

class wall_controller
    : public ksdk::controller
    , public ksdk::input_listener
    , public ksdk::event_producer
{
public:
    wall_controller(class wall& wall, std::queue<std::unique_ptr<ksdk::event>>& event_queue)
        : ksdk::event_producer(event_queue)
        , wall(wall)
    {
    }

    // tick_listener interface
    int on_tick(const ksdk::tick_event &tick_event) override
    {
        std::ignore = tick_event;
        if (input_controller)
        {
            if (input_controller->get_down_keys() & ksdk::keys::Right)
            {
                event_queue.emplace(std::make_unique<ksdk::actor_move_event>(wall, ksdk::keys::Right));
            }
        }
        return 0;
    }
private:
    class wall& wall;
};
