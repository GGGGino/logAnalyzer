#include <iostream>
#include <fstream>
#include <string>
#include "include/FileLoader.h"
#include "include/LineParser.h"
#include "include/LogChecker.h"
#include "include/window/WindowManager.h"

log_analyzer::WindowManager createPanel() {
    return log_analyzer::WindowManager();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    log_analyzer::FileLoader fileLoader = log_analyzer::FileLoader("../error.log");
    std::ifstream fileS = fileLoader.loadFile();

    if( !fileS.is_open() ) {
        return 0;
    }

    log_analyzer::WindowManager windowManager = createPanel();

    std::string line;
    log_analyzer::LogChecker logChecker;

    while ( getline(fileS, line) ){
        // std::cout << line << std::endl;
        log_analyzer::LineParser lineParsed(line);
        logChecker.addLine(lineParsed);
        char completeString[80];
        std::strcpy(completeString, lineParsed.completeString_.c_str());
        windowManager.print_in_body(windowManager.my_wins[2], 5, 5, 0, completeString, COLOR_PAIR(2));
    }

    bool checkViolation = logChecker.checkViolation();

    if( !checkViolation ) {
        std::cout << "Attack started" << std::endl;
    }

    return 0;
}