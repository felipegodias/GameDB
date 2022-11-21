#include "GameDB/Debug/ProfileScopeGuard.hpp"

namespace GDB
{
    ProfileScopeGuard::ProfileScopeGuard(std::string name, ProfileSectionGuard* section)
        : _section(section)
    {
        section->PushScope(std::move(name));
    }

    ProfileScopeGuard::~ProfileScopeGuard()
    {
        _section->PopScope();
    }
}
