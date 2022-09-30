#include "GameDB/Config.hpp"
#include "GameDB/HelloWorld.hpp"
#include "GameDB/Editor/Application.hpp"
#include "GameDB/Editor/HelloWorld.hpp"

#include <argparse/argparse.hpp>
#include <fmt/format.h>

#include <iostream>

namespace Pluto::GameDB::Editor::Standalone
{
    int Main([[maybe_unused]] const int argc, [[maybe_unused]] const char* argv[])
    {
        std::cout << GetGameDBHelloWorld() << std::endl;
        std::cout << GetGameDBEditorHelloWorld() << std::endl;
        std::cout << fmt::format("{0} {1}", "Hello", "World") << std::endl;

        argparse::ArgumentParser argumentParser(PROJECT_NAME, PROJECT_VER);
        try
        {
            argumentParser.parse_args(argc, argv);
        }
        catch (const std::runtime_error& err)
        {
            std::cout << err.what() << std::endl;
            std::cout << argumentParser << std::endl;
            return EXIT_FAILURE;
        }

        Application application;
        application.Run();

        return EXIT_SUCCESS;
    }
}

int main(const int argc, const char* argv[])
{
    return Pluto::GameDB::Editor::Standalone::Main(argc, argv);
}
