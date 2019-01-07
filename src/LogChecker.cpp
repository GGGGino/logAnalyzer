//
// Created by david ginanni on 07/01/2019.
//

#include "../include/LogChecker.h"

void log_analyzer::LogChecker::addLine(log_analyzer::LineParser line) {
    lines_.push_back(line);
}

void log_analyzer::LogChecker::setLines(const std::vector<log_analyzer::LineParser> &lines) {
    lines_ = lines;
}
