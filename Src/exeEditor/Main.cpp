#include <iostream>
#include <argparse/argparse.hpp>
#include <fmt/format.h>
#include <gsl/span>

#include "GameDB/Config.hpp"
#include "GameDB/libWindow.hpp"
#include "GameDB/libEditor.hpp"
#include "GameDB/libDataEditor.hpp"
#include "GameDB/libData.hpp"

namespace GDB
{
    int Main(const std::vector<std::string>& args)
    {
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

        
        Window window;
        Editor editor;

        DataTable dataTable(DataId::Random(), "Pokemons");
        dataTable.AddColumn(MakeUnique<DataColumn>(DataId::Random(), "Id", MakeUnique<DataTypeString>()));
        dataTable.AddColumn(MakeUnique<DataColumn>(DataId::Random(), "Name", MakeUnique<DataTypeString>()));

        editor.AddWindow<DataTableEditorWindow>(&dataTable, true);

        while (window.IsOpen())
        {
            window.BeginFrame();
            editor.MainLoop();
            window.EndFrame();
        }

        return EXIT_SUCCESS;
    }
}

int main(const int argc, const char* argv[])
{
    try
    {
        const gsl::span<const char*> argsSpan(argv, argc);
        std::vector<std::string> args;
        args.reserve(argc);
        for (const char* arg : argsSpan)
        {
            args.emplace_back(arg);
        }

        const int exitCode = GDB::Main(args);
        return exitCode;
    }
    catch (const std::runtime_error& re)
    {
        // specific handling for runtime_error
        std::cerr << "Runtime error: " << re.what() << std::endl;
    }
    catch (const std::exception& ex)
    {
        // specific handling for all exceptions extending std::exception, except
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
