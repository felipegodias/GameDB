#include <iostream>
#include <argparse/argparse.hpp>
#include <fmt/format.h>
#include <gsl/span>

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
    try
    {
        gsl::span<const char*> argsSpan(argv, argc);
        std::vector<std::string> args;
        args.reserve(argc);
        for (const char* arg : argsSpan)
        {
            args.emplace_back(arg);
        }

        const int exitCode = Pluto::GameDB::Editor::Standalone::Main(args);
        return exitCode;
    }
    catch (const std::runtime_error& re)
    {
        // speciffic handling for runtime_error
        std::cerr << "Runtime error: " << re.what() << std::endl;
    }
    catch (const std::exception& ex)
    {
        // speciffic handling for all exceptions extending std::exception, except
        // std::runtime_error which is handled explicitly
        std::cerr << "Error occurred: " << ex.what() << std::endl;
    }
    catch (...)
    {
        // catch any other errors (that we have no information about)
        std::cerr << "Unknown failure occurred. Possible memory corruption" << std::endl;
    }

    return EXIT_FAILURE;
}
