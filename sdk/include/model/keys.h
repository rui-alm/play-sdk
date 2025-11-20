#pragma once

namespace ksdk
{
    // These are optimized to match PDButtons
    typedef enum keys
    {
        None = 0,
        Left = (1 << 0),
        Right = (1 << 1),
        Up = (1 << 2),
        Down = (1 << 3),
        Back = (1 << 4),
        Enter = (1 << 5),
        Select = (1 << 6),
        Start = (1 << 7),
        Special = (1 << 8)
    } keys;
};
