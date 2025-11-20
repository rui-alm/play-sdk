#include "model/game_model.h"

game_model::game_model() : camera(0.0f, 0.0f)
{
}

int game_model::on_tick(const ksdk::tick_event& tick_event)
{
    for (auto& cell_x: actors_map)
    {
        for (auto& cell_y: cell_x)
        {
            for (auto& actor_entry: cell_y)
            {
                auto& actor = actor_entry.second;
                actor->on_tick(tick_event);
            }
        }
    }
    return 0;
}
