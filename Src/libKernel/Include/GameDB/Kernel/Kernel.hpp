#ifndef GDB_LIB_KERNEL_KERNEL_HPP
#define GDB_LIB_KERNEL_KERNEL_HPP

#include <filesystem>
#include <chrono>

#include "GameDB/Container/String.hpp"

namespace GDB
{
    class Kernel
    {
    public:
        static std::filesystem::path GetAppDataPath();

        static String ToTimeStr(std::time_t time, std::string_view fmt);
    };
}

#endif // !GDB_LIB_KERNEL_KERNEL_HPP
