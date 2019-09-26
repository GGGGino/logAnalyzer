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