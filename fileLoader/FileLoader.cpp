//
// Created by david ginanni on 05/01/2019.
//

#include <iostream>
#include <boost/filesystem.hpp>
#include "./FileLoader.h"

log_analyzer::FileLoader::FileLoader(std::string path): path_(path) {}

std::ifstream log_analyzer::FileLoader::loadFile() {
    return std::ifstream(path_);
}

std::string log_analyzer::FileLoader::getFilePath() {
    boost::filesystem::path abs_path = boost::filesystem::complete(path_);
    return abs_path.string();
}

bool log_analyzer::FileLoader::fileExists() {
    return boost::filesystem::exists(path_);
}