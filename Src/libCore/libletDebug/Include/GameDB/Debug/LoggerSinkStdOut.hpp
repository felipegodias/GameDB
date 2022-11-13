#ifndef GDB_LIBLET_DEBUG_LOGGER_SINK_STD_OUT_HPP
#define GDB_LIBLET_DEBUG_LOGGER_SINK_STD_OUT_HPP

#include "LoggerSink.hpp"

namespace GDB
{
    /**
     * \brief 
     */
    class LoggerSinkStdOut : public LoggerSink
    {
    public:
        void Dump(std::string_view log) override;
    };
}

#endif // !GDB_LIBLET_DEBUG_LOGGER_SINK_STD_OUT_HPP
