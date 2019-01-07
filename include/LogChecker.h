//
// Created by david ginanni on 07/01/2019.
//

#ifndef LOGANALYZER_LOGCHECKER_H
#define LOGANALYZER_LOGCHECKER_H

#include <vector>
#include "LineParser.h"

namespace log_analyzer {
    /** For academic purpose */
    typedef std::vector<LineParser> vectorLines;

    class LogChecker {
    private:
        std::vector<LineParser> lines_;

    public:
        void addLine(LineParser line);
        void setLines(const std::vector<LineParser> &lines);
    };
}

#endif //LOGANALYZER_LOGCHECKER_H
