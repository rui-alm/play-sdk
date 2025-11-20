#pragma once

#include <memory>
#include <tuple>
#include <vector>

#include "model/actor/actor.h"
class game_model
{
public:
    game_model()
    {
    }
    std::vector<std::unique_ptr<ksdk::actor>>& get_actors() { return actors; }

    int on_tick(void* userdata)
    {
        std::ignore = userdata;
        return 0;
    }
private:
    std::vector<std::unique_ptr<ksdk::actor>> actors;
};