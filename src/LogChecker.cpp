//
// Created by david ginanni on 07/01/2019.
//

#include "../include/LogChecker.h"

void log_analyzer::LogChecker::addLine(log_analyzer::LineParser line) {
    lines_.push_back(line);
}

void log_analyzer::LogChecker::setLines(const vectorLines &lines) {
    lines_ = lines;
}

bool log_analyzer::LogChecker::checkViolation() {
    vectorCheckers *checkers = getCheckers();

    for (auto const &checker: *checkers) {
        if( !checker.check() ){
            return false;
        }
    }

    return true;
}

log_analyzer::vectorCheckers *log_analyzer::LogChecker::getCheckers() {
    if( !checkers_.empty() ){
        return  &checkers_;
    }

    ManyLogInTimeChecker checkMlt(&lines_);

    //checkers_.push_back(checkMlt);

    return &checkers_;
}
