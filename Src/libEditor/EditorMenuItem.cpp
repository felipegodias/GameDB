#include "GameDB/Editor/EditorMenuItem.hpp"

namespace GDB
{
    EditorMenuItem::EditorMenuItem(String name, Callback callback)
        : _name(std::move(name)),
          _callback(std::move(callback))
    {
    }

    const String& EditorMenuItem::GetName() const
    {
        return _name;
    }

    void EditorMenuItem::InvokeCallback() const
    {
        _callback();
    }
}
