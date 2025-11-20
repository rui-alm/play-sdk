#pragma once

#include "event/event.h"
#include "model/actor/actor.h"
#include "model/keys.h"

namespace ksdk
{
    class actor_move_event : public ksdk::event
    {
    public:
        actor_move_event(ksdk::actor& actor, const ksdk::keys direction)
            : actor(actor), direction(direction) {}

        virtual int on_tick(const ksdk::tick_event& tick_event) override
        {
            switch (direction)
            {
            case ksdk::keys::Right:
            {
                const float delta_seconds = tick_event.get_delta_seconds();
                const float speed_x = 10 * delta_seconds;
                const float current_x = actor.get_x();
                const float updated_x = current_x + speed_x;
                actor.set_x(updated_x);
            }
            default:
                break;
            }
            return 0;
        }
    protected:
        ksdk::actor& actor;
        const ksdk::keys direction;
    };
}
