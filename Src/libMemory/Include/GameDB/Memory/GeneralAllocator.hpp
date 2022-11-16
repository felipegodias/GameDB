#ifndef GDB_LIB_MEMORY_GENERAL_ALLOCATOR_HPP
#define GDB_LIB_MEMORY_GENERAL_ALLOCATOR_HPP

#include "FreeListAllocator.hpp"
#include "MallocAllocator.hpp"
#include "ThresholdAllocator.hpp"
#include "TrackerAllocator.hpp"

namespace GDB
{
    using TrackedMallocAllocator = TrackedAllocator<MallocAllocator>;
    using Allocator2048 = ThresholdAllocator<2048, FreeListAllocator<2048, TrackedMallocAllocator>, TrackedMallocAllocator>;
    using Allocator1536 = ThresholdAllocator<1536, FreeListAllocator<1536, TrackedMallocAllocator>, Allocator2048>;
    using Allocator1024 = ThresholdAllocator<1024, FreeListAllocator<1024, TrackedMallocAllocator>, Allocator1536>;
    using Allocator768 = ThresholdAllocator<768, FreeListAllocator<768, TrackedMallocAllocator>, Allocator1024>;
    using Allocator512 = ThresholdAllocator<512, FreeListAllocator<512, TrackedMallocAllocator>, Allocator768>;
    using Allocator384 = ThresholdAllocator<384, FreeListAllocator<384, TrackedMallocAllocator>, Allocator512>;
    using Allocator256 = ThresholdAllocator<256, FreeListAllocator<256, TrackedMallocAllocator>, Allocator384>;
    using Allocator192= ThresholdAllocator<192, FreeListAllocator<192, TrackedMallocAllocator>, Allocator256>;
    using Allocator128 = ThresholdAllocator<128, FreeListAllocator<128, TrackedMallocAllocator>, Allocator192>;
    using Allocator96 = ThresholdAllocator<96, FreeListAllocator<96, TrackedMallocAllocator>, Allocator128>;
    using Allocator64 = ThresholdAllocator<64, FreeListAllocator<64, TrackedMallocAllocator>, Allocator96>;
    using Allocator48 = ThresholdAllocator<48, FreeListAllocator<48, TrackedMallocAllocator>, Allocator64>;
    using Allocator32 = ThresholdAllocator<32, FreeListAllocator<32, TrackedMallocAllocator>, Allocator48>;
    using Allocator24 = ThresholdAllocator<24, FreeListAllocator<24, TrackedMallocAllocator>, Allocator32>;
    using Allocator16 = ThresholdAllocator<16, FreeListAllocator<16, TrackedMallocAllocator>, Allocator24>;

    using GeneralAllocator = Allocator16;
}

#endif // !GDB_LIB_MEMORY_GENERAL_ALLOCATOR_HPP