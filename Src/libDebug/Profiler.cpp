#include "GameDB/Debug/Profiler.hpp"

namespace GDB
{
    Profiler* Profiler::Global()
    {
        static Profiler profiler;
        return &profiler;
    }

    void Profiler::PushSection(SectionEntry sectionEntry)
    {
        _sections.push_back(std::move(sectionEntry));
    }
}
