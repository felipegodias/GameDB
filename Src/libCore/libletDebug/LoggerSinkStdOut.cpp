#include "GameDB/Debug/LoggerSinkStdOut.hpp"

#include <iostream>

namespace GDB
{
    void LoggerSinkStdOut::Dump(const std::string_view log)
    {
        std::cout << log << std::endl;
    }
}
