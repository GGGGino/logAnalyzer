//
// Created by david ginanni on 05/01/2019.
//

#include <iostream>
#include "./FileLoader.h"

log_analyzer::FileLoader::FileLoader(std::string &&path): path_(path) {}

std::ifstream log_analyzer::FileLoader::loadFile() {
    return std::ifstream(path_);
}
