#include "CrossScriptingChecker.h"

log_analyzer::CrossScriptingChecker::CrossScriptingChecker(std::vector<LineParser> *lines, LogChecker &logChecker):
CheckerInterface(lines, logChecker) {}

bool log_analyzer::CrossScriptingChecker::check() const {
    for( LineParser &line: *lines_) {
        if (checkUrl(line)) {
            return false;
        }
    }
    
    return true;
}

bool log_analyzer::CrossScriptingChecker::checkUrl(LineParser &line) const{
    return line.realUrl_.query_.find("script") != std::string::npos;
}

const char *log_analyzer::CrossScriptingChecker::getName() const {
    char * name = new char[10];
    strcpy(name, "Cross scripting");
    return name;
}