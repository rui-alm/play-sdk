#pragma once

#include "system/file_system.h"
#include <pd_api.h>

#include <string>
#include <vector>

// extern "C" void list_file_callback(const char* file_name, void* user_data);

namespace ksdk::playdate {
    class file_system : public ksdk::file_system
    {
    public:
        file_system(const playdate_file& pd_file);
        virtual ~file_system() = default;

        virtual int list_files(const std::string& path, std::vector<std::string>& file_list) const override;
    private:
        playdate_file& pd_file;
    };

    class list_file_helper
    {
    public:
        static void list_file_callback(const char* file_name, void* user_data);
        static std::vector<std::string>* file_list;
    };
}
