#include <iostream>
#include <argparse/argparse.hpp>
#include <fmt/format.h>

#include "GameDB/Config.hpp"
#include "GameDB/HelloWorld.hpp"
#include "GameDB/Editor/Application.hpp"
#include "GameDB/Editor/HelloWorld.hpp"

namespace Pluto::GameDB::Editor::Standalone
{
    int Main(const std::vector<std::string>& args)
    {
        std::cout << GetGameDBHelloWorld() << std::endl;
        std::cout << GetGameDBEditorHelloWorld() << std::endl;
        std::cout << fmt::format("{0} {1}", "Hello", "World") << std::endl;

        argparse::ArgumentParser argumentParser(PROJECT_NAME, PROJECT_VER);
        try
        {
            argumentParser.parse_args(args);
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
    std::vector<std::string> args;
    args.reserve(argc);
    for (int i = 0; i < argc; ++i)
    {
        args.emplace_back(argv[i]);
    }

    return Pluto::GameDB::Editor::Standalone::Main(args);
}
