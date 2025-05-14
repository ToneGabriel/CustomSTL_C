cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)

include(FetchContent)

project(custom_stl_c VERSION 0.0.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

FetchContent_Declare(
googletest
GIT_REPOSITORY https://github.com/google/googletest.git
GIT_TAG main
)

set(INSTALL_GTEST OFF CACHE BOOL "Disable installation of googletest" FORCE)

FetchContent_MakeAvailable(googletest)

set(GTEST_CMAKE_LIB_NAME gtest)
set(GMOCK_CMAKE_LIB_NAME gmock)

set(TEST_CUSTOM_STL_C_EXE_NAME test_custom_stl_c)
add_executable(${TEST_CUSTOM_STL_C_EXE_NAME} ${CMAKE_SOURCE_DIR}/test/main.cpp)

target_link_libraries(${TEST_CUSTOM_STL_C_EXE_NAME} PRIVATE
${GTEST_CMAKE_LIB_NAME}
${GMOCK_CMAKE_LIB_NAME}
)

target_include_directories(${TEST_CUSTOM_STL_C_EXE_NAME} PRIVATE
${CMAKE_SOURCE_DIR}/include
)

target_sources(${TEST_CUSTOM_STL_C_EXE_NAME} PRIVATE
${CMAKE_SOURCE_DIR}/test/test_priority_queue.c
)

