#include "CrossScriptingChecker.h"

log_analyzer::CrossScriptingChecker::CrossScriptingChecker(std::vector<LineParser> *lines, LogChecker &logChecker):
CheckerInterface(lines, logChecker) {}

bool log_analyzer::CrossScriptingChecker::check() const {
    return false;
}