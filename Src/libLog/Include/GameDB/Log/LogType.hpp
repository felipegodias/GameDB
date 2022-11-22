#ifndef GDB_LIB_LOG_LOG_TYPE_HPP
#define GDB_LIB_LOG_LOG_TYPE_HPP

#include "GameDB/Container/String.hpp"

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

    /**
     * \brief 
     * \param logType 
     * \return 
     */
    const String& ToString(LogType logType);
}

#endif // !GDB_LIB_LOG_LOG_TYPE_HPP
