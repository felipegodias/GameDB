#ifndef GDB_LIB_DEBUG_ASSERT_HPP
#define GDB_LIB_DEBUG_ASSERT_HPP

#include <cstdlib>
#include <filesystem>

#include "GameDB/Container/String.hpp"

namespace GDB
{
    /**
     * \brief 
     */
    class Assert
    {
    public:
        /**
         * \brief 
         */
        struct AssertionInfo
        {
            String expression;
            std::filesystem::path filePath;
            std::size_t fileLine;
            String function;
            String message;
        };

        /**
         * \brief 
         * \param assertionInfo 
         */
        static void OnAssertionFailed(const AssertionInfo& assertionInfo);
    };
}

#ifndef NDEBUG
#if defined(__clang__)
#define GDB_ASSERT_FUNCSIG __PRETTY_FUNCTION__
#elif defined(__GNUC__) || defined(__GNUG__)
#define GDB_ASSERT_FUNCSIG __PRETTY_FUNCTION__
#elif defined(_MSC_VER)
#define GDB_ASSERT_FUNCSIG __FUNCSIG__
#endif

#define GDB_ASSERT(expression, message) \
if (static_cast<bool>((expression))) { \
    GDB::Assert::OnAssertionFailed({#expression, __FILE__, __LINE__, GDB_ASSERT_FUNCSIG, message}); \
    abort(); \
} void(0)
#else
#define GDB_ASSERT(expression, message) void(0)
#endif

#endif // !GDB_LIB_DEBUG_ASSERT_HPP
