#include "GameDB/Kernel/Kernel.hpp"

namespace GDB
{
    std::filesystem::path Kernel::GetAppDataPath()
    {
        std::filesystem::path appData = std::filesystem::absolute("~/Library/GameDB");
        return appData;
    }
}
