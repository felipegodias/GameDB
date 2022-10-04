#include "GameDB/HelloWorld.hpp"

#include <fstream>
#include <iostream>
#include <memory>
#include <fmt/format.h>
#include <nlohmann/json.hpp>

using Json = nlohmann::ordered_json;

namespace Pluto::GameDB
{
    namespace
    {
        using Guid = std::string;

        class SchemaField;

        class SchemaFieldValue
        {
        public:
            SchemaField* SchemaField;

            explicit SchemaFieldValue(GameDB::SchemaField* schemaField)
                : SchemaField(schemaField)
            {
            }

            virtual ~SchemaFieldValue() = 0 {}

            virtual void ToJson(Json& json) const = 0;
        };

        class SchemaFieldType
        {
        public:
            virtual ~SchemaFieldType() = 0 {}

            [[nodiscard]] virtual std::string GetTypeName() const = 0;
            [[nodiscard]] virtual std::unique_ptr<SchemaFieldValue> InstantiateValue(SchemaField* schemaField) const = 0;
            virtual void ToJson(Json& json) const = 0;
        };

        class SchemaFieldValueString final : public SchemaFieldValue
        {
        public:
            std::string Value;

            explicit SchemaFieldValueString(GameDB::SchemaField* schemaField)
                : SchemaFieldValue(schemaField)
            {
            }

            void ToJson(Json& json) const override
            {
                json["Value"] = Value;
            }
        };

        class SchemaFieldTypeString final : public SchemaFieldType
        {
        public:
            [[nodiscard]] std::string GetTypeName() const override
            {
                return "String";
            }

            [[nodiscard]] std::unique_ptr<SchemaFieldValue> InstantiateValue(SchemaField* schemaField) const override
            {
                return std::make_unique<SchemaFieldValueString>(schemaField);
            }

            void ToJson(Json& json) const override
            {
                json["Name"] = GetTypeName();
            }
        };

        class SchemaField
        {
        public:
            Guid InstanceId;
            std::string Name;
            std::unique_ptr<SchemaFieldType> Type;

            SchemaField(Guid InstanceId, std::string name, std::unique_ptr<SchemaFieldType> type)
                : InstanceId(std::move(InstanceId)),
                  Name(std::move(name)),
                  Type(std::move(type))
            {
            }
        };

        class Schema
        {
        public:
            std::vector<std::unique_ptr<SchemaField>> Fields;
        };

        class TableRow
        {
        public:
            Guid InstanceId;
            std::unordered_map<Guid, std::unique_ptr<SchemaFieldValue>> Fields;

            explicit TableRow(Guid InstanceId)
                : InstanceId(std::move(InstanceId))
            {
            }

            TableRow(const TableRow& other) = delete;

            TableRow(TableRow&& other) noexcept
                : InstanceId(std::move(other.InstanceId)),
                  Fields(std::move(other.Fields))
            {
            }

            TableRow& operator=(const TableRow& other) = delete;

            TableRow& operator=(TableRow&& other) noexcept
            {
                if (this == &other)
                {
                    return *this;
                }
                    
                InstanceId = std::move(other.InstanceId);
                Fields = std::move(other.Fields);
                return *this;
            }
        };

        class Table
        {
        public:
            Guid InstanceId;
            std::string Name;
            Schema Schema;
            std::vector<TableRow> Entries;
        };

        void to_json(Json& json, const SchemaFieldType& schemaFieldType)
        {
            schemaFieldType.ToJson(json);
        }

        void to_json(Json& json, const SchemaFieldValue& schemaFieldValue)
        {
            schemaFieldValue.ToJson(json);
        }

        void to_json(Json& json, const Table& table)
        {
            json["InstanceId"] = table.InstanceId;
            json["Name"] = table.Name;

            Json schemaJson;
            for (const auto& field : table.Schema.Fields)
            {
                Json typeJson(*field->Type);

                schemaJson[field->InstanceId] = {
                    {"Name", field->Name},
                    {"Type", typeJson}
                };
            }
            json["Schema"] = std::move(schemaJson);

            Json rowsJson;
            for (const TableRow& entry : table.Entries)
            {
                Json rowJson;
                rowJson["InstanceId"] = entry.InstanceId;
                for (const auto& field : table.Schema.Fields)
                {
                    rowJson[field->InstanceId] = *entry.Fields.at(field->InstanceId);
                }
                rowsJson.push_back(std::move(rowJson));
            }
            json["Rows"] = std::move(rowsJson);
        }
    }

    std::string GetGameDBHelloWorld()
    {
        //std::make_unique<SchemaField>({ "d92e9519e1c7433a9eb9b9a91963bb78","Id", std::make_unique<SchemaFieldTypeString>() }),

        //[[maybe_unused]] auto a = std::make_unique<SchemaField>("d92e9519e1c7433a9eb9b9a91963bb78", "Id", std::make_unique<SchemaFieldTypeString>());

        Schema schema;
        schema.Fields.push_back(std::make_unique<SchemaField>("d92e9519e1c7433a9eb9b9a91963bb78", "Id", std::make_unique<SchemaFieldTypeString>()));
        schema.Fields.push_back(std::make_unique<SchemaField>("17e25ec8041445eda84b836348a0c065", "Name", std::make_unique<SchemaFieldTypeString>()));

        size_t numRows = 100000;
        std::vector<TableRow> rows;
        rows.reserve(numRows);
        for (size_t i = 0; i < numRows; ++i)
        {
            TableRow tableRow(fmt::format("3c64a0e3e32242819d49311cf8d5ac37+{0}", i));
            for (const auto& field : schema.Fields)
            {
                std::unique_ptr<SchemaFieldValue> schemaFieldValue = field->Type->InstantiateValue(field.get());
                tableRow.Fields.emplace(field->InstanceId, std::move(schemaFieldValue));
            }
            rows.push_back(std::move(tableRow));
        }

        
        [[maybe_unused]] Table table = {
            "63478f24ae4a4900b805ca206a47df5b",
            "Items",
            std::move(schema),
            std::move(rows)
        };

        auto start = std::chrono::high_resolution_clock::now();
        {
            Json json(table);
            std::ofstream ofs("file.json");
            ofs << json.dump(2);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = end - start;
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << " ms" << std::endl;

        return "Hello GameDB";
    }
}
