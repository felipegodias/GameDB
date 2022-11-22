#ifndef GDB_LIB_PROFILER_PROFILER_HPP
#define GDB_LIB_PROFILER_PROFILER_HPP

#include <chrono>
#include <string>
#include <vector>

namespace GDB
{
    class Profiler
    {
    public:
        using TimePoint = std::chrono::time_point<std::chrono::system_clock>;

        struct ScopeEntry
        {
            ScopeEntry* parent;
            std::string name;
            TimePoint start;
            TimePoint end;
            std::vector<ScopeEntry> children;
        };

        struct SectionEntry
        {
            std::string name;
            TimePoint start;
            TimePoint end;
            std::vector<ScopeEntry> scopeEntries;
        };

        static Profiler* Global();

        void PushSection(SectionEntry sectionEntry);

    private:
        // TODO: Use a ring buffer.
        std::vector<SectionEntry> _sections;
    };
}

#endif // !GDB_LIB_PROFILER_PROFILER_HPP
