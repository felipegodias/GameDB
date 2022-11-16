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
        void MainLoop() const;

        EditorWindow* AddWindow(UniquePtr<EditorWindow> window);

        template <typename Ty, typename ... ArgsTy,
                  std::enable_if_t<std::is_base_of_v<EditorWindow, Ty>, bool>  = true,
                  std::enable_if_t<std::is_constructible_v<Ty, ArgsTy...>, bool>  = true>
        Ty* AddWindow(ArgsTy&& ... args)
        {
            return static_cast<Ty*>(AddWindow(MakeUnique<Ty>(std::forward<ArgsTy>(args)...)));
        }

    private:
        void AwakeWindows() const;
        void UpdateWindows() const;
        void RenderWindows() const;

        Vector<UniquePtr<EditorWindow>> _windows;
    };
}

#endif // !GDB_LIB_EDITOR_EDITOR_HPP
