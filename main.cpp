#include <iostream>
#include <fstream>
#include <string>
#include "include/FileLoader.h"
#include "include/LineParser.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    log_analyzer::FileLoader fileLoader = log_analyzer::FileLoader("../error.log");
    std::ifstream fileS = fileLoader.loadFile();

    if( !fileS.is_open() ) {
        return 0;
    }

    std::string line;

    while ( getline(fileS, line) ){
        // std::cout << line << std::endl;
        log_analyzer::LineParser lineParsed(line);
        std::cout << "pippo";
    }

    return 0;
}