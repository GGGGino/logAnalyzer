//
// Created by david ginanni on 05/01/2019.
//

#include <iostream>
#include "../include/Checkers.h"
#include "../include/LogChecker.h"

log_analyzer::CheckerInterface::CheckerInterface(vectorLines *lines): lines_(lines) {}

bool log_analyzer::ManyLogInTimeChecker::check() const{
    return true;

    for (const LineParser &line: *lines_) {

    }
}

log_analyzer::ManyLogInTimeChecker::ManyLogInTimeChecker(vectorLines *lines): CheckerInterface(lines) {}