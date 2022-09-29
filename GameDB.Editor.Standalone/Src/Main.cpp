#include "GameDB/HelloWorld.hpp"
#include "GameDB/Editor/HelloWorld.hpp"

#include <iostream>

namespace Pluto::GameDB::Editor::Standalone
{
    int Main([[maybe_unused]] const int argc, [[maybe_unused]] const char* argv[])
    {
        std::cout << GetGameDBHelloWorld() << std::endl;
        std::cout << GetGameDBEditorHelloWorld() << std::endl;
        return EXIT_SUCCESS;
    }
}

int main(const int argc, const char* argv[])
{
    return Pluto::GameDB::Editor::Standalone::Main(argc, argv);
}
