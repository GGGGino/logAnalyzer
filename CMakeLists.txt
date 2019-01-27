cmake_minimum_required(VERSION 3.12)
project(logAnalyzer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-lpanel")
set(CMAKE_CXX_FLAGS "-lncurses")

add_executable(logAnalyzer main.cpp src/FileLoader.cpp include/FileLoader.h include/LineParser.h src/LineParser.cpp src/LogChecker.cpp include/LogChecker.h include/Checkers.h src/Checkers.cpp include/Uri.h src/Uri.cpp src/window/WindowManager.cpp include/window/WindowManager.h)

target_link_libraries(logAnalyzer panel)