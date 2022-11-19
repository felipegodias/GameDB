#include "GameDB/FileSystem/File.hpp"

namespace GDB
{
    File::~File() = default;

    UniquePtr<std::iostream> File::Open()
    {
        return nullptr;
    }
}
