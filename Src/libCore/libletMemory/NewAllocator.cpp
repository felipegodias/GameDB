#include "GameDB/Memory/NewAllocator.hpp"

#include <iostream>

#include "GameDB/Memory/GeneralAllocator.hpp"

void* operator new(const size_t size)
{
    void* ptr = GDB::GeneralAllocator::Allocate(size);
    return ptr;
}

void operator delete(void* ptr, const size_t size) noexcept
{
    GDB::GeneralAllocator::Deallocate(ptr, size);
}
