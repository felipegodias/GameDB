add_library(libCore INTERFACE)

target_link_libraries(libCore INTERFACE
    libletContainer
	libletData
	libletDebug
	libletMemory
)

add_subdirectory(libletContainer)
add_subdirectory(libletData)
add_subdirectory(libletDebug)
add_subdirectory(libletMemory)
