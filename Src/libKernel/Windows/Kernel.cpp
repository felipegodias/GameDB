#include "GameDB/Kernel/Kernel.hpp"

#include <shlobj_core.h>
#include <stdexcept>

#include "GameDB/Container/StringStream.hpp"

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

    String Kernel::ToTimeStr(const std::time_t time, const std::string_view fmt)
    {
        tm tmBlock = {};
        if (localtime_s(&tmBlock, &time) != 0)
        {
            throw std::runtime_error("");
        }

        StringStream stringstream;
        stringstream << std::put_time(&tmBlock, fmt.data());
        return stringstream.str();
    }
}
