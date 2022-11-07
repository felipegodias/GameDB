#ifndef PLUTO_GAME_DB_ASSERT_H
#define PLUTO_GAME_DB_ASSERT_H

#include <string_view>

namespace Pluto::GameDB
{
    class Assert
    {
    public:
        static void OnAssertionFailed(std::string_view expr, std::string_view file, int line, std::string_view function,
                                      std::string_view msg);
    };
}

#ifdef NDEBUG
#define GAME_DB_ASSERT(expr, msg) void(0)
#else // NDEBUG
#define GAME_DB_ASSERT(expr, msg) if (static_cast<bool>((expr))) { Pluto::GameDB::Assert::OnAssertionFailed(#expr, __FILE__, __LINE__, static_cast<const char*>(__FUNCTION__), (msg)); abort(); } void(0)
#endif // NDEBUG

#endif // ! PLUTO_GAME_DB_ASSERT_H
