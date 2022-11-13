#include "GameDB/Memory/NewAllocator.hpp"

#include <unordered_map>

#include "GameDB/Memory/GeneralAllocator.hpp"
#include "GameDB/Memory/StlContainerAllocator.hpp"

std::unordered_map<size_t, size_t, std::hash<size_t>, std::equal_to<>, GDB::StlContainerAllocator<std::pair<const size_t, size_t>, GDB::TrackedMallocAllocator>> sizes;

void* operator new(const size_t size)
{
    void* ptr = GDB::GeneralAllocator::Allocate(size);
    sizes[reinterpret_cast<size_t>(ptr)] = size;
    return ptr;
}

void operator delete(void* ptr) noexcept
{
    const auto sizesIt = sizes.find(reinterpret_cast<size_t>(ptr));
    if (sizesIt == sizes.end())
    {
        abort();
    }

    GDB::GeneralAllocator::Deallocate(ptr, sizesIt->second);
    sizes.erase(sizesIt);
}
