add_library(libletData STATIC 
    "DataColumn.cpp"
    "DataId.cpp"
    "DataRow.cpp"
    "DataTable.cpp"
    "DataType.cpp"
    "DataTypeString.cpp"
    "DataValue.cpp"
    "DataValueString.cpp"
)

target_include_directories(libletData PUBLIC
    "Include"
)

target_link_libraries(libletData PUBLIC
	libletContainer
    libletMemory
)
