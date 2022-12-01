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

    const EditorMenuItem::Callback& EditorMenuItem::GetCallback() const
    {
        return _callback;
    }
}
