#ifndef GDB_LIB_PROFILER_PROFILER_HPP
#define GDB_LIB_PROFILER_PROFILER_HPP

#include <chrono>

#include "GameDB/Container/String.hpp"
#include "GameDB/Container/Vector.hpp"
#include "GameDB/Container/RingBuffer.hpp"

namespace GDB
{
    class Profiler
    {
    public:
        using TimePoint = std::chrono::time_point<std::chrono::system_clock>;

        struct ScopeEntry
        {
            ScopeEntry* parent;
            String name;
            TimePoint start;
            TimePoint end;
            Vector<ScopeEntry> children;
        };

        struct SectionEntry
        {
            String name;
            TimePoint start;
            TimePoint end;
            Vector<ScopeEntry> scopeEntries;
        };

        static Profiler* Global();

        void PushSection(SectionEntry sectionEntry);

    private:
        // 3600 = 60 frames per second multiplied by 60 seconds.
        // So we keep track from the last minute.
        RingBuffer<SectionEntry, 3600> _sections;
    };
}

#endif // !GDB_LIB_PROFILER_PROFILER_HPP
