#ifndef GDB_LIB_EDITOR_EDITOR_WIDGETS_HPP
#define GDB_LIB_EDITOR_EDITOR_WIDGETS_HPP

#include <imgui.h>

#include "GameDB/Container/String.hpp"

namespace GDB
{
    /**
     * \brief 
     * \param label 
     * \param str 
     * \param flags 
     * \param callback 
     * \param userData 
     * \return 
     */
    bool InputText(const char* label, String* str, ImGuiInputTextFlags flags = 0,
                   ImGuiInputTextCallback callback = nullptr, void* userData = nullptr);
}

#endif // !GDB_LIB_EDITOR_EDITOR_WIDGETS_HPP
