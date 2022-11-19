#include "GameDB/Kernel/Kernel.hpp"

namespace GDB
{
    std::filesystem::path Kernel::GetAppDataPath()
    {
        std::filesystem::path appData = absolute("~/.GameDB");
        return appData;
    }
}
