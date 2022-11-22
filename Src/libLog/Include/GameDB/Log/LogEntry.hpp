#ifndef GDB_LIB_LOG_LOG_ENTRY_HPP
#define GDB_LIB_LOG_LOG_ENTRY_HPP

#include <filesystem>

#include "LogType.hpp"
#include "GameDB/Container/String.hpp"

namespace GDB
{
    /**
     * \brief
     */
    struct LogEntry
    {
        using TimePoint = std::chrono::time_point<std::chrono::system_clock>;
        LogType logType;
        TimePoint timePoint;
        std::filesystem::path filePath;
        std::size_t fileLine;
        String function;
        String message;
        String formatterMessage;
    };
}

#endif // !GDB_LIB_LOG_LOG_ENTRY_HPP
