#include "GameDB/Profiler/ProfileScopeGuard.hpp"

namespace GDB
{
    ProfileScopeGuard::ProfileScopeGuard(String name, ProfileSectionGuard* section)
        : _section(section)
    {
        section->PushScope(std::move(name));
    }

    ProfileScopeGuard::~ProfileScopeGuard()
    {
        _section->PopScope();
    }
}
