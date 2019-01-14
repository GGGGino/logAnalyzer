//
// Created by david ginanni on 07/01/2019.
//

#ifndef LOGANALYZER_CHECKERINTERFACE_H
#define LOGANALYZER_CHECKERINTERFACE_H

#include <vector>
#include "LineParser.h"

namespace log_analyzer {
    class LogChecker;

    class CheckerInterface {
    protected:
        std::vector<LineParser> *lines_;
        LogChecker &logChecker;
    public:
        explicit CheckerInterface(std::vector<LineParser> *lines, LogChecker &logChecker);
        virtual bool check() const = 0;
    };

    class ManyLogInTimeChecker: public CheckerInterface {
    public:
        bool check() const;
        explicit ManyLogInTimeChecker(std::vector<LineParser> *lines, LogChecker &logChecker);
    };

    class SqlInjectionChecker: public CheckerInterface {
    public:
        bool check() const;
        explicit SqlInjectionChecker(std::vector<LineParser> *lines, LogChecker &logChecker);
    };
}

#endif //LOGANALYZER_CHECKERINTERFACE_H