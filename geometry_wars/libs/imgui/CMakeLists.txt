# CMake minimum version required
cmake_minimum_required(VERSION 3.12)

# Project name
project(MyProject)

file(GLOB SOURCE_FILES "./*.cpp")

add_library(imgui STATIC ${SOURCE_FILES})

target_include_directories(imgui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
