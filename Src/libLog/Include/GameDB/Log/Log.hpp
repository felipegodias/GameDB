#ifndef GDB_LIB_LOG_LOG_HPP
#define GDB_LIB_LOG_LOG_HPP

#include <memory>
#include <optional>
#include <string>
#include <map>

#include "LogSpool.hpp"

namespace GDB
{
    /**
     * \brief 
     */
    class Log
    {
    public:
        using SpoolsMap = std::map<std::string, std::shared_ptr<LogSpool>>;

        /**
         * \brief 
         * \return 
         */
        static Log* Global();

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] const SpoolsMap& GetSpools() const;

        /**
         * \brief 
         * \param spool 
         * \return 
         */
        [[nodiscard]] std::optional<std::weak_ptr<LogSpool>> GetSpool(const std::string& spool) const;

        /**
         * \brief 
         * \param logSpool 
         * \param logSpool 
         */
        std::weak_ptr<LogSpool> SetSpool(const std::string& spool, std::shared_ptr<LogSpool> logSpool);

        /**
         * \brief 
         * \param spool 
         */
        std::weak_ptr<LogSpool> AddSpool(const std::string& spool);

        /**
         * \brief 
         * \param spool 
         * \param logType 
         * \param filePath 
         * \param fileLine 
         * \param function 
         * \param message 
         */
        void LogMessage(const std::string& spool, LogType logType, std::filesystem::path filePath, std::size_t fileLine,
                        std::string function, std::string message);

    private:
        SpoolsMap _spools;
    };
}

#define GDB_LOG(logType, spool, message) \
GDB::Log::Global()->LogMessage((spool), (logType), __FILE__, __LINE__, __FUNCSIG__, (message));

#define GDB_LOG_VERBOSE(spool, message) GDB_LOG(GDB::LogType::Verbose, spool, message)
#define GDB_LOG_DEBUG(spool, message) GDB_LOG(GDB::LogType::Debug, spool, message)

#endif // !GDB_LIB_LOG_LOG_HPP
