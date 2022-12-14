#include "GameDB/Log/LogSpool.hpp"

namespace GDB
{
    void LogSpool::LogEntry(const GDB::LogEntry& logEntry) const
    {
        for (const auto& sink : _sinks)
        {
            sink->Dump(logEntry);
        }
    }

    const LogSpool::LogSinks& LogSpool::GetSinks() const
    {
        return _sinks;
    }

    WeakPtr<LogSink> LogSpool::AddSink(SharedPtr<LogSink> sink)
    {
        _sinks.push_back(std::move(sink));
        return _sinks[_sinks.size() - 1];
    }
}
