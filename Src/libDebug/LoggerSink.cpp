#include "GameDB/Debug/LoggerSink.hpp"

namespace GDB
{
    LoggerSink::~LoggerSink() = default;

    void LoggerSink::Dump([[maybe_unused]] std::string_view log)
    {
    }
}
