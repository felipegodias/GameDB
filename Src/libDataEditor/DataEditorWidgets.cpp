#include "GameDB/DataEditor/DataEditorWidgets.hpp"

#include <imgui.h>

#include "GameDB/Data/DataValueString.hpp"
#include "GameDB/Editor/EditorWidgets.hpp"

namespace GDB
{
    bool InputDataValue(DataValue* dataValue)
    {
        auto* stringValue = dynamic_cast<DataValueString*>(dataValue);

        ImGui::PushID(stringValue->GetDataId().GetValue());
        ImGui::PushItemWidth(-FLT_MIN);

        const ImVec4 oldFrameBg = ImGui::GetStyle().Colors[ImGuiCol_FrameBg];
        const ImVec4 oldChildBorder = ImGui::GetStyle().Colors[ImGuiCol_Border];
        ImGui::GetStyle().Colors[ImGuiCol_FrameBg] = ImVec4(0, 0, 0, 0);
        ImGui::GetStyle().Colors[ImGuiCol_Border] = ImVec4(0, 0, 0, 0);

        const bool result = InputText("##v", &stringValue->GetValue());

        ImGui::GetStyle().Colors[ImGuiCol_FrameBg] = oldFrameBg;
        ImGui::GetStyle().Colors[ImGuiCol_ChildBg] = oldChildBorder;

        ImGui::PopID();

        return result;
    }
}
