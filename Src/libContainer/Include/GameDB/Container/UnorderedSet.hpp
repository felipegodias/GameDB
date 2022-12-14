#ifndef GDB_LIB_CONTAINER_UNORDERED_SET_HPP
#define GDB_LIB_CONTAINER_UNORDERED_SET_HPP

#include <unordered_set>

#include "GameDB/Memory/GeneralAllocator.hpp"
#include "GameDB/Memory/StlContainerAllocator.hpp"

namespace GDB
{
    template <typename KTy, typename AllocatorTy = GeneralAllocator>
    using UnorderedSet = std::unordered_set<KTy, std::hash<KTy>, std::equal_to<KTy>, StlContainerAllocator<KTy, AllocatorTy>>;
}

#endif // !GDB_LIB_CONTAINER_UNORDERED_SET_HPP
