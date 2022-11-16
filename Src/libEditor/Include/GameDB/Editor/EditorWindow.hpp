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
        EditorWindow(String name, bool isActive);

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
        [[nodiscard]] bool IsActive() const;

        /**
         * \brief 
         * \param active 
         */
        void SetActive(bool active);

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] bool IsAwaken() const;

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

    protected:
        virtual void OnAwake() = 0;
        virtual void OnUpdate() = 0;
        virtual void OnGUI() = 0;

    private:
        String _name;
        bool _isActive;
        bool _isAwaken;
        UniquePtr<EditorMenu> _editorMenu;
    };
}

#endif // !GDB_LIB_EDITOR_EDITOR_WINDOW_HPP
