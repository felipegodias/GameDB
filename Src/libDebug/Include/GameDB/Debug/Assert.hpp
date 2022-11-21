#ifndef GDB_LIB_DEBUG_ASSERT_HPP
#define GDB_LIB_DEBUG_ASSERT_HPP

#include <cstdlib>
#include <filesystem>
#include <string>

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
            std::string expression;
            std::filesystem::path filePath;
            std::size_t fileLine;
            std::string function;
            std::string message;
        };

        /**
         * \brief 
         * \param assertionInfo 
         */
        static void OnAssertionFailed(const AssertionInfo& assertionInfo);
    };
}

#ifndef NDEBUG
#define GDB_ASSERT(expression, message) \
if (static_cast<bool>((expression))) { \
    GDB::Assert::OnAssertionFailed({#expression, __FILE__, __LINE__, __FUNCSIG__, message}); \
    abort(); \
} void(0)
#else
#define GDB_ASSERT(expression, message) void(0)
#endif

#endif // !GDB_LIB_DEBUG_ASSERT_HPP
