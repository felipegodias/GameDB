#include "GameDB/Debug/Log.hpp"

namespace GDB
{
    Log* Log::Global()
    {
        static Log global;
        return &global;
    }

    std::optional<Logger*> Log::GetLogger(const std::string& spool) const
    {
        const auto loggersIt = _loggers.find(spool);
        if (loggersIt == _loggers.end())
        {
            return std::nullopt;
        }

        return loggersIt->second.get();
    }

    void Log::SetLogger(const std::string& spool, std::unique_ptr<Logger> logger)
    {
        _loggers[spool] = std::move(logger);
    }
}
