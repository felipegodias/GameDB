#include "GameDB/LogEditor/LoggerSinkConsole.hpp"

namespace GDB
{
    void LoggerSinkConsole::Dump(const LogEntry& logEntry)
    {
        _logEntries.push_back(logEntry);
    }

    const std::vector<LogEntry>& LoggerSinkConsole::GetLogEntries() const
    {
        return _logEntries;
    }

    void LoggerSinkConsole::Clear()
    {
        _logEntries.clear();
    }
}
