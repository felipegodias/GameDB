#ifndef GDB_LIB_DEBUG_LOG_TYPE_HPP
#define GDB_LIB_DEBUG_LOG_TYPE_HPP
#include <string>

namespace GDB
{
    /**
     * \brief
     */
    enum class LogType
    {
        Verbose = 0,
        Debug = 1,
        Info = 2,
        Warning = 3,
        Error = 4,
        Critical = 5
    };

    const std::string& ToString(LogType logType);
}

#endif // !GDB_LIB_DEBUG_LOG_TYPE_HPP
