#ifndef GDB_LIBLET_DEBUG_LOGGER_HPP
#define GDB_LIBLET_DEBUG_LOGGER_HPP

#include <filesystem>
#include <memory>
#include <string>
#include <vector>

#include "LoggerSink.hpp"

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
     */
    class Logger
    {
    public:
        /**
         * \brief 
         */
        struct LogInfo
        {
            LogType logType;
            std::filesystem::path FilePath;
            size_t FileLine;
            std::string Function;
            std::string Message;
        };

        /**
         * \brief 
         * \param logInfo 
         */
        void LogMessage(const LogInfo& logInfo) const;

        /**
         * \brief 
         * \param sink 
         */
        void AddSink(std::unique_ptr<LoggerSink> sink);

    private:
        std::vector<std::unique_ptr<LoggerSink>> _sinks;
    };
}

#endif // !GDB_LIBLET_DEBUG_LOGGER_HPP
