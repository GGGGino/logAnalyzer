//
// Created by david ginanni on 05/01/2019.
//

#include <iostream>
#include <chrono>
#include <map>
#include <ctime>
#include "./Checkers.h"
#include "./LogChecker.h"

log_analyzer::SqlInjectionChecker::SqlInjectionChecker(vectorLines *lines, LogChecker &logChecker):
CheckerInterface(lines, logChecker) {}

char const *log_analyzer::SqlInjectionChecker::getName() const {
    char *nome = new char;
    strcpy(nome, "Sql Injection");

    return nome;
}

bool log_analyzer::SqlInjectionChecker::check() const {
    if( lines_->empty() )
        return false;

    for (const LineParser &line: *lines_) {
        if( checkUrl(&line.realUrl_) )
            return true;
    }

    return false;
}

bool log_analyzer::SqlInjectionChecker::checkUrl(const log_analyzer::Uri *url) const {
    const std::string query = url->query_;

    if( query.find("SELECT") != std::string::npos || query.find("UNION") != std::string::npos )
        return true;

    return false;
}