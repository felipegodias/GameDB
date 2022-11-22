#ifndef GDB_LIB_PROFILER_PROFILE_SECTION_GUARD_HPP
#define GDB_LIB_PROFILER_PROFILE_SECTION_GUARD_HPP

#include <string>

#include "Profiler.hpp"

namespace GDB
{
    class ProfileSectionGuard
    {
    public:
        explicit ProfileSectionGuard(std::string name, Profiler* profiler);

        ProfileSectionGuard(const ProfileSectionGuard& other) = delete;
        ProfileSectionGuard(ProfileSectionGuard&& other) noexcept = delete;
        ProfileSectionGuard& operator=(const ProfileSectionGuard& other) = delete;
        ProfileSectionGuard& operator=(ProfileSectionGuard&& other) noexcept = delete;

        ~ProfileSectionGuard();

        static ProfileSectionGuard* GetCurrent();

        void PushScope(std::string name);
        void PopScope();

    private:
        Profiler* _profiler;
        Profiler::ScopeEntry* _currentScopeEntry;
        Profiler::SectionEntry _sectionEntry;
    };
}

#define GDB_PROFILE_SECTION_COMBINE1(X,Y) X##Y
#define GDB_PROFILE_SECTION_COMBINE(X,Y) GDB_PROFILE_SECTION_COMBINE(X,Y)
#define GDB_PROFILE_SECTION(name) ProfileSectionGuard GDB_PROFILE_SCOPE_COMBINE(profileSectionGuard, __LINE__) ((name), GDB::Profiler::Global() )

#endif // !GDB_LIB_PROFILER_PROFILE_SECTION_GUARD_HPP
