#ifndef GDB_LIB_CONTAINER_SET_HPP
#define GDB_LIB_CONTAINER_SET_HPP

#include <set>

#include "GameDB/Memory/GeneralAllocator.hpp"
#include "GameDB/Memory/StlContainerAllocator.hpp"

namespace GDB
{
    template <typename Ty, typename AllocatorTy = GeneralAllocator>
    using Set = std::set<Ty, std::less<Ty>, StlContainerAllocator<Ty, AllocatorTy>>;
}

#endif // !GDB_LIB_CONTAINER_SET_HPP
