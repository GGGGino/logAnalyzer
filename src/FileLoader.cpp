//
// Created by david ginanni on 05/01/2019.
//

#include <iostream>
#include "../include/FileLoader.h"

log_analyzer::FileLoader::FileLoader(std::string &&path): path_(path) {}

const std::ifstream &log_analyzer::FileLoader::loadFile() {
    //std::ifstream stream(path_);
    return std::ifstream(path_);
}