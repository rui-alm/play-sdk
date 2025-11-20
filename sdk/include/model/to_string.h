#pragma once

#include <string>

namespace ksdk
{
    template<typename T>
    static std::string to_string(const T& t)
    {
        return std::to_string(t);
    }
}
