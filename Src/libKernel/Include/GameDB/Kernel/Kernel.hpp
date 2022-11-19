#ifndef GDB_LIB_KERNEL_KERNEL_HPP
#define GDB_LIB_KERNEL_KERNEL_HPP

#include <filesystem>

namespace GDB
{
    class Kernel
    {
    public:
        static std::filesystem::path GetAppDataPath();
    };
}

#endif // !GDB_LIB_KERNEL_KERNEL_HPP
