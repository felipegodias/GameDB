#include "GameDB/Kernel/Kernel.hpp"

#include <shlobj_core.h>
#include <stdexcept>

namespace GDB
{
    std::filesystem::path Kernel::GetAppDataPath()
    {
        PWSTR path = nullptr;
        const HRESULT getKnownFolderPathResult = SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &path);
        if (FAILED(getKnownFolderPathResult))
        {
            throw std::runtime_error("");
        }

        std::filesystem::path appData(path);
        CoTaskMemFree(path);
        appData /= "GameDB";
        return appData;
    }
}
