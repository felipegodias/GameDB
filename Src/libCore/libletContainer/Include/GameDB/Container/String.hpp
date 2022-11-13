#ifndef GDB_LIBLET_CONTAINER_STRING_HPP
#define GDB_LIBLET_CONTAINER_STRING_HPP

#include <string>

#include "GameDB/Memory/GeneralAllocator.hpp"
#include "GameDB/Memory/StlContainerAllocator.hpp"

namespace GDB
{
    using String = std::basic_string<char, std::char_traits<char>, StlContainerAllocator<char, GeneralAllocator>>;
    using WString = std::basic_string<wchar_t, std::char_traits<wchar_t>, StlContainerAllocator<wchar_t, GeneralAllocator>>;
}

#endif // !GDB_LIBLET_CONTAINER_STRING_HPP
