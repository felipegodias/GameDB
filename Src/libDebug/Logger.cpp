#include "GameDB/Debug/Logger.hpp"

#include <sstream>

namespace GDB
{
    void Logger::LogMessage(const LogInfo& logInfo) const
    {
        std::stringstream ss;
        ss << logInfo.Message << '\n' << logInfo.Function << "\nat " << logInfo.FilePath.generic_string() << logInfo.FileLine;

        for (const auto& sink : _sinks)
        {
            sink->Dump(ss.str());
        }
    }

    void Logger::AddSink(std::unique_ptr<LoggerSink> sink)
    {
        _sinks.push_back(std::move(sink));
    }
}
