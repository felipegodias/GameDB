#ifndef GDB_LIB_CONTAINER_STRING_HPP
#define GDB_LIB_CONTAINER_STRING_HPP

#include <string>

#include "GameDB/Memory/GeneralAllocator.hpp"
#include "GameDB/Memory/StlContainerAllocator.hpp"

namespace GDB
{
    template <typename Ty>
    using BasicString = std::basic_string<Ty, std::char_traits<Ty>, StlContainerAllocator<Ty, GeneralAllocator>>;

    using String = BasicString<char>;
    using WString = BasicString<wchar_t>;
}

#endif // !GDB_LIB_CONTAINER_STRING_HPP
