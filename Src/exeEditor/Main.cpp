#include <iostream>
#include <argparse/argparse.hpp>
#include <fmt/format.h>
#include <gsl/span>

#include "GameDB/Config.hpp"
#include "GameDB/libData.hpp"
#include "GameDB/libDataEditor.hpp"
#include "GameDB/libDebug.hpp"
#include "GameDB/libDebugEditor.hpp"
#include "GameDB/libDI.hpp"
#include "GameDB/libEditor.hpp"
#include "GameDB/libEditorTheme.hpp"
#include "GameDB/libEditorThemeSerializer.hpp"
#include "GameDB/libFileSystem.hpp"
#include "GameDB/libKernel.hpp"
#include "GameDB/libProfiler.hpp"
#include "GameDB/libWindow.hpp"
#include "GameDB/libContainer.hpp"

namespace GDB
{
    int Main(const std::vector<std::string>& args)
    {
        auto loadingProfilerSection = MakeUnique<ProfileSectionGuard>("Loading", GDB::Profiler::Global());

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

        auto spool = Log::Global()->AddSpool("Main");
        spool.lock()->AddSink<LoggerSinkConsole>();

        DIContainer::Global()->RegisterFactory<FileSystem*>([&args](const DIContainer&)
        {
            auto* vfs = SingletonContainer::Global()->GetInstance<VirtualFileSystem>();
            if (vfs != nullptr)
            {
                return vfs;
            }

            vfs = SingletonContainer::Global()->RegisterInstance<VirtualFileSystem>();
            const std::filesystem::path exePath = args[0];
            vfs->AddFileSystem<NativeFileSystem>("/bin", exePath.parent_path());
            vfs->AddFileSystem<NativeFileSystem>("/res", exePath.parent_path() / "Resources");
            vfs->AddFileSystem<NativeFileSystem>("/appdata", Kernel::GetAppDataPath());
            return vfs;
        });

        DIContainer::Global()->RegisterFactory<Window*>([](const DIContainer&)
        {
            auto* window = SingletonContainer::Global()->GetInstance<Window>();
            if (window != nullptr)
            {
                return window;
            }

            return SingletonContainer::Global()->RegisterInstance<Window>();
        });

        DIContainer::Global()->RegisterFactory<Editor*>([](const DIContainer&)
        {
            auto* editor = SingletonContainer::Global()->GetInstance<Editor>();
            if (editor != nullptr)
            {
                return editor;
            }

            return SingletonContainer::Global()->RegisterInstance<Editor>();
        });

        auto* window = DIContainer::Global()->Resolve<Window*>();
        auto* editor = DIContainer::Global()->Resolve<Editor*>();

        SharedPtr<DataSet> dataSet = MakeShared<DataSet>();
        editor->AddWindow<DataSetEditorWindow>(dataSet);
        editor->AddWindow<ConsoleEditorWindow>(Log::Global());

        loadingProfilerSection.reset();

        while (window->IsOpen())
        {
            GDB_PROFILE_SECTION("frame");
            editor->AwakeWindows();
            editor->UpdateWindows();
            window->BeginFrame();
            editor->RenderWindows();
            window->EndFrame();
            editor->DestroyWindows();
        }

        [[maybe_unused]] Profiler* profiler = Profiler::Global();

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
