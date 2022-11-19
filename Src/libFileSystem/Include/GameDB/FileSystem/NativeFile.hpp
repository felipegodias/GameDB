#ifndef GDB_LIB_FILE_SYSTEM_NATIVE_FILE_HPP
#define GDB_LIB_FILE_SYSTEM_NATIVE_FILE_HPP

#include "File.hpp"

#include <filesystem>

namespace GDB
{
    class NativeFile final : public File
    {
    public:
        explicit NativeFile(std::filesystem::path path);

        UniquePtr<std::iostream> Open() override;

    private:
        std::filesystem::path _path;
    };
}

#endif // !GDB_LIB_FILE_SYSTEM_NATIVE_FILE_HPP
