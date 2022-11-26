#include "GameDB/Memory/NewAllocator.hpp"

#include <any>
#include <unordered_map>

#include "GameDB/Memory/GeneralAllocator.hpp"
#include "GameDB/Memory/StlContainerAllocator.hpp"

namespace
{
    using SizesMap = std::unordered_map<uintptr_t, size_t, std::hash<uintptr_t>, std::equal_to<>,
                                        GDB::StlContainerAllocator<
                                            std::pair<const uintptr_t, size_t>, GDB::GeneralAllocator>>;
    SizesMap* GetSizesMap()
    {
        static SizesMap* sizesMap = nullptr;
        if (sizesMap != nullptr)
        {
            return sizesMap;
        }

        // Manually heap allocating so we don't need to care about when the global is gonna be destructed.
        sizesMap = static_cast<SizesMap*>(std::malloc(sizeof(SizesMap)));
        new (sizesMap)SizesMap();
        return sizesMap;
    }
}

gsl::owner<void*> operator new(const size_t size) // NOLINT [readability-inconsistent-declaration-parameter-name]
{
    SizesMap* sizesMap = GetSizesMap();
    gsl::owner<void*> ptr = GDB::GeneralAllocator::Allocate(size);
    sizesMap->emplace(reinterpret_cast<uintptr_t>(ptr), size); // NOLINT [cppcoreguidelines-pro-type-reinterpret-cast]
    return ptr;
}

void operator delete(gsl::owner<void*> ptr) noexcept // NOLINT [readability-inconsistent-declaration-parameter-name]
{
    SizesMap* sizesMap = GetSizesMap();
    const auto sizesIt = sizesMap->find(reinterpret_cast<uintptr_t>(ptr)); // NOLINT [cppcoreguidelines-pro-type-reinterpret-cast]
    if (sizesIt == sizesMap->end())
    {
        // WTF!? Should not reach this point but life goes on...
        GDB::MallocAllocator::Deallocate(ptr, 0);
        return;
    }

    GDB::GeneralAllocator::Deallocate(ptr, sizesIt->second);
    sizesMap->erase(sizesIt);
}
