cmake_minimum_required(VERSION 3.14)

# CMake settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Project declaration
project(dohyo C CXX)

# CMake includes
include(FetchContent)

# Box2D
FetchContent_Declare(box2d
        GIT_REPOSITORY https://github.com/erincatto/box2d.git
        GIT_TAG f0763aca7d4dfa8f1c19c2c4a9e66fa6e93ea32e
)
FetchContent_MakeAvailable(box2d)

# SDL3
FetchContent_Declare(
        SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG 080b3002c69f888d83f5de25be876ec4a672ed43
)
FetchContent_MakeAvailable(SDL3)

# Nuklear
FetchContent_Declare(
        nuklear
        GIT_REPOSITORY https://github.com/Immediate-Mode-UI/Nuklear
        GIT_TAG 369d038990265bccf6fda83d80cdf67327d6acf0
)
FetchContent_MakeAvailable(nuklear)

# Add main executable
add_executable(dohyo src/main.c
        src/graphics/graphics.c
        src/graphics/graphics.h
        src/physics/physics.c
        src/physics/physics.h)

# Link libraries
target_link_libraries(dohyo PRIVATE
        box2d
        SDL3::SDL3
)

# Include directories
target_include_directories(dohyo PRIVATE
        ${SDL3_SOURCE_DIR}/include
        ${nuklear_SOURCE_DIR}
)

# If on Windows, copy SDL3.dll from external/SDL3 into the build directory.
set(SDL3_SRC ${CMAKE_SOURCE_DIR}/external/SDL3/SDL3.dll)
if(WIN32 AND EXISTS ${SDL3_SRC})
    file(COPY ${SDL3_SRC} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
else()
    message(WARNING "SDL3.dll not found at ${SDL3_SRC}. You cannot run Dohyo without this file.")
endif()