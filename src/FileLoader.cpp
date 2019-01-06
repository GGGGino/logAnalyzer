//
// Created by david ginanni on 05/01/2019.
//

#include "../include/FileLoader.h"

log_analyzer::FileLoader::FileLoader(std::string &path): path_(path) {}

std::ifstream log_analyzer::FileLoader::loadFile() {
    std::ifstream file;
    file.open(path_);

    return file;
}
