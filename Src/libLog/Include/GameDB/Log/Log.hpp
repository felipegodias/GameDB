#ifndef GDB_LIB_LOG_LOG_HPP
#define GDB_LIB_LOG_LOG_HPP

#include <optional>

#include "LogSpool.hpp"
#include "GameDB/Container/Map.hpp"
#include "GameDB/Container/String.hpp"
#include "GameDB/Memory/Pointers.hpp"

namespace GDB
{
    /**
     * \brief 
     */
    class Log
    {
    public:
        using SpoolsMap = Map<String, SharedPtr<LogSpool>>;

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
        [[nodiscard]] std::optional<std::weak_ptr<LogSpool>> GetSpool(const String& spool) const;

        /**
         * \brief 
         * \param logSpool 
         * \param logSpool 
         */
        std::weak_ptr<LogSpool> SetSpool(const String& spool, SharedPtr<LogSpool> logSpool);

        /**
         * \brief 
         * \param spool 
         */
        std::weak_ptr<LogSpool> AddSpool(const String& spool);

        /**
         * \brief 
         * \param spool 
         * \param logType 
         * \param filePath 
         * \param fileLine 
         * \param function 
         * \param message 
         */
        void LogMessage(const String& spool, LogType logType, std::filesystem::path filePath, std::size_t fileLine,
                        String function, String message);

    private:
        SpoolsMap _spools;
    };
}

#define GDB_LOG(logType, spool, message) \
GDB::Log::Global()->LogMessage((spool), (logType), __FILE__, __LINE__, __FUNCSIG__, (message));

#define GDB_LOG_VERBOSE(spool, message) GDB_LOG(GDB::LogType::Verbose, spool, message)
#define GDB_LOG_DEBUG(spool, message) GDB_LOG(GDB::LogType::Debug, spool, message)

#endif // !GDB_LIB_LOG_LOG_HPP