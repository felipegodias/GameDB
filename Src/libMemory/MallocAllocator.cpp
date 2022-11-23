#include "Include/GameDB/Memory/MallocAllocator.hpp"

#include <cstdlib>
#include <iostream>
#include <cassert>

namespace GDB
{
    gsl::owner<void*> MallocAllocator::Allocate(const size_t size)
    {
        //assert(size < 131072);
        const gsl::owner<void*> ptr = std::malloc(size); // NOLINT [cppcoreguidelines-no-malloc]
        return ptr;
    }

    void MallocAllocator::Deallocate(gsl::owner<void*> ptr, [[maybe_unused]] size_t size)
    {
        std::free(ptr); // NOLINT [cppcoreguidelines-no-malloc]
    }
}

