cmake_minimum_required(VERSION 3.16)
project(PipelineProject LANGUAGES CXX)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Detect Windows
if (WIN32)
    message(STATUS "Compiling for Windows")

    # Define Windows-specific macros (optional)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)  # Avoid MSVC warnings for `fopen`
endif()

# Enable multithreading support
find_package(Threads REQUIRED)

# Add the executable
add_executable(cynlr
    src/main.cpp
    src/pipeline.cpp
    src/blocks/data_generation_block.cpp
    src/blocks/filtering_block.cpp
    src/ring_buffer.cpp
)

# Include directories
target_include_directories(cynlr PRIVATE ${CMAKE_SOURCE_DIR})

# Link necessary libraries
target_link_libraries(cynlr PRIVATE Threads::Threads)

# Define _DEBUG in Debug mode
target_compile_definitions(cynlr PRIVATE $<$<CONFIG:Debug>:_DEBUG>)

# Enable optimizations for Release mode
target_compile_options(cynlr PRIVATE $<$<CONFIG:Release>:-O3>)
