#include "GameDB/Log/LogSink.hpp"

namespace GDB
{
    LogSink::~LogSink() = default;

    void LogSink::Dump([[maybe_unused]] const LogEntry& logEntry)
    {
    }
}
