# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Set the CMake policy to prefer GLVND (modern OpenGL/Vulkan/GLX)
cmake_policy(SET CMP0072 NEW)

# Project name and language
project(Cpp)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find OpenGL and glfw3
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Source files
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# Add an executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Add glad library
add_library(glad STATIC ./src/glad.c)

# Add include directories for the glad library
# This is the directory where all your header files are

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL glfw3 glad)

# Add compile options (e.g., warnings)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -g)

