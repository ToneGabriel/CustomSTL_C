cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)
project(
    CustomSTL_C
    VERSION 1.0.0
    LANGUAGES C
)

# Get unity project
include(cmake/unity.cmake)

# Add utils
include(cmake/internal_utils.cmake)

# Configure C and C++ STL
add_subdirectory(custom_stl_c)
