#ifndef GDB_LIB_WINDOW_WINDOW_HPP
#define GDB_LIB_WINDOW_WINDOW_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace GDB
{
    class Window
    {
    public:
        Window();
        ~Window();

        bool IsOpen();

        void BeginFrame();
        void EndFrame();

    private:
        GLFWwindow* _window;
    };
}

#endif // !GDB_LIB_WINDOW_WINDOW_HPP
