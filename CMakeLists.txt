# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(Cpp)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

# Add source files
set(SOURCES src/main.cpp ${SRC_FILES})

add_library(glad STATIC ./src/glad.c)

# Add an executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Add compile options (e.g., warnings)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -g)


target_include_directories(Cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL glfw3 glad)

