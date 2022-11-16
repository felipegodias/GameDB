#include "GameDB/Format/Format.hpp"

#include <fmt/format.h>

namespace GDB
{
    using StringMemoryBuffer = fmt::basic_memory_buffer<char, fmt::inline_buffer_size, String::allocator_type>;

    String FormatArgs(const String::allocator_type alloc, const std::string_view fmt, const fmt::format_args args)
    {
        auto buf = StringMemoryBuffer(alloc);
        fmt::vformat_to(std::back_inserter(buf), fmt, args);
        String result(buf.data(), buf.size(), alloc);
        return result;
    }
}
