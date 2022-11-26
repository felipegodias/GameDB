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
}
