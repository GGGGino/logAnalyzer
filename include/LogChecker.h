//
// Created by david ginanni on 07/01/2019.
//

#ifndef LOGANALYZER_LOGCHECKER_H
#define LOGANALYZER_LOGCHECKER_H

#include <vector>
#include "LineParser.h"
#include "Checkers.h"

namespace log_analyzer {
    /** For academic purpose */
    typedef std::vector<LineParser> vectorLines;
    typedef std::vector<CheckerInterface> vectorCheckers;

    class LogChecker {
    private:
        vectorLines lines_;
        vectorCheckers checkers_;

    public:
        void addLine(LineParser line);
        void setLines(const vectorLines &lines);
        /** For academic purpose yet */
        vectorCheckers *getCheckers();
        bool checkViolation();
    };
}

#endif //LOGANALYZER_LOGCHECKER_H
