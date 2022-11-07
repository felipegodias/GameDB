#include "GameDB/Debug/Assert.hpp"

#include <iostream>
#include <spdlog/spdlog.h>

namespace Pluto::GameDB
{
    void Assert::OnAssertionFailed(const std::string_view expr, const std::string_view file, const int line,
                                   const std::string_view function, const std::string_view msg)
    {
        std::cout << "Assertion hit! (" << expr << ") at function " << function << "\n" << msg << "\n" <<
            file << ":" << line << std::endl;
    }
}
