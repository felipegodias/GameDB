#include "GameDB/Kernel/Kernel.hpp"

#include <mutex>
#include <pwd.h>
#include <unistd.h>

namespace GDB
{
    std::filesystem::path Kernel::GetAppDataPath()
    {
        static std::mutex getAppDataPathMutex;
        std::lock_guard guard(getAppDataPathMutex);

        const char* homeDir = getenv("HOME");

        if (!homeDir)
        {
            if (const passwd* pwd = getpwuid(getuid()))
            {
                homeDir = pwd->pw_dir;
            }
            else
            {
                throw std::runtime_error("");
            }
        }

        std::filesystem::path appData = homeDir;
        appData /= "GameDB";
        return appData;
    }
}
