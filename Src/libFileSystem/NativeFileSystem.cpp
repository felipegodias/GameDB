#include "GameDB/FileSystem/NativeFileSystem.hpp"

#include "GameDB/FileSystem/NativeFile.hpp"

namespace GDB
{
    NativeFileSystem::NativeFileSystem(std::filesystem::path root)
        : _root(std::move(root))
    {
        if (!is_directory(_root))
        {
            create_directory(_root);
        }
    }

    UniquePtr<File> NativeFileSystem::GetFile(const std::filesystem::path& path)
    {
        const std::filesystem::path physicalPath = absolute(_root / path.relative_path());
        if (!is_regular_file(physicalPath))
        {
            return nullptr;
        }

        auto file = MakeUnique<NativeFile>(physicalPath);
        return file;
    }
}
