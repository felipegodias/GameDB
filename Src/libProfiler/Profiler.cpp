#include "GameDB/Profiler/Profiler.hpp"

namespace GDB
{
    Profiler* Profiler::Global()
    {
        static Profiler profiler;
        return &profiler;
    }

    void Profiler::PushSection(SectionEntry sectionEntry)
    {
        _sections.PushBack(std::move(sectionEntry));
    }
}
