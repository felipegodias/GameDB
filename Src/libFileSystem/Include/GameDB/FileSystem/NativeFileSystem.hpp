#ifndef GDB_LIB_FILE_SYSTEM_NATIVE_FILE_SYSTEM_HPP
#define GDB_LIB_FILE_SYSTEM_NATIVE_FILE_SYSTEM_HPP

#include "FileSystem.hpp"

namespace GDB
{
    /**
     * \brief 
     */
    class NativeFileSystem final : public FileSystem
    {
    public:
        explicit NativeFileSystem(std::filesystem::path root);

        /**
         * \brief 
         * \param path 
         * \return 
         */
        UniquePtr<File> GetFile(const std::filesystem::path& path) override;

    private:
        std::filesystem::path _root;
    };
}

#endif // !GDB_LIB_FILE_SYSTEM_NATIVE_FILE_SYSTEM_HPP
