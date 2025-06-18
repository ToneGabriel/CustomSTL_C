cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)

project(your_project_name VERSION 0.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(TEST_YOUR_PROJECT_NAME_EXE_NAME test_your_project_name)
add_executable(${TEST_YOUR_PROJECT_NAME_EXE_NAME} ${CMAKE_SOURCE_DIR}/test/main.c)

target_include_directories(${TEST_YOUR_PROJECT_NAME_EXE_NAME} PRIVATE
${CMAKE_SOURCE_DIR}/include
)

target_sources(${TEST_YOUR_PROJECT_NAME_EXE_NAME} PRIVATE
${CMAKE_SOURCE_DIR}/test/test_priority_queue.c
)

target_compile_definitions(${TEST_YOUR_PROJECT_NAME_EXE_NAME} PRIVATE
DEF_EXAMPLE
DEF_VAL_EXAMPLE=value
DEF_STR_EXAMPLE="string"
)

include(FetchContent)
FetchContent_Declare(
Unity
GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
GIT_TAG master
)

FetchContent_MakeAvailable(Unity)

set(UNITY_CMAKE_LIB_NAME Unity)

target_link_libraries(${TEST_YOUR_PROJECT_NAME_EXE_NAME} PRIVATE
${UNITY_CMAKE_LIB_NAME}
)

