#ifndef GDB_LIBLET_DEBUG_LOGGER_SINK_HPP
#define GDB_LIBLET_DEBUG_LOGGER_SINK_HPP

#include <string_view>

namespace GDB
{
    /**
     * \brief 
     */
    class LoggerSink
    {
    public:
        virtual ~LoggerSink() = 0;

        /**
         * \brief 
         * \param log 
         */
        virtual void Dump(std::string_view log) = 0;
    };
}

#endif // !GDB_LIBLET_DEBUG_LOGGER_SINK_HPP
