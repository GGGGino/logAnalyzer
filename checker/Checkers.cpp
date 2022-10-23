//
// Created by david ginanni on 05/01/2019.
//

#include <iostream>
#include <chrono>
#include <map>
#include <ctime>
#include <cstring>
#include "./Checkers.h"
#include "./LogChecker.h"

log_analyzer::CheckerInterface::CheckerInterface(vectorLines *lines, LogChecker &logChecker):
lines_(lines), logChecker(logChecker) {}

const char *log_analyzer::CheckerInterface::getName() const {
    char *stringa = new char[20];
    strcpy(stringa, "Checker generic");
    return stringa;
}