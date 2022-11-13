#include "GameDB/Memory/NewAllocator.hpp"

#include <iostream>

#include "GameDB/Memory/GeneralAllocator.hpp"

void* operator new(const size_t size)
{
    const auto ptr = static_cast<size_t*>(GDB::GeneralAllocator::Allocate(size + sizeof(size_t)));
    *ptr = size;
    return ptr + 1;
}

void operator delete(void* ptr) noexcept
{
    const auto realPtr = static_cast<size_t*>(ptr) - 1;
    const size_t size = *realPtr;
    operator delete(realPtr, size);
}

void operator delete(void* ptr, const size_t size) noexcept
{
    GDB::GeneralAllocator::Deallocate(ptr, size);
}
