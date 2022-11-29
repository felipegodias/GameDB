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

        ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0, 0, 0, 0));
        ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
        const bool result = InputText("##v", &stringValue->GetValue());
        ImGui::PopStyleColor();
        ImGui::PopStyleColor();

        ImGui::PopID();

        return result;
    }
}
