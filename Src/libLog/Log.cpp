#include "GameDB/Log/Log.hpp"

#include "GameDB/Container/StringStream.hpp"
#include "GameDB/Kernel/Kernel.hpp"

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

    std::optional<WeakPtr<LogSpool>> Log::GetSpool(const String& spool) const
    {
        const auto spoolsIt = _spools.find(spool);
        if (spoolsIt == _spools.end())
        {
            return std::nullopt;
        }

        return spoolsIt->second;
    }

    WeakPtr<LogSpool> Log::SetSpool(const String& spool, SharedPtr<LogSpool> logSpool)
    {
        _spools.emplace(spool, std::move(logSpool));
        return _spools[spool];
    }

    WeakPtr<LogSpool> Log::AddSpool(const String& spool)
    {
        return SetSpool(spool, std::make_shared<LogSpool>());
    }

    void Log::LogMessage(const String& spool, LogType logType, std::filesystem::path filePath,
                         std::size_t fileLine, String function, String message)
    {
        auto spoolsIt = _spools.find(spool);
        if (spoolsIt == _spools.end())
        {
            return;
        }

        // TODO: Abstract time point logic somewhere else.
        LogEntry::TimePoint timePoint = std::chrono::system_clock::now();
        std::time_t time = std::chrono::system_clock::to_time_t(timePoint);


        StringStream formattedMessage;
        formattedMessage << Kernel::ToTimeStr(time, "%FT%T");
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
