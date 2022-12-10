#ifndef GDB_LIB_LIB_EDITOR_LOGGER_SINK_CONSOLE_HPP
#define GDB_LIB_LIB_EDITOR_LOGGER_SINK_CONSOLE_HPP

#include <string>
#include <vector>

#include "GameDB/Log/LogSink.hpp"

namespace GDB
{
    /**
     * \brief 
     */
    class LoggerSinkConsole final : public LogSink
    {
    public:
        void Dump(const LogEntry& logEntry) override;

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] const std::vector<LogEntry>& GetLogEntries() const;

        /**
         * \brief 
         */
        void Clear();

    private:
        std::vector<LogEntry> _logEntries;
    };
}

#endif // !GDB_LIB_LIB_EDITOR_LOGGER_SINK_CONSOLE_HPP
