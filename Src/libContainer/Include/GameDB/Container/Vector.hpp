#ifndef GDB_LIB_CONTAINER_VECTOR_HPP
#define GDB_LIB_CONTAINER_VECTOR_HPP

#include <vector>

#include "GameDB/Memory/GeneralAllocator.hpp"
#include "GameDB/Memory/StlContainerAllocator.hpp"

namespace GDB
{
    template <typename Ty, typename Allocator = GeneralAllocator>
    using Vector = std::vector<Ty, StlContainerAllocator<Ty, Allocator>>;
}

#endif // !GDB_LIB_CONTAINER_VECTOR_HPP
