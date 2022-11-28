cmake_minimum_required(VERSION 3.21)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/vcpkg/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(GameDB
        VERSION 0.1.0.0
        DESCRIPTION ""
        HOMEPAGE_URL "https://github.com/Pluto-Games/GameDB.Client"
        LANGUAGES CXX
)

message("Using compiler '${CMAKE_CXX_COMPILER_ID}' version '${CMAKE_CXX_COMPILER_VERSION}'")

set(GNU_MIN_VERSION "7.0")
set(MSVC_MIN_VERSION "19.14")
set(Clang_MIN_VERSION "6.0")
set(AppleClang_MIN_VERSION "10.0")

if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS ${${CMAKE_CXX_COMPILER_ID}_MIN_VERSION})
    message(FATAL_ERROR "Insufficient ${CMAKE_CXX_COMPILER_ID} version. Minimum Required is ${${CMAKE_CXX_COMPILER_ID}_MIN_VERSION}!")
endif()

set(MSVC_COMPILER_OPTIONS "")
set(GCC_COMPILER_OPTIONS "")
set(Clang_COMPILER_OPTIONS "")
set(AppleClang_COMPILER_OPTIONS "")
set(COMPILER_OPTIONS ${${CMAKE_CXX_COMPILER_ID}_COMPILER_OPTIONS})
add_compile_options(${COMPILER_OPTIONS})

set(ENABLE_PROFILING ON CACHE STRING "Enable profiling instrumentation")
if (ENABLE_PROFILING)
    message("Profiler enabled!")
    set(MSVC_PROFILER_ENABLED_COMPILER_OPTIONS /DGDB_PROFILER_ENABLED)
    set(GCC_PROFILER_ENABLED_COMPILER_OPTIONS -DGDB_PROFILER_ENABLED)
    set(Clang_PROFILER_ENABLED_COMPILER_OPTIONS -DGDB_PROFILER_ENABLED)
    set(AppleClang_PROFILER_ENABLED_COMPILER_OPTIONS -DGDB_PROFILER_ENABLED)
    set(PROFILER_ENABLED_COMPILER_OPTIONS ${${CMAKE_CXX_COMPILER_ID}_PROFILER_ENABLED_COMPILER_OPTIONS})
    add_compile_options(${PROFILER_ENABLED_COMPILER_OPTIONS})
endif()

set(ENABLE_ALL_WARNINGS_AS_ERROR ON CACHE STRING "Enable all warnings as errors")
if (ENABLE_ALL_WARNINGS_AS_ERROR)
    message("Warning as errors enabled!")
    set(MSVC_WARNING_COMPILER_OPTIONS /W4 /WX /permissive-)
    set(GCC_WARNING_COMPILER_OPTIONS -Wall -Wextra -Werror)
    set(Clang_WARNING_COMPILER_OPTIONS -Wall -Wextra -Werror)
    set(AppleClang_WARNING_COMPILER_OPTIONS -Wall -Wextra -Werror)
    set(WARNING_COMPILER_OPTIONS ${${CMAKE_CXX_COMPILER_ID}_WARNING_COMPILER_OPTIONS})
    add_compile_options(${WARNING_COMPILER_OPTIONS})
endif()

set(ENABLE_CLANG_TIDY ON CACHE STRING "Enable clang tidy")
if (ENABLE_CLANG_TIDY)
    message("Enabling clang tidy...")
    find_program(CLANG_TIDY clang-tidy)
    if (CLANG_TIDY)
        # Manually passing the /EHsc to clang-tidy due to a bug when the argument is passed after -- argument.
        # For more information look at: https://gitlab.kitware.com/cmake/cmake/-/issues/20512
        set(MSVC_CLANG_TIDY_EXTRA_ARGS /EHsc)
        set(CLANG_TIDY_EXTRA_ARGS ${${CMAKE_CXX_COMPILER_ID}_CLANG_TIDY_EXTRA_ARGS})
        set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY};--extra-arg=${CLANG_TIDY_EXTRA_ARGS})
    else()
        message(FATAL_ERROR "Could not found the exectutable for clang-tidy installed on the machine!")
    endif()
endif()

include("ThirdParty/vcpkg.cmake")

add_subdirectory("Src")

# first we can indicate the documentation build as an option and set it to ON by default
set(ENABLE_DOXYGEN ON CACHE STRING "Enable DoxyGen")
if (ENABLE_DOXYGEN)
    # check if Doxygen is installed
    find_package(Doxygen)
    if (DOXYGEN_FOUND)
        # set input and output files
        set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Docs/Doxyfile.in)
        set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

        # request to configure the file
        configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
        message("Doxygen build started")

        # note the option ALL which allows to build the docs together with the application
        add_custom_target( doc_doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM )
    else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
    endif (DOXYGEN_FOUND)
endif(ENABLE_DOXYGEN)

include(CPack)
