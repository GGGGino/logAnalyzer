//
// Created by david ginanni on 05/01/2019.
//

#include <iostream>
#include <chrono>
#include <map>
#include <ctime>
#include "./Checkers.h"
#include "./LogChecker.h"

log_analyzer::CheckerInterface::CheckerInterface(vectorLines *lines, LogChecker &logChecker):
lines_(lines), logChecker(logChecker) {}

log_analyzer::SqlInjectionChecker::SqlInjectionChecker(vectorLines *lines, LogChecker &logChecker):
CheckerInterface(lines, logChecker) {}

bool log_analyzer::SqlInjectionChecker::check() const{
    if( lines_->empty() )
        return true;

    for (const LineParser &line: *lines_) {
        if( checkUrl(&line.realUrl_) )
            return true;
    }
}

bool log_analyzer::SqlInjectionChecker::checkUrl(const log_analyzer::Uri *url) const {
    std::string query = url->query_;

    if( query.find("SELECT") != std::string::npos )
        return true;

    return false;
}