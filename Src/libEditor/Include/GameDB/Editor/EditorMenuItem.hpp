#ifndef GDB_LIB_EDITOR_EDITOR_MENU_ITEM_HPP
#define GDB_LIB_EDITOR_EDITOR_MENU_ITEM_HPP

#include <functional>

#include "GameDB/Container/String.hpp"

namespace GDB
{
    /**
     * \brief 
     */
    class EditorMenuItem
    {
    public:
        using Callback = std::function<void()>;

        EditorMenuItem(String name, Callback callback);

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] const String& GetName() const;

        /**
         * \brief 
         */
        void InvokeCallback() const;

    private:
        String _name;
        Callback _callback;
    };
}

#endif // !GDB_LIB_EDITOR_EDITOR_MENU_ITEM_HPP
