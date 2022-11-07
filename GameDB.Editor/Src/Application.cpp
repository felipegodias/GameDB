#include "GameDB/Editor/Application.hpp"

#include <filesystem>
#include <fstream>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <iostream>
#include <fmt/format.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h> // Will drag system OpenGL headers
#include <gsl/span>

#include "GameDB/Editor/Theme.hpp"

namespace Pluto::GameDB::Editor
{
    namespace
    {
        void GlfwErrorCallback(int error, const char* description)
        {
            std::cout << fmt::format("Glfw Error {0}: {1}", error, description) << std::endl;
        }

        ImVec4 ToImVec4(const Color& color)
        {
            return { color.r, color.g, color.b, color.a };
        }

        ImVec2 ToImVec2(const Vector2& vector2)
        {
            return { vector2.x, vector2.y };
        }

        void ApplyTheme(const Theme& theme)
        {
            const float fontSize = 16.0F;
            const float fontScale = 1.25F;
            std::filesystem::path fontPath = "Resources/Fonts";
            fontPath /= theme.font;
            ImGui::GetIO().Fonts->AddFontFromFileTTF(fontPath.generic_string().c_str(), fontSize * fontScale);

            ImGuiStyle& style = ImGui::GetStyle();
            style.WindowPadding = ToImVec2(theme.style.windowPadding);
            style.FramePadding = ToImVec2(theme.style.framePadding);
            style.CellPadding = ToImVec2(theme.style.cellPadding);
            style.ItemSpacing = ToImVec2(theme.style.itemSpacing);
            style.ItemInnerSpacing = ToImVec2(theme.style.itemInnerSpacing);
            style.TouchExtraPadding = ToImVec2(theme.style.touchExtraPadding);
            style.IndentSpacing = theme.style.indentSpacing;
            style.ScrollbarSize = theme.style.scrollbarSize;
            style.GrabMinSize = theme.style.grabMinSize;
            style.WindowBorderSize = theme.style.windowBorderSize;
            style.ChildBorderSize = theme.style.childBorderSize;
            style.PopupBorderSize = theme.style.popupBorderSize;
            style.FrameBorderSize = theme.style.frameBorderSize;
            style.TabBorderSize = theme.style.tabBorderSize;
            style.WindowRounding = theme.style.windowRounding;
            style.ChildRounding = theme.style.childRounding;
            style.FrameRounding = theme.style.frameRounding;
            style.PopupRounding = theme.style.popupRounding;
            style.ScrollbarRounding = theme.style.scrollbarRounding;
            style.GrabRounding = theme.style.grabRounding;
            style.LogSliderDeadzone = theme.style.logSliderDeadzone;
            style.TabRounding = theme.style.tabRounding;

            gsl::span colors(style.Colors);
            colors[ImGuiCol_Text] = ToImVec4(theme.palette.text);
            colors[ImGuiCol_TextDisabled] = ToImVec4(theme.palette.textDisabled);
            colors[ImGuiCol_WindowBg] = ToImVec4(theme.palette.windowBg);
            colors[ImGuiCol_ChildBg] = ToImVec4(theme.palette.childBg);
            colors[ImGuiCol_PopupBg] = ToImVec4(theme.palette.popupBg);
            colors[ImGuiCol_Border] = ToImVec4(theme.palette.border);
            colors[ImGuiCol_BorderShadow] = ToImVec4(theme.palette.borderShadow);
            colors[ImGuiCol_FrameBg] = ToImVec4(theme.palette.frameBg);
            colors[ImGuiCol_FrameBgHovered] = ToImVec4(theme.palette.frameBgHovered);
            colors[ImGuiCol_FrameBgActive] = ToImVec4(theme.palette.frameBgActive);
            colors[ImGuiCol_TitleBg] = ToImVec4(theme.palette.titleBg);
            colors[ImGuiCol_TitleBgActive] = ToImVec4(theme.palette.titleBgActive);
            colors[ImGuiCol_TitleBgCollapsed] = ToImVec4(theme.palette.titleBgCollapsed);
            colors[ImGuiCol_MenuBarBg] = ToImVec4(theme.palette.menuBarBg);
            colors[ImGuiCol_ScrollbarBg] = ToImVec4(theme.palette.scrollbarBg);
            colors[ImGuiCol_ScrollbarGrab] = ToImVec4(theme.palette.scrollbarGrab);
            colors[ImGuiCol_ScrollbarGrabHovered] = ToImVec4(theme.palette.scrollbarGrabHovered);
            colors[ImGuiCol_ScrollbarGrabActive] = ToImVec4(theme.palette.scrollbarGrabActive);
            colors[ImGuiCol_CheckMark] = ToImVec4(theme.palette.checkMark);
            colors[ImGuiCol_SliderGrab] = ToImVec4(theme.palette.sliderGrab);
            colors[ImGuiCol_SliderGrabActive] = ToImVec4(theme.palette.sliderGrabActive);
            colors[ImGuiCol_Button] = ToImVec4(theme.palette.button);
            colors[ImGuiCol_ButtonHovered] = ToImVec4(theme.palette.buttonHovered);
            colors[ImGuiCol_ButtonActive] = ToImVec4(theme.palette.buttonActive);
            colors[ImGuiCol_Header] = ToImVec4(theme.palette.header);
            colors[ImGuiCol_HeaderHovered] = ToImVec4(theme.palette.headerHovered);
            colors[ImGuiCol_HeaderActive] = ToImVec4(theme.palette.headerActive);
            colors[ImGuiCol_Separator] = ToImVec4(theme.palette.separator);
            colors[ImGuiCol_SeparatorHovered] = ToImVec4(theme.palette.separatorHovered);
            colors[ImGuiCol_SeparatorActive] = ToImVec4(theme.palette.separatorActive);
            colors[ImGuiCol_ResizeGrip] = ToImVec4(theme.palette.resizeGrip);
            colors[ImGuiCol_ResizeGripHovered] = ToImVec4(theme.palette.resizeGripHovered);
            colors[ImGuiCol_ResizeGripActive] = ToImVec4(theme.palette.resizeGripActive);
            colors[ImGuiCol_Tab] = ToImVec4(theme.palette.tab);
            colors[ImGuiCol_TabHovered] = ToImVec4(theme.palette.tabHovered);
            colors[ImGuiCol_TabActive] = ToImVec4(theme.palette.tabActive);
            colors[ImGuiCol_TabUnfocused] = ToImVec4(theme.palette.tabUnfocused);
            colors[ImGuiCol_TabUnfocusedActive] = ToImVec4(theme.palette.tabUnfocusedActive);
            colors[ImGuiCol_DockingPreview] = ToImVec4(theme.palette.dockingPreview);
            colors[ImGuiCol_DockingEmptyBg] = ToImVec4(theme.palette.dockingEmptyBg);
            colors[ImGuiCol_PlotLines] = ToImVec4(theme.palette.plotLines);
            colors[ImGuiCol_PlotLinesHovered] = ToImVec4(theme.palette.plotLinesHovered);
            colors[ImGuiCol_PlotHistogram] = ToImVec4(theme.palette.plotHistogram);
            colors[ImGuiCol_PlotHistogramHovered] = ToImVec4(theme.palette.plotHistogramHovered);
            colors[ImGuiCol_TableHeaderBg] = ToImVec4(theme.palette.tableHeaderBg);
            colors[ImGuiCol_TableBorderStrong] = ToImVec4(theme.palette.tableBorderStrong);
            colors[ImGuiCol_TableBorderLight] = ToImVec4(theme.palette.tableBorderLight);
            colors[ImGuiCol_TableRowBg] = ToImVec4(theme.palette.tableRowBg);
            colors[ImGuiCol_TableRowBgAlt] = ToImVec4(theme.palette.tableRowBgAlt);
            colors[ImGuiCol_TextSelectedBg] = ToImVec4(theme.palette.textSelectedBg);
            colors[ImGuiCol_DragDropTarget] = ToImVec4(theme.palette.dragDropTarget);
            colors[ImGuiCol_NavHighlight] = ToImVec4(theme.palette.navHighlight);
            colors[ImGuiCol_NavWindowingHighlight] = ToImVec4(theme.palette.navWindowingHighlight);
            colors[ImGuiCol_NavWindowingDimBg] = ToImVec4(theme.palette.navWindowingDimBg);
            colors[ImGuiCol_ModalWindowDimBg] = ToImVec4(theme.palette.modalWindowDimBg);
        }

