#include "GameDB/Editor/EditorMenu.hpp"

namespace GDB
{
    const Map<String, UniquePtr<EditorMenuItem>>& EditorMenu::GetItems() const
    {
        return _items;
    }

    EditorMenuItem* EditorMenu::AddItem(UniquePtr<EditorMenuItem> item)
    {
        EditorMenuItem* itemPtr = item.get();
        _items[item->GetName()] = std::move(item);
        return itemPtr;
    }

    const Map<String, UniquePtr<EditorMenuGroup>>& EditorMenu::GetGroups() const
    {
        return _groups;
    }

    EditorMenuGroup* EditorMenu::AddGroup(UniquePtr<EditorMenuGroup> group)
    {
        EditorMenuGroup* groupPtr = group.get();
        _groups[group->GetName()] = std::move(group);
        return groupPtr;
    }
}
