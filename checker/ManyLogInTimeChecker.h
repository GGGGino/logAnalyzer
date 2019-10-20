//
// Created by david ginanni on 07/01/2019.
//

#ifndef LOGANALYZER_MANYLOGINTIMECHECKER_H
#define LOGANALYZER_MANYLOGINTIMECHECKER_H

#include <vector>
#include "../lineParser/LineParser.h"
#include "../lineParser/Uri.h"
#include "./Checkers.h"

namespace log_analyzer {
    class ManyLogInTimeChecker: public CheckerInterface {
    public:
        explicit ManyLogInTimeChecker(std::vector<LineParser> *lines, LogChecker &logChecker);
        bool check() const;
        char const *getName() const;
    };
}

#endif //LOGANALYZER_MANYLOGINTIMECHECKER_H