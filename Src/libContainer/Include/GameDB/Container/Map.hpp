#ifndef GDB_LIB_CONTAINER_MAP_HPP
#define GDB_LIB_CONTAINER_MAP_HPP

#include <map>

#include "GameDB/Memory/GeneralAllocator.hpp"
#include "GameDB/Memory/StlContainerAllocator.hpp"

namespace GDB
{
    template <typename KTy, typename Ty, typename AllocatorTy = GeneralAllocator>
    using Map = std::map<KTy, Ty, std::less<KTy>, StlContainerAllocator<std::pair<const KTy, Ty>, AllocatorTy>>;
}

#endif // !GDB_LIB_CONTAINER_MAP_HPP