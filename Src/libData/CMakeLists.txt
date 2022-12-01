add_library(gdb.libData STATIC 
    "DataColumn.cpp"
    "DataId.cpp"
    "DataRow.cpp"
    "DataSet.cpp"
    "DataTable.cpp"
    "DataType.cpp"
    "DataTypeString.cpp"
    "DataValue.cpp"
    "DataValueString.cpp"
)

target_include_directories(gdb.libData PUBLIC
    "Include"
)

target_link_libraries(gdb.libData PUBLIC
	gdb.libContainer
    gdb.libDI
    gdb.libEvent
    gdb.libLog
    gdb.libMemory
    gdb.libProfiler
)
