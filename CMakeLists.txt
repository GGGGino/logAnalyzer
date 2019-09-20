cmake_minimum_required(VERSION 3.12)
set (VERSION 0.1)
set (PACKAGE logAnalyzer)
project(${PACKAGE})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-lncurses")

add_subdirectory(lineParser)
add_subdirectory(fileLoader)
add_subdirectory(checker)

add_executable(${PACKAGE} main.cpp)

target_link_libraries(${PACKAGE} lineParser fileLoader checker)