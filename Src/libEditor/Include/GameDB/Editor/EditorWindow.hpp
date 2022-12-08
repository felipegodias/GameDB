#ifndef GDB_LIB_EDITOR_EDITOR_WINDOW_HPP
#define GDB_LIB_EDITOR_EDITOR_WINDOW_HPP

#include "EditorMenu.hpp"
#include "GameDB/Container/String.hpp"
#include "GameDB/Memory/Pointers.hpp"

namespace GDB
{
    class Editor;

    /**
     * \brief 
     */
    class EditorWindow
    {
    public:
        /**
         * \brief 
         */
        enum class State
        {
            /**
             * \brief 
             */
            None = 0,

            /**
             * \brief 
             */
            WaitingForEnable = 1,

            /**
             * \brief 
             */
            Enabled = 2,

            /**
             * \brief 
             */
            WaitingForDisable = 3,

            /**
             * \brief 
             */
            Disabled = 4,
        };

        /**
         * \brief 
         */
        enum class Type
        {
            /**
             * \brief 
             */
            None = 0,

            /**
             * \brief 
             */
            Regular = 1,

            /**
             * \brief 
             */
            Modal = 2
        };

        EditorWindow(Editor* editor, String name, Type type = Type::Regular);

        virtual ~EditorWindow() = 0;

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] const String& GetName() const;

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] State GetState() const;

        /**
         * \brief 
         * \return 
         */
        EditorMenu* GetEditorMenu() const;

        /**
         * \brief 
         */
        void Update();

        /**
         * \brief 
         */
        void Render();

        /**
         * \brief 
         */
        void Show();

        /**
         * \brief 
         */
        void Hide();

    protected:
        virtual void OnEnabled();
        virtual void OnDisabled();
        virtual void OnUpdate();
        virtual void OnPreRender();
        virtual void OnRenderMenuBar();
        virtual void OnRender();
        virtual void OnPostRender();

    private:
        Editor* _editor;
        String _name;
        Type _type;
        State _state;
        UniquePtr<EditorMenu> _editorMenu;
    };
}

#endif // !GDB_LIB_EDITOR_EDITOR_WINDOW_HPP
