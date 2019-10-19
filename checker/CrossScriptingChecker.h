#ifndef LOGANALYZER_CROSSSCRIPTINGCHECKER_H
#define LOGANALYZER_CROSSSCRIPTINGCHECKER_H

#include "Checkers.h"

namespace log_analyzer {
    class CrossScriptingChecker: public CheckerInterface {
    private:
        std::vector<LineParser> *lines;

    public:
        explicit CrossScriptingChecker(std::vector<LineParser> *lines, LogChecker &logChecker);
    };
}

#endif