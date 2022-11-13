#include <iostream>
#include <argparse/argparse.hpp>
#include <fmt/format.h>
#include <gsl/span>

#include "GameDB/Config.hpp"
#include "GameDB/HelloWorld.hpp"
#include "GameDB/Editor/Application.hpp"
#include "GameDB/Editor/HelloWorld.hpp"

#include "GameDB/Data.hpp"
#include "GameDB/Debug.hpp"
#include "GameDB/Container.hpp"

using namespace GDB;

namespace Pluto::GameDB::Editor::Standalone
{
    class ColumnDrawer
    {
    public:
        explicit ColumnDrawer(DataColumn* column)
            : _column(column)
        {
        }

        virtual ~ColumnDrawer() = 0;
        virtual void Draw(DataRow* row) = 0;

    protected:
        DataColumn* _column;
    };

    ColumnDrawer::~ColumnDrawer() = default;


    class DataTypeStringColumnDrawer final : public ColumnDrawer
    {
    public:
        explicit DataTypeStringColumnDrawer(DataColumn* column)
            : ColumnDrawer(column)
        {
        }

        void Draw(DataRow* row) override
        {
            const std::optional<DataValue*> rowDataValue = row->GetValue(*_column);
            const auto rowDataValueString = dynamic_cast<DataValueString*>(rowDataValue.value());
            std::cout << _column->GetName() << ": " << rowDataValueString->GetValue() << std::endl;
        }
    };


    int Main(const std::vector<std::string>& args)
    {
        GeneralAllocator::Allocate(16);

        auto mainLogger = std::make_unique<Logger>();
        mainLogger->AddSink(std::make_unique<LoggerSinkStdOut>());
        Log::Global()->SetLogger("Main", std::move(mainLogger));

        //GDB_ASSERT(false, "bla");

        //GDB_LOG(GDB::LogType::Debug, "", "");

        DataTable dataTable(DataId::Random(), "Pokemons");

        auto columnId = std::make_unique<DataColumn>(DataId::Random(), "id", std::make_unique<DataTypeString>());
        auto columnName = std::make_unique<DataColumn>(DataId::Random(), "name", std::make_unique<DataTypeString>());
        const DataColumn* columnNamePtr = columnName.get();

        dataTable.AddColumn(std::move(columnId));
        dataTable.AddColumn(std::move(columnName));

        const DataRow* dataRow = dataTable.AddRow();
        const std::optional<DataValue*> dataValue = dataRow->GetValue(*columnNamePtr);
        const auto dataValueString = dynamic_cast<DataValueString*>(dataValue.value());
        dataValueString->SetValue("Pikachu");

        std::vector<std::unique_ptr<ColumnDrawer>> drawers;
        for (const auto& column : dataTable.GetColumns())
        {
            drawers.push_back(std::make_unique<DataTypeStringColumnDrawer>(column.get()));
        }

        for (const auto& row : dataTable.GetRows())
        {
            for (const auto& drawer : drawers)
            {
                drawer->Draw(row.get());
            }
        }



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
        const gsl::span<const char*> argsSpan(argv, argc);
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
