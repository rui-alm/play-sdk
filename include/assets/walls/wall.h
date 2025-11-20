#pragma once

#include "model/actor/actor.h"

class wall : public ksdk::actor
{
public:
    wall(int x, int y) : ksdk::actor(x, y) {}
    virtual ~wall() = default;
};