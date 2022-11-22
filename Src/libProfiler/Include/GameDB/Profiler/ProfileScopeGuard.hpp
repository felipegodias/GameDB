#ifndef GDB_LIB_PROFILER_PROFILE_SCOPE_GUARD_HPP
#define GDB_LIB_PROFILER_PROFILE_SCOPE_GUARD_HPP

#include "ProfileSectionGuard.hpp"
#include "GameDB/Container/String.hpp"

namespace GDB
{
    class ProfileScopeGuard
    {
    public:
        ProfileScopeGuard(String name, ProfileSectionGuard* section);

        ProfileScopeGuard(const ProfileScopeGuard& other) = delete;
        ProfileScopeGuard(ProfileScopeGuard&& other) noexcept = delete;
        ProfileScopeGuard& operator=(const ProfileScopeGuard& other) = delete;
        ProfileScopeGuard& operator=(ProfileScopeGuard&& other) noexcept = delete;

        ~ProfileScopeGuard();

    private:
        ProfileSectionGuard* _section;
    };
}

#define GDB_PROFILE_SCOPE_COMBINE1(X,Y) X##Y
#define GDB_PROFILE_SCOPE_COMBINE(X,Y) GDB_PROFILE_SCOPE_COMBINE1(X,Y)
#define GDB_PROFILE_SCOPE(name) ProfileScopeGuard GDB_PROFILE_SCOPE_COMBINE(profileScopeGuard, __LINE__) ((name), GDB::ProfileSectionGuard::GetCurrent() )
#define GDB_PROFILE_FUNCTION() GDB_PROFILE_SCOPE(__FUNCSIG__)

#endif // !GDB_LIB_PROFILER_PROFILE_SCOPE_GUARD_HPP
