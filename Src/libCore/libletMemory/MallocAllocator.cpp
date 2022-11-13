#include "Include/GameDB/Memory/MallocAllocator.hpp"

#include <cstdlib>
#include <iostream>

namespace GDB
{
    void* MallocAllocator::Allocate(const size_t size)
    {
        void* ptr = std::malloc(size);
        std::cout << "Allocate: " << ptr << " Size: " << size << std::endl;
        return ptr;
    }

    void MallocAllocator::Deallocate(void* ptr, [[maybe_unused]] size_t size)
    {
        std::cout << "Deallocate: " << ptr << " Size: " << size << std::endl;
        std::free(ptr);
    }
}
