#ifndef GDB_LIB_EDITOR_EDITOR_MENU_HPP
#define GDB_LIB_EDITOR_EDITOR_MENU_HPP

#include "EditorMenuGroup.hpp"
#include "EditorMenuItem.hpp"
#include "GameDB/Container/Map.hpp"
#include "GameDB/Memory/Pointers.hpp"

namespace GDB
{
    /**
     * \brief 
     */
    class EditorMenu
    {
    public:
        /**
         * \brief
         * \return
         */
        [[nodiscard]] const Map<String, UniquePtr<EditorMenuItem>>& GetItems() const;

        /**
         * \brief
         * \param item
         */
        EditorMenuItem* AddItem(UniquePtr<EditorMenuItem> item);

        /**
         * \brief
         * \tparam ArgsTy
         * \param args
         * \return
         */
        template <typename ... ArgsTy>
        EditorMenuItem* AddItem(ArgsTy&& ... args)
        {
            return AddItem(MakeUnique<EditorMenuItem>(std::forward<ArgsTy>(args)...));
        }

        /**
         * \brief
         * \return
         */
        [[nodiscard]] const Map<String, UniquePtr<EditorMenuGroup>>& GetGroups() const;

        /**
         * \brief
         * \param group
         * \return
         */
        EditorMenuGroup* AddGroup(UniquePtr<EditorMenuGroup> group);

        /**
         * \brief
         * \tparam ArgsTy
         * \param args
         * \return
         */
        template <typename ... ArgsTy>
        EditorMenuGroup* AddGroup(ArgsTy&& ... args)
        {
            return AddGroup(MakeUnique<EditorMenuGroup>(std::forward<ArgsTy>(args)...));
        }

    private:
        Map<String, UniquePtr<EditorMenuItem>> _items;
        Map<String, UniquePtr<EditorMenuGroup>> _groups;
    };
}

#endif // !GDB_LIB_EDITOR_EDITOR_MENU_GROUP_HPP
