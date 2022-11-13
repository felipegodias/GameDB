#ifndef GDB_LIBLET_FORMAT_FORMAT_HPP
#define GDB_LIBLET_FORMAT_FORMAT_HPP

#include <fmt/core.h>

#include "GameDB/Container/String.hpp"

namespace GDB
{
    [[nodiscard]] String FormatArgs(String::allocator_type alloc, std::string_view fmt, fmt::format_args args);

    template <typename ... ArgsTy>
    String Format(const std::string_view fmt, ArgsTy&& ... args)
    {
        return FormatArgs(String::allocator_type(), fmt, fmt::make_format_args(std::forward<ArgsTy>(args)...));
    }
}

#endif // !GDB_LIBLET_FORMAT_FORMAT_HPP
