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

# Dear ImGui
FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG 13c4084362b35ce58a25be70b9f1710dfe3377e9
)
FetchContent_MakeAvailable(imgui)

# Add main executable
add_executable(dohyo src/main.c
        src/graphics/graphics.c
        src/graphics/graphics.h
        src/physics/physics.c
        src/physics/physics.h
        src/graphics/circles.c
        src/graphics/circles.h)

# Add ImGui backend files
target_sources(dohyo PRIVATE
        ${imgui_SOURCE_DIR}/backends/imgui_impl_sdl3.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
        ${imgui_SOURCE_DIR}/imgui.cpp
        ${imgui_SOURCE_DIR}/imgui_draw.cpp
        ${imgui_SOURCE_DIR}/imgui_tables.cpp
        ${imgui_SOURCE_DIR}/imgui_widgets.cpp
)

# Include directories
target_include_directories(dohyo PRIVATE
        ${imgui_SOURCE_DIR}
        ${SDL3_SOURCE_DIR}/include
)

# Link libraries
target_link_libraries(dohyo PRIVATE
        box2d
        SDL3::SDL3
)

# If on Windows, copy SDL3.dll from external/SDL3 into the build directory.
set(SDL3_SRC ${CMAKE_SOURCE_DIR}/external/SDL3/SDL3.dll)
if(WIN32 AND EXISTS ${SDL3_SRC})
    file(COPY ${SDL3_SRC} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
else()
    message(WARNING "SDL3.dll not found at ${SDL3_SRC}. You cannot run Dohyo without this file.")
endif()