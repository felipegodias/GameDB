#ifndef GDB_LIB_FILE_SYSTEM_FILE_SYSTEM_HPP
#define GDB_LIB_FILE_SYSTEM_FILE_SYSTEM_HPP

#include <filesystem>

#include "File.hpp"
#include "GameDB/Memory/Pointers.hpp"

namespace GDB
{
    class FileSystem
    {
    public:
        virtual ~FileSystem() = 0;
        virtual UniquePtr<File> GetFile(const std::filesystem::path& path) = 0;
    };
}

#endif // !GDB_LIB_FILE_SYSTEM_FILE_SYSTEM_HPP
