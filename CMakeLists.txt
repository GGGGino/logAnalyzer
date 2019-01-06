cmake_minimum_required(VERSION 3.12)
project(logAnalyzer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-lncurses")

add_executable(logAnalyzer main.cpp src/FileLoader.cpp include/FileLoader.h)