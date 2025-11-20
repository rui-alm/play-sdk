#include "playdate/system/pd_file_system.h"

std::vector<std::string>* ksdk::playdate::list_file_helper::file_list = nullptr;

ksdk::playdate::file_system::file_system(const playdate_file &pd_file) : pd_file(const_cast<playdate_file&>(pd_file))
{
}

int ksdk::playdate::file_system::list_files(const std::string& path, std::vector<std::string>& file_list) const
{
    const char* path_ptr = path.c_str();
    list_file_helper::file_list = &file_list;
    const int err = pd_file.listfiles(path_ptr, &list_file_helper::list_file_callback, nullptr, 1);
    if (err != 0)
    {
        // TODO: log error
    }
    list_file_helper::file_list = nullptr;
    return err;
}

void ksdk::playdate::list_file_helper::list_file_callback(const char* file_name, void* user_data)
{
    std::ignore = user_data;
    file_list->emplace_back(file_name);
}

// void list_file_callback(const char* file_name, void* user_data)
// {
//     ksdk::playdate::list_file_helper::list_file_callback(file_name, user_data);
// }
