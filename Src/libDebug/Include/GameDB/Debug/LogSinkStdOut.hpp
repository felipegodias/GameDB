#ifndef GDB_LIB_DEBUG_LOG_SINK_STD_OUT_HPP
#define GDB_LIB_DEBUG_LOG_SINK_STD_OUT_HPP

#include "LogSink.hpp"

namespace GDB
{
    /**
     * \brief 
     */
    class LogSinkStdOut final : public LogSink
    {
    public:
        void Dump(const LogEntry& logEntry) override;
    };
}

#endif // !GDB_LIB_DEBUG_LOG_SINK_STD_OUT_HPP
