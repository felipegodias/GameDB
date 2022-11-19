#ifndef GDB_LIB_EDITOR_EDITOR_HPP
#define GDB_LIB_EDITOR_EDITOR_HPP

#include "EditorWindow.hpp"
#include "GameDB/Container/Vector.hpp"
#include "GameDB/Memory/Pointers.hpp"

namespace GDB
{
    class Editor
    {
    public:
        Editor();
        void AwakeWindows();
        void UpdateWindows() const;
        void RenderWindows() const;
        void DestroyWindows();

        WeakPtr<EditorWindow> AddWindow(SharedPtr<EditorWindow> window);

        template <typename Ty, typename ... ArgsTy,
                  std::enable_if_t<std::is_base_of_v<EditorWindow, Ty>, bool>  = true,
                  std::enable_if_t<std::is_constructible_v<Ty, ArgsTy...>, bool>  = true>
        WeakPtr<Ty> AddWindow(ArgsTy&& ... args)
        {
            auto ptr = MakeShared<Ty>(std::forward<ArgsTy>(args)...);
            AddWindow(ptr);
            return ptr;
        }

    private:
        Vector<SharedPtr<EditorWindow>> _toAwakeWindows;
        Vector<SharedPtr<EditorWindow>> _activeWindows;
    };
}

#endif // !GDB_LIB_EDITOR_EDITOR_HPP
