#include "GameDB/Profiler/ProfileSectionGuard.hpp"

#include "GameDB/Debug/Assert.hpp"

namespace GDB
{
    ProfileSectionGuard* current = nullptr;

    ProfileSectionGuard::ProfileSectionGuard(std::string name, Profiler* profiler)
        : _profiler(profiler), _currentScopeEntry(nullptr), _sectionEntry({})
    {
        _sectionEntry.name = std::move(name);
        _sectionEntry.start = std::chrono::system_clock::now();
        current = this;
    }

    ProfileSectionGuard::~ProfileSectionGuard()
    {
        _sectionEntry.end = std::chrono::system_clock::now();
        _profiler->PushSection(std::move(_sectionEntry));
    }

    ProfileSectionGuard* ProfileSectionGuard::GetCurrent()
    {
        return current;
    }

    void ProfileSectionGuard::PushScope(std::string name)
    {
        Profiler::ScopeEntry scopeEntry{
            _currentScopeEntry,
            std::move(name),
            std::chrono::system_clock::now(),
            std::chrono::system_clock::now(),
            {}
        };

        if (_currentScopeEntry == nullptr)
        {
            _sectionEntry.scopeEntries.push_back(std::move(scopeEntry));
            _currentScopeEntry = &_sectionEntry.scopeEntries[_sectionEntry.scopeEntries.size() - 1];
        }
        else
        {
            _currentScopeEntry->children.push_back(std::move(scopeEntry));
            _currentScopeEntry = &_currentScopeEntry->children[_currentScopeEntry->children.size() - 1];
        }
    }

    void ProfileSectionGuard::PopScope()
    {
        GDB_ASSERT(_currentScopeEntry == nullptr, "");

        _currentScopeEntry->end = std::chrono::system_clock::now();
        _currentScopeEntry = _currentScopeEntry->parent;
    }
}
