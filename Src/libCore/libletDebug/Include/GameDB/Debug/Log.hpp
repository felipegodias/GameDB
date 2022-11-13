#ifndef GDB_LIBLET_DEBUG_LOG_HPP
#define GDB_LIBLET_DEBUG_LOG_HPP

#include <memory>
#include <optional>
#include <string>
#include <unordered_map>

#include "Logger.hpp"

namespace GDB
{
    /**
     * \brief 
     */
    class Log
    {
    public:
        /**
         * \brief 
         * \return 
         */
        static Log* Global();

        /**
         * \brief 
         * \param spool 
         * \return 
         */
        [[nodiscard]] std::optional<Logger*> GetLogger(const std::string& spool) const;

        /**
         * \brief 
         * \param spool 
         * \param logger 
         */
        void SetLogger(const std::string& spool, std::unique_ptr<Logger> logger);

    private:
        std::unordered_map<std::string, std::unique_ptr<Logger>> _loggers;
    };
}

#define GDB_LOG(logType, spool, message) \
GDB::Log::Global()->GetLogger((spool)).value()->LogMessage({(logType), __FILE__, __LINE__, __FUNCSIG__, (message)})

#define GDB_LOG_VERBOSE(spool, message) GDB_LOG(GDB::LogType::Verbose, spool, message);
#define GDB_LOG_DEBUG(spool, message) GDB_LOG(GDB::LogType::Debug, spool, message);

#endif // !GDB_LIBLET_DEBUG_LOG_HPP
