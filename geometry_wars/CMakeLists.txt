# CMake minimum version required
cmake_minimum_required(VERSION 3.12)

# Project name
project(geometry_wars)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Specify the source files for the executable
file(GLOB SOURCE_FILES "src/*.cpp")
add_executable(geometry_wars ${SOURCE_FILES})

# Specify the directory containing header files
include_directories(include)
include_directories(libs/imgui)

#add subdirectories with their own CMakeLists.txt files
add_subdirectory(libs/imgui)

# -------------------- Static Library --------------------
# Create a static library named "my_static_lib"
# add_library(my_static_lib STATIC
#     src/static_lib_file1.cpp
#     src/static_lib_file2.cpp
# )

# Link the executable with the static library
# target_link_libraries(MyExecutable PRIVATE my_static_lib)

# -------------------- Dynamic Library --------------------
# Create a dynamic library named "my_dynamic_lib"
# add_library(my_dynamic_lib SHARED
#     src/dynamic_lib_file1.cpp
#     src/dynamic_lib_file2.cpp
# )

# # Link the executable with the dynamic library
# target_link_libraries(MyExecutable PRIVATE my_dynamic_lib)

# # Specify the directory containing dynamic library headers
# target_include_directories(MyExecutable PRIVATE include/dynamic_lib)

# -------------------- External Libraries --------------------
# Link with external libraries (e.g., if using a math library)
find_library(SFML_GRAPHICS_LIB sfml-graphics)
find_library(SFML_WINDOW_LIB sfml-window)
find_library(SFML_AUDIO_LIB sfml-audio)
find_library(SFML_SYSTEM_LIB sfml-system)

if(SFML_GRAPHICS_LIB)
    target_link_libraries(geometry_wars PRIVATE ${SFML_GRAPHICS_LIB})
else()
    message(FATAL_ERROR "sfml-graphics library not found.")
endif()

if(SFML_WINDOW_LIB)
    target_link_libraries(geometry_wars PRIVATE ${SFML_WINDOW_LIB})
else()
    message(FATAL_ERROR "sfml-window library not found.")
endif()

if(SFML_AUDIO_LIB)
    target_link_libraries(geometry_wars PRIVATE ${SFML_AUDIO_LIB})
else()
    message(FATAL_ERROR "sfml-audio library not found.")
endif()

if(SFML_SYSTEM_LIB)
    target_link_libraries(geometry_wars PRIVATE ${SFML_SYSTEM_LIB})
else()
    message(FATAL_ERROR "sfml-system library not found.")
endif()

target_link_libraries(geometry_wars PUBLIC imgui)
