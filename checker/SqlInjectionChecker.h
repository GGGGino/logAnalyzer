//
// Created by david ginanni on 07/01/2019.
//

#ifndef LOGANALYZER_SQLINJECTIONCHECKER_H
#define LOGANALYZER_SQLINJECTIONCHECKER_H

#include <vector>
#include "../lineParser/LineParser.h"
#include "../lineParser/Uri.h"
#include "./Checkers.h"

namespace log_analyzer {
    class CheckerInterface;

    class SqlInjectionChecker: public CheckerInterface {
    public:
        bool check() const;
        bool checkUrl(const log_analyzer::Uri *url) const;
        explicit SqlInjectionChecker(std::vector<LineParser> *lines, LogChecker &logChecker);
    };
}

#endif //LOGANALYZER_SQLINJECTIONCHECKER_H