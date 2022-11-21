#ifndef GDB_LIB_DEBUG_LOG_SINK_HPP
#define GDB_LIB_DEBUG_LOG_SINK_HPP

#include "LogEntry.hpp"

namespace GDB
{
    /**
     * \brief 
     */
    class LogSink
    {
    public:
        virtual ~LogSink() = 0;

        /**
         * \brief 
         * \param logEntry 
         * \param formattedMessage 
         */
        virtual void Dump(const LogEntry& logEntry) = 0;
    };
}

#endif // !GDB_LIB_DEBUG_LOG_SINK_HPP
