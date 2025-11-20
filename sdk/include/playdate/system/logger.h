#pragma once

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
            static void log(const char* format, const char* file, const size_t line_number, const char* function, Args... args)
            {
                const std::string log_line = get_log_line(format, file, line_number, function);
                ksdk::playdate::pd_system::system->log_to_console(log_line.c_str(), args...);
            }

            template<typename... Args>
            static void error(const char* format, const char* file, const size_t line_number, const char* function, Args... args)
            {
                const std::string log_line = get_log_line(format, file, line_number, function);
                ksdk::playdate::pd_system::system->error(log_line.c_str(), args...);
            }
        private:
            static std::string get_log_line(const char* format, const char* file, const size_t line_number, const char* function)
            {
                std::stringstream ss;
                ss << file << ':' << line_number << ' ' << function << ": " << format;
                const std::string log_line = ss.str();
                return log_line;
            }
        };
    }
}

#ifndef ERR
#define ERR(message, ...) (ksdk::playdate::logger::error(message, __FILE__, __LINE__, __func__, __VA_ARGS__))
#endif

#ifndef LOG
#define LOG(message, ...) (ksdk::playdate::logger::log(message, __FILE__, __LINE__, __func__, __VA_ARGS__))
#endif
