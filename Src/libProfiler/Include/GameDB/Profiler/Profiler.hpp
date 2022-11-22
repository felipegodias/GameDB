#ifndef GDB_LIB_PROFILER_PROFILER_HPP
#define GDB_LIB_PROFILER_PROFILER_HPP

#include <chrono>

#include "GameDB/Container/String.hpp"
#include "GameDB/Container/Vector.hpp"

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
        // TODO: Use a ring buffer.
        Vector<SectionEntry> _sections;
    };
}

#endif // !GDB_LIB_PROFILER_PROFILER_HPP
