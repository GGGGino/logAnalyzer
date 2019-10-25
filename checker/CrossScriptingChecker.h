#ifndef LOGANALYZER_CROSSSCRIPTINGCHECKER_H
#define LOGANALYZER_CROSSSCRIPTINGCHECKER_H

#include "Checkers.h"

namespace log_analyzer {
    class CrossScriptingChecker: public CheckerInterface {
    private:
        bool checkUrl(LineParser &line) const;
    public:
        explicit CrossScriptingChecker(std::vector<LineParser> *lines, LogChecker &logChecker);
        bool check() const;
        const char *getName() const;
    };
}

#endif