        void ApplyDefaultTheme()
        {
            std::ifstream themeFile("Resources/Themes/Default.json");
            if (!themeFile.is_open())
            {
                // TODO: Log
                return;
            }

            Json themeJson;
            themeFile >> themeJson;
            Theme theme = themeJson;

            OrderedJson oJson = theme;
            std::cout << oJson.dump(2) << std::endl;

            ApplyTheme(theme);
        }
    }

    void Application::Run()
    {
        [[maybe_unused]] auto instance = *this;

        // Setup window
        glfwSetErrorCallback(GlfwErrorCallback);
        if (glfwInit() == GLFW_FALSE)
        {
            return;
        }

        // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
        // GL ES 2.0 + GLSL 100
        const std::string glsl_version = "#version 100";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
        // GL 3.2 + GLSL 150
        const std::string glsl_version = "#version 150";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
        // GL 3.0 + GLSL 130
        const std::string glsl_version = "#version 130";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
        //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
        //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

        // Create window with graphics context
        const int windowWidth = 1280;
        const int windowHeight = 720;
        GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "GameDB", nullptr, nullptr);
        if (window == nullptr)
        {
            return;
        }

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1); // Enable vsync

        GLenum err = glewInit();
        if (GLEW_OK != err)
        {
            /* Problem: glewInit failed, something is seriously wrong. */
            std::cout << "Error: " << glewGetErrorString(err) << std::endl;
        }
        std::cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION) << std::endl;

        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& imGuiIo = ImGui::GetIO();
        (void)imGuiIo;
        //ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        //io.FontGlobalScale = 2;

        //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
        imGuiIo.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        imGuiIo.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

        ApplyDefaultTheme();

        // Setup Dear ImGui style
        //ImGui::StyleColorsDark();
        //ImGui::StyleColorsClassic();
        //ImGui::StyleColorsLight();

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init(glsl_version.c_str());

        // Load Fonts
        // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
        // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
        // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
        // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
        // - Read 'docs/FONTS.md' for more instructions and details.
        // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
        //io.Fonts->AddFontDefault();
        //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
        //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
        //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
        //io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
        //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
        //IM_ASSERT(font != NULL);

        //const float fontSize = 16.0F;
        //const float fontScale = 1.25F;
        //imGuiIo.Fonts->AddFontFromFileTTF("Resources/Fonts/Roboto-Regular.ttf", fontSize * fontScale);

        //ImFontConfig cfg;
        //cfg.SizePixels = 13 * SCALE;
        //ImGui::GetIO().Fonts->AddFontDefault(&cfg);

        // Our state
        const auto clear_color = ImVec4(0.12F, 0.12F, 0.12F, 1.00F);

        // Main loop
        while (glfwWindowShouldClose(window) == GLFW_FALSE)
        {
            // Poll and handle events (inputs, window resize, etc.)
            // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
            // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
            // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
            // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
            glfwPollEvents();

            // Start the Dear ImGui frame
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            ImGui::SetNextWindowPos(ImVec2(0.0F, 0.0F));
            ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);

            //ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
            ImGui::ShowDemoWindow();

            // Rendering
            ImGui::Render();

            int display_w = 0;
            int display_h = 0;
            glfwGetFramebufferSize(window, &display_w, &display_h);
            glViewport(0, 0, display_w, display_h);
            glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w,
                clear_color.w);
            glClear(GL_COLOR_BUFFER_BIT);
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            if ((imGuiIo.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) == ImGuiConfigFlags_ViewportsEnable)
            { 
                GLFWwindow* backup_current_context = glfwGetCurrentContext(); 
                ImGui::UpdatePlatformWindows(); 
                ImGui::RenderPlatformWindowsDefault(); 
                glfwMakeContextCurrent(backup_current_context); 
            }

            glfwSwapBuffers(window);
        }

        // Cleanup
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(window);
        glfwTerminate();
    }
}
