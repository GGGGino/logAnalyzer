#include <iostream>
#include <fstream>
#include <string>
#include "include/FileLoader.h"
#include "include/LineParser.h"
#include "include/LogChecker.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    log_analyzer::FileLoader fileLoader = log_analyzer::FileLoader("../error.log");
    std::ifstream fileS = fileLoader.loadFile();

    if( !fileS.is_open() ) {
        return 0;
    }

    std::string line;
    log_analyzer::LogChecker logChecker;

    while ( getline(fileS, line) ){
        // std::cout << line << std::endl;
        log_analyzer::LineParser lineParsed(line);
        logChecker.addLine(lineParsed);
    }

    bool checkViolation = logChecker.checkViolation();

    if( !checkViolation ) {
        std::cout << "Attack started" << std::endl;
    }

    return 0;
}