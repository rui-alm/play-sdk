#pragma once

#include <source_location>
#include <sstream>
#include <string>

#include <playdate/system/pd_system.h>

namespace ksdk
{
    namespace playdate
    {
        class logger
        {
        public:
            template<typename... Args>
            static void log(const char* format, const std::source_location& source_location, Args... args)
            {
                const std::string log_line = get_log_line(format, source_location);
                ksdk::playdate::pd_system::system->log_to_console(log_line.c_str(), args...);
            }

            template<typename... Args>
            static void error(const char* format, const std::source_location& source_location, Args... args)
            {
                const std::string log_line = get_log_line(format, source_location);
                ksdk::playdate::pd_system::system->error(log_line.c_str(), args...);
            }
        private:
            static std::string get_log_line(const char* format, const std::source_location& source_location)
            {
                std::stringstream ss;
                const char* file_name = source_location.file_name();
                const auto line_number = source_location.line();
                const char* function_name = source_location.function_name();
                ss << file_name << ':' << line_number << ' ' << function_name << ": " << format;
                const std::string log_line = ss.str();
                return log_line;
            }
        };
    }
}

#ifndef ERR
#define ERR(message, ...) (ksdk::playdate::logger::error(message, std::source_location::current(), __VA_ARGS__))
#endif

#ifndef LOG
#define LOG(message, ...) (ksdk::playdate::logger::log(message, std::source_location::current(), __VA_ARGS__))
#endif
