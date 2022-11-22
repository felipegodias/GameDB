#include "GameDB/Log/Log.hpp"

#include <sstream>

namespace GDB
{
    Log* Log::Global()
    {
        static Log global;
        return &global;
    }

    const Log::SpoolsMap& Log::GetSpools() const
    {
        return _spools;
    }

    std::optional<std::weak_ptr<LogSpool>> Log::GetSpool(const std::string& spool) const
    {
        const auto spoolsIt = _spools.find(spool);
        if (spoolsIt == _spools.end())
        {
            return std::nullopt;
        }

        return spoolsIt->second;
    }

    std::weak_ptr<LogSpool> Log::SetSpool(const std::string& spool, std::shared_ptr<LogSpool> logSpool)
    {
        _spools.emplace(spool, std::move(logSpool));
        return _spools[spool];
    }

    std::weak_ptr<LogSpool> Log::AddSpool(const std::string& spool)
    {
        return SetSpool(spool, std::make_shared<LogSpool>());
    }

    void Log::LogMessage(const std::string& spool, LogType logType, std::filesystem::path filePath,
                         std::size_t fileLine, std::string function, std::string message)
    {
        auto spoolsIt = _spools.find(spool);
        if (spoolsIt == _spools.end())
        {
            return;
        }

        LogEntry::TimePoint timePoint = std::chrono::system_clock::now();
        std::time_t time = std::chrono::system_clock::to_time_t(timePoint);
        tm tm{};
        if (gmtime_s(&tm, &time) != 0)
        {
            return;
        }

        std::stringstream formattedMessage;
        formattedMessage << std::put_time(&tm, "%FT%T");
        formattedMessage << " [" << ToString(logType) << "]: ";
        formattedMessage << message << "\n";
        formattedMessage << function << " at " << filePath.generic_string() << ":" << fileLine;
        LogEntry logEntry = {
            logType,
            timePoint,
            std::move(filePath),
            fileLine,
            std::move(function),
            std::move(message),
            formattedMessage.str()
        };

        spoolsIt->second->LogEntry(logEntry);
    }
}
