#ifndef GDB_LIB_EDITOR_EDITOR_WINDOW_HPP
#define GDB_LIB_EDITOR_EDITOR_WINDOW_HPP

#include "EditorMenu.hpp"
#include "GameDB/Container/String.hpp"
#include "GameDB/Memory/Pointers.hpp"

namespace GDB
{
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
            WaitingForAwake = 1,

            /**
             * \brief 
             */
            Active = 2,

            /**
             * \brief 
             */
            WaitingForDestroy = 3
        };

        explicit EditorWindow(String name);

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
        void Awake();

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
        void Destroy();

    protected:
        virtual void OnAwake() = 0;
        virtual void OnUpdate() = 0;
        virtual void OnGUI() = 0;

    private:
        int _instanceId;
        String _name;
        State _state;
        UniquePtr<EditorMenu> _editorMenu;
    };
}

#endif // !GDB_LIB_EDITOR_EDITOR_WINDOW_HPP
