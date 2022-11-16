#include "GameDB/Editor/EditorMenuGroup.hpp"

namespace GDB
{
    EditorMenuGroup::EditorMenuGroup(String name)
        : _name(std::move(name))
    {
    }

    const String& EditorMenuGroup::GetName() const
    {
        return _name;
    }

    const Map<String, UniquePtr<EditorMenuItem>>& EditorMenuGroup::GetItems() const
    {
        return _items;
    }

    EditorMenuItem* EditorMenuGroup::AddItem(UniquePtr<EditorMenuItem> item)
    {
        EditorMenuItem* itemPtr = item.get();
        _items[item->GetName()] = std::move(item);
        return itemPtr;
    }

    const Map<String, UniquePtr<EditorMenuGroup>>& EditorMenuGroup::GetGroups() const
    {
        return _groups;
    }

    EditorMenuGroup* EditorMenuGroup::AddGroup(UniquePtr<EditorMenuGroup> group)
    {
        EditorMenuGroup* groupPtr = group.get();
        _groups[group->GetName()] = std::move(group);
        return groupPtr;
    }
}
