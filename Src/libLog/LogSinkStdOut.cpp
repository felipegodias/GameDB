#include "GameDB/Log/LogSinkStdOut.hpp"

#include <iostream>

namespace GDB
{
    void LogSinkStdOut::Dump(const LogEntry& logEntry)
    {
        std::cout << logEntry.formatterMessage << std::endl;
    }
}
