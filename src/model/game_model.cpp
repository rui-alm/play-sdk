#include "model/game_model.h"

game_model::game_model() : camera(100, 100)
{
}

int game_model::on_tick(void* userdata)
{
    for (auto& cell_x: actors_map)
    {
        for (auto& cell_y: cell_x)
        {
            for (auto& actor_entry: cell_y)
            {
                auto& actor = actor_entry.second;
                actor->on_tick(userdata);
            }
        }
    }
    return 0;
}