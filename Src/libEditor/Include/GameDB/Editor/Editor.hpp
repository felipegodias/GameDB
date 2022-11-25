#ifndef GDB_LIB_EDITOR_EDITOR_HPP
#define GDB_LIB_EDITOR_EDITOR_HPP

#include "EditorWindow.hpp"
#include "GameDB/Container/Vector.hpp"
#include "GameDB/DI/DIContainer.hpp"
#include "GameDB/Memory/Pointers.hpp"

namespace GDB
{
    class Editor
    {
    public:
        using EditorWindowList = Vector<SharedPtr<EditorWindow>>;

        Editor();
        void AwakeWindows() const;
        void UpdateWindows() const;
        void RenderWindows() const;
        void DestroyWindows();

        void AddWindow(SharedPtr<EditorWindow> window);

        template <typename Ty, typename ... ArgsTy,
                  std::enable_if_t<std::is_base_of_v<EditorWindow, Ty>, bool>  = true,
                  std::enable_if_t<std::is_constructible_v<Ty, ArgsTy...>, bool>  = true>
        SharedPtr<Ty> AddWindow(ArgsTy&& ... args)
        {
            auto ptr = MakeShared<Ty>(std::forward<ArgsTy>(args)...);
            AddWindow(ptr);
            return ptr;
        }

        template <typename Ty, typename ... ArgsTy,
                  std::enable_if_t<std::is_base_of_v<EditorWindow, Ty>, bool>  = true,
                  std::enable_if_t<std::is_constructible_v<Ty, ArgsTy...>, bool>  = true>
        static SharedPtr<Ty> CreateWindow(ArgsTy&& ... args)
        {
            auto* editor = DIContainer::Global()->Resolve<Editor*>();
            return editor->AddWindow<Ty>(std::forward<ArgsTy>(args)...);
        }

    private:
        EditorWindowList _windows;
    };
}

#endif // !GDB_LIB_EDITOR_EDITOR_HPP
