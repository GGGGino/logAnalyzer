#include "CrossScriptingChecker.h"

log_analyzer::CrossScriptingChecker::CrossScriptingChecker(std::vector<LineParser> *lines, LogChecker &logChecker):
CheckerInterface(lines, logChecker) {}