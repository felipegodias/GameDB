#include "GameDB/FileSystem/NativeFile.hpp"

#include <fstream>

namespace GDB
{
    NativeFile::NativeFile(std::filesystem::path path)
        : _path(std::move(path))
    {
    }

    UniquePtr<std::iostream> NativeFile::Open()
    {
        auto fileStream = MakeUnique<std::fstream>(_path);
        return fileStream;
    }
}
 