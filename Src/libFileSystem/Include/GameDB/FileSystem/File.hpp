#ifndef GDB_LIB_FILE_SYSTEM_FILE_HPP
#define GDB_LIB_FILE_SYSTEM_FILE_HPP

#include <iostream>

#include "GameDB/Memory/Pointers.hpp"

namespace GDB
{
    class File
    {
    public:
        virtual ~File() = 0;
        virtual UniquePtr<std::iostream> Open() = 0;
    };
}

#endif // !GDB_LIB_FILE_SYSTEM_FILE_HPP
