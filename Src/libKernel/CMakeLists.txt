add_library(gdb.libKernel STATIC)

target_include_directories(gdb.libKernel PUBLIC
    "Include"
)

target_link_libraries(gdb.libKernel PUBLIC
	gdb.libContainer
)

if(WIN32)
add_subdirectory(Windows)
elseif(APPLE)
add_subdirectory(MacOS)
elseif(UNIX)
add_subdirectory(Linux)
else()
message(FATAL_ERROR "Platform not suported!")
endif()
