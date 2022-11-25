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

        [[nodiscard]] const EditorWindowList& GetWindows() const;

        template <typename Ty, std::enable_if_t<std::is_base_of_v<EditorWindow, Ty>, bool>  = true>
        [[nodiscard]] SharedPtr<Ty> GetWindow() const
        {
            for (const auto& editorWindow : _windows)
            {
                auto window = std::dynamic_pointer_cast<Ty>(editorWindow);
                if (window != nullptr)
                {
                    return window;
                }
            }

            return nullptr;
        }

        template <typename Ty, std::enable_if_t<std::is_base_of_v<EditorWindow, Ty>, bool>  = true>
        void ForEachWindow(std::function<bool(const SharedPtr<Ty>&)> callback) const
        {
            for (const auto& editorWindow : _windows)
            {
                auto window = std::dynamic_pointer_cast<Ty>(editorWindow);
                if (window == nullptr)
                {
                    continue;
                }

                if (!callback(window))
                {
                    break;
                }
            }
        }

    private:
        EditorWindowList _windows;
    };
}

#endif // !GDB_LIB_EDITOR_EDITOR_HPP
