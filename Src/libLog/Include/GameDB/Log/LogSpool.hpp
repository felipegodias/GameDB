#ifndef GDB_LIB_LOG_LOG_SPOOL_HPP
#define GDB_LIB_LOG_LOG_SPOOL_HPP

#include <filesystem>
#include <optional>
#include <type_traits>

#include "LogSink.hpp"
#include "LogEntry.hpp"
#include "GameDB/Container/Vector.hpp"
#include "GameDB/Memory/Pointers.hpp"

namespace GDB
{
    /**
     * \brief 
     */
    class LogSpool
    {
    public:
        using LogSinks = Vector<SharedPtr<LogSink>>;

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
        std::optional<WeakPtr<Ty>> GetSink() const
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
        WeakPtr<LogSink> AddSink(SharedPtr<LogSink> sink);

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
        WeakPtr<Ty> AddSink(ArgsTy&& ... args)
        {
            auto sink = MakeShared<Ty>(std::forward<ArgsTy>(args)...);
            AddSink(sink);
            return sink;
        }


    private:
        LogSinks _sinks;
    };
}

#endif // !GDB_LIB_LOG_LOG_SPOOL_HPP
