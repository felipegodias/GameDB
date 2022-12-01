#ifndef GDB_LIB_DEBUG_EDITOR_CONSOLE_EDITOR_WINDOW_HPP
#define GDB_LIB_DEBUG_EDITOR_CONSOLE_EDITOR_WINDOW_HPP

#include "LoggerSinkConsole.hpp"
#include "GameDB/Log/Log.hpp"
#include "GameDB/Editor/EditorWindow.hpp"
#include <GameDB/Container/Vector.hpp>

namespace GDB
{
    class ConsoleEditorWindow final : public EditorWindow
    {
    public:
        ConsoleEditorWindow(Editor* editor, const Log* log);

    protected:
        void OnEnabled() override;
        void OnDisabled() override;
        void OnUpdate() override;
        void OnRender() override;

    private:
        Vector<WeakPtr<LoggerSinkConsole>> _sinks;
    };
}

#endif // !GDB_LIB_DEBUG_EDITOR_CONSOLE_EDITOR_WINDOW_HPP
