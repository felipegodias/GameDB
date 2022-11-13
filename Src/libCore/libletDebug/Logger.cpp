#include "GameDB/Debug/Logger.hpp"

#include <iostream>
#include <fmt/format.h>

namespace GDB
{
    void Logger::LogMessage(const LogInfo& logInfo) const
    {
        std::cout << "LogMessage {" << std::endl;
        const std::string logMessage = fmt::format("{0}\n{1}\nat {2}:{3}", logInfo.Message, logInfo.Function,
                                                   logInfo.FilePath.generic_string(), logInfo.FileLine);

        for (const auto& sink : _sinks)
        {
            sink->Dump(logMessage);
        }
        std::cout << "}" << std::endl;
    }

    void Logger::AddSink(std::unique_ptr<LoggerSink> sink)
    {
        _sinks.push_back(std::move(sink));
    }
}
