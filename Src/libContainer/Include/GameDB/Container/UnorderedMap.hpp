#ifndef GDB_LIB_CONTAINER_UNORDERED_MAP_HPP
#define GDB_LIB_CONTAINER_UNORDERED_MAP_HPP

#include <unordered_map>

#include "GameDB/Memory/GeneralAllocator.hpp"
#include "GameDB/Memory/StlContainerAllocator.hpp"

namespace GDB
{
    template <typename KTy, typename Ty, typename AllocatorTy = GeneralAllocator>
    using UnorderedMap = std::unordered_map<KTy, Ty, std::hash<KTy>, std::equal_to<KTy>, StlContainerAllocator<
                                                std::pair<const KTy, Ty>, AllocatorTy>>;
}

#endif // !GDB_LIB_CONTAINER_UNORDERED_MAP_HPP
