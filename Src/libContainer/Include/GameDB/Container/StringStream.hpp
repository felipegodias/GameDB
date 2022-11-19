#ifndef GDB_LIB_CONTAINER_STRING_STREAM_HPP
#define GDB_LIB_CONTAINER_STRING_STREAM_HPP

#include <sstream>

#include "GameDB/Memory/GeneralAllocator.hpp"
#include "GameDB/Memory/StlContainerAllocator.hpp"

namespace GDB
{
    using StringStream = std::basic_stringstream<
        char, std::char_traits<char>, StlContainerAllocator<char, GeneralAllocator>>;

    using WStringStream = std::basic_stringstream<
        wchar_t, std::char_traits<wchar_t>, StlContainerAllocator<wchar_t, GeneralAllocator>>;
}

#endif // !GDB_LIB_CONTAINER_STRING_STREAM_HPP
