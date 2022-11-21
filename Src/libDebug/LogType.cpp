#include "GameDB/Debug/LogType.hpp"

#include <array>

namespace GDB
{
    const std::array<std::string, static_cast<size_t>(LogType::Critical) + 1> logTypeStr = {
        "Verbose",
        "Debug",
        "Info",
        "Warning",
        "Error",
        "Critical"
    };

    const std::string& ToString(LogType logType)
    {
        return logTypeStr[static_cast<size_t>(logType)];
    }
}
