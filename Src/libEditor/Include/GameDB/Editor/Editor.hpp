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
        using EditorWindowList = Vector<UniquePtr<EditorWindow>>;
        using ActionCallback = std::function<void()>;
        using ActionsList = Vector<ActionCallback>;

        Editor();

        /**
         * \brief 
         */
        void ConsumeActions();

        /**
         * \brief 
         */
        void UpdateWindows();

        /**
         * \brief 
         */
        void RenderWindows() const;

        /**
         * \brief 
         * \param window 
         */
        void AddWindow(UniquePtr<EditorWindow> window);

        /**
         * \brief 
         * \tparam Ty 
         * \tparam ArgsTy 
         * \param args 
         * \return 
         */
        template <typename Ty, typename ... ArgsTy,
                  std::enable_if_t<std::is_base_of_v<EditorWindow, Ty>, bool>  = true,
                  std::enable_if_t<std::is_constructible_v<Ty, Editor*, ArgsTy...>, bool>  = true>
        Ty* AddWindow(ArgsTy&& ... args)
        {
            auto uniquePtr = MakeUnique<Ty>(this, std::forward<ArgsTy>(args)...);
            Ty* ptr = uniquePtr.get();
            AddWindow(std::move(uniquePtr));
            return ptr;
        }

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] const EditorWindowList& GetWindows() const;

        /**
         * \brief 
         * \tparam Ty 
         * \return 
         */
        template <typename Ty,
                  std::enable_if_t<std::is_base_of_v<EditorWindow, Ty>, bool>  = true>
        [[nodiscard]] Ty* GetWindow() const
        {
            for (const auto& editorWindow : _windows)
            {
                auto* window = dynamic_cast<Ty*>(editorWindow.get());
                if (window != nullptr)
                {
                    return window;
                }
            }

            return nullptr;
        }

        /**
         * \brief 
         * \tparam Ty 
         * \param callback 
         */
        template <typename Ty,
                  std::enable_if_t<std::is_base_of_v<EditorWindow, Ty>, bool>  = true>
        void ForEachWindow(std::function<bool(Ty*)> callback) const
        {
            for (const auto& editorWindow : _windows)
            {
                auto* window = dynamic_cast<Ty*>(editorWindow.get());
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

        /**
         * \brief 
         * \param actionCallback 
         */
        void PushAction(ActionCallback actionCallback);

    private:
        EditorWindowList _windows;
        ActionsList _actions;
    };
}

#endif // !GDB_LIB_EDITOR_EDITOR_HPP
