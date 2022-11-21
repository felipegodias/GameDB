#ifndef GDB_LIB_DEBUG_EDITOR_CONSOLE_EDITOR_WINDOW_HPP
#define GDB_LIB_DEBUG_EDITOR_CONSOLE_EDITOR_WINDOW_HPP

#include "LoggerSinkConsole.hpp"
#include "GameDB/Debug/Log.hpp"
#include "GameDB/Editor/EditorWindow.hpp"
#include <GameDB/Container/Vector.hpp>

namespace GDB
{
    class ConsoleEditorWindow final : public EditorWindow
    {
    public:
        explicit ConsoleEditorWindow(const Log* log);

    protected:
        void OnAwake() override;
        void OnUpdate() override;
        void OnGUI() override;

    private:
        Vector<WeakPtr<LoggerSinkConsole>> _sinks;
    };
}

#endif // !GDB_LIB_DEBUG_EDITOR_CONSOLE_EDITOR_WINDOW_HPP
