#include "model/ui/tree_menu.h"

ksdk::tree_menu::tree_menu(const std::string& root) : root(root)
{
}

ksdk::tree_menu::tree_menu(const std::string& root, const std::vector<ksdk::tree_menu>& entries)
    : root(root)
    , entries(entries)
{
}
