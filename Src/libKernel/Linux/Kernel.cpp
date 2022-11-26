#include "GameDB/Kernel/Kernel.hpp"

#include <mutex>
#include <pwd.h>
#include <unistd.h>

#include "GameDB/Container/StringStream.hpp"

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

    String Kernel::ToTimeStr(const std::time_t time, const std::string_view fmt)
    {
        static std::mutex toTimeStrMutex;
        std::lock_guard guard(toTimeStrMutex);
        StringStream stringstream;
        stringstream << std::put_time(std::localtime(&time), fmt.data());
        return stringstream.str();
    }
}
