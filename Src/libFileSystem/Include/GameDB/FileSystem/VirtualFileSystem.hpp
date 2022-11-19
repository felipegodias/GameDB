#ifndef GDB_LIB_FILE_SYSTEM_VIRTUAL_FILE_SYSTEM_HPP
#define GDB_LIB_FILE_SYSTEM_VIRTUAL_FILE_SYSTEM_HPP

#include "FileSystem.hpp"

#include "GameDB/Container/Map.hpp"

namespace GDB
{
    class VirtualFileSystem : public FileSystem
    {
    public:
        UniquePtr<File> GetFile(const std::filesystem::path& path) override;

        FileSystem* AddFileSystem(std::filesystem::path path, UniquePtr<FileSystem> fileSystem);

        template <typename Ty, typename ... ArgsTy>
        FileSystem* AddFileSystem(std::filesystem::path path, ArgsTy&& ... args)
        {
            return AddFileSystem(std::move(path), MakeUnique<Ty>(std::forward<ArgsTy>(args)...));
        }

    private:
        Map<std::filesystem::path, UniquePtr<FileSystem>> _fileSystems;
    };
}

#endif // !GDB_LIB_FILE_SYSTEM_VIRTUAL_FILE_SYSTEM_HPP
