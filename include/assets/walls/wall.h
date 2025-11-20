#pragma once

#include "model/actor/actor.h"

class wall : public ksdk::actor
{
public:
    wall(float x, float y)
        : ksdk::actor(x, y) {}
    virtual ~wall() = default;
};
