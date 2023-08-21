cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

project(Copper-Math VERSION 1.0.0.0 LANGUAGES CXX)

include(${PROJECT_SOURCE_DIR}/CMath/CMakeLists.txt)

add_executable(Copper-Math-Test ${CMathSources} CMath/App.cpp)

set_target_properties(Copper-Math-Test PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/Tests")

target_compile_definitions(Copper-Math-Test PRIVATE INCLUDE_GLM)
target_include_directories(Copper-Math-Test PRIVATE CMath GLM/include)