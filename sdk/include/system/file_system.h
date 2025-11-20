#pragma once

#include <string>
#include <vector>

namespace ksdk
{
    class file_system
    {
    public:
        virtual ~file_system() = default;
        virtual int list_files(const std::string& path, std::vector<std::string>& files) const = 0;
    };
}
