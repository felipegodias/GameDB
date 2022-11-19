#include "GameDB/FileSystem/VirtualFileSystem.hpp"

namespace GDB
{
    UniquePtr<File> VirtualFileSystem::GetFile([[maybe_unused]] const std::filesystem::path& path)
    {
        const std::filesystem::path root = "/";
        std::filesystem::path current;
        for (const auto folder : path)
        {
            current /= folder;
            auto fileSystemsIt = _fileSystems.find(current);
            if (fileSystemsIt != _fileSystems.end())
            {
                std::filesystem::path p = root / relative(path, current);
                UniquePtr<File> file = fileSystemsIt->second->GetFile(p);
                if (file != nullptr)
                {
                    return file;
                }
            }
        }
        return nullptr;
    }

    FileSystem* VirtualFileSystem::AddFileSystem(std::filesystem::path path,
                                                 UniquePtr<FileSystem> fileSystem)
    {
        FileSystem* fileSystemPtr = fileSystem.get();
        _fileSystems.emplace(std::move(path), std::move(fileSystem));
        return fileSystemPtr;
    }
}
