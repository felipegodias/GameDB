#include "GameDB/Log/LogType.hpp"

#include <array>

namespace GDB
{
    const std::array<String, static_cast<size_t>(LogType::Critical) + 1> logTypeStr = {
        "Verbose",
        "Debug",
        "Info",
        "Warning",
        "Error",
        "Critical"
    };

    const String& ToString(LogType logType)
    {
        return logTypeStr[static_cast<size_t>(logType)];
    }
}
