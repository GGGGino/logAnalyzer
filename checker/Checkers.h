//
// Created by david ginanni on 07/01/2019.
//

#ifndef LOGANALYZER_CHECKERINTERFACE_H
#define LOGANALYZER_CHECKERINTERFACE_H

#include <vector>
#include "../lineParser/LineParser.h"

namespace log_analyzer {
    class LogChecker;

    class CheckerInterface {
    protected:
        std::vector<LineParser> *lines_;
        LogChecker &logChecker;
    public:
        explicit CheckerInterface(std::vector<LineParser> *lines, LogChecker &logChecker);
        /* Return false in case of attack */
        virtual bool check() const = 0;
        /* Return the name of the Checker */
        virtual const char *getName() const;
    };
}

#endif //LOGANALYZER_CHECKERINTERFACE_H