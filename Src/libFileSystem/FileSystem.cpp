#include "GameDB/FileSystem/FileSystem.hpp"

namespace GDB
{
    FileSystem::~FileSystem() = default;

    UniquePtr<File> FileSystem::GetFile([[maybe_unused]] const std::filesystem::path& path)
    {
        return nullptr;
    }
}
