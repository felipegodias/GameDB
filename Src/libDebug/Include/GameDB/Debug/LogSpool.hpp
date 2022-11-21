#ifndef GDB_LIB_DEBUG_LOG_SPOOL_HPP
#define GDB_LIB_DEBUG_LOG_SPOOL_HPP

#include <filesystem>
#include <memory>
#include <optional>
#include <type_traits>
#include <vector>

#include "LogSink.hpp"
#include "LogEntry.hpp"

namespace GDB
{
    /**
     * \brief 
     */
    class LogSpool
    {
    public:
        using LogSinks = std::vector<std::shared_ptr<LogSink>>;

        /**
         * \brief 
         * \param logEntry 
         */
        void LogEntry(const LogEntry& logEntry) const;

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] const LogSinks& GetSinks() const;

        /**
         * \brief 
         * \tparam Ty 
         * \return 
         */
        template <typename Ty, std::enable_if_t<std::is_base_of_v<LogSink, Ty>, bool>  = true>
        std::optional<std::weak_ptr<Ty>> GetSink() const
        {
            for (const auto& loggerSink : _sinks)
            {
                std::shared_ptr<Ty> sink = std::dynamic_pointer_cast<Ty>(loggerSink);
                if (sink != nullptr)
                {
                    return sink;
                }
            }
            return std::nullopt;
        }

        /**
         * \brief 
         * \param sink 
         * \return 
         */
        std::weak_ptr<LogSink> AddSink(std::shared_ptr<LogSink> sink);

        /**
         * \brief 
         * \tparam Ty   
         * \tparam ArgsTy 
         * \param args 
         * \return 
         */
        template <typename Ty, typename ... ArgsTy,
                  std::enable_if_t<std::is_constructible_v<Ty, ArgsTy...>, bool>  = true,
                  std::enable_if_t<std::is_base_of_v<LogSink, Ty>, bool>  = true>
        std::weak_ptr<Ty> AddSink(ArgsTy&& ... args)
        {
            auto sink = std::make_shared<Ty>(std::forward<ArgsTy>(args)...);
            AddSink(sink);
            return sink;
        }


    private:
        LogSinks _sinks;
    };
}

#endif // !GDB_LIB_DEBUG_LOG_SPOOL_HPP
