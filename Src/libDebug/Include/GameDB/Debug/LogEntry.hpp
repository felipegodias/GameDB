#ifndef GDB_LIB_DEBUG_LOG_ENTRY_HPP
#define GDB_LIB_DEBUG_LOG_ENTRY_HPP

#include <filesystem>

#include "LogType.hpp"

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
        std::string function;
        std::string message;
        std::string formatterMessage;
    };
}

#endif // !GDB_LIB_DEBUG_LOG_ENTRY_HPP
