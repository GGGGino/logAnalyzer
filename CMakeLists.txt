cmake_minimum_required(VERSION 3.10)
set (VERSION 0.1)
set (PACKAGE logAnalyzer)
project(${PACKAGE})

set(CMAKE_CXX_STANDARD 14)

find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_subdirectory(lineParser)
add_subdirectory(fileLoader)
add_subdirectory(checker)
add_subdirectory(mywindow)

add_executable(${PACKAGE} main.cpp)

target_link_libraries(${PACKAGE} lineParser fileLoader checker mywindow panel ${Boost_LIBRARIES})
