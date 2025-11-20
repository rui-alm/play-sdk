#pragma once

#include <string>
#include <vector>

namespace ksdk
{
    class tree_menu
    {
    public:
        tree_menu(const std::string& root);
        tree_menu(const std::string& root, const std::vector<tree_menu>& entries);
    private:
        const std::string root;
        std::vector<tree_menu> entries;
    };
}
