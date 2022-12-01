#include "GameDB/Editor/EditorWidgets.hpp"

namespace GDB
{
    namespace
    {
        struct InputTextCallbackUserData
        {
            String* str;
            ImGuiInputTextCallback chainCallback;
            void* chainCallbackUserData;
        };

        int InputTextCallback(ImGuiInputTextCallbackData* data)
        {
            const auto userData = static_cast<InputTextCallbackUserData*>(data->UserData);
            if (data->EventFlag == ImGuiInputTextFlags_CallbackResize)
            {
                String* str = userData->str;
                str->resize(data->BufTextLen);
                data->Buf = str->data();
            }
            else if (userData->chainCallback)
            {
                // Forward to user callback, if any
                data->UserData = userData->chainCallbackUserData;
                return userData->chainCallback(data);
            }
            return 0;
        }
    }

    bool InputText(const char* label, String* str, ImGuiInputTextFlags flags, const ImGuiInputTextCallback callback,
                   void* userData)
    {
        flags |= ImGuiInputTextFlags_CallbackResize;

        InputTextCallbackUserData cbUserData{str, callback, userData};
        return ImGui::InputText(label, str->data(), str->capacity() + 1, flags, InputTextCallback,
                                &cbUserData);
    }

    bool InputTextMultiline(const char* label, String* str, const ImVec2& size, ImGuiInputTextFlags flags,
                            const ImGuiInputTextCallback callback, void* userData)
    {
        flags |= ImGuiInputTextFlags_CallbackResize;

        InputTextCallbackUserData cbUserData{str, callback, userData};
        return ImGui::InputTextMultiline(label, str->data(), str->capacity() + 1, size, flags, InputTextCallback,
                                         &cbUserData);
    }

    bool InputTextWithLabelOnLeft(const char* label, String* str, const ImGuiInputTextFlags flags,
                                  const ImGuiInputTextCallback callback, void* userData)
    {
        bool result = false;
        ImGui::PushID(label);
        if (ImGui::BeginTable("T", 2, ImGuiTableFlags_SizingStretchSame))
        {
            ImGui::TableSetupColumn("L", ImGuiTableColumnFlags_None, 0.4F);
            ImGui::TableSetupColumn("I", ImGuiTableColumnFlags_None, 0.6F);
            ImGui::TableNextRow();
            ImGui::TableNextColumn();

            const ImVec2 sz = ImGui::CalcTextSize(label);
            const float cursorY = ImGui::GetCursorPosY();
            ImGui::InvisibleButton("##IB", ImVec2(sz.x, sz.y + ImGui::GetStyle().ItemInnerSpacing.y * 2));
            const float finalCursorPosY = ImGui::GetCursorPosY();
            ImGui::SetCursorPosY(cursorY + ImGui::GetStyle().ItemInnerSpacing.y);
            ImGui::Text("%s", label);
            ImGui::SetCursorPosY(finalCursorPosY);

            ImGui::TableNextColumn();
            ImGui::PushItemWidth(-FLT_MIN);
            result = InputText("##V", str, flags, callback, userData);

            ImGui::EndTable();
        }
        ImGui::PopID();
        float y = ImGui::GetCursorPosY();
        ImGui::SetCursorPosY(y - ImGui::GetStyle().ItemInnerSpacing.y);

        return result;
    }
}